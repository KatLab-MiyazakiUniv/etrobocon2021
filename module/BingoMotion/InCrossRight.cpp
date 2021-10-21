/**
 * @file InCrossRight.cpp
 * @brief 交点内移動（右折）のクラス
 * @author kodama0720, yutotanaka24
 */

#include "InCrossRight.h"

InCrossRight::InCrossRight(LineTracer& _lineTracer) : BingoMotion(10, 10), lineTracer(_lineTracer)
{
}

void InCrossRight::runRight(void)
{
  int targetDistance = 10;
  int runPwm = 30;
  // 現在のエッジとピボットターン方向が不一致の場合、多めに回転する
  int angle = !lineTracer.getIsLeftEdge() ? 91 : 94;
  int turnPwm = !lineTracer.getIsLeftEdge() ? 90 : 70;

  //ピボットターン後の位置を調整するため、直進する
  straightRunner.runStraightToDistance(targetDistance, runPwm);
  //右に90度ピボットターンする
  rotation.turnForwardRightPivot(angle, turnPwm);
  //エッジを右にする
  lineTracer.setIsLeftEdge(false);
}
