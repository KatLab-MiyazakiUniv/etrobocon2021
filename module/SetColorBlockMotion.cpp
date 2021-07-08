/**
 * @file SetColorBlockMotion.cpp
 * @brief カラーブロック設置クラス
 * @author kodama0720, yutotanaka24
 */

#include "SetColorBlockMotion.h"

void SetColorBlockMotion::throwBlock(bool isLeft)
{
  double targetDistance = 30;
  int runPwm = 30;
  int angle = 45;
  int rotatePwm = 30;
  int armPwm = 30;
  //直進する
  straightRunner.runStraightToDistance(targetDistance, runPwm);
  //ピボットターンする
  if(isLeft) {
    rotation.turnForwardRightPivot(angle, rotatePwm);
  } else {
    rotation.turnForwardLeftPivot(angle, rotatePwm);
  }
  //アームを上げる
  while(measurer.getArmMotorCount() <= 60) {
    controller.setArmMotorPwm(armPwm);
    controller.sleep();
  }
  //アームを戻す
  while(measurer.getArmMotorCount() >= 0) {
    controller.setArmMotorPwm(-armPwm);
    controller.sleep();
  }
}

void SetColorBlockMotion::setBlockPivotTurn(bool isLeft)
{
  double angle = 135;
  int pwm = 30;
  //前方にピボットターン
  rotation.turnForwardRightPivot(angle, pwm);
  //元の位置に戻る
  rotation.turnBackRightPivot(angle, pwm);
}