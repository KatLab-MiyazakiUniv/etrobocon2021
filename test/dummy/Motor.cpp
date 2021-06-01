/**
 * @file Measure.cpp
 * @brief モータクラスで用いる関数（ダミー）
 * @author kodama0720, yutotanaka24
 */

#include "Motor.h"
using namespace ev3api;

//コンストラクタ
Motor::Motor(ePortM port, bool brake, motor_type_t type)
{
}

//モータ角位置取得
int Motor::getCount()
{
  return static_cast<int>(count);
}
