/**
 * @file BlockPivotTurn.cpp
 * @brief ピボットターン設置クラス
 * @author kodama0720, yutotanaka24
 */

#include "BlockPivotTurn.h"

BlockPivotTurn::BlockPivotTurn() : BingoMotion(2, 2) {}

void BlockPivotTurn::setBlockPivotTurn(bool isClockwise)
{
  double targetDistance = 105;
  double runPwm = 30;
  double angle = 180;
  int rotatePwm = 40;

  //黒線の奥まで直進する
  straightRunner.runStraightToDistance(targetDistance, runPwm);
  //ピボットターンする
  if(isClockwise) {
    rotation.turnForwardRightPivot(angle, rotatePwm);
    ArmMotion::throwMotion();
    rotation.turnBackRightPivot(angle, rotatePwm);
  } else {
    rotation.turnForwardLeftPivot(angle, rotatePwm);
    ArmMotion::throwMotion();
    rotation.turnBackLeftPivot(angle, rotatePwm);
  }
}
