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
  double targetLeftDistance
      = Mileage::calculateWheelMileage(measurer.getLeftCount()) - targetDistance;
  double targetRightDistance
      = Mileage::calculateWheelMileage(measurer.getRightCount()) + targetDistance;

  //両輪がtargetDistanceに到達するまでループ
  while(leftSign != 0 || rightSign != 0) {
    currentLeftDistance = Mileage::calculateWheelMileage(measurer.getLeftCount());
    currentRightDistance = Mileage::calculateWheelMileage(measurer.getRightCount());
    if(currentLeftDistance <= targetLeftDistance) {
      leftSign = 0;
    }
    if(currentRightDistance >= targetRightDistance) {
      rightSign = 0;
    }

    controller.setLeftMotorPwm(abs(pwm) * leftSign);
    controller.setRightMotorPwm(abs(pwm) * rightSign);

    controller.sleep();
  }
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
    currentLeftDistance = Mileage::calculateWheelMileage(measurer.getLeftCount());
    currentRightDistance = Mileage::calculateWheelMileage(measurer.getRightCount());

    if(currentLeftDistance >= targetLeftDistance) {
      leftSign = 0;
    }
    if(currentRightDistance <= targetRightDistance) {
      rightSign = 0;
    }

    controller.setLeftMotorPwm(abs(pwm) * leftSign);
    controller.setRightMotorPwm(abs(pwm) * rightSign);

    controller.sleep();
  }
  controller.stopMotor();
}

//設定された角度とPWM値で右タイヤを軸に前方へピボットターンする
void Rotation::turnForwardRightPivot(int angle, int pwm)
{
  double Distance = 2 * M_PI * TREAD * angle / 360;  //弧の長さ r:半径 angle:中心角
  double targetDistance = Mileage::calculateWheelMileage(measurer.getLeftCount()) + Distance;

  while(true) {
    double currentArcDistance = Mileage::calculateWheelMileage(measurer.getLeftCount());

    if(currentArcDistance >= targetDistance) {
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
  double Distance = 2 * M_PI * TREAD * angle / 360;  //弧の長さ r:半径 angle:中心角
  double targetDistance = Mileage::calculateWheelMileage(measurer.getLeftCount()) - Distance;

  while(true) {
    double currentArcDistance = Mileage::calculateWheelMileage(measurer.getLeftCount());

    if(currentArcDistance <= targetDistance) {
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
  double Distance = 2 * M_PI * TREAD * angle / 360;  //弧の長さ r:半径 angle:中心角
  double targetDistance = Mileage::calculateWheelMileage(measurer.getRightCount()) + Distance;

  while(true) {
    double currentArcDistance = Mileage::calculateWheelMileage(measurer.getRightCount());

    if(currentArcDistance >= targetDistance) {
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
  double Distance = 2 * M_PI * TREAD * angle / 360;  //弧の長さ r:半径 angle:中心角
  double targetDistance = Mileage::calculateWheelMileage(measurer.getRightCount()) - Distance;

  while(true) {
    double currentArcDistance = Mileage::calculateWheelMileage(measurer.getRightCount());

    if(currentArcDistance <= targetDistance) {
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