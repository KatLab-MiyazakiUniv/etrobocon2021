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
  const PidGain RUN_GAIN(0.1, 0.8, 0.15);  //直進のライントレースに使用するゲイン
  const PidGain BLUE_LINE_GAIN(0.2, 1, 0.5);  //青線上をライントレースする際に使用するゲイン
  const PidGain TO_GREEN_LINE_GAIN(0.2, 1, 0.3);  //緑の円までライントレースする際に使用するゲイン
  const PidGain LAST_LINE_GAIN(0.1, 0.1, 0.12);  //黒ブロックを取得するラインで使用するゲイン
  bool isLeftEdge = !IS_LEFT_COURSE;
  Rotation rotation;
  StraightRunner straightRunner;
  LineTracer lineTracer(isLeftEdge);
  Measurer measurer;
  Controller controller;
  InCrossLeft inCrossLeft(lineTracer);
  InCrossRight inCrossRight(lineTracer);
  ToCrossMotion toCrossMotion(lineTracer);

  //青の線を通過
  lineTracer.run(250, TARGET_BRIGHTNESS, RUN_STRAIGHT_PWM, BLUE_LINE_GAIN);
  //青の線まで
  lineTracer.run(650, TARGET_BRIGHTNESS, RUN_CURVE_PWM, CURVE_GAIN);
  //青の線を通過
  lineTracer.run(350, TARGET_BRIGHTNESS, RUN_STRAIGHT_PWM, BLUE_LINE_GAIN);
  //黄色の円まで
  lineTracer.runToColor(TARGET_BRIGHTNESS, RUN_STRAIGHT_PWM - 40, RUN_GAIN);
  //黄色の円を通過
  straightRunner.runStraightToDistance(120, RUN_STRAIGHT_PWM - 30);
  //緑の円まで
  lineTracer.runToColor(TARGET_BRIGHTNESS, RUN_STRAIGHT_PWM - 40, TO_GREEN_LINE_GAIN);
  //９０度ピボットターン
  straightRunner.runStraightToDistance(10, RUN_STRAIGHT_PWM - 50);
  IS_LEFT_COURSE ? rotation.turnForwardRightPivot(90, 33) : rotation.turnForwardLeftPivot(90, 33);
  //黒ブロック手前までライントレース
  lineTracer.run(85, TARGET_BRIGHTNESS, 20, LAST_LINE_GAIN);
  //センターマークの平行線上まで直進
  straightRunner.runStraightToDistance(100, RUN_STRAIGHT_PWM - 50);
  straightRunner.runStraightToDistance(100, RUN_STRAIGHT_PWM - 40);
  straightRunner.runStraightToDistance(270, RUN_STRAIGHT_PWM - 30);
  straightRunner.runStraightToDistance(75, RUN_STRAIGHT_PWM - 50);
  controller.sleep(500);
  // 90度ピボットターン
  IS_LEFT_COURSE ? rotation.turnForwardRightPivot(89, 33) : rotation.turnForwardLeftPivot(89, 33);
  //センターマークまで直進する(黒→青→青→黒の順に認識する)
  straightRunner.runStraightToDistance(70, RUN_STRAIGHT_PWM - 50);
  straightRunner.runStraightToColor(RUN_STRAIGHT_PWM - 40, COLOR::BLACK);
  straightRunner.runStraightToColor(RUN_STRAIGHT_PWM - 30, COLOR::BLUE);
  straightRunner.runStraightToColor(RUN_STRAIGHT_PWM - 30, COLOR::BLUE);
  straightRunner.runStraightToColor(RUN_STRAIGHT_PWM - 30, COLOR::BLACK);
  straightRunner.runStraightToDistance(135, RUN_STRAIGHT_PWM - 50);
  //タイヤの中心を黒線に合わせる
  controller.sleep(500);
  straightRunner.runStraightToColor(-20, COLOR::BLACK);
  straightRunner.runStraightToDistance(50, RUN_STRAIGHT_PWM - 60);
}
