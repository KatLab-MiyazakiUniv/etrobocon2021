/**
 * @file ToCrossMotion.cpp
 * @brief 交点サークル間移動のクラス
 * @author kodama0720, yutotanaka24
 */

#include "ToCrossMotion.h"

ToCrossMotion::ToCrossMotion(LineTracer& _lineTracer)
  : BingoMotion(1.02, 1.01), lineTracer(_lineTracer)
{
}

void ToCrossMotion::runToCross(void)
{
  int targetBrightness = 12;
  int pwm = 40;
  PidGain gain(1.0, 0.0, 0.23);
  StraightRunner straightRunner;

  //白黒以外までライントレース
  lineTracer.runToColor(targetBrightness, pwm, gain);
}
