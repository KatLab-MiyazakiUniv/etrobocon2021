/**
 * @file BlockThrower.cpp
 * @brief 投げ入れ設置クラス
 * @author kodama0720, yutotanaka24
 */

#include "BlockThrower.h"

BlockThrower::BlockThrower() : BingoMotion(1.17, 1.39), TREAD(140), MIN_PWM(10) {}

void BlockThrower::setBlockThrow(bool isClockwise)
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
  const double _TREAD = TREAD - 8;
  double targetDistance = M_PI * _TREAD * angle / 360;
  double targetLeftDistance;
  double targetRightDistance;
  int armPwm = 90;

  // printfすると、ブロックを投げずに旋回する挙動が起きなくなる？
  printf("Target:%lf\n", targetDistance);

  //黒線の奥まで直進する
  straightRunner.runStraightToDistance(runDistance, runPwm);
  // アームを水平にする処理を無効化
  ArmMotion::setKeepFlag(false);
  //回頭する
  targetLeftDistance
      = Mileage::calculateWheelMileage(measurer.getLeftCount()) + targetDistance * leftSign;
  targetRightDistance
      = Mileage::calculateWheelMileage(measurer.getRightCount()) + targetDistance * rightSign;
  // printfすると、ブロックを投げずに旋回する挙動が起きなくなる？
  printf("L:%lf R:%lf\n", targetLeftDistance, targetRightDistance);

  //両輪が目標距離に到達するまでループ
  while(leftSign != 0 || rightSign != 0) {
    // 残りの移動距離
    diffLeftDistance
        = (targetLeftDistance - Mileage::calculateWheelMileage(measurer.getLeftCount())) * leftSign;
    diffRightDistance
        = (targetRightDistance - Mileage::calculateWheelMileage(measurer.getRightCount()))
          * rightSign;

    // printfすると、ブロックを投げずに旋回する挙動が起きなくなる？
    // 出力文字数が多いと、投げ入れ距離が短くなる
    printf("T\n");

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

  // 反動を打ち消すため直進する
  straightRunner.runStraightToDistance(13.0, 20);

  //モータの停止
  controller.stopMotor();
}
