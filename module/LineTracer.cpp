/**
 * @file LineTracer.cpp
 * @brief ライントレースする
 * @author yutotanaka24,kodama0720
 */
#include "LineTracer.h"

LineTracer::LineTracer(bool _isLeft) : edge((_isLeft == true) ? 1 : -1) {}

//設定された距離を走行する
void LineTracer::run(double targetDistance, int targetBrightness, int pwm, const PidGain& gain)
{
  double currentDistance = 0;
  double currentPid = 0;
  Pid pid(gain.kp, gain.ki, gain.kd, targetBrightness);

  //走行距離のリセット
  controller.resetMotorCount();

  //走行距離が目標距離に到達するまで繰り返す
  while(true) {
    currentDistance = Mileage::calculateMileage(measurer.getRightCount(), measurer.getLeftCount());
    if(currentDistance >= targetDistance) {
      break;
    }
    // PID計算
    currentPid = pid.calculatePid(measurer.getBrightness()) * edge;
    //モータのPWM値をセット
    controller.setRightMotorPwm(pwm - currentPid);
    controller.setLeftMotorPwm(pwm + currentPid);
    // 10ミリ秒待機
    controller.sleep();
  }
  //モータの停止
  controller.stopMotor();
}