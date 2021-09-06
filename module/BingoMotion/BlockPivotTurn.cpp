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
  double angle = 87.5;
  int rotatePwm = 100;
  int rotateAngle = 44;
  int backPwm = -10;

  LineTracer lineTracer(isClockwise);
  InCrossLeft inCrossLeft(lineTracer);
  InCrossRight inCrossRight(lineTracer);

  //ピボットターンする
  if(isClockwise) {
    inCrossRight.runRight();
    blockThrower.setBlockPivotThrow(isClockwise);
    rotation.rotateLeft(rotateAngle, rotatePwm);
    straightRunner.runStraightToColor(backPwm);
    straightRunner.runStraightToDistance(targetDistance, backPwm);
    rotation.rotateLeft(angle, rotatePwm);
  } else {
    inCrossLeft.runLeft();
    blockThrower.setBlockPivotThrow(isClockwise);
    rotation.rotateRight(rotateAngle, rotatePwm);
    straightRunner.runStraightToColor(backPwm);
    straightRunner.runStraightToDistance(targetDistance, backPwm);
    rotation.rotateRight(angle, rotatePwm);
  }
}
