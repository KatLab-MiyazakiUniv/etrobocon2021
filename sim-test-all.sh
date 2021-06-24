#!/bin/bash -eu

# @file: sim-test-wsl.sh
# @author: Takahiro55555
# @brief: 設定ファイルを適用した後、シミュレータを動作させる
#         WSL で動作させることしか考えていない
#         sim-settings/l 又は、sim-settings/r ディレクトリ中の設定ファイルの数だけテストを行う

### 以下、設定 ###
LOG_FILES_DIR="`pwd`/logs/`date '+%Y-%m-%d'`/`date '+%H-%M-%S'`"  # ログを格納するディレクトリ名
MD_FILE_NAME='result.txt'  # マークダウン形式で出力するファイル
CSV_FILE_NAME='result.csv'  # CSV 形式で出力するファイル
### 以上、設定 ###

# このシェルスクリプトを Ctrl-C で強制終了した際、
# バックグランドで実行しているプロセスも強制終了する
trap 'kill $(jobs -p)' EXIT

### 以下、必要なパッケージの確認・インストール ###
INSTALL_PACKAGE_LIST=""
if [ `dpkg -l | grep '^ii' | grep ffmpeg | wc -l` -eq "0" ]; then
    INSTALL_PACKAGE_LIST="ffmpeg "
fi

if [ `dpkg -l | grep '^ii' | grep -oE "\sjq\s" | wc -l` -eq "0" ]; then
    INSTALL_PACKAGE_LIST+="jq "
fi

if [ "${INSTALL_PACKAGE_LIST}" != "" ]; then
    echo "Install additional packages (${INSTALL_PACKAGE_LIST})"
    sudo apt update && sudo apt install $INSTALL_PACKAGE_LIST
fi
### 以上、必要なパッケージの確認・インストール ###



### 以下、シミュレータを実行し、結果を集計する ###
mkdir -p ${LOG_FILES_DIR};
CAPTURE_DIR=`date '+%Y-%m-%d'`\\`date '+%H-%M-%S'`

# シミュレータを起動
echo 'sim' | ${HOME}/startetrobo shell

# 設定ファイルをシミュレータに反映した後、プログラムを実行する
# awk コマンドの -v オプションで awk 中のスクリプトにシェル変数を渡している
ls sim-settings/?/* | \
    xargs -L1 -I{} ./scripts/sim-test-wsl.sh {} $CAPTURE_DIR true | \
    awk -v md_file_path=${LOG_FILES_DIR}/${MD_FILE_NAME} \
        -v csv_file_name=${LOG_FILES_DIR}/${CSV_FILE_NAME} '
    BEGIN {
        # ループの最初に1度だけ呼び出されるブロック
        # ここでは、変数の初期化を行っている
        counter = 0;
        run_time_sum = 0;
        goaled_num = 0;
        settings_file_name = "Unknown";
        capture_rate = "Unknown";
    }
    {
        # 標準出力から1行出力されるたびに呼び出されるブロック（ループ）
        # $0 に標準出力の1行が設定されている
        # $1, $2, $3, ... $n には標準出力の1行をスペースで区切ったものが順に設定されている

        # 設定ファイル名を取得
        if($0 ~ /\[ script: settings file name: .+\]/){
            settings_file_name = $6;
            print "\n" $0;
        }

        # シミュレータをキャプチャする際のフレームレートを取得
        if($0 ~ /\[ script: captureRate: [0-9] \]/){
            if ($4 == 0) {
                capture_rate = "OFF";
            } else if ($4 == 1) {
                capture_rate = "60fps";
            } else if ($4 == 2) {
                capture_rate = "30fps";
            } else if ($4 == 3) {
                capture_rate = "20fps";
            } else if ($4 == 4) {
                capture_rate = "15fps";
            }
            print $0;
        }

        # 連想配列の初期化
        if($0 ~ /\[ launcher: ready to start on ((right)|(left)) course \]/){
            counter++;
            STATISTICS[counter]["course"]="";
            STATISTICS[counter]["settings_file_name"]=settings_file_name;
            STATISTICS[counter]["start_gate"]="false";
            STATISTICS[counter]["gate_1"]="false";
            STATISTICS[counter]["gate_2"]="false";
            STATISTICS[counter]["goal_time"]="none";
            STATISTICS[counter]["capture_rate"]=capture_rate;
            settings_file_name = "Unknown";
            capture_rate = "Unknown";
            print $0;
        }

        # コース情報を取得
        if($0 ~ /\[ launcher: ready to start on right course \]/){
            STATISTICS[counter]["course"]="Right";
        }else if($0 ~ /\[ launcher: ready to start on left course \]/){
            STATISTICS[counter]["course"]="Left";
        }

        # スタートゲート通貨情報を取得
        if($0 ~ /^\[ launcher: ((left)|(right)): passed Start Gate \]$/){
            STATISTICS[counter]["start_gate"]="true";
            print $0;
        }

        # ゲート1通過情報を取得
        if($0 ~ /^\[ launcher: ((left)|(right)): passed Gate 1 \]$/){
            STATISTICS[counter]["gate_1"]="true";
            print $0;
        }

        # ゲート2通過情報を取得
        if($0 ~ /^\[ launcher: ((left)|(right)): passed Gate 2 \]$/){
            STATISTICS[counter]["gate_2"]="true";
            print $0;
        }

        # ゴール通過情報を取得
        if($0 ~ /^\[ launcher: ((left)|(right)): GOAL!  Goal Time: [0-9]*\.[0-9]* \]$/){
            STATISTICS[counter]["goal_time"]=$7;
            run_time_sum += $7;
            goaled_num++;
            print $0;
        }
    }
    END {
        # ループの最後に1度だけ呼び出されるブロック
        
        if(counter == 0){
            print "ERR: シミュレータログの検出に失敗";
            exit 1;
        }


        ### 以下、CSVファイル生成 ###
        # ヘッダ行の作成
        for (i in STATISTICS[1]) {
            printf "%s,", i >> csv_file_name
        }
        printf "\n" >> csv_file_name

        # データ行の作成
        for (i in STATISTICS) {
            for (j in STATISTICS[i]) {
                printf "%s,", STATISTICS[i][j] >> csv_file_name
            }
            printf "\n" >> csv_file_name
        }
        ### 以上、CSVファイル生成 ###


        ### 以下、Markdown形式ファイル生成(.txt ファイル) ###
        ## 各実験結果テーブルの作成
        # ヘッダー行の作成
        print "### 各実験結果" > md_file_path;
        print "| 番号 | コース | Start Gate | Gate 1 | Gate 2 | 走行時間 | キャプチャ | 設定ファイル名 |" >> md_file_path;
        print "| ---- | ----- | ---------- | ------ | ------ | ------- | ---------- | ------------- |" >> md_file_path;

        # データ行の作成
        for (i in STATISTICS) {
            printf "| %s ", i >> md_file_path;
            printf "| %s ", STATISTICS[i]["course"] >> md_file_path;
            printf "| %s ", STATISTICS[i]["start_gate"] >> md_file_path;
            printf "| %s ", STATISTICS[i]["gate_1"] >> md_file_path;
            printf "| %s ", STATISTICS[i]["gate_2"] >> md_file_path;
            printf "| %s ", STATISTICS[i]["goal_time"] >> md_file_path;
            printf "| %s ", STATISTICS[i]["capture_rate"] >> md_file_path;
            printf "| %s |\n", STATISTICS[i]["settings_file_name"] >> md_file_path;
        }
        print "\n__Bool値は、各ゲートを通過したか否かを示している__\n" >> md_file_path;

        ## 集計テーブルの作成
        run_time_average = run_time_sum/goaled_num;
        goal_persentage = goaled_num/counter*100;
        print "### 集計結果" > md_file_path;
        print "\n| 走行エリア平均 | 成功率 |" >> md_file_path;
        print "| ------------- | ----- |" >> md_file_path;
        printf "| %3.3f [s] (n=%d)    ", run_time_average, goaled_num >> md_file_path;
        printf "| %3.3f [%] (n=%d) |\n", goal_persentage , counter    >> md_file_path;
        ### 以上、Markdown形式ファイル生成(.txt ファイル) ###


        ### 以下、標準出力 ###
        print "走行エリア平均 : " run_time_average " [s] (n=" goaled_num ")";
        print "成功率        : " goal_persentage " [%] (n=" counter ")";
        ### 以上、標準出力 ###
    }' && (cd ${LOG_FILES_DIR}; explorer.exe ${MD_FILE_NAME})
    # 上記の && 以降で生成した Markdown 形式のファイルを開く処理を行っている
### 以上、シミュレータを実行し、結果を集計する ###
