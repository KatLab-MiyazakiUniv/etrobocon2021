/**
 * @file Rotation.cpp
 * @brief 回頭・ピボットターンする
 * @author kodama0720, yutotanaka24
 */

#include "Rotation.h"

using namespace std;

void Rotation::rotate(int angle, int pwm)
{
  //右回転なら左モータが正
  int leftSign = (angle > 0) ? 1 : -1;
  int rightSign = (angle > 0) ? -1 : 1;
  double leftDistance = 0;
  double rightDistance = 0;
  double targetDistance = M_PI * TREAD * angle / 360;  //弧の長さ
  int leftPwm;
  int rightPwm;

  controller.resetMotorCount();

  //両輪がtargetDistanceに到達するまでループ
  while(leftSign != 0 || rightSign != 0) {
    leftDistance = Mileage::calculateWheelMileage(measurer.getLeftCount());
    rightDistance = Mileage::calculateWheelMileage(measurer.getRightCount());

    if(abs(leftDistance) >= abs(targetDistance)) {
      leftSign = 0;
    }
    if(abs(rightDistance) >= abs(targetDistance)) {
      rightSign = 0;
    }

    leftPwm = pwm * leftSign;
    rightPwm = pwm * rightSign;

    controller.setLeftMotorPwm(leftPwm);
    controller.setRightMotorPwm(rightPwm);

    controller.sleep();
  }
  controller.stopMotor();
}

//設定された角度とPWM値で右タイヤを軸にピボットターンする
void Rotation::turnRightPivot(int angle, int pwm)
{
  int forwardSign = (angle > 0) ? 1 : -1;
  double currentArcDistance = 0;                           //現在の走行距離
  double targetDistance = 2 * M_PI * TREAD * angle / 360;  //弧の長さ r:半径 angle:中心角

  //走行距離のリセット
  controller.resetMotorCount();

  while(true) {
    currentArcDistance = Mileage::calculateWheelMileage(measurer.getLeftCount());

    if(abs(currentArcDistance) >= abs(targetDistance)) {
      break;
    }
    //モータのPWM値をセット
    controller.setRightMotorPwm(0);
    controller.setLeftMotorPwm(pwm * forwardSign);

    // 10ミリ秒待機
    controller.sleep();
  }
  //モータの停止
  controller.stopMotor();
}

//設定された角度とPWM値で左タイヤを軸にピボットターンする
void Rotation::turnLeftPivot(int angle, int pwm)
{
  double currentArcDistance = 0;                    //現在の走行距離
  double leftArc = 2 * M_PI * TREAD * angle / 360;  //弧の長さ r:半径 angle:中心角

  //走行距離のリセット
  controller.resetMotorCount();

  while(leftArc >= 0) {
    currentArcDistance
        = Mileage::calculateMileage(measurer.getRightCount(), measurer.getLeftCount());

    if(2 * currentArcDistance >= leftArc) {
      break;
    }
    //モータのPWMをセット
    controller.setRightMotorPwm(pwm);
    controller.setLeftMotorPwm(0);

    // 10ミリ秒待機
    controller.sleep();
  }
  //後ろ方向に進む（角度がマイナス）
  while(leftArc < 0) {
    currentArcDistance
        = Mileage::calculateMileage(measurer.getRightCount(), measurer.getLeftCount());

    if(2 * currentArcDistance <= leftArc) {
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
