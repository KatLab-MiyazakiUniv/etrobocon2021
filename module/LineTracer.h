/**
 * @file LineTracer.h
 * @brief ライントレースする
 * @author yutotanaka24,kodama0720
 */

#ifndef LINE_TRACER_H
#define LINE_TRACER_H

#include "Pid.h"
#include "Measurer.h"
#include "Mileage.h"
#include "Controller.h"
/**
 * ライントレースをするクラス
 */
class LineTracer {
 public:
  /**
   * コンストラクタ
   * @param _leftCourse コースのLR判定
   */
  LineTracer(bool _leftCourse);

  /**
   * 指定された距離の間ライントレースをする関数
   * @param targetDistance 目標距離
   * @param targetBrightness 目標輝度
   * @param pwm PWM値
   * @param gain PIDを保持する構造体
   */
  void run(double targetDistance, int targetBrightness, int pwm, const PidGain& gain);

 private:
  int edge;
  Measurer measurer;
  Controller controller;
};

#endif