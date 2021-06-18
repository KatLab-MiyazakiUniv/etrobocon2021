/**
 * @file Measurer.cpp
 * @brief 計測に用いる関数
 * @author kodama0720, yutotanaka24
 */

#include "Measurer.h"

Measurer::Measurer()
  : colorSensor(PORT_3), leftWheel(PORT_C), rightWheel(PORT_B), touchSensor(PORT_1)
{
}

//明るさを取得
int Measurer::getBrightness()
{
  return static_cast<int>(colorSensor.getBrightness());
}

// RGB値取得
rgb_raw_t Measurer::getRgbRaw()
{
  rgb_raw_t rgb;
  rgb_raw_t& rgbRef = rgb;

  colorSensor.getRawColor(rgbRef);
  return rgb;
}

//識別された色のIDを返す
int Measurer::getColorId()
{
  return colorSensor.getColorNumber();
}

//左モータ角位置取得
int Measurer::getLeftCount()
{
  return leftWheel.getCount();
}

//右モータ角位置取得
int Measurer::getRightCount()
{
  return rightWheel.getCount();
}

//タッチセンサの状態取得
bool Measurer::isPressed()
{
  return touchSensor.isPressed();
}