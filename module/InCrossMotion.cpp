/**
 * @file InCrossMotion.cpp
 * @brief 交点内移動のクラス
 * @author kodama0720, yutotanaka24
 */

#include "InCrossMotion.h"

InCrossMotion::InCrossMotion(LineTracer& _lineTracer) : lineTracer(_lineTracer) {}

void InCrossMotion::runForward(void)
{
  int targetDistance = 140.0;  //交点サークルの外径
  int pwm = 30;

  //交点サークルの外径分直進する
  straightRunner.runStraightToDistance(targetDistance, pwm);
}

void InCrossMotion::runBack(void)
{
  double targetDistance = 35.0;
  int runPwm = 5;
  int angle = 85;
  int rotatePwm = 10;

  //直進する
  straightRunner.runStraightToDistance(targetDistance, runPwm);

  if(lineTracer.getIsLeftEdge()) {
    // 90度回頭する
    rotation.rotateRight(angle, rotatePwm);
    // 黒線の幅分直進する
    straightRunner.runStraightToDistance(25.0, 5);
    // 90度回頭する
    rotation.rotateRight(angle, rotatePwm);
  } else {
    // 90度回頭する
    rotation.rotateLeft(angle, rotatePwm);
    // 黒線の幅分直進する
    straightRunner.runStraightToDistance(25.0, 5);
    // 90度回頭する
    rotation.rotateLeft(angle, rotatePwm);
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

  //エッジを切り替えないようにするため、直進する
  straightRunner.runStraightToDistance(20, 20);
  //左に90度ピボットターンする
  rotation.turnForwardLeftPivot(angle, pwm);
}
