/**
 * @file InCrossLeft.cpp
 * @brief 交点内移動（左折）のクラス
 * @author kodama0720, yutotanaka24
 */

#include "InCrossLeft.h"

InCrossLeft::InCrossLeft(LineTracer& _lineTracer) : lineTracer(_lineTracer) {}

void InCrossLeft::runLeft(void)
{
  int angle = 90;
  int pwm = 30;

  //ピボットターン後の位置を調整するため、直進する
  //straightRunner.runStraightToDistance(10, 20);
  //左に90度ピボットターンする
  rotation.turnForwardLeftPivot(angle, pwm);
  //エッジを左にする
  lineTracer.setIsLeftEdge(true);
}
