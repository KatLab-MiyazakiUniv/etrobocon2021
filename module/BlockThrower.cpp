/**
 * @file BlockThrower.cpp
 * @brief 投げ入れ設置クラス
 * @author kodama0720, yutotanaka24
 */

#include "BlockThrower.h"

void BlockThrower::throwBlock(bool isLeft)
{
  double targetDistance = 105;
  int runPwm = 20;
  int angle = 45;
  int rotatePwm = 20;
  int upArmPwm = 100;
  int downArmPwm = -100;

  //黒線の奥まで直進する
  straightRunner.runStraightToDistance(targetDistance, runPwm);
  //回頭する
  if(isLeft) {
    rotation.rotateLeft(angle, rotatePwm);
  } else {
    rotation.rotateRight(angle, rotatePwm);
  }
  //アームを上げる
  while(measurer.getArmMotorCount() < 40) {
    controller.setArmMotorPwm(upArmPwm);
    controller.sleep();
  }
  //アームを戻す
  while(measurer.getArmMotorCount() > -40) {
    controller.setArmMotorPwm(downArmPwm);
    controller.sleep();
  }
  controller.stopArmMotor();
}
