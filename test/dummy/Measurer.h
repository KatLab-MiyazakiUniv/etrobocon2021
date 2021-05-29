/**
 * @file Measurer.h
 * @brief 計測に用いる関数をまとめたクラス
 * @author kodama0720, yutotanaka24
 */

#ifndef MEASURER_H
#define MEASURER_H

//カラーセンサクラス
class ColorSensor {
 public:
  int brightness = 0;
  int getBrightness();  //明るさを取得
};

//モータクラス
class Motor {
 public:
  double count = 0.0;
  int getCount();  //モータ角位置取得
};

//タッチセンサクラス
class TouchSensor {
 public:
  bool isPressed();  //タッチセンサの状態取得
};

//計測クラス
class Measurer {
 public:
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
  ColorSensor colorSensor;
  Motor leftWheel;
  Motor rightWheel;
  TouchSensor touchSensor;
};

#endif