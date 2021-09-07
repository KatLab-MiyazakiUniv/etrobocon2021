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
    straightRunner.runStraightToDistance(2, 40);

    inCrossRight.runRight();
    blockThrower.setBlockPivotThrow(isClockwise);
    rotation.rotateLeft(rotateAngle, rotatePwm);
    straightRunner.runStraightToColor(backPwm);
    straightRunner.runStraightToDistance(targetDistance, backPwm);
    rotation.rotateLeft(angle, rotatePwm);
  } else {
    straightRunner.runStraightToDistance(2, 40);
    inCrossLeft.runLeft();
    blockThrower.setBlockPivotThrow(isClockwise);
    rotation.rotateRight(rotateAngle, rotatePwm);
    straightRunner.runStraightToColor(backPwm);
    straightRunner.runStraightToDistance(targetDistance, backPwm);
    rotation.rotateRight(angle, rotatePwm);
  }
}
