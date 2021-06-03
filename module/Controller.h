/**
 * @file Controller.cpp
 * @brief モーター制御
 * @author yutotanaka24,kodama0720
 */
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "ev3api.h"
#include "Motor.h"

using namespace ev3api;
/**
 *モーターを制御するクラス
 */
class Controller {
 public:
  Controller();
  static const int MOTOR_PWM_MAX = 100;
  static const int MOTOR_PWM_MIN = -100;
  //モーターPWM値設定
  void setRightMotorPwm(const int pwm);
  void setLeftMotorPwm(const int pwm);
  //停止する
  void stopMotor();

 private:
  Motor rightWheel;
  Motor leftWheel;
  //モーター入力電圧を制限内に抑える
  int limitPwmValue(const int value);
};
#endif
