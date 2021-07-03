/**
 * @file StraightRunner.h
 * @brief 直進クラス
 * @author hiroto0927, miyashita64
 */

#ifndef STRAIGHTER_H
#define STRAIGHTER_H

#include "Measurer.h"
#include "Mileage.h"
#include "Controller.h"
#include "ColorJudge.h"

class StraightRunner {
 public:
  /**
   * コンストラクタ
   */
  StraightRunner();

  /**
   * 指定された距離を直進する関数
   * @param targetDistance 目標距離
   * @param pwm PWM値
   */
  void runStraightToDistance(double targetDistance, int pwm);

  /**
   * 白黒以外の色を検出するまで直進する関数
   * @param pwm PWM値
   */
  void runStraightToColor(int pwm);

 private:
  Measurer measurer;
  Controller controller;
};
#endif