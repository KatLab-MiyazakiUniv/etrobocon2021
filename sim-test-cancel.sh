#!/bin/bash -eu

# @file: sim-test-cancel.sh
# @author: Takahiro55555
# @brief: シミュレータの自動実行ツールを途中で停止させたい際に使用する。

touch .cancel-sim-test
echo "sim stop" | ${HOME}/startetrobo shell
