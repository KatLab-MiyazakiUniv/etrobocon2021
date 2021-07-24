/**
 * @file InCrossRight.cpp
 * @brief 交点内移動（右）のクラス
 * @author kodama0720, yutotanaka24
 */

#include "InCrossRight.h"

InCrossRight::InCrossRight(LineTracer& _lineTracer) : lineTracer(_lineTracer) {}

void InCrossRight::runRight(void)
{
  int angle = 90;
  int pwm = 30;

  //ピボットターン後の位置を調整するため、直進する
  straightRunner.runStraightToDistance(15, 20);
  //右に90度ピボットターンする
  rotation.turnForwardRightPivot(angle, pwm);
  //エッジを右にする
  lineTracer.setIsLeftEdge(false);
}
