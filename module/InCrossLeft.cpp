/**
 * @file InCrossLeft.cpp
 * @brief 交点内移動（左折）のクラス
 * @author kodama0720, yutotanaka24
 */

#include "InCrossLeft.h"

InCrossLeft::InCrossLeft(LineTracer& _lineTracer) : lineTracer(_lineTracer) {}

void InCrossLeft::runLeft(void)
{
  int targetDistance = 15;
  int runPwm = 20;
  int angle = 90;
  int turnPwm = 30;

  //ピボットターン後の位置を調整するため、直進する
  straightRunner.runStraightToDistance(targetDistance, runPwm);
  //左に90度ピボットターンする
  rotation.turnForwardLeftPivot(angle, turnPwm);
  //エッジを左にする
  lineTracer.setIsLeftEdge(true);
}
