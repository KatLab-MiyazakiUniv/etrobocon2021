/**
 * @file Motor.cpp
 * @brief モータクラスで用いる関数（ダミー）
 * @author kodama0720, yutotanaka24
 */

#include "Motor.h"
using namespace ev3api;

//コンストラクタ
Motor::Motor(ePortM _port, bool brake, motor_type_t type) : port(_port) {}

// PORT_B　右モータ
// PORT_C　左モータ
//モータ角位置取得
int Motor::getCount()
{
  if(port == PORT_C) {
    return static_cast<int>(leftCount);
  } else {
    return static_cast<int>(rightCount);
  }
}

// pwm値設定
void Motor::setPWM(int pwm)
{
  if(port == PORT_C) {
    leftCount += pwm * 0.05;
  } else {
    rightCount += pwm * 0.05;
  }
}
