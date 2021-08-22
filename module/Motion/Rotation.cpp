/**
 * @file Rotation.cpp
 * @brief 回頭・ピボットターンする
 * @author kodama0720, yutotanaka24, hiroto0927, miyashita64
 */

#include "Rotation.h"
#include "stdio.h"

using namespace std;

//左回転
void Rotation::rotateLeft(int angle, int pwm)
{
  int leftSign = -1;
  int rightSign = 1;
  double targetDistance = M_PI * TREAD * abs(angle) / 360;  //弧の長さ
  //目標距離（呼び出し時の走行距離 ± 指定された回転量に必要な距離）
  double targetLeftDistance
      = Mileage::calculateWheelMileage(measurer.getLeftCount()) + targetDistance * leftSign;
  double targetRightDistance
      = Mileage::calculateWheelMileage(measurer.getRightCount()) + targetDistance * rightSign;

  //両輪が目標距離に到達するまでループ
  while(leftSign != 0 || rightSign != 0) {
    // 残りの移動距離
    double diffLeftDistance
        = (targetLeftDistance - Mileage::calculateWheelMileage(measurer.getLeftCount())) * leftSign;
    double diffRightDistance
        = (targetRightDistance - Mileage::calculateWheelMileage(measurer.getRightCount()))
          * rightSign;

    // 目標距離に到達した場合
    if(diffLeftDistance <= 0) {
      leftSign = 0;
    }
    if(diffRightDistance <= 0) {
      rightSign = 0;
    }

    // PWM値 = 残りの走行距離/走行距離 * 指定PWM値(最小値 MIN_PWM)
    int leftPwm = (diffLeftDistance / targetDistance * pwm >= MIN_PWM)
                      ? diffLeftDistance / targetDistance * pwm
                      : MIN_PWM;
    int rightPwm = (diffRightDistance / targetDistance * pwm >= MIN_PWM)
                       ? diffRightDistance / targetDistance * pwm
                       : MIN_PWM;
    controller.setLeftMotorPwm(abs(leftPwm) * leftSign);
    controller.setRightMotorPwm(abs(rightPwm) * rightSign);

    controller.sleep();
  }

  //モータの停止
  controller.stopMotor();
}

//右回転
void Rotation::rotateRight(int angle, int pwm)
{
  int leftSign = 1;
  int rightSign = -1;
  double targetDistance = M_PI * TREAD * abs(angle) / 360;  //弧の長さ
  //目標距離（呼び出し時の走行距離 ± 指定された回転量に必要な距離）
  double targetLeftDistance
      = Mileage::calculateWheelMileage(measurer.getLeftCount()) + targetDistance * leftSign;
  double targetRightDistance
      = Mileage::calculateWheelMileage(measurer.getRightCount()) + targetDistance * rightSign;

  //両輪が目標距離に到達するまでループ
  while(leftSign != 0 || rightSign != 0) {
    // 残りの移動距離
    double diffLeftDistance
        = (targetLeftDistance - Mileage::calculateWheelMileage(measurer.getLeftCount())) * leftSign;
    double diffRightDistance
        = (targetRightDistance - Mileage::calculateWheelMileage(measurer.getRightCount()))
          * rightSign;

    // 目標距離に到達した場合
    if(diffLeftDistance <= 0) {
      leftSign = 0;
    }
    if(diffRightDistance <= 0) {
      rightSign = 0;
    }

    // PWM値 = 残りの走行距離/走行距離 * 指定PWM値(最小値 MIN_PWM)
    int leftPwm = (diffLeftDistance / targetDistance * pwm >= MIN_PWM)
                      ? diffLeftDistance / targetDistance * pwm
                      : MIN_PWM;
    int rightPwm = (diffRightDistance / targetDistance * pwm >= MIN_PWM)
                       ? diffRightDistance / targetDistance * pwm
                       : MIN_PWM;
    controller.setLeftMotorPwm(abs(leftPwm) * leftSign);
    controller.setRightMotorPwm(abs(rightPwm) * rightSign);

    controller.sleep();
  }

  //モータの停止
  controller.stopMotor();
}

//設定された角度とPWM値で右タイヤを軸に前方へピボットターンする
void Rotation::turnForwardRightPivot(int angle, int pwm)
{
  double distance = 2 * M_PI * TREAD * angle / 360;  //弧の長さ
  double targetDistance = Mileage::calculateWheelMileage(measurer.getLeftCount()) + distance;

  //目標距離を超えるまでループ
  while(true) {
    //現在の距離を取得
    double currentDistance = Mileage::calculateWheelMileage(measurer.getLeftCount());

    if(currentDistance >= targetDistance) {
      break;
    }

    //モータのPWM値をセット
    controller.setRightMotorPwm(0);
    controller.setLeftMotorPwm(pwm);

    // 10ミリ秒待機
    controller.sleep();
  }
  //モータの停止
  controller.stopMotor();
}

//設定された角度とPWM値で右タイヤを軸に後方へピボットターンする
void Rotation::turnBackRightPivot(int angle, int pwm)
{
  double distance = 2 * M_PI * TREAD * angle / 360;  //弧の長さ
  double targetDistance = Mileage::calculateWheelMileage(measurer.getLeftCount()) - distance;

  //目標距離を超えるまでループ
  while(true) {
    double currentDistance = Mileage::calculateWheelMileage(measurer.getLeftCount());

    if(currentDistance <= targetDistance) {
      break;
    }

    //モータのPWM値をセット
    controller.setRightMotorPwm(0);
    controller.setLeftMotorPwm(-pwm);

    // 10ミリ秒待機
    controller.sleep();
  }
  //モータの停止
  controller.stopMotor();
}

//設定された角度とPWM値で左タイヤを軸に前方へピボットターンする
void Rotation::turnForwardLeftPivot(int angle, int pwm)
{
  double distance = 2 * M_PI * TREAD * angle / 360;  //弧の長さ
  double targetDistance = Mileage::calculateWheelMileage(measurer.getRightCount()) + distance;

  //目標距離を超えるまでループ
  while(true) {
    double currentDistance = Mileage::calculateWheelMileage(measurer.getRightCount());

    if(currentDistance >= targetDistance) {
      break;
    }

    //モータのPWM値をセット
    controller.setRightMotorPwm(pwm);
    controller.setLeftMotorPwm(0);

    // 10ミリ秒待機
    controller.sleep();
  }
  //モータの停止
  controller.stopMotor();
}

//設定された角度とPWM値で左タイヤを軸に後方へピボットターンする
void Rotation::turnBackLeftPivot(int angle, int pwm)
{
  double distance = 2 * M_PI * TREAD * angle / 360;  //弧の長さ
  double targetDistance = Mileage::calculateWheelMileage(measurer.getRightCount()) - distance;

  //目標距離を超えるまでループ
  while(true) {
    double currentDistance = Mileage::calculateWheelMileage(measurer.getRightCount());

    if(currentDistance <= targetDistance) {
      break;
    }

    //モータのPWM値をセット
    controller.setRightMotorPwm(-pwm);
    controller.setLeftMotorPwm(0);

    // 10ミリ秒待機
    controller.sleep();
  }
  //モータの停止
  controller.stopMotor();
}