/**
 * @file ColorSensor.cpp
 * @brief カラーセンサクラスで用いる関数（ダミー）
 * @author kodama0720, yutotanaka24
 */

#include "ColorSensor.h"
using namespace ev3api;

//コンストラクタ
ColorSensor::ColorSensor(ePortS port) {}

//明るさを取得
int ColorSensor::getBrightness()
{
  return brightness;
}

// RGB値を取得
void ColorSensor::getRawColor(rgb_raw_t& rgb)
{
  int index = rand() % 2;
  if(index == 0){
    rgb = { 8, 9, 10 };//black
  } else {
    rgb = { 111, 19, 19 };//red
  }
}