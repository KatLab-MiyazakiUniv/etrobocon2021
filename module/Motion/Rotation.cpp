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
  int leftPwm = pwm;
  int rightPwm = -1;

  // const double _TREAD = TREAD + 5;  //トレッド幅の調整
  double motorCount = 0;
  double targetMotorCount = calculate(angle);
  int rightCount = measurer.getRightCount();
  int leftCount = measurer.getLeftCount();

  while(motorCount < targetMotorCount) {
    double leftCountRate = 1 - (measurer.getLeftCount() - leftCount) / targetMotorCount;
    leftPwm = pwm * leftCountRate > PIVOT_FRONT_MIN_PWM ? (int)(pwm * leftCountRate)
                                                        : PIVOT_FRONT_MIN_PWM;

    controller.setLeftMotorPwm(leftPwm);
    controller.setRightMotorPwm(rightPwm);
    controller.sleep();

    motorCount
        = ((measurer.getLeftCount() - leftCount) + (measurer.getRightCount() - rightCount)) / 2;

    controller.sleep();
  }

  controller.stopMotor();
}

//設定された角度とPWM値で右タイヤを軸に後方へピボットターンする
void Rotation::turnBackRightPivot(int angle, int pwm)
{
  angle = abs(angle);
  int leftPwm = pwm;
  int rightPwm = 1;

  double motorCount = 0;
  double targetMotorCount = calculate(angle);
  int rightCount = abs(measurer.getRightCount());
  int leftCount = abs(measurer.getLeftCount());

  while(motorCount < targetMotorCount) {
    double leftCountRate = 1 - (leftCount - abs(measurer.getLeftCount())) / targetMotorCount;
    leftPwm = pwm * leftCountRate > PIVOT_FRONT_MIN_PWM ? (int)(pwm * leftCountRate)
                                                        : PIVOT_FRONT_MIN_PWM;

    controller.setLeftMotorPwm(-leftPwm);
    controller.setRightMotorPwm(rightPwm);
    controller.sleep();

    motorCount = ((leftCount - abs(measurer.getLeftCount()))
                  + (rightCount - abs(measurer.getRightCount())))
                 / 2;

    controller.sleep();
  }

  controller.stopMotor();
}

//設定された角度とPWM値で左タイヤを軸に前方へピボットターンする
void Rotation::turnForwardLeftPivot(int angle, int pwm)
{
  int leftPwm = -1;
  int rightPwm = pwm;

  double motorCount = 0;
  double targetMotorCount = calculate(angle);
  int rightCount = measurer.getRightCount();
  int leftCount = measurer.getLeftCount();

  while(motorCount < targetMotorCount) {
    double rightCountRate = 1 - (measurer.getRightCount() - rightCount) / targetMotorCount;
    rightPwm = pwm * rightCountRate > PIVOT_FRONT_MIN_PWM ? (int)(pwm * rightCountRate)
                                                          : PIVOT_FRONT_MIN_PWM;

    controller.setLeftMotorPwm(leftPwm);
    controller.setRightMotorPwm(rightPwm);
    controller.sleep();

    motorCount
        = ((measurer.getLeftCount() - leftCount) + (measurer.getRightCount() - rightCount)) / 2;

    controller.sleep();
  }

  controller.stopMotor();
}

//設定された角度とPWM値で左タイヤを軸に後方へピボットターンする
void Rotation::turnBackLeftPivot(int angle, int pwm)
{
  angle = abs(angle);
  int leftPwm = 1;
  int rightPwm = pwm;

  double motorCount = 0;
  double targetMotorCount = calculate(angle);
  int rightCount = abs(measurer.getRightCount());
  int leftCount = abs(measurer.getLeftCount());

  while(motorCount < targetMotorCount) {
    //徐々に速度を遅くする処理
    double rightCountRate = 1 - (rightCount - abs(measurer.getRightCount())) / targetMotorCount;
    rightPwm = pwm * rightCountRate > PIVOT_FRONT_MIN_PWM ? (int)(pwm * rightCountRate)
                                                          : PIVOT_FRONT_MIN_PWM;

    controller.setLeftMotorPwm(leftPwm);
    controller.setRightMotorPwm(-rightPwm);
    controller.sleep();

    motorCount = ((leftCount - abs(measurer.getLeftCount()))
                  + (rightCount - abs(measurer.getRightCount())))
                 / 2;

    controller.sleep();
  }

  controller.stopMotor();
}

double Rotation::calculate(int angle)
{
  // @see docs/Odometry/odometry.pdf
  const double transform = 2.0 * RADIUS / TREAD;
  return angle / transform;
}