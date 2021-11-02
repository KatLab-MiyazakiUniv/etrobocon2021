/**
 * @file InCrossRight.cpp
 * @brief 交点内移動（右折）のクラス
 * @author kodama0720, yutotanaka24
 */

#include "InCrossRight.h"

InCrossRight::InCrossRight(LineTracer& _lineTracer)
  : BingoMotion(1.23, 1.09), lineTracer(_lineTracer)
{
}

void InCrossRight::runRight(void)
{
  int targetDistance = 25;
  int runPwm = 30;
  int angle = 74;
  int turnPwm = 90;

  //ピボットターン後の位置を調整するため、直進する
  straightRunner.runStraightToDistance(targetDistance, runPwm);
  //右に90度ピボットターンする
  rotation.turnForwardRightPivot(angle, turnPwm);
  //エッジを左にする
  lineTracer.setIsLeftEdge(true);
}
