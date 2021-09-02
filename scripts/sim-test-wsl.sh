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

# ログファイルを出力するディレクトリへのパスをコマンドライン引数から取得する
LOG_FILES_DIR_NAME="`pwd`/$2"
if [[ "$2" =~ ^/.+$ ]]; then
    LOG_FILES_DIR_NAME="$2"
elif [[ "$2" =~ ^\./.+$ ]]; then
    LOG_FILES_DIR_NAME="`pwd``echo $2 | cut -b 2-`"
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

# キャプチャファイルを生成する一時ディレクトリを生成する
CAPTURE_DIR_WSL=$(mktemp -d)

# 生成したキャプチャディレクトリをシミュレータからアクセスできる Windows 側のパスに変換する
UBUNTU_VER=$(lsb_release -a | grep -oE '^Release:\s*[0-9]{2}\.[0-9]{2}' | cut -f 2)
CAPTURE_DIR_WIN="\\\\wsl\$\\Ubuntu-${UBUNTU_VER}$(echo ${CAPTURE_DIR_WSL} | sed -r 's/\//\\/g')"

# 設定ファイルの書き込み
mkdir -p ${ETROBO_HRP3_WORKSPACE}/simdist/${APP_NAME};
EDITED_SETTINGS_FILE_NAME="${ETROBO_HRP3_WORKSPACE}/simdist/${APP_NAME}/settings.json"
CAPTURE_DIR_WIN_JSON_ESCAPED=$(echo "$CAPTURE_DIR_WIN" | sed -e 's/\\/\\\\/g')

# sim-settings/default.json の内容を simsettings/(l|r)/*.json ファイルの内容で上書して保存
jq -sc add ${DEFAULT_SETTINGS_FILE_NAME} ${OVERWRITE_SETTINGS_FILE_NAME} | \
    jq ".captureDir=\"${CAPTURE_DIR_WIN_JSON_ESCAPED}\"" > "${EDITED_SETTINGS_FILE_NAME}"

# キャプチャする際のフレームレートを取得
CAPTURE_RATE=$(jq -r '.captureRate' ${EDITED_SETTINGS_FILE_NAME})

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


# CSV ファイルをコピーする
L_OR_R=`echo ${COURSE} | tr lr LR`
cp ${CAPTURE_DIR_WSL}/${L_OR_R}.csv ${LOG_FILES_DIR_NAME}/.logs/${COURSE}-${NAME}.csv

# スタート前に撮影されたキャプチャ画像を削除する
# スタート前に撮影されたキャプチャ画像が無い場合、一番最後のフレームが消えることになるが影響は無いと判断
CSV_TAIL_NUM=$(cat ${CAPTURE_DIR_WSL}/${L_OR_R}.csv | tail -n1 | sed -r 's/.*(L|R)_([0-9]{8})\.png.*/\2/g')
PNG_TAIL_NUM=$(ls ${CAPTURE_DIR_WSL}/*.png | tail -n1 | sed -r 's/.*(L|R)_([0-9]{8})\.png/\2/g')
echo "echo ${CAPTURE_DIR_WSL}/${L_OR_R}_{${CSV_TAIL_NUM}..${PNG_TAIL_NUM}}.png" | bash | xargs -L1 rm

# キャプチャ映像を MP4 に変換する
ffmpeg -framerate ${FRAME_RATE} \
       -i ${CAPTURE_DIR_WSL}/${L_OR_R}_%08d.png \
       -vcodec libx264 \
       -pix_fmt yuv420p \
       -r ${FRAME_RATE} \
       ${LOG_FILES_DIR_NAME}/${COURSE}-${NAME}.mp4


# 一時ディレクトリを削除する
rm -rf ${CAPTURE_DIR_WSL}
