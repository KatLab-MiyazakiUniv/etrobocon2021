/**
 * @file Measure.cpp
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
  return colorSensor.getBrightness();
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