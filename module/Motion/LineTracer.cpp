/**
 * @file LineTracer.cpp
 * @brief ライントレースする
 * @author yutotanaka24,kodama0720
 */
#include "LineTracer.h"

LineTracer::LineTracer(bool _isLeftEdge) : isLeftEdge(_isLeftEdge) {}

//設定された距離を走行する
void LineTracer::run(double targetDistance, int targetBrightness, int pwm, const PidGain& gain)
{
  double initialDistance = 0;
  double currentDistance = 0;
  double currentPid = 0;
  int pidSign = 0;
  Pid pid(gain.kp, gain.ki, gain.kd, targetBrightness);

  //左右で符号を変える
  pidSign = (isLeftEdge) ? -1 : 1;

  // 初期値を格納
  initialDistance = Mileage::calculateMileage(measurer.getRightCount(), measurer.getLeftCount());

  //走行距離が目標距離に到達するまで繰り返す
  while(true) {
    currentDistance = Mileage::calculateMileage(measurer.getRightCount(), measurer.getLeftCount());
    if(currentDistance - initialDistance >= targetDistance) {
      break;
    }
    // PID計算
    currentPid = pid.calculatePid(measurer.getBrightness()) * pidSign;
    //モータのPWM値をセット
    controller.setRightMotorPwm(pwm - currentPid);
    controller.setLeftMotorPwm(pwm + currentPid);
    // 10ミリ秒待機
    controller.sleep();
  }
  //モータの停止
  controller.stopMotor();
}

//白黒を判定している間走行する
void LineTracer::runToColor(int targetBrightness, int pwm, const PidGain& gain)
{
  double currentPid = 0;
  int pidSign = 0;
  Pid pid(gain.kp, gain.ki, gain.kd, targetBrightness);

  COLOR color = COLOR::NONE;

  //左右で符号を変える
  pidSign = (isLeftEdge) ? -1 : 1;

  //白黒を判定している間走行する
  while(true) {
    // 色を判定し、白黒以外で在ればループを抜ける
    color = ColorJudge::getColor(measurer.getRawColor());
    if(color != COLOR::BLACK && color != COLOR::WHITE) {
      break;
    }
    // PID計算
    currentPid = pid.calculatePid(measurer.getBrightness()) * pidSign;
    //モータのPWM値をセット
    controller.setRightMotorPwm(pwm - currentPid);
    controller.setLeftMotorPwm(pwm + currentPid);
    // 10ミリ秒待機
    controller.sleep();
  }
  //モータの停止
  controller.stopMotor();
}

bool LineTracer::getIsLeftEdge()
{
  return isLeftEdge;
}

void LineTracer::setIsLeftEdge(bool _isLeftEdge)
{
  isLeftEdge = _isLeftEdge;
}

void LineTracer::toggleEdge()
{
  isLeftEdge = !isLeftEdge;
}
