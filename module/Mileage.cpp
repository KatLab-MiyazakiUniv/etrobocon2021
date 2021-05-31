/**
 **  @file Mileage.cpp
 **  @brief 走行距離を計算するクラス
 **  @author Hisataka-Hagiyama,uchyam
 **/

#include "Mileage.h"

// タイヤの半径を45[mm] で初期化する
Mileage::Mileage() : radius(45) {}
Mileage::Mileage(const Mileage& other) : radius(45) {}
Mileage &Mileage::operator=(const Mileage& other) {
  return *this;
}

Mileage& Mileage::getInstance()
{
  static Mileage mileage;
  return mileage;
}

double Mileage::calculateWheelMileage(int angle)
{
  //タイヤの累計走行距離＝2 * π * タイヤの半径　* (タイヤの回転角度 / 360[deg])
  return 2.0 * M_PI * radius * static_cast<double>(angle) / 360.0;
}

double Mileage::calculateMileage(int rightAngle, int leftAngle)
{
  //右タイヤの累計走行距離を計算
  double rightWheel = calculateWheelMileage(rightAngle);
  //左タイヤの累計走行距離を計算
  double leftWheel = calculateWheelMileage(leftAngle);
  //走行体全体の累計走行距離 = (右タイヤの累計走行距離 + 左タイヤの累計走行距離) / 2
  return (rightWheel + leftWheel) / 2.0;
}
