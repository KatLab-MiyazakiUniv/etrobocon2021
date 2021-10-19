/**
 * @file InCrossLeft.cpp
 * @brief 交点内移動（左折）のクラス
 * @author kodama0720, yutotanaka24
 */

#include "InCrossLeft.h"

InCrossLeft::InCrossLeft(LineTracer& _lineTracer) : BingoMotion(1.22, 1.19), lineTracer(_lineTracer)
{
}

void InCrossLeft::runLeft(void)
{
  int targetDistance = 10;
  int runPwm = 30;
  int angle = 92;
  int turnPwm = 95;

  //ピボットターン後の位置を調整するため、直進する
  straightRunner.runStraightToDistance(targetDistance, runPwm);
  //左に90度ピボットターンする
  rotation.turnForwardLeftPivot(angle, turnPwm);
  //エッジを左にする
  lineTracer.setIsLeftEdge(true);
}
