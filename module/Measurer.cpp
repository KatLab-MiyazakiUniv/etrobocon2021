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

//識別された色の識別番号を返す
colorid_t Measurer::getColorId()
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