/**
 * @file Measurer.h
 * @brief 計測に用いる関数をまとめたクラス
 * @author kodama0720, yutotanaka24
 */

#ifndef MEASURER_H
#define MEASURER_H

#include "ev3api.h"
#include "ColorSensor.h"
#include "Motor.h"
#include "TouchSensor.h"

// 色識別番号
enum class COLOR_NUMBER : int {
  COLOR_NONE = 0,
  COLOR_BLACK = 1,
  COLOR_BLUE = 2,
  COLOR_GREEN = 3,
  COLOR_YELLOW = 4,
  COLOR_RED = 5,
  COLOR_WHITE = 6,
  COLOR_BROWN = 7,
  TNUM_COLOR  // サイズ
};

class Measurer {
 public:
  /**
   * コンストラクタ
   */
  Measurer();

  /**
   * 明るさを取得
   * @return 反射光の強さ(0-100)
   */
  int getBrightness();

  /**
   * 色の識別番号を取得
   * @return 色の識別番号(0-7),enumのサイズがTNUM_COLOR(8)
   */
  COLOR_NUMBER getColorId();

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
