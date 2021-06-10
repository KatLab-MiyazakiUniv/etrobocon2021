/**
 * @file LineTracer.cpp
 * @brief ライントレースする
 * @author yutotanaka24,kodama0720
 */
#include "LineTracer.h"

LineTracer::LineTracer(int _edge) : edge(_edge) {}

void LineTracer::run(double targetDistance, int targetValue, int pwm, PidGain& gain)
{
  Pid pid(gain.kp, gain.ki, gain.kd, targetValue);

  //走行距離が目標距離を超えるまで繰り返す
  while(true) {
    currentDistance = mileage.calculateMileage(measurer.getRightCount(), measurer.getLeftCount());
    if(currentDistance > targetDistance) {
      break;
    }
    // PID計算
    currentPid = pid.calculatePid(measurer.getBrightness()) * edge;
    //モータのPWM値をセット
    controller.setRightMotorPwm(pwm - currentPid);
    controller.setLeftMotorPwm(pwm + currentPid);
  }
}