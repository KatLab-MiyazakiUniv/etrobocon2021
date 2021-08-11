/**
 * @file BlockThrower.cpp
 * @brief 投げ入れ設置クラス
 * @author kodama0720, yutotanaka24
 */

#include "BlockThrower.h"

BlockThrower::BlockThrower() : BingoMotion(1, 1) {}

void BlockThrower::setBlockThrow(bool isClockwise)
{
  double targetDistance = 105;
  int runPwm = 20;
  int angle = 45;
  int rotatePwm = 20;

  //黒線の奥まで直進する
  straightRunner.runStraightToDistance(targetDistance, runPwm);
  //回頭する
  if(isClockwise) {
    rotation.rotateRight(angle, rotatePwm);
  } else {
    rotation.rotateLeft(angle, rotatePwm);
  }
  ArmMotion::throwMotion();
}
