/**
 * @file BlockPivotTurn.cpp
 * @brief ピボットターン設置クラス
 * @author kodama0720, yutotanaka24
 */

#include "BlockPivotTurn.h"

BlockPivotTurn::BlockPivotTurn() : BingoMotion(2, 2) {}

void BlockPivotTurn::setBlockPivotTurn(bool isClockwise)
{
  double targetDistance = 4;
  double runPwm = 30;
  double angle = 93;
  int rotatePwm = 85;
  int rotateAngle = 45;
  int backPwm = -10;

  LineTracer lineTracer(isClockwise);
  InCrossLeft inCrossLeft(lineTracer);
  InCrossRight inCrossRight(lineTracer);

  //ピボットターンする
  if(isClockwise) {
    straightRunner.runStraightToDistance(86, 10);
    rotation.rotateRight(45, 10);
    straightRunner.runStraightToDistance(20, 15);
    rotation.rotateRight(45, 10);
    // straightRunner.runStraightToDistance(10, 15);
    setBlockPivotThrow(isClockwise);
    straightRunner.runStraightToDistance(20, -15);
  } else {
    straightRunner.runStraightToDistance(86, 10);
    rotation.rotateLeft(45, 10);
    straightRunner.runStraightToDistance(22, 15);
    rotation.rotateLeft(45, 10);
    // straightRunner.runStraightToDistance(20, 15);
    setBlockPivotThrow(isClockwise);
  }
}

void BlockPivotTurn::setBlockPivotThrow(bool isClockwise)
{
  double runDistance = 100;
  int runPwm = 30;
  int angle = 45;
  int rotatePwm = 100;
  int leftSign = isClockwise ? 1 : -1;
  int rightSign = isClockwise ? -1 : 1;
  double diffLeftDistance;
  double diffRightDistance;
  int leftPwm;
  int rightPwm;
  double targetDistance = M_PI * TREAD * angle / 360;
  double targetLeftDistance;
  double targetRightDistance;
  int armPwm = 70;

  // アームを水平にする処理を無効化
  ArmMotion::setKeepFlag(false);
  //回頭する
  targetLeftDistance
      = Mileage::calculateWheelMileage(measurer.getLeftCount()) + targetDistance * leftSign;
  targetRightDistance
      = Mileage::calculateWheelMileage(measurer.getRightCount()) + targetDistance * rightSign;

  //両輪が目標距離に到達するまでループ
  while(leftSign != 0 || rightSign != 0) {
    // 残りの移動距離
    diffLeftDistance
        = (targetLeftDistance - Mileage::calculateWheelMileage(measurer.getLeftCount())) * leftSign;
    diffRightDistance
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
    leftPwm = (diffLeftDistance / targetDistance * rotatePwm >= MIN_PWM)
                  ? diffLeftDistance / targetDistance * rotatePwm
                  : MIN_PWM;
    rightPwm = (diffRightDistance / targetDistance * rotatePwm >= MIN_PWM)
                   ? diffRightDistance / targetDistance * rotatePwm
                   : MIN_PWM;
    controller.setLeftMotorPwm(abs(leftPwm) * leftSign);
    controller.setRightMotorPwm(abs(rightPwm) * rightSign);

    //アームの動作
    if(measurer.getArmMotorCount() >= 40) {
      armPwm = 0;
    }
    controller.setArmMotorPwm(armPwm);

    // 10ミリ秒待機
    controller.sleep();
  }
  // アームを水平にする処理を有効化
  ArmMotion::setKeepFlag(true);

  //モータの停止
  controller.stopMotor();
}
