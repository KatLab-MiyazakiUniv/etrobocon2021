/**
 * @file BingoMotion.cpp
 * @brief ビンゴ動作の親クラス
 * @author kodama0720, yutotanaka24
 */

#include "BingoMotion.h"

//動作時間の取得
int BingoMotion::getMotionTime(void){
  return MOTION_TIME;
}

//失敗リスクの取得
int BingoMotion::getFailureRisk(void){
  return FAILURE_RISK;
}
