/**
 * @file InCrossLeft.cpp
 * @brief 交点内移動（左折）のクラス
 * @author kodama0720, yutotanaka24
 */

#include "InCrossLeft.h"

InCrossLeft::InCrossLeft(LineTracer& _lineTracer) : BingoMotion(1.23, 1.09), lineTracer(_lineTracer)
{
}

void InCrossLeft::runLeft(void)
{
  int targetDistance = 25;
  int runPwm = 30;
  int angle = 74;
  int turnPwm = 90;

  //ピボットターン後の位置を調整するため、直進する
  straightRunner.runStraightToDistance(targetDistance, runPwm);
  //左に90度ピボットターンする
  rotation.turnForwardLeftPivot(angle, turnPwm);
  //エッジを右にする
  lineTracer.setIsLeftEdge(false);
}
