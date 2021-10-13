/**
 * @file BlockPivotTurn.cpp
 * @brief ピボットターン設置クラス
 * @author kodama0720, yutotanaka24
 */

#include "BlockPivotTurn.h"

BlockPivotTurn::BlockPivotTurn() : BingoMotion(100, 100) {}

void BlockPivotTurn::setBlockPivotTurn(bool isClockwise)
{
  int runDistance = 86;  //最初に直進する距離
  int runPwm = 10;       //最初に直進する際のPwm値
  int rotateAngle = 44;  //回頭の角度
  int rotatePwm = 100;    //回頭のPwm値
  int backPwm = -15;     //位置調整用のPwm値

  LineTracer lineTracer(isClockwise);
  InCrossLeft inCrossLeft(lineTracer);
  InCrossRight inCrossRight(lineTracer);

  //ピボットターンする
  if(isClockwise) {
    straightRunner.runStraightToDistance(16, runPwm);
    rotation.turnForwardRightPivot(50, 30);
    rotation.rotateRight(75, 100);
    straightRunner.runStraightToDistance(150, 50);
    straightRunner.runStraightToDistance(145, -50);
  } else {
    straightRunner.runStraightToDistance(16, runPwm);
    rotation.turnForwardLeftPivot(45, rotatePwm);
    rotation.rotateLeft(80, rotatePwm);
    straightRunner.runStraightToDistance(150, 50);
    straightRunner.runStraightToDistance(145, -50);
  }
}