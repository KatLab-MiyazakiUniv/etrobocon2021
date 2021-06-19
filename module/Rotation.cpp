/**
 * @file Rotation.cpp
 * @brief 回頭・ピボットターンする
 * @author kodama0720, yutotanaka24
 */

#include "Rotation.h"

void Rotation::rotate(int angle, int pwm)
{
  double r = 45.0; //タイヤの半径
  I = 2 * pi * r; //タイヤの円周
  double radius = 70.0; //トレッド幅
  I = 2 * pi * radius * angle/360; //弧の長さ r:半径 angle:中心角

}
