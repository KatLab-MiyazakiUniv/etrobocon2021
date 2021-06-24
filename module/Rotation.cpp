/**
 * @file Rotation.cpp
 * @brief 回頭・ピボットターンする
 * @author kodama0720, yutotanaka24
 */

#include "Rotation.h"

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
