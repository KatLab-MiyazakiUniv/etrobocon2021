/**
 * @file Measurer.h
 * @brief 計測に用いる関数をまとめたクラス
 * @author kodama0720, yutotanaka24
 */

#ifndef MEASURER_H
#define MEASURER_H

//消す！！！！
#include <typeinfo>
//
#include "ev3api.h"
#include "ColorSensor.h"
#include "Motor.h"
#include "TouchSensor.h"

class Measurer {
 public:
  /**
   * コンストラクタ
   */
  Measurer();

  // テスト
  rgb_raw_t getRgbRaw();
  int getColorId();

  /**
   * 明るさを取得
   * @return 反射光の強さ(0-100)
   */
  int getBrightness();

  /**
   * 左モータ角位置取得
   * @return 左モータ角位置[deg]
   */
  int getLeftCount();

  /**
   * 右モータ角位置取得
   * @return 右モータ角位置[deg]
   */
  int getRightCount();

  /**
   * タッチセンサ状態取得
   * @return true:押されている状態, false:押されていない状態
   */
  bool isPressed();

 private:
  ev3api::ColorSensor colorSensor;
  ev3api::Motor leftWheel;
  ev3api::Motor rightWheel;
  ev3api::TouchSensor touchSensor;
};

#endif
