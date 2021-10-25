/**
 * @file ChangeDirection.cpp
 * @brief 方向転換クラス
 * @author kodama0720, yutotanaka24
 */

#include "DirectionChanger.h"

DirectionChanger::DirectionChanger(LineTracer& _lineTracer)
  : BingoMotion(0.88, 0.92), lineTracer(_lineTracer)
{
}

void DirectionChanger::changeDirection(int rotateAngle, int changeAngle)
{
  StraightRunner straightRunner;
  int rotatePwm = 30;
  int targetDistance = 10;
  int runPwm = 20;

  //回転方向を判定
  if(rotateAngle >= 0) {
    rotation.rotateRight(rotateAngle, rotatePwm);
  } else {
    rotation.rotateLeft(rotateAngle, rotatePwm);
  }

  //エッジ切り替え
  switch(changeAngle) {
    case 90:  // 右方向に方向転換する場合
      lineTracer.setIsLeftEdge(true);
      break;
    case -90:  // 左方向に方向転換する場合
      lineTracer.setIsLeftEdge(false);
      break;
    case 180:  // 後ろ方向に方向転換する場合
    case -180:
      lineTracer.toggleEdge();
      break;
  }

  //色サークルに乗るまで直進
  straightRunner.runStraightToDistance(targetDistance, runPwm);

  //白黒を判定するまで進む
  straightRunner.runStraightToBlackWhite(runPwm);
}
