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
  double _TREAD = TREAD + 5;                          //トレッド幅の調整
  double distance = 2 * M_PI * _TREAD * angle / 360;  //弧の長さ
  int rightCount = 0;

  //目標距離を超えるまでループ
  while(true) {
    //現在の距離を取得
    double currentDistance = Mileage::calculateWheelMileage(measurer.getLeftCount());
    double targetDistance = distance - currentDistance;

    //モーターの速度を徐々に遅くする
    int leftPwm = (targetDistance / distance * pwm > PIVOT_MIN_PWM)
                      ? targetDistance / distance * pwm
                      : PIVOT_MIN_PWM;

    if(currentDistance > distance) {
      break;
    }

    //モータのPWM値をセット
    controller.setRightMotorPwm(0);
    controller.setLeftMotorPwm(leftPwm);

    //軸足のずれの調整
    if(measurer.getRightCount() > rightCount) {
      controller.setRightMotorPwm(-10);
    }

    if(measurer.getRightCount() < rightCount) {
      controller.setRightMotorPwm(10);
    }

    // 10ミリ秒待機
    controller.sleep();
  }

  //モータの停止
  controller.stopMotor();
}

//設定された角度とPWM値で右タイヤを軸に後方へピボットターンする
void Rotation::turnBackRightPivot(int angle, int pwm)
{
  double _TREAD = TREAD - 5;
  double distance = -2 * M_PI * _TREAD * angle / 360;  //弧の長さ
  int rightCount = 0;

  //目標距離を超えるまでループ
  while(true) {
    double currentDistance = Mileage::calculateWheelMileage(measurer.getLeftCount());
    double targetDistance = distance - currentDistance;

    //モーターの速度を徐々に遅くする
    int leftPwm = (targetDistance / distance * pwm > PIVOT_MIN_PWM_2)
                      ? targetDistance / distance * pwm
                      : PIVOT_MIN_PWM_2;

    if(currentDistance < distance) {
      break;
    }

    //モータのPWM値をセット
    controller.setRightMotorPwm(0);
    controller.setLeftMotorPwm(-leftPwm);

    //軸足のずれの調整
    if(measurer.getRightCount() > rightCount) {
      controller.setRightMotorPwm(-10);
    }

    if(measurer.getRightCount() < rightCount) {
      controller.setRightMotorPwm(10);
    }

    // 10ミリ秒待機
    controller.sleep();
  }

  //モータの停止
  controller.stopMotor();
}

//設定された角度とPWM値で左タイヤを軸に前方へピボットターンする
void Rotation::turnForwardLeftPivot(int angle, int pwm)
{
  double _TREAD = TREAD + 5;                          //トレッド幅の調整
  double distance = 2 * M_PI * _TREAD * angle / 360;  //弧の長さ
  int leftCount = 0;

  //目標距離を超えるまでループ
  while(true) {
    //現在の距離を取得
    double currentDistance = Mileage::calculateWheelMileage(measurer.getRightCount());
    double targetDistance = distance - currentDistance;

    if(currentDistance > distance) {
      break;
    }
    //モーターの速度を徐々に遅くする
    int rightPwm = (targetDistance / distance * pwm > PIVOT_MIN_PWM)
                       ? targetDistance / distance * pwm
                       : PIVOT_MIN_PWM;

    //モータのPWM値をセット
    controller.setRightMotorPwm(rightPwm);
    controller.setLeftMotorPwm(0);

    //軸足のずれの調整
    if(measurer.getLeftCount() > leftCount) {
      controller.setLeftMotorPwm(-10);
    }

    if(measurer.getLeftCount() < leftCount) {
      controller.setLeftMotorPwm(10);
    }

    // 10ミリ秒待機
    controller.sleep();
  }

  //モータの停止
  controller.stopMotor();
}

//設定された角度とPWM値で左タイヤを軸に後方へピボットターンする
void Rotation::turnBackLeftPivot(int angle, int pwm)
{
  double _TREAD = TREAD - 5;
  double distance = -2 * M_PI * _TREAD * angle / 360;  //弧の長さ
  int leftCount = 0;

  //目標距離を超えるまでループ
  while(true) {
    double currentDistance = Mileage::calculateWheelMileage(measurer.getRightCount());
    double targetDistance = distance - currentDistance;

    //モーターの速度を徐々に遅くする
    int rightPwm = (targetDistance / distance * pwm > PIVOT_MIN_PWM_2)
                       ? targetDistance / distance * pwm
                       : PIVOT_MIN_PWM_2;

    if(currentDistance < distance) {
      break;
    }

    //モータのPWM値をセット
    controller.setRightMotorPwm(-rightPwm);
    controller.setLeftMotorPwm(0);

    //軸足のずれの調整
    if(measurer.getLeftCount() > leftCount) {
      controller.setLeftMotorPwm(-10);
    }

    if(measurer.getLeftCount() < leftCount) {
      controller.setLeftMotorPwm(10);
    }

    // 10ミリ秒待機
    controller.sleep();
  }

  //モータの停止
  controller.stopMotor();
}