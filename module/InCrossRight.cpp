/**
 * @file InCrossRight.cpp
 * @brief 交点内移動（右折）のクラス
 * @author kodama0720, yutotanaka24
 */

#include "InCrossRight.h"

InCrossRight::InCrossRight(LineTracer& _lineTracer) : lineTracer(_lineTracer) {}

void InCrossRight::runRight(void)
{
  int targetDistance = 15;
  int runPwm = 20;
  int angle = 90;
  int rotatePwm = 30;

  //ピボットターン後の位置を調整するため、直進する
  straightRunner.runStraightToDistance(targetDistance, runPwm);
  //右に90度ピボットターンする
  rotation.turnForwardRightPivot(angle, rotatePwm);
  //エッジを右にする
  lineTracer.setIsLeftEdge(false);
}
