/**
 * @file InCrossMotion.cpp
 * @brief 交点内移動のクラス
 * @author kodama0720, yutotanaka24
 */

#include "InCrossMotion.h"

InCrossMotion::InCrossMotion(bool _isLeftEdge) : lineTracer(_isLeftEdge) {}

void InCrossMotion::runForward(void)
{
  int targetDistance = 80.0;
  int pwm = 30;

  //交点サークルの外径分直進する
  straightRunner.runStraightToDistance(targetDistance, pwm);
}

void InCrossMotion::runBack(void)
{
  double targetDistance = 30.0;
  int runPwm = 30;
  int angle = 180;
  int rotatePwm = 30;

  //直進する
  straightRunner.runStraightToDistance(targetDistance, runPwm);
  // 180度回頭する
  rotation.rotateLeft(angle, rotatePwm);
  //エッジを逆にする
  if(lineTracer.getIsLeftEdge()) {
    lineTracer.setIsLeftEdge(false);
  } else {
    lineTracer.setIsLeftEdge(true);
  }
}

void InCrossMotion::runRight(void)
{
  int angle = 90;
  int pwm = 30;

  //右に90度ピボットターンする
  rotation.turnForwardRightPivot(angle, pwm);
}

void InCrossMotion::runLeft(void)
{
  int angle = 90;
  int pwm = 30;

  //左に90度ピボットターンする
  rotation.turnForwardLeftPivot(angle, pwm);
}
