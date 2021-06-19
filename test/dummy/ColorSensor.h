/**
 * @file ColorSensor.h
 * @brief カラーセンサクラス（ダミー）
 * @author kodama0720, yutotanaka24
 */

#ifndef COLOR_SENSOR_H
#define COLOR_SENSOR_H

#include "Port.h"
// 色識別番号
enum colorid_t {
  COLOR_NONE = 0,
  COLOR_BLACK = 1,
  COLOR_BLUE = 2,
  COLOR_GREEN = 3,
  COLOR_YELLOW = 4,
  COLOR_RED = 5,
  COLOR_WHITE = 6,
  COLOR_BROWN = 7,
  TNUM_COLOR
};

namespace ev3api {

  //カラーセンサクラス
  class ColorSensor {
   public:
    int brightness = 0;
    colorid_t colorNumber = colorid_t::COLOR_WHITE;

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

    /**
     * 色の識別番号を取得
     * @return 色の識別番号(0-7), enumのサイズがTNUM_COLOR(8)
     */
    colorid_t getColorNumber();
  };
}  // namespace ev3api

#endif
