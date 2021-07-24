/**
 * @file HorizonArm.h
 * @brief アームを水平にする
 * @author hiroto0927, miyashita64
 */

#ifndef HORIZON_ARM_H
#define HORIZON_ARM_H

#include "Measurer.h"
#include "Controller.h"
#include "Pid.h"

class HorizonArm {
 public:
  /**
   * コンストラクタ
   */
  HorizonArm();

  /**
   * アームを目標の角位置に保つ
   */
  void keepArm();

 private:
  // アームの角位置の目標値
  static constexpr int targetArmCount = -45;
};

#endif