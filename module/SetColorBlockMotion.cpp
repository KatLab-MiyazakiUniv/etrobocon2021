/**
 * @file SetColorBlockMotion.cpp
 * @brief カラーブロック設置クラス
 * @author kodama0720, yutotanaka24
 */

#include "SetColorBlockMotion.h"

void SetColorBlockMotion::throwBlock(bool isLeft)
{
  double targetDistance = 60;
  int runPwm = 10;
  int angle = 55;
  int rotatePwm = 15;
  int upArmPwm = 100;
  int downArmPwm = -30;

  //直進する
  straightRunner.runStraightToDistance(targetDistance, runPwm);
  //ピボットターンする
  if(isLeft) {
    rotation.turnForwardLeftPivot(angle, rotatePwm);
  } else {
    rotation.turnForwardRightPivot(angle, rotatePwm);
  }
  //アームを上げる
  while(measurer.getArmMotorCount() < 40) {
    controller.setArmMotorPwm(upArmPwm);
    printf("%d\n", measurer.getArmMotorCount());
    controller.sleep();
  }
  //アームを戻す
  while(measurer.getArmMotorCount() > -40) {
    controller.setArmMotorPwm(downArmPwm);
    printf("%d\n", measurer.getArmMotorCount());
    controller.sleep();
  }
  controller.stopArmMotor();
  //元の位置に戻る
  if(isLeft) {
    rotation.turnBackLeftPivot(angle - 5, rotatePwm);
  } else {
    rotation.turnBackRightPivot(angle - 5, rotatePwm);
  }
  straightRunner.runStraightToDistance(targetDistance, -runPwm);
}

void SetColorBlockMotion::setBlockPivotTurn(bool isLeft)
{
  double angle = 200;
  int pwm = 30;
  //ピボットターンする
  if(isLeft) {
    rotation.turnForwardLeftPivot(angle, pwm);
    rotation.turnBackLeftPivot(angle - 10, pwm);
  } else {
    rotation.turnForwardRightPivot(angle, pwm);
    rotation.turnBackRightPivot(angle - 10, pwm);
  }
}
