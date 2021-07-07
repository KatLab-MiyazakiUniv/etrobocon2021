/**
 * @file ToCrossMotion.cpp
 * @brief 交点間移動のクラス
 * @author kodama0720, yutotanaka24
 */

#include "ToCrossMotion.h"

void ToCrossMotion::runToCross(void){
  int targetBrightness = 12;
  int pwm = 80;
  PidGain gain(3.5, 1, 1);
  bool isLeftEdge;

  //エッジの設定
  isLeftEdge = !IS_LEFT_COURSE;

  //LineTracerにエッジを与えてインスタンス化する
  LineTracer lineTracer(isLeftEdge);

  //白黒以外までライントレース
  lineTracer.runToColor(targetBrightness, pwm, gain);
}
