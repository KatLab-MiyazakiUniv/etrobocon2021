/**
 * @file Rotation.cpp
 * @brief 回頭・ピボットターンする
 * @author kodama0720, yutotanaka24, hiroto0927, miyashita64
 */

#include "Rotation.h"

using namespace std;

Rotation::Rotation()
  : RADIUS(45.0), TREAD(140), ROTATE_MIN_PWM(20), PIVOT_FRONT_MIN_PWM(20), PIVOT_BACK_MIN_PWM(10)
{
}

//左回転
void Rotation::rotateLeft(int angle, int pwm)
{
  const double _TREAD = TREAD - 3;  // 回頭距離の調整
  int leftSign = -1;
  int rightSign = 1;
  double targetDistance = M_PI * _TREAD * abs(angle) / 360;  //弧の長さ
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
    int leftPwm = (diffLeftDistance / targetDistance * pwm >= ROTATE_MIN_PWM)
                      ? diffLeftDistance / targetDistance * pwm
                      : ROTATE_MIN_PWM;
    int rightPwm = (diffRightDistance / targetDistance * pwm >= ROTATE_MIN_PWM)
                       ? diffRightDistance / targetDistance * pwm
                       : ROTATE_MIN_PWM;
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
  const double _TREAD = TREAD - 3;  // 回頭距離の調整
  int leftSign = 1;
  int rightSign = -1;
  double targetDistance = M_PI * _TREAD * abs(angle) / 360;  //弧の長さ
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
    int leftPwm = (diffLeftDistance / targetDistance * pwm >= ROTATE_MIN_PWM)
                      ? diffLeftDistance / targetDistance * pwm
                      : ROTATE_MIN_PWM;
    int rightPwm = (diffRightDistance / targetDistance * pwm >= ROTATE_MIN_PWM)
                       ? diffRightDistance / targetDistance * pwm
                       : ROTATE_MIN_PWM;
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
  const double _TREAD = TREAD + 5;  //トレッド幅の調整
  double initialDistance = Mileage::calculateWheelMileage(measurer.getLeftCount());
  double targetDistance = 2 * M_PI * _TREAD * angle / 360;  //目標距離
  int rightCount = 0 + measurer.getRightCount();

  //目標距離を超えるまでループ
  while(true) {
    //現在の距離を取得
    double currentDistance = Mileage::calculateWheelMileage(measurer.getLeftCount());
    double restDistance = initialDistance + targetDistance - currentDistance;  //残りの距離

    //モーターの速度を徐々に遅くする
    int leftPwm = (restDistance / targetDistance * pwm > PIVOT_FRONT_MIN_PWM)
                      ? restDistance / targetDistance * pwm
                      : PIVOT_FRONT_MIN_PWM;

    if(currentDistance >= initialDistance + targetDistance) {
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
  const double _TREAD = TREAD - 5;
  double initialDistance = Mileage::calculateWheelMileage(measurer.getLeftCount());
  double targetDistance = -2 * M_PI * _TREAD * angle / 360;  //目標距離
  int rightCount = 0 + measurer.getRightCount();

  //目標距離を超えるまでループ
  while(true) {
    double currentDistance = Mileage::calculateWheelMileage(measurer.getLeftCount());
    double restDistance = initialDistance + targetDistance - currentDistance;  //残りの距離

    //モーターの速度を徐々に遅くする
    int leftPwm = (restDistance / targetDistance * pwm > PIVOT_BACK_MIN_PWM)
                      ? restDistance / targetDistance * pwm
                      : PIVOT_BACK_MIN_PWM;

    if(currentDistance <= initialDistance + targetDistance) {
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
  const double _TREAD = TREAD + 5;  //トレッド幅の調整
  double initialDistance = Mileage::calculateWheelMileage(measurer.getRightCount());
  double targetDistance = 2 * M_PI * _TREAD * angle / 360;  //目標距離
  int leftCount = 0 + measurer.getLeftCount();

  //目標距離を超えるまでループ
  while(true) {
    //現在の距離を取得
    double currentDistance = Mileage::calculateWheelMileage(measurer.getRightCount());
    double restDistance = initialDistance + targetDistance - currentDistance;  //残りの距離

    //モーターの速度を徐々に遅くする
    int rightPwm = (restDistance / targetDistance * pwm > PIVOT_FRONT_MIN_PWM)
                       ? restDistance / targetDistance * pwm
                       : PIVOT_FRONT_MIN_PWM;

    if(currentDistance >= initialDistance + targetDistance) {
      break;
    }

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
  const double _TREAD = TREAD - 5;
  double initialDistance = Mileage::calculateWheelMileage(measurer.getRightCount());
  double targetDistance = -2 * M_PI * _TREAD * angle / 360;  //目標距離
  int leftCount = 0 + measurer.getLeftCount();

  //目標距離を超えるまでループ
  while(true) {
    double currentDistance = Mileage::calculateWheelMileage(measurer.getRightCount());
    double restDistance = initialDistance + targetDistance - currentDistance;  //残りの距離

    //モーターの速度を徐々に遅くする
    int rightPwm = (restDistance / targetDistance * pwm > PIVOT_BACK_MIN_PWM)
                       ? restDistance / targetDistance * pwm
                       : PIVOT_BACK_MIN_PWM;

    if(currentDistance <= initialDistance + targetDistance) {
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