/**
 * @file BingoMotion.cpp
 * @brief ビンゴ動作の親クラス
 * @author kodama0720, yutotanaka24
 */

#include "BingoMotion.h"

BingoMotion::BingoMotion(double time, double risk) : MOTION_TIME(time), FAILURE_RISK(risk){};

//動作時間の取得
double BingoMotion::getMotionTime(void)
{
  return MOTION_TIME;
}

//失敗リスクの取得
double BingoMotion::getFailureRisk(void)
{
  return FAILURE_RISK;
}
