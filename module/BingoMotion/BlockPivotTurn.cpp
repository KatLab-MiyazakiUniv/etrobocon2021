/**
 * @file BlockPivotTurn.cpp
 * @brief ピボットターン設置クラス
 * @author kodama0720, yutotanaka24
 */

#include "BlockPivotTurn.h"

BlockPivotTurn::BlockPivotTurn() : BingoMotion(2, 2) {}

void BlockPivotTurn::setBlockPivotTurn(bool isClockwise)
{
  double targetDistance = 30;
  double runPwm = 30;
  double angle = 90;
  int rotatePwm = 100;
  int rotateAngle = 60;
  LineTracer lineTracer(isClockwise);
  StraightRunner straightRunner;
  InCrossLeft inCrossLeft(lineTracer);
  InCrossRight inCrossRight(lineTracer);

  
  //ピボットターンする
  if(isClockwise) {
    inCrossRight.runRight();
    blockThrower.setBlockPivotThrow(isClockwise);
    rotation.rotateLeft(44, 100);
    straightRunner.runStraightToColor(-10);
    straightRunner.runStraightToDistance(4, -10);
    rotation.rotateLeft(87.5, 100);
  } else {
    inCrossLeft.runLeft();
    blockThrower.setBlockPivotThrow(isClockwise);
    rotation.rotateRight(44, 100);
    straightRunner.runStraightToColor(-10);
    straightRunner.runStraightToDistance(4, -10);
    rotation.rotateRight(87.5, 100);
  }
}
