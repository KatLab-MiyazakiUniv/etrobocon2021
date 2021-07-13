/**
 * @file ToCrossMotion.cpp
 * @brief 交点サークル間移動のクラス
 * @author kodama0720, yutotanaka24
 */

#include "ToCrossMotion.h"

ToCrossMotion::ToCrossMotion(LineTracer& _lineTracer) : lineTracer(_lineTracer) {}

void ToCrossMotion::runToCross(void)
{
  int targetBrightness = 12;
  int pwm = 30;
  PidGain gain(3.5, 1, 1);
  StraightRunner straightRunner;

  //白黒以外までライントレース
  lineTracer.runToColor(targetBrightness, pwm, gain);
}
