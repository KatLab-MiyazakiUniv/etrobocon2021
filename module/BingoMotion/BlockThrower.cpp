/**
 * @file BlockThrower.cpp
 * @brief 投げ入れ設置クラス
 * @author kodama0720, yutotanaka24
 */

#include "BlockThrower.h"

BlockThrower::BlockThrower() : BingoMotion(1, 1) {}

void BlockThrower::setBlockThrow(bool isClockwise)
{
  double runDistance = 105;
  int runPwm = 30;
  int angle = 45;
  int rotatePwm = 55;
  int leftSign;
  int rightSign;
  double currentLeftDistance = 0;
  double currentRightDistance = 0;
  double targetDistance = M_PI * 140 * angle / 360;
  double targetLeftDistance;
  double targetRightDistance;
  int armPwm = 80;

  //黒線の奥まで直進する
  straightRunner.runStraightToDistance(runDistance, runPwm);
  // アームを水平にする処理を無効化
  ArmMotion::setKeepFlag(false);
  //回頭する
  if(isClockwise) {
    leftSign = 1;
    rightSign = -1;
    targetLeftDistance = Mileage::calculateWheelMileage(measurer.getLeftCount()) + targetDistance;
    targetRightDistance = Mileage::calculateWheelMileage(measurer.getRightCount()) - targetDistance;

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
      controller.setLeftMotorPwm(rotatePwm * leftSign);
      controller.setRightMotorPwm(rotatePwm * rightSign);

      //アームを動かす
      while(measurer.getArmMotorCount() >= 40) {
        armPwm = 0;
      }
      controller.setArmMotorPwm(armPwm);

      // 10ミリ秒待機
      controller.sleep();
    }
  } else {
    leftSign = -1;
    rightSign = 1;
    targetLeftDistance = Mileage::calculateWheelMileage(measurer.getLeftCount()) - targetDistance;
    targetRightDistance = Mileage::calculateWheelMileage(measurer.getRightCount()) + targetDistance;

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
      controller.setLeftMotorPwm(rotatePwm * leftSign);
      controller.setRightMotorPwm(rotatePwm * rightSign);

      //アームを動かす
      while(measurer.getArmMotorCount() >= 40) {
        armPwm = 0;
      }
      controller.setArmMotorPwm(armPwm);

      // 10ミリ秒待機
      controller.sleep();
    }
  }
  // アームを水平にする処理を有効化
  ArmMotion::setKeepFlag(true);
  //モータの停止
  controller.stopMotor();
}
