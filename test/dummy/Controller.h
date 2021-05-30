/**
 * @file Controller.cpp
 * @brief モーター制御(ダミー)
 * @author yutotanaka24,kodama0720
 */
#ifndef CONTROLLER_H
#define CONTROLLER_H
class Motor {
 public:
  double count = 0.0;
  void setPWM(int pwm);
  void stop(){};
};
class Controller {
 public:
  static int suppressPwmValue(const int value);
  //モーター入力電圧の最大値
  static const int MOTOR_PWM_MAX = 100;
  //モーター入力電圧の最小値
  static const int MOTOR_PWM_MIN = -100;
  void setRightMotorPwm(const int pwm) { leftWheel.setPWM(suppressPwmValue(pwm)); };
  void setLeftMotorPwm(const int pwm) { rightWheel.setPWM(suppressPwmValue(pwm)); };
  void stopMotor();

 private:
  Motor rightWheel;
  Motor leftWheel;
};
#endif