/**
 * @file ArmMotion.cpp
 * @brief アーム動作クラス
 * @author kodama0720, yutotanaka24
 */

#include "ArmMotion.h"

void ArmMotion::throwMotion(void){
  Measurer measurer;
  Controller controller;
  int upArmPwm = 100;
  int downArmPwm = -100;

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
