/**
 * @file BlockPivotTurn.cpp
 * @brief ピボットターン設置クラス
 * @author kodama0720, yutotanaka24
 */

#include "BlockPivotTurn.h"
#include "Clock.h"

BlockPivotTurn::BlockPivotTurn() : BingoMotion(2.0, 1.41) {}

void BlockPivotTurn::setBlockPivotTurn(bool isClockwise)
{
  int runDistance = 40;      //最初に直進する距離
  int runFirstPwm = 10;      //最初に直進する際のPwm値
  int pivotAngle = 45;       //ピボットターンの角度
  int pivotPwm = 50;         //ピボットターンのPwm値50
  int rotateAngle = 90;      //回頭の角度
  int rotatePwm = 10;        //回頭のPwm値10
  int forwardDistance = 90;  // 前進する距離100
  int backDistance = 80;     //後退する距離90
  int runPwm = 30;           //前進、後退する際のPwm値

  LineTracer lineTracer(isClockwise);
  InCrossLeft inCrossLeft(lineTracer);
  InCrossRight inCrossRight(lineTracer);

  //ピボットターンする
  if(isClockwise) {
    straightRunner.runStraightToDistance(runDistance, runFirstPwm);
    rotation.turnForwardRightPivot(pivotAngle, pivotPwm);
    rotation.rotateRight(rotateAngle, rotatePwm);
    straightRunner.runStraightToDistance(forwardDistance, runPwm);
    straightRunner.runStraightToDistance(backDistance, -runPwm);
  } else {
    straightRunner.runStraightToDistance(runDistance, runPwm);
    rotation.turnForwardLeftPivot(pivotAngle, pivotAngle);
    rotation.rotateLeft(rotateAngle, rotatePwm);
    straightRunner.runStraightToDistance(forwardDistance, runPwm);
    straightRunner.runStraightToDistance(backDistance, -runPwm);
  }
}