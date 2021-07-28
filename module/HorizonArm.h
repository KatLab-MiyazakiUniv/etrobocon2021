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
  // アームが水平なときの角位置
  static constexpr int HORIZONTAL_ARM_COUNT = -45;
};

#endif