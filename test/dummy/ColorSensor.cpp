/**
 * @file Measure.cpp
 * @brief カラーセンサクラスで用いる関数（ダミー）
 * @author kodama0720, yutotanaka24
 */

#include "ColorSensor.h"
using namespace ev3api;

//コンストラクタ
  ColorSensor::ColorSensor(ePortS port)
{
}

//明るさを取得
int ColorSensor::getBrightness()
{
  return brightness;
}
