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
  int runDistance = 40;        //最初に直進する距離
  int runFirstPwm = 10;        //最初に直進する際のPwm値
  int rotateFirstAngle = 10;   //最初に回頭する角度
  int rotateFirstPwm = 10;     //最初に回頭するPwm
  int pivotAngle = 50;         //ピボットターンの角度
  int pivotPwm = 40;           //ピボットターンのPwm値
  int rotateSecondAngle = 88;  //二回目の回頭の角度
  int rotateSecondPwm = 10;    //二回目の回頭のPwm値
  int forwardDistance = 90;    //前進する距離
  int backDistance = 115;      //後退する距離
  int runPwm = 30;             //前進、後退する際のPwm値

  LineTracer lineTracer(isClockwise);
  InCrossLeft inCrossLeft(lineTracer);
  InCrossRight inCrossRight(lineTracer);

  //ピボットターンする
  if(isClockwise) {
    straightRunner.runStraightToDistance(runDistance, runFirstPwm);
    rotation.rotateRight(rotateFirstAngle, rotateFirstPwm);
    rotation.turnForwardRightPivot(pivotAngle - 2, pivotPwm);
    controller.sleep();
    rotation.rotateRight(rotateSecondAngle - 20, rotateSecondPwm - 2);
    straightRunner.runStraightToDistance(forwardDistance, runPwm);
    straightRunner.runStraightToDistance(backDistance, -(runPwm - 10));
  } else {
    straightRunner.runStraightToDistance(runDistance, runPwm);
    rotation.rotateRight(rotateFirstAngle, rotateFirstPwm);
    rotation.turnForwardLeftPivot(pivotAngle, pivotAngle);
    rotation.rotateLeft(rotateSecondAngle - 10, rotateSecondPwm);
    straightRunner.runStraightToDistance(forwardDistance, runPwm);
    straightRunner.runStraightToDistance(backDistance, -(runPwm - 10));
  }
  controller.sleep(500);
}