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
  bool isLeftEdge = !IS_LEFT_COURSE;
  Rotation rotation;
  StraightRunner straightRunner;
  LineTracer lineTracer(isLeftEdge);
  Measurer measurer;
  Controller controller;
  //青の線までライントレース
  lineTracer.runToColor(TARGET_BRIGHTNESS, RUN_STRAIGHT_PWM - 40, PidGain(0.1, 0.8, 0.12));
  //青の線を通過
  lineTracer.run(140, TARGET_BRIGHTNESS, RUN_STRAIGHT_PWM - 30, PidGain(0.12, 0.8, 0.12));
  //青の線まで
  lineTracer.run(780, TARGET_BRIGHTNESS, RUN_CURVE_PWM, PidGain(0.4, 0.8, 0.2));
  //青の線を通過
  lineTracer.run(200, TARGET_BRIGHTNESS, RUN_STRAIGHT_PWM - 20, PidGain(0.16, 0.8, 0.15));
  //黄色の円まで
  lineTracer.run(200, TARGET_BRIGHTNESS, RUN_STRAIGHT_PWM - 20, PidGain(0.12, 0.8, 0.15));
  lineTracer.runToColor(TARGET_BRIGHTNESS, RUN_STRAIGHT_PWM - 40, PidGain(0.1, 0.8, 0.14));
  //黄色の円を通過
  straightRunner.runStraightToDistance(120, RUN_STRAIGHT_PWM - 30);
  //緑の円まで
  lineTracer.runToColor(TARGET_BRIGHTNESS, RUN_STRAIGHT_PWM - 40, PidGain(0.14, 1, 0.2));
  //９０度ピボットターン
  controller.sleep(300);
  IS_LEFT_COURSE ? rotation.turnForwardRightPivot(91, 33) : rotation.turnForwardLeftPivot(91, 33);
  //黒ブロック手前までライントレース
  lineTracer.run(85, TARGET_BRIGHTNESS, 20, PidGain(0.11, 0.8, 0.16));
  //センターマークの平行線上まで直進
  straightRunner.runStraightToDistance(100, RUN_STRAIGHT_PWM - 50);
  straightRunner.runStraightToDistance(100, RUN_STRAIGHT_PWM - 40);
  straightRunner.runStraightToDistance(230, RUN_STRAIGHT_PWM - 30);
  straightRunner.runStraightToDistance(75, RUN_STRAIGHT_PWM - 50);
  controller.sleep(100);
  // 90度ピボットターン
  IS_LEFT_COURSE ? rotation.turnForwardRightPivot(91, 33) : rotation.turnForwardLeftPivot(91, 33);
  controller.sleep(200);
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
  controller.sleep(200);
  straightRunner.runStraightToDistance(50, RUN_STRAIGHT_PWM - 60);
}