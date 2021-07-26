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
  double currentRightDistance = 0;
  double targetDistance = M_PI * TREAD * abs(angle) / 360;  //弧の長さ
  //目標距離（呼び出し時の走行距離 ± 指定された回転量に必要な距離）
  double targetRightDistance
      = Mileage::calculateWheelMileage(measurer.getRightCount()) + targetDistance;
  int ratePwm;  // タイヤのモーターパワー(回頭角度に応じて減衰していく)
  double countRate;  //現在のタイヤの回転比率[0.0~1.0]
  double baseDistance = Mileage::calculateWheelMileage(measurer.getRightCount());

  //両輪が目標距離に到達するまでループ
  while(leftSign != 0 || rightSign != 0) {
    //現在の走行距離を取得
    currentRightDistance = Mileage::calculateWheelMileage(measurer.getRightCount());
    //目標距離に到達したらpwm値にかける値を0にする
    if(currentRightDistance >= targetRightDistance) {
      leftSign = 0;
      rightSign = 0;
    }
    //目標距離に近づくほどPWM値が下がる。（最低値が５）
    countRate = 1 - (currentRightDistance - baseDistance) / targetDistance;
    ratePwm = pwm * countRate > 5 ? (pwm * countRate) : 5;

    //モータのPWM値をセット
    controller.setLeftMotorPwm(abs(ratePwm) * leftSign);
    controller.setRightMotorPwm(abs(ratePwm) * rightSign);

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
  double targetDistance = M_PI * TREAD * abs(angle) / 360;  //弧の長さ
  //左右のタイヤの目標距離
  double targetLeftDistance
      = Mileage::calculateWheelMileage(measurer.getLeftCount()) + targetDistance;
  int ratePwm;  // タイヤのモーターパワー(回頭角度に応じて減衰していく)
  double countRate;  //現在のタイヤの回転比率[0.0~1.0]
  double baseDistance = Mileage::calculateWheelMileage(measurer.getLeftCount());

  //両輪が目標距離に到達するまでループ
  while(leftSign != 0 || rightSign != 0) {
    //現在の走行距離を取得
    currentLeftDistance = Mileage::calculateWheelMileage(measurer.getLeftCount());

    //目標距離に到達したらpwm値にかける値を0にする
    if(currentLeftDistance >= targetLeftDistance) {
      leftSign = 0;
      rightSign = 0;
    }

    countRate = 1 - (currentLeftDistance - baseDistance) / targetDistance;
    ratePwm = pwm * countRate > 5 ? (pwm * countRate) : 5;

    //モータのPWM値をセット
    controller.setLeftMotorPwm(abs(ratePwm) * leftSign);
    controller.setRightMotorPwm(abs(ratePwm) * rightSign);

    // 10ミリ秒待機
    controller.sleep();
  }
  //モータの停止
  controller.stopMotor();
}

//設定された角度とPWM値で右タイヤを軸に前方へピボットターンする
void Rotation::turnForwardRightPivot(int angle, int pwm)
{
  double distance = DIAMETER * M_PI * angle / 360;  //弧の長さ
  double targetDistance = Mileage::calculateWheelMileage(measurer.getLeftCount()) + distance;
  int leftPwm;  // タイヤのモーターパワー(回頭角度に応じて減衰していく)
  double leftCountRate;  //現在のタイヤの回転比率[0.0~1.0]
  double baseDistance = Mileage::calculateWheelMileage(measurer.getLeftCount());
  //目標距離を超えるまでループ
  while(true) {
    //現在の距離を取得
    double currentDistance = Mileage::calculateWheelMileage(measurer.getLeftCount());

    if(currentDistance >= targetDistance) {
      break;
    }

    leftCountRate = 1 - (currentDistance - baseDistance) / distance;
    leftPwm = pwm * leftCountRate > 15 ? (pwm * leftCountRate) : 15;

    //モータのPWM値をセット
    controller.setRightMotorPwm(0);
    controller.setLeftMotorPwm(leftPwm);

    // 10ミリ秒待機
    controller.sleep();
  }
  //モータの停止
  controller.stopMotor();
}

//設定された角度とPWM値で右タイヤを軸に後方へピボットターンする
void Rotation::turnBackRightPivot(int angle, int pwm)
{
  double distance = (DIAMETER - 5) * M_PI * angle / 360;  //弧の長さ
  double targetDistance = Mileage::calculateWheelMileage(measurer.getLeftCount()) - distance;
  int leftPwm;  // タイヤのモーターパワー(回頭角度に応じて減衰していく)
  double leftCountRate;  //現在のタイヤの回転比率[0.0~1.0]
  double baseDistance = Mileage::calculateWheelMileage(measurer.getLeftCount());
  //目標距離を超えるまでループ
  while(true) {
    double currentDistance = Mileage::calculateWheelMileage(measurer.getLeftCount());

    if(currentDistance <= targetDistance) {
      break;
    }

    leftCountRate = 1 - (baseDistance - currentDistance) / distance;
    leftPwm = pwm * leftCountRate > 10 ? (pwm * leftCountRate) : 10;

    //モータのPWM値をセット
    controller.setRightMotorPwm(0);
    controller.setLeftMotorPwm(-leftPwm);

    // 10ミリ秒待機
    controller.sleep();
  }
  //モータの停止
  controller.stopMotor();
}

//設定された角度とPWM値で左タイヤを軸に前方へピボットターンする
void Rotation::turnForwardLeftPivot(int angle, int pwm)
{
  double distance = DIAMETER * M_PI * angle / 360;  //弧の長さ
  double targetDistance = Mileage::calculateWheelMileage(measurer.getRightCount()) + distance;
  int rightPwm;  // タイヤのモーターパワー(回頭角度に応じて減衰していく)
  double rightCountRate;  //現在のタイヤの回転比率[0.0~1.0]
  double baseDistance = Mileage::calculateWheelMileage(measurer.getRightCount());
  //目標距離を超えるまでループ
  while(true) {
    double currentDistance = Mileage::calculateWheelMileage(measurer.getRightCount());

    if(currentDistance >= targetDistance) break;

    rightCountRate = 1 - (currentDistance - baseDistance) / distance;
    rightPwm = pwm * rightCountRate > 15 ? (pwm * rightCountRate) : 15;

    //モータのPWM値をセット
    controller.setRightMotorPwm(rightPwm);
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
  double distance = (DIAMETER - 5) * M_PI * angle / 360;  //弧の長さ
  double targetDistance = Mileage::calculateWheelMileage(measurer.getRightCount()) - distance;
  int rightPwm;  // タイヤのモーターパワー(回頭角度に応じて減衰していく)
  double rightCountRate;  //現在のタイヤの回転比率[0.0~1.0]
  double baseDistance = Mileage::calculateWheelMileage(measurer.getRightCount());
  //目標距離を超えるまでループ
  while(true) {
    double currentDistance = Mileage::calculateWheelMileage(measurer.getRightCount());

    if(currentDistance <= targetDistance) {
      break;
    }

    rightCountRate = 1 - (baseDistance - currentDistance) / distance;
    rightPwm = pwm * rightCountRate > 10 ? (pwm * rightCountRate) : 10;

    //モータのPWM値をセット
    controller.setRightMotorPwm(-rightPwm);
    controller.setLeftMotorPwm(0);

    // 10ミリ秒待機
    controller.sleep();
  }
  //モータの停止
  controller.stopMotor();
}