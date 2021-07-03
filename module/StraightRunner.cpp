/**
 * @file StraightRunner.cpp
 * @brief 直進クラス
 * @author hiroto0927, miyashita64
 */

#include "StraightRunner.h"

StraightRunner::StraightRunner() {}

// 設定された距離を直進する
void StraightRunner::runStraightToDistance(double targetDistance, int pwm)
{
  double initialDistance = 0;
  double currentDistance = 0;

  // 初期値を格納
  initialDistance = Mileage::calculateMileage(measurer.getRightCount(), measurer.getLeftCount());

  // pwm値が0の際は、終了する
  if(pwm == 0) return;

  // 走行距離が目標距離に到達するまで繰り返す
  while(true) {
    //現在の距離を取得する
    currentDistance = Mileage::calculateMileage(measurer.getRightCount(), measurer.getLeftCount());

    //現在の距離が目標距離に到達したらループを終了する
    if(std::abs(currentDistance - initialDistance) >= targetDistance) {
      break;
    }
    // モータのPWM値をセット
    controller.setRightMotorPwm(pwm);
    controller.setLeftMotorPwm(pwm);
    // 10ミリ秒待機
    controller.sleep();
  }
  // モータの停止
  controller.stopMotor();
}

// 白黒以外の色を検出するまで直進する
void StraightRunner::runStraightToColor(int pwm)
{
  // pwm値が0の際は、終了する。
  if(pwm == 0) return;

  while(true) {
    // 現在のRGB値から色を識別する
    COLOR color = ColorJudge::getColor(measurer.getRawColor());

    // 白黒以外の色を検出した場合、直進終了
    if(color != COLOR::BLACK && color != COLOR::WHITE) {
      break;
    }

    // モータのPWM値をセット
    controller.setRightMotorPwm(pwm);
    controller.setLeftMotorPwm(pwm);
    // 10ミリ秒待機
    controller.sleep();
  }
  // モータの停止
  controller.stopMotor();
}