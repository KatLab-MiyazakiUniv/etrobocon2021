/**
 * @file Rotation.h
 * @brief 回頭・ピボットターンするクラス
 * @author kodama0720, yutotanaka24
 */

#ifndef ROTATION_H
#define ROTATION_H

#include <cmath>
#include "Controller.h"
#include "Measurer.h"
#include "Mileage.h"

/**
 * 回頭とピボットターンをするクラス
 */
class Rotation {
 public:
  /**
   * 左に回頭する関数
   * @param angle 回転角度(deg) 0~360
   * @param pwm PWM値 0~100
   */
  void rotateLeft(int angle, int pwm);

  /**
   * 右に回頭する関数
   * @param angle 回転角度(deg) 0~360
   * @param pwm PWM値 0~100
   */
  void rotateRight(int angle, int pwm);

  /**
   * 右タイヤを軸にピボットターンする関数
   * @param angle　回転角度(deg)
   * @param pwm PWM値
   */
  void turnRightPivot(int angle, int pwm);

  /**
   * 左タイヤを軸にピボットターンする関数
   * @param angle　回転角度(deg)
   * @param pwm PWM値
   */
  void turnLeftPivot(int angle, int pwm);

 private:
  Controller controller;
  Measurer measurer;

  static constexpr double RADIUS = 45.0;
  static constexpr double TREAD = 140.0;
};

#endif
