/**
 * @file ToCrossMotion.cpp
 * @brief 交点間移動のクラス
 * @author kodama0720, yutotanaka24
 */

#include "ToCrossMotion.h"

ToCrossMotion::ToCrossMotion(LineTracer& _lineTracer) : BingoMotion(3, 3), lineTracer(_lineTracer)
{
}

void ToCrossMotion::runToCross(void)
{
  int targetBrightness = 12;
  int pwm = 40;
  PidGain gain(2, 1, 1);
  StraightRunner straightRunner;

  //白黒以外までライントレース
  lineTracer.runToColor(targetBrightness, pwm, gain);
}
