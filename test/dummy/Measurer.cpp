/**
 * @file Measure.cpp
 * @brief 計測に用いる関数
 * @author kodama0720, yutotanaka24
 */

#include "Measurer.h"

//カラーセンサクラス
//明るさを取得
int ColorSensor::getBrightness()
{
  return brightness;
}

//モータクラス
//モータ角位置取得
int Motor::getCount()
{
  return static_cast<int>(count);
}

//タッチセンサクラス
//タッチセンサの状態取得
bool TouchSensor::isPressed()
{
  return false;
}

//測定クラス
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