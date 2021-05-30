/**
 * @file Controller.cpp
 * @brief モーター制御(ダミー)
 * @author yutotanaka24,kodama0720
 */
#include "Controller.h"

int Controller::suppressPwmValue(const int value)
{
  if(value > MOTOR_PWM_MAX) {
    return MOTOR_PWM_MAX;
  } else if(value < MOTOR_PWM_MIN) {
    return MOTOR_PWM_MIN;
  }
  return value;
}

void Controller::stopMotor()
{
  leftWheel.stop();
  rightWheel.stop();
}
void Motor::setPWM(int pwm)
{
  count += pwm * 0.05;
}
