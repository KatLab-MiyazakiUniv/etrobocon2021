/**
 * @file ThrowInBlock.cpp
 * @brief 投げ入れ設置クラス
 * @author kodama0720, yutotanaka24
 */

#include "ThrowInBlock.h"

void ThrowInBlock::throwBlock(bool isLeft)
{
  double targetDistance = 60;
  int runPwm = 10;
  int angle = 55;
  int rotatePwm = 15;
  int upArmPwm = 100;
  int downArmPwm = -30;

  //黒線の奥まで直進する
  straightRunner.runStraightToDistance(targetDistance, runPwm);
  //ピボットターンする
  if(isLeft) {
    rotation.turnForwardLeftPivot(angle, rotatePwm);
  } else {
    rotation.turnForwardRightPivot(angle, rotatePwm);
  }
  //アームを上げる
  while(measurer.getArmMotorCount() < 40) {
    controller.setArmMotorPwm(upArmPwm);
    controller.sleep();
  }
  //アームを戻す
  while(measurer.getArmMotorCount() > 0) {
    controller.setArmMotorPwm(downArmPwm);
    controller.sleep();
  }
  controller.stopArmMotor();
}
