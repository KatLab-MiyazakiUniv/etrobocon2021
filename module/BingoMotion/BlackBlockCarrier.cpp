/**
 * @file BlackBlockCarrier.cpp
 * @brief 黒ブロックを取得してセンターマークまで運搬する
 * @author kodama0720, yutotanaka24
 */
#include "BlackBlockCarrier.h"

void BlackBlockCarrier::carryBlackBlock()
{
  constexpr int RUN_STRAIGHT_PWM = 80;
  constexpr int RUN_CURVE_PWM = 50;
  constexpr int TARGET_BRIGHTNESS = 20;  //目標輝度
  const PidGain CURVE_GAIN(3, 1, 1);     //カーブのライントレースに使用するゲイン
  const PidGain RUN_GAIN(0.1, 0.8, 0.15);     //直進のライントレースに使用するゲイン
  const PidGain BLUE_LINE_GAIN(0.2, 1, 0.5);  //青線上をライントレースする際に使用するゲイン
  const PidGain GAIN(0.2, 1, 0.3);  //青線上をライントレースする際に使用するゲイン
  const PidGain LAST_LINE_GAIN(0.12, 0.1, 0.12); //黒ブロックを取得するラインで使用するゲイン
  bool isLeftEdge = !IS_LEFT_COURSE;
  Rotation rotation;
  StraightRunner straightRunner;
  LineTracer lineTracer(isLeftEdge);
  Measurer measurer;
  Controller controller;
  InCrossLeft inCrossLeft(lineTracer);
  InCrossRight inCrossRight(lineTracer);

  //青の線を通過
  lineTracer.run(250, TARGET_BRIGHTNESS, RUN_STRAIGHT_PWM, BLUE_LINE_GAIN);
  //青の線まで
  lineTracer.run(650, TARGET_BRIGHTNESS, RUN_CURVE_PWM, CURVE_GAIN);
  //青の線を通過
  lineTracer.run(350, TARGET_BRIGHTNESS, RUN_STRAIGHT_PWM, BLUE_LINE_GAIN);
  //黄色の円まで
  lineTracer.runToColor(TARGET_BRIGHTNESS, RUN_STRAIGHT_PWM-40, RUN_GAIN);
  //黄色の円を通過
  straightRunner.runStraightToDistance(120, RUN_STRAIGHT_PWM-30);
  //緑の円まで
  lineTracer.runToColor(TARGET_BRIGHTNESS, RUN_STRAIGHT_PWM-40, GAIN);
  //９０度ピボットターン
  IS_LEFT_COURSE ? rotation.turnForwardRightPivot(92, 33) : rotation.turnForwardLeftPivot(92, 33);;
  //黒ブロック手前まで直進
  lineTracer.run(65, 20, 20, LAST_LINE_GAIN);
  //センターマークの平行線上まで直進
 straightRunner.runStraightToDistance(475, RUN_STRAIGHT_PWM-30);
 straightRunner.runStraightToDistance(75, RUN_STRAIGHT_PWM-50);
  //90度ピボットターン
  IS_LEFT_COURSE ? rotation.turnForwardRightPivot(88,33) : rotation.turnForwardLeftPivot(88,33);
  //センターマークまで直進する
 straightRunner.runStraightToDistance(490, RUN_STRAIGHT_PWM-30);
 straightRunner.runStraightToDistance(200, RUN_STRAIGHT_PWM-50);
 controller.stopMotor();

 //タイヤの中心を黒線に合わせる
 straightRunner.runStraightToDistance(40, -20);
}
