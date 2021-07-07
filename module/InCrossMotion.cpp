/**
 * @file InCrossMotion.cpp
 * @brief 交点内移動のクラス
 * @author kodama0720, yutotanaka24
 */

#include "InCrossMotion.h"

void InCrossMotion::runForward(void){
  int targetDistance = 80.0;
  int pwm = 80;

  //交点サークルの外径分直進する
  rotation.runStraightToDistance(targetDistance, pwm);
}

void InCrossMotion::runBack(void){
  double targetDistance = 80.0;
  int runPwm = 80;
  int angle = 180;
  int rotatePwm = 60;
  Rotation rotation;
  StraightRunner straightRunner;

  //直進する
  straightRunnner.runStraightToDistance(targetDistance, runPwm);
  //180度回頭する
  rotation.rotateLeft(angle, rotatePwm);
  //エッジを逆にする
  isLeftCourse = false;
}

void InCrossMotion::runRight(void){
  int angle = 90;
  int pwm = 60;

  //右に90度ピボットターンする
  rotation.turnForwardRightPivot(int angle, int pwm);
}

void InCrossMotion::runLeft(void){
  int angle = 90;
  int pwm = 60;

  //左に90度ピボットターンする
  rotation.turnForwardLeftPivot(int angle, int pwm);
}
