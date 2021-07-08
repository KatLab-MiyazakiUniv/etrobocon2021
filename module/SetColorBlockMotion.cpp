/**
 * @file SetColorBlockMotion.cpp
 * @brief カラーブロック設置クラス
 * @author kodama0720, yutotanaka24
 */

#include "SetColorBlockMotion.h"

void SetColorBlockMotion::throwBlock(bool isLeft){
  double targetDistance = 30;
  int pwm = 60;
  int angle = 30;
  straightRunner.runStraightToDistance(targetDistance, pwm);
  rotate.turnForwardRightPivot(int angle, int pwm);
}

void SetColorBlockMotion::setBlockPivotTurn(bool isLeft){
  double angle = 135;
  int angle
  rotate.turnForwardRightPivot(int angle, int pwm);
  
}