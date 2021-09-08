/**
 * @file ToCrossMotion.cpp
 * @brief 交点サークル間移動のクラス
 * @author kodama0720, yutotanaka24
 */
/**
 * @file ToCrossMotion.cpp
 * @brief 交点サークル間移動のクラス
 * @author kodama0720, yutotanaka24
 */

#include "ToCrossMotion.h"

ToCrossMotion::ToCrossMotion(LineTracer& _lineTracer) : BingoMotion(3, 3), lineTracer(_lineTracer)
{
}

void ToCrossMotion::runToCross(void)
{
  int targetBrightness = 20;
  int pwm = 35;
  PidGain gain(0.15, 1, 0.23);
  StraightRunner straightRunner;

  //白黒以外までライントレース
  lineTracer.runToColor(targetBrightness, pwm, gain);
}