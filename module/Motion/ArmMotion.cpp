/**
 * @file ArmMotion.cpp
 * @brief アーム動作クラス
 * @author kodama0720, yutotanaka24, hiroto0927, miyashita64
 */

#include "ArmMotion.h"

bool ArmMotion::keepFlag = true;

// アームの角位置を目標値に保つ
void ArmMotion::keepArm()
{
  Measurer measurer;
  Controller controller;
  Pid pid(1.0, 0.3, 0.001, HORIZONTAL_ARM_COUNT);

  // アーム水平が有効な場合、アームを水平にする
  while(keepFlag) {
    int currentCount = measurer.getArmMotorCount();
    // 水平になったとき、ループを抜ける
    if(currentCount == HORIZONTAL_ARM_COUNT) {
      break;
    }
    // アームの角度が目標値(水平)になるように、アームを動かす
    controller.setArmMotorPwm(pid.calculatePid(currentCount));
    controller.sleep();
  }
  controller.sleep();
}

// アームを上げる
void ArmMotion::throwMotion(void)
{
  Measurer measurer;
  Controller controller;
  int upArmPwm = 100;
  int downArmPwm = -100;

  // アームを水平にする処理を無効化
  keepFlag = false;
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

  // アームを水平にする処理を有効化
  keepFlag = true;
}