/**
 * @file Controller.cpp
 * @brief モーター制御
 * @author yutotanaka24,kodama0720
 */
#include "Controller.h"

Controller::Controller() : rightWheel(PORT_B), leftWheel(PORT_C) {}
int Controller::limitPwmValue(const int value)
{
  if(value > MOTOR_PWM_MAX) {
    return MOTOR_PWM_MAX;
  } else if(value < MOTOR_PWM_MIN) {
    return MOTOR_PWM_MIN;
  }
  return value;
}

void Controller::setRightMotorPwm(const int pwm)
{
  rightWheel.setPWM(limitPwmValue(pwm));
}
void Controller::setLeftMotorPwm(const int pwm)
{
  leftWheel.setPWM(limitPwmValue(pwm));
}
void Controller::stopMotor()
{
  leftWheel.stop();
  rightWheel.stop();
}
