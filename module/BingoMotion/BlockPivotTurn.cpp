/**
 * @file BlockPivotTurn.cpp
 * @brief ピボットターン設置クラス
 * @author kodama0720, yutotanaka24
 */

#include "BlockPivotTurn.h"

BlockPivotTurn::BlockPivotTurn() : BingoMotion(2.0, 1.48) {}

void BlockPivotTurn::setBlockPivotTurn(bool isClockwise)
{
  int runDistance = 86;  //最初に直進する距離
  int runPwm = 10;       //最初に直進する際のPwm値
  int rotateAngle = 44;  //回頭の角度
  int rotatePwm = 10;    //回頭のPwm値
  int backPwm = -15;     //位置調整用のPwm値

  LineTracer lineTracer(isClockwise);
  InCrossLeft inCrossLeft(lineTracer);
  InCrossRight inCrossRight(lineTracer);

  //ピボットターンする
  if(isClockwise) {
    straightRunner.runStraightToDistance(runDistance, runPwm);
    rotation.rotateRight(rotateAngle, rotatePwm);
    straightRunner.runStraightToDistance(20, 15);
    rotation.rotateRight(rotateAngle, rotatePwm);
    setBlockPivotThrow(isClockwise);
    straightRunner.runStraightToDistance(10, backPwm);
  } else {
    straightRunner.runStraightToDistance(86, runPwm);
    rotation.rotateLeft(rotateAngle, rotatePwm);
    straightRunner.runStraightToDistance(22, 15);
    rotation.rotateLeft(rotateAngle, rotatePwm);
    setBlockPivotThrow(isClockwise);
    straightRunner.runStraightToDistance(10, backPwm);
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
