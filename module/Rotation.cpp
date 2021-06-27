/**
 * @file Rotation.cpp
 * @brief 回頭・ピボットターンする
 * @author kodama0720, yutotanaka24
 */

#include "Rotation.h"
#include "stdio.h"

using namespace std;

//左回転
void Rotation::rotateLeft(int angle, int pwm)
{
  int leftSign = -1;
  int rightSign = 1;
  double currentLeftDistance = 0;
  double currentRightDistance = 0;
  double targetDistance = M_PI * TREAD * abs(angle) / 360;  //弧の長さ
  //目標距離（呼び出し時の走行距離 ± 指定された回転量に必要な距離）
  double targetLeftDistance
      = Mileage::calculateWheelMileage(measurer.getLeftCount()) - targetDistance;
  double targetRightDistance
      = Mileage::calculateWheelMileage(measurer.getRightCount()) + targetDistance;

  //両輪が目標距離に到達するまでループ
  while(leftSign != 0 || rightSign != 0) {
    //現在の走行距離を取得
    currentLeftDistance = Mileage::calculateWheelMileage(measurer.getLeftCount());
    currentRightDistance = Mileage::calculateWheelMileage(measurer.getRightCount());
    //目標距離に到達したらpwm値にかける値を0にする
    if(currentLeftDistance <= targetLeftDistance) {
      leftSign = 0;
    }
    if(currentRightDistance >= targetRightDistance) {
      rightSign = 0;
    }
    //モータのPWM値をセット
    controller.setLeftMotorPwm(abs(pwm) * leftSign);
    controller.setRightMotorPwm(abs(pwm) * rightSign);

    // 10ミリ秒待機
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
  double currentLeftDistance = 0;
  double currentRightDistance = 0;
  double targetDistance = M_PI * TREAD * abs(angle) / 360;  //弧の長さ
  //左右のタイヤの目標距離
  double targetLeftDistance
      = Mileage::calculateWheelMileage(measurer.getLeftCount()) + targetDistance;
  double targetRightDistance
      = Mileage::calculateWheelMileage(measurer.getRightCount()) - targetDistance;

  //両輪が目標距離に到達するまでループ
  while(leftSign != 0 || rightSign != 0) {
    //現在の走行距離を取得
    currentLeftDistance = Mileage::calculateWheelMileage(measurer.getLeftCount());
    currentRightDistance = Mileage::calculateWheelMileage(measurer.getRightCount());
    //目標距離に到達したらpwm値にかける値を0にする
    if(currentLeftDistance >= targetLeftDistance) {
      leftSign = 0;
    }
    if(currentRightDistance <= targetRightDistance) {
      rightSign = 0;
    }
    //モータのPWM値をセット
    controller.setLeftMotorPwm(abs(pwm) * leftSign);
    controller.setRightMotorPwm(abs(pwm) * rightSign);

    // 10ミリ秒待機
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