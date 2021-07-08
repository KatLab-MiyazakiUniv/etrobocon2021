/**
 * @file ToCrossMotion.cpp
 * @brief 交点間移動のクラス
 * @author kodama0720, yutotanaka24
 */

#include "ToCrossMotion.h"

ToCrossMotion::ToCrossMotion(bool _isLeftEdge) : lineTracer(_isLeftEdge) {}

void ToCrossMotion::runToCross(void){
  int targetBrightness = 12;
  int pwm = 30;
  PidGain gain(3.5, 1, 1);

  //白黒以外までライントレース
  lineTracer.runToColor(targetBrightness, pwm, gain);
}
 