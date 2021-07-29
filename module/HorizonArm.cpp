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
  Pid pid(1.0, 0.3, 0.001, HORIZONTAL_ARM_COUNT);

  while(true) {
    int currentCount = measurer.getArmMotorCount();
    if(currentCount == HORIZONTAL_ARM_COUNT) break;

    controller.setArmMotorPwm(pid.calculatePid(currentCount));
    controller.sleep();
  }
}