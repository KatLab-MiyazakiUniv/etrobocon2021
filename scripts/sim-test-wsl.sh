#!/bin/bash -eu

# @file: sim-test-wsl.sh
# @author: Takahiro55555
# @brief: 設定ファイルを適用した後、シミュレータを動作させる
#         WSL で動作させることしか考えていない

### 以下、設定  ###
APP_NAME="etrobocon2021"
SETTINGS_FILES_DIR="`pwd`/sim-settings"
DEFAULT_SETTINGS_FILE_NAME="${SETTINGS_FILES_DIR}/default.json"  # デフォルトのシミュレータ設定ファイル名
### 以上、設定  ###

# WSL であるかどうかを確認する
if [ ! -f /proc/sys/fs/binfmt_misc/WSLInterop ]; then
    echo "このスクリプトは、WSL上でしか動作しません"
    exit 1
fi

# 設定ファイルのフォーマットを確認する
if [[ ! "$1" =~ ^.*/[lr]/[0-9a-fA-F_\-]+\.json$ ]]; then
    echo "Format Error (File path): ${1}"
    echo 'Expected File Path Regex: ^.*/[lr]/[0-9a-fA-F_\-]+\.json$'
    exit 1
fi

# 上書きするための設定ファイルへのパスをコマンドライン引数から取得する
OVERWRITE_SETTINGS_FILE_NAME="`pwd`/$1"
if [[ "$1" =~ ^/.+$ ]]; then
    OVERWRITE_SETTINGS_FILE_NAME="$1"
elif [[ "$1" =~ ^\./.+$ ]]; then
    OVERWRITE_SETTINGS_FILE_NAME="`pwd``echo $1 | cut -b 2-`"
fi

# ファイルが見つからない場合、プログラムを終了する
if [ ! -f "${OVERWRITE_SETTINGS_FILE_NAME}" ]; then
    echo "File Not Found: ${OVERWRITE_SETTINGS_FILE_NAME}"
    exit 1
fi

# etrobo独自の環境変数の確認
if [[ -z "$ETROBO_ROOT" ]]; then
    ETROBO_ROOT=`echo 'echo $ETROBO_ROOT' | ${HOME}/startetrobo shell | tail -n 1`
fi
if [[ -z "$ETROBO_HRP3_WORKSPACE" ]]; then
    $ETROBO_HRP3_WORKSPACE=`echo 'echo $ETROBO_HRP3_WORKSPACE' | ${HOME}/startetrobo shell | tail -n 1`
fi

# 設定ファイルのあるディレクトリ名から左右どちらのコースで走行するか決定する
COURSE=`echo $1 | sed -r 's/.*\/([rl])\/.+/\1/g'`

# 設定ファイル名から番号を取得する
NAME=`echo $1 | sed -r 's/.*\/[rl]\/([0-9a-fA-F_\-]+)\.json/\1/g'`

# ファイルが見つからない場合、プログラムを終了する
if [ ! -f "${DEFAULT_SETTINGS_FILE_NAME}" ]; then
    echo "File Not Found: ${DEFAULT_SETTINGS_FILE_NAME}"
    exit 1
fi

# 設定ファイルから、ベースとなるキャプチャディレクトリへのパスを取得する
BASE_CAPTURE_DIR_WIN=$(jq -sc add ${DEFAULT_SETTINGS_FILE_NAME} ${OVERWRITE_SETTINGS_FILE_NAME} | jq -r '.captureDir')
if [[ "$BASE_CAPTURE_DIR_WIN" =~ ^$ ]]; then
    UBUNTU_VER=$(lsb_release -a | grep -oE '^Release:\s*[0-9]{2}\.[0-9]{2}' | cut -f 2)
    BASE_CAPTURE_DIR_WIN="\\\\wsl\$\\Ubuntu-${UBUNTU_VER}\\tmp\\etrobo\\capture"
fi

# ベースとなるキャプチャディレクトリ配下に生成するディレクトリ名
if [[ "$2" =~ ^$ ]]; then
    CAPTURE_DIR_WIN="${BASE_CAPTURE_DIR_WIN}\\`date '+%Y-%m-%d'`\\`date '+%H-%M-%S'`\\${COURSE}\\${NAME}"
else
    if [[ "$2" =~ ^([0-9a-zA-Z_\-]+)(\\[0-9a-zA-Z_\-]+)?$ ]]; then
        CAPTURE_DIR_WIN="${BASE_CAPTURE_DIR_WIN}\\$2\\${COURSE}\\${NAME}"
    else
        echo "Format Error (File path): ${2}"
        echo 'Expected File Path Regex: ^([0-9a-zA-Z_\-]+)(\\[0-9a-zA-Z_\-]+)?$'
        exit 1
    fi
fi

# パスのフォーマットを WSL で扱える形式に変換する
if [[ "${CAPTURE_DIR_WIN}" =~ ^\\\\wsl.+$ ]]; then
    CAPTURE_DIR_WSL=$(echo "${CAPTURE_DIR_WIN}" | sed -r 's/^\\{2}wsl\$\\Ubuntu-[0-9\.]+\\/\\/g' | sed -e 's/\\/\//g')
elif [[ ${CAPTURE_DIR_WIN} =~ ^[A-Z]:(\\.*)+$ ]]; then
    CAPTURE_DIR_WSL="/mnt/`echo ${CAPTURE_DIR_WIN,} | cut -b 1`"
    CAPTURE_DIR_WSL+=$(echo "${CAPTURE_DIR_WIN}" | sed -r 's/[A-Z]:(.+)/\1/g' | sed -e 's/\\/\//g')
fi

# 設定ファイルの書き込み
mkdir -p ${ETROBO_HRP3_WORKSPACE}/simdist/${APP_NAME};
EDITED_SETTINGS_FILE_NAME="${ETROBO_HRP3_WORKSPACE}/simdist/${APP_NAME}/settings.json"
CAPTURE_DIR_WIN_JSON_ESCAPED=$(echo "$CAPTURE_DIR_WIN" | sed -e 's/\\/\\\\/g')

# sim-settings/default.json の内容を simsettings/(l|r)/*.json ファイルの内容で上書して保存
jq -sc add ${DEFAULT_SETTINGS_FILE_NAME} ${OVERWRITE_SETTINGS_FILE_NAME} | \
    jq ".captureDir=\"${CAPTURE_DIR_WIN_JSON_ESCAPED}\"" > "${EDITED_SETTINGS_FILE_NAME}"

# キャプチャする際のフレームレートを取得
CAPTURE_RATE=$(jq -r '.captureRate' ${EDITED_SETTINGS_FILE_NAME})

# シミュレータによるキャプチャが有効化されている場合、キャプチャ先のディレクトリを生成
if [[ ${CAPTURE_RATE} -ne 0 ]]; then
    mkdir -p $CAPTURE_DIR_WSL
fi

# シミュレータに設定ファイルの内容を反映し、実行する
echo "[ script: starting: $APP_NAME ]"
echo "[ script: settings file name: ${1} ]"
echo "[ script: captureRate: ${CAPTURE_RATE} ]"
echo "[ script: EnvLightIntensityLevel: `jq -r '.EnvLightIntensityLevel' ${EDITED_SETTINGS_FILE_NAME}` ]"
echo "[ script: EnvLightRotation: `jq -r '.EnvLightRotation' ${EDITED_SETTINGS_FILE_NAME}` ]"
echo "[ script: LSpotLight: `jq -r '.LSpotLight' ${EDITED_SETTINGS_FILE_NAME}` ]"
echo "[ script: RSpotLight: `jq -r '.RSpotLight' ${EDITED_SETTINGS_FILE_NAME}` ]"
EXEC_COMMANDS="curl -X POST -H \"Content-Type: application/json\" -d @${EDITED_SETTINGS_FILE_NAME} http://localhost:54000; "
EXEC_COMMANDS+="make ${COURSE} noset app=${APP_NAME} sim up; "
echo ${EXEC_COMMANDS} | ${HOME}/startetrobo shell

### シミュレータ映像のキャプチャが有効化されていた場合 ###
if [[ ${CAPTURE_RATE} -eq 1 ]]; then
    FRAME_RATE=60
elif [[ ${CAPTURE_RATE} -eq 2 ]]; then
    FRAME_RATE=30
elif [[ ${CAPTURE_RATE} -eq 3 ]]; then
    FRAME_RATE=20
elif [[ ${CAPTURE_RATE} -eq 4 ]]; then
    FRAME_RATE=15
else
    # シミュレータ映像のキャプチャが有効化されていなかった場合、スクリプトを終了する
    exit 0
fi
# キャプチャ映像を MP4 に変換する
cd $CAPTURE_DIR_WSL
cd ../../
ffmpeg -r ${FRAME_RATE} \
       -i ${CAPTURE_DIR_WSL}/L_%08d.png \
       -vcodec libx264 \
       -pix_fmt yuv420p \
       -r ${FRAME_RATE} \
       ${COURSE}-${NAME}.mp4

# キャプチャ先のディレクトリを開く
if [[ "$3" == 'true' ]]; then
    (cd $CAPTURE_DIR_WSL; cd ../../ ; if [ -f .isOpened ]; then exit 0; fi; touch .isOpened; explorer.exe .)
fi
