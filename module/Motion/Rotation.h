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
   * 右タイヤを軸に前方へピボットターンする関数
   * @param angle　回転角度(deg) 0~360
   * @param pwm PWM値 0~100
   */
  void turnForwardRightPivot(int angle, int pwm);

  /**
   * 右タイヤを軸に後方へピボットターンする関数
   * @param angle　回転角度(deg) 0~360
   * @param pwm PWM値 0~100
   */
  void turnBackRightPivot(int angle, int pwm);

  /**
   * 左タイヤを軸に前方へピボットターンする関数
   * @param angle　回転角度(deg) 0~360
   * @param pwm PWM値 0~100
   */
  void turnForwardLeftPivot(int angle, int pwm);

  /**
   * 左タイヤを軸に後方へピボットターンする関数
   * @param angle　回転角度(deg) 0~360
   * @param pwm PWM値 0~100
   */
  void turnBackLeftPivot(int angle, int pwm);

 private:
  Controller controller;
  Measurer measurer;

  static constexpr double RADIUS = 45.0;  // 車輪の半径[mm]
  static constexpr double TREAD = 140.0;  // 走行体のトレッド幅（両輪の間の距離）[mm]
  static constexpr int MIN_PWM = 10;      // モーターパワーの最小値
};

#endif
