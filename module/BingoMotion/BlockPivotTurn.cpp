/**
 * @file BlockPivotTurn.cpp
 * @brief ピボットターン設置クラス
 * @author kodama0720, yutotanaka24
 */

#include "BlockPivotTurn.h"

BlockPivotTurn::BlockPivotTurn() : BingoMotion(2.0, 1.41) {}

void BlockPivotTurn::setBlockPivotTurn(bool isClockwise)
{
  int runDistance = 16;       //最初に直進する距離
  int runFirstPwm = 10;       //最初に直進する際のPwm値
  int pivotAngle = 45;        //ピボットターンの角度
  int pivotPwm = 40;          //ピボットターンのPwm値
  int rotateAngle = 85;       //回頭の角度
  int rotatePwm = 20;         //回頭のPwm値
  int forwardDistance = 100;  // 前進する距離
  int backDistance = 90;      //後退する距離
  int runPwm = 30;            //前進、後退する際のPwm値

  LineTracer lineTracer(isClockwise);
  InCrossLeft inCrossLeft(lineTracer);
  InCrossRight inCrossRight(lineTracer);

  //ピボットターンする
  if(isClockwise) {
    straightRunner.runStraightToDistance(runDistance, runFirstPwm);
    rotation.turnForwardRightPivot(pivotAngle, pivotPwm);
    rotation.rotateRight(rotateAngle - 5, rotatePwm);
    straightRunner.runStraightToDistance(forwardDistance, runPwm);
    straightRunner.runStraightToDistance(backDistance, -runPwm);
  } else {
    straightRunner.runStraightToDistance(runDistance, runPwm);
    rotation.turnForwardLeftPivot(pivotAngle, pivotAngle);  // pwm:20
    rotation.rotateLeft(rotateAngle - 5, rotatePwm);        // pwm:40
    straightRunner.runStraightToDistance(forwardDistance, runPwm);
    straightRunner.runStraightToDistance(backDistance, -runPwm);
  }
}