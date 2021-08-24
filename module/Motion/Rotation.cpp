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
    printf("left::%d rgiht::%d \n", measurer.getLeftCount(), measurer.getRightCount());
    controller.sleep();
  }
  printf("------------------END---------\n");
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
  int rightCount = 0;

  //目標距離を超えるまでループ
  while(true) {
    //現在の距離を取得
    double currentDistance = Mileage::calculateWheelMileage(measurer.getLeftCount());
    double targetDistance = distance - currentDistance;

    if(currentDistance > distance) {
      break;
    }

    int leftPwm = (targetDistance / distance * pwm > PIVOT_MIN_PWM)
                      ? targetDistance / distance * pwm
                      : PIVOT_MIN_PWM;

    if(measurer.getRightCount() > rightCount) {
      controller.setRightMotorPwm(-10);
    }

    if(rightCount > measurer.getRightCount()) {
      controller.setRightMotorPwm(10);
    }

    //モータのPWM値をセット
    controller.setRightMotorPwm(0);
    controller.setLeftMotorPwm(leftPwm);

    printf("RightMotorCount:: %d \n", measurer.getRightCount());

    // 10ミリ秒待機
    controller.sleep();
  }

  /*
    while(measurer.getRightCount() > rightCount) {
      if(measurer.getRightCount() <= rightCount) break;
      controller.setRightMotorPwm(-10);

      printf("RightMotorCount:: %d  count:: %d\n", measurer.getRightCount(), rightCount);
      controller.sleep();
    }
    */

  printf("----------------------------------------\n");

  //モータの停止
  controller.stopMotor();
}

//設定された角度とPWM値で右タイヤを軸に後方へピボットターンする
void Rotation::turnBackRightPivot(int angle, int pwm)
{
  double distance = -2 * M_PI * TREAD * angle / 360;  //弧の長さ

  //目標距離を超えるまでループ
  while(true) {
    double currentDistance = Mileage::calculateWheelMileage(measurer.getLeftCount());
    double targetDistance = distance - currentDistance;

    if(currentDistance < distance) {
      break;
    }

    int leftPwm = (targetDistance / distance * pwm > PIVOT_MIN_PWM)
                      ? targetDistance / distance * pwm
                      : PIVOT_MIN_PWM;

    //モータのPWM値をセット
    controller.setRightMotorPwm(0);
    controller.setLeftMotorPwm(-leftPwm);

    //  printf("leftPwm::%d\n", leftPwm);
    printf("leftPwm::%d | RightMotorCount:: %d\n", leftPwm, measurer.getRightCount());
    // 10ミリ秒待機
    controller.sleep();
  }

  printf("----------------------END------------------\n");
  //モータの停止
  controller.stopMotor();
}

//設定された角度とPWM値で左タイヤを軸に前方へピボットターンする
void Rotation::turnForwardLeftPivot(int angle, int pwm)
{
  double distance = 2 * M_PI * TREAD * angle / 360;  //弧の長さ
  int leftCount = measurer.getLeftCount();

  //目標距離を超えるまでループ
  while(true) {
    double currentDistance = Mileage::calculateWheelMileage(measurer.getRightCount());
    double targetDistance = distance - currentDistance;

    if(currentDistance > distance) {
      break;
    }

    int rightPwm = (targetDistance / distance * pwm > PIVOT_MIN_PWM)
                       ? targetDistance / distance * pwm
                       : PIVOT_MIN_PWM;

    //モータのPWM値をセット
    controller.setRightMotorPwm(rightPwm);
    controller.setLeftMotorPwm(0);

    if(leftCount > measurer.getLeftCount()) {
      leftCount = measurer.getLeftCount();
    }

    printf("LeftMotorCount:: %d  count:: %d\n", measurer.getLeftCount(), leftCount);

    // 10ミリ秒待機
    controller.sleep();
  }

  while(measurer.getLeftCount() > leftCount) {
    if(measurer.getLeftCount() <= leftCount) break;
    controller.setLeftMotorPwm(-10);

    printf("LeftMotorCount:: %d  count:: %d\n", measurer.getLeftCount(), leftCount);
    controller.sleep();
  }

  printf("---------------------END");

  //モータの停止
  controller.stopMotor();
}

//設定された角度とPWM値で左タイヤを軸に後方へピボットターンする
void Rotation::turnBackLeftPivot(int angle, int pwm)
{
  double distance = -2 * M_PI * TREAD * angle / 360;  //弧の長さ

  //目標距離を超えるまでループ
  while(true) {
    double currentDistance = Mileage::calculateWheelMileage(measurer.getRightCount());
    double targetDistance = distance - currentDistance;

    if(currentDistance < distance) {
      break;
    }

    int rightPwm = (targetDistance / distance * pwm > PIVOT_MIN_PWM)
                       ? targetDistance / distance * pwm
                       : PIVOT_MIN_PWM;

    //モータのPWM値をセット
    controller.setRightMotorPwm(-rightPwm);
    controller.setLeftMotorPwm(0);

    printf("角度::%d | PWM:: %d\n", measurer.getRightCount(), rightPwm);

    // 10ミリ秒待機
    controller.sleep();
  }
  //モータの停止
  controller.stopMotor();
}