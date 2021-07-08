/**
 * @file BlackBlockCarrier.h
 * @brief 黒ブロックを取得してセンターマークまで運搬する
 * @author kodama0720, yutotanaka24
 */

#ifndef BlackBlockCarrier_H
#define BlackBlockCarrier_H

#include "Controller.h"
#include "Rotation.h"
#include "LineTracer.h"
#include "StraightRunner.h"

class BlackBlockCarrier {
 public:
  void carryBlackBlock();

 private:
  bool isLeftEdge;
  Mileage mileage;
  Measurer measurer;
  Controller controller;
  Rotation rotation;
  LineTracer linetracer;
  StraightRunner straightrunner;
  static constexpr int runPwm = 100;
  static constexpr int anglePwm = 60;
  static constexpr int blackAngle = 90;
  static constexpr int targetBrightness = 12;
  static constexpr double circleDistance = 50.0;
  static constexpr double firstBlackDistance = 200.0;
  static constexpr double secondBlackDistance = 300.0;
  static const PidGain gain(3.0, 1, 1);
};
#endif