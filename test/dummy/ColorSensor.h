/**
 * @file Measure.cpp
 * @brief カラーセンサクラス（ダミー）
 * @author kodama0720, yutotanaka24
 */

#ifndef COLOR_SENSOR_H
#define COLOR_SENSOR_H

#include "Port.h"

namespace ev3api {

  //カラーセンサクラス
  class ColorSensor {
   public:
    int brightness = 0;

    /**
     * コンストラクタ
     * @param port カラーセンサポート番号
     * @return -
     */
    explicit ColorSensor(ePortS port);

    /**
     * 明るさを取得
     * @return 反射光の強さ(0-100)
     */
    int getBrightness();  //明るさを取得
  };
}  // namespace ev3api

#endif
