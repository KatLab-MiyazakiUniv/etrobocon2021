/**
 * @file Controller.h
 * @brief モーター制御
 * @author yutotanaka24,kodama0720
 */
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "ev3api.h"
#include "Motor.h"
#include "Clock.h"
#include "Measurer.h"

class Controller {
 public:
  static const int MOTOR_PWM_MAX = 100;
  static const int MOTOR_PWM_MIN = -100;

  Controller();

  /**
   * モータにPWM値をセット
   * @param pwm PWM値
   */
  void setRightMotorPwm(const int pwm);
  void setLeftMotorPwm(const int pwm);

  /**
   *モータカウントリセット
   */
  void resetMotorCount();

  /**
   * 停止する
   */
  void stopMotor();

  /**
   * 自タスクスリープ
   * @param milliSec スリープ時間(ミリ秒)
   */
  void sleep(int milliSec = 10);

 private:
  ev3api::Motor rightWheel;
  ev3api::Motor leftWheel;
  ev3api::Clock clock;
  Measurer measurer;
  /**
   * モータに設定するPWM値の制限
   * @param value 入力されたPWM値
   * @return 制限されたPWM値
   */
  int limitPwmValue(const int value);
};

#endif
