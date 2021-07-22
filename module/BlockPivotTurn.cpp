/**
 * @file BlockPivotTurn.cpp
 * @brief カラーブロック設置クラス
 * @author kodama0720, yutotanaka24
 */

#include "BlockPivotTurn.h"

void BlockPivotTurn::setBlockPivotTurn(bool isLeft)
{
  double targetDistance = 60;
  double runPwm = 30;
  double angle = 215;
  int rotatePwm = 30;
  int upArmPwm = 100;
  int downArmPwm = -30;

  //黒線の奥まで直進する
  straightRunner.runStraightToDistance(targetDistance, runPwm);
  //ピボットターンする
  if(isLeft) {
    rotation.turnForwardLeftPivot(angle, rotatePwm);
    //アームを上げる
    while(measurer.getArmMotorCount() < 40) {
      controller.setArmMotorPwm(upArmPwm);
      controller.sleep();
    }
    //アームを戻す
    while(measurer.getArmMotorCount() > 0) {
      controller.setArmMotorPwm(downArmPwm);
      controller.sleep();
    }
    controller.stopArmMotor();
    rotation.turnBackLeftPivot(angle - 10, rotatePwm);
  } else {
    rotation.turnForwardRightPivot(angle, rotatePwm);
    //アームを上げる
    while(measurer.getArmMotorCount() < 40) {
      controller.setArmMotorPwm(upArmPwm);
      controller.sleep();
    }
    //アームを戻す
    while(measurer.getArmMotorCount() > 0) {
      controller.setArmMotorPwm(downArmPwm);
      controller.sleep();
    }
    controller.stopArmMotor();
    rotation.turnBackRightPivot(angle - 10, rotatePwm);
  }
}
