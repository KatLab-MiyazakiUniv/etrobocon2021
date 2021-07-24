/**
 * @file ChangeDirection.cpp
 * @brief 方向転換クラス
 * @author kodama0720, yutotanaka24
 */

#include "DirectionChanger.h"

DirectionChanger::DirectionChanger(LineTracer& _lineTracer) : lineTracer(_lineTracer) {}

void DirectionChanger::changeDirection(int angle, bool isLeft)
{
  StraightRunner straightRunner;
  int rotatePwm = 30;
  int targetDistance = 30;
  int runPwm = 20;

  //回転方向を判定
  if(angle >= 0) {
    rotation.rotateRight(angle, rotatePwm);
  } else {
    rotation.rotateLeft(angle, rotatePwm);
  }

  //エッジ切り替え
  if(lineTracer.getIsLeftEdge()) {
    if((isLeft && angle == -45) || (!isLeft && angle == 135) || angle == -135 || angle == -90 || angle == 180) {
      lineTracer.setIsLeftEdge(false);
    }
  } else {
    if((isLeft && angle == -135) || (!isLeft && angle == 45) || angle == 135 || angle == 90 || angle == 180) { 
      lineTracer.setIsLeftEdge(true);
    }
  }

  //色サークルに乗るまで直進
  straightRunner.runStraightToDistance(targetDistance, runPwm);

  //白黒を判定するまで進む
  // straightRunner.runStraightToBlackWhite(runPwm);
}
