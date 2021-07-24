/**
 * @file HorizonArm.cpp
 * @brief アームを水平にする
 * @author hiroto0927, miyashita64
 */

#include "HorizonArm.h"

// コンストラクタ
HorizonArm::HorizonArm() {}

// アームの角位置を目標値に保つ
void HorizonArm::keepArm()
{
  // アームの角度が目標値(水平)になるまで、アームを動かす
  Measurer measurer;
  Controller controller;
  Pid pid(3.0, 0.3, 0.001, targetArmCount);

  int currentCount = measurer.getArmCount();
  while(true) {
    currentCount = measurer.getArmCount();
    if(currentCount == targetArmCount) break;

    controller.setArmMotorPwm(pid.calculatePid(currentCount));
    controller.sleep();
  }
}