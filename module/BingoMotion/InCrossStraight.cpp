/**
 * @file InCrossMotion.cpp
 * @brief 交点内移動（直進）のクラス
 * @author kodama0720, yutotanaka24
 */

#include "InCrossStraight.h"

InCrossStraight::InCrossStraight() : BingoMotion(1.0, 1.12) {}

void InCrossStraight::runForward(void)
{
  int targetDistance = 140.0;  //交点サークルの外径
  int pwm = 30;

  //交点サークルの外径分直進する
  straightRunner.runStraightToDistance(targetDistance, pwm);
}
