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
  lineTracer.run(200, TARGET_BRIGHTNESS, RUN_STRAIGHT_PWM - 20, PidGain(0.19, 0.8, 0.19));
  //黄色の円まで
  lineTracer.run(200, TARGET_BRIGHTNESS, RUN_STRAIGHT_PWM - 20, PidGain(0.12, 0.8, 0.15));
  lineTracer.runToColor(TARGET_BRIGHTNESS, RUN_STRAIGHT_PWM - 40, PidGain(0.15, 0.8, 0.2));
  //黄色の円を通過
  straightRunner.runStraightToDistance(120, RUN_STRAIGHT_PWM - 30);
  //緑の円まで
  lineTracer.run(300, TARGET_BRIGHTNESS, RUN_STRAIGHT_PWM - 30, PidGain(0.12, 0.8, 0.2));
  lineTracer.run(100, TARGET_BRIGHTNESS, RUN_STRAIGHT_PWM - 45, PidGain(0.12, 0.8, 0.15));
  lineTracer.runToColor(TARGET_BRIGHTNESS, RUN_STRAIGHT_PWM - 60, PidGain(0.1, 1, 0.13));
  //９０度ピボットターン
  straightRunner.runStraightToDistance(15, RUN_STRAIGHT_PWM - 60);
  controller.sleep(500);
  IS_LEFT_COURSE ? rotation.turnForwardRightPivot(91, 33) : rotation.turnForwardLeftPivot(91, 33);
  //黒ブロック手前までライントレース
  lineTracer.run(85, TARGET_BRIGHTNESS, 20, PidGain(0.11, 0.1, 0.11));
  lineTracer.runToColor(TARGET_BRIGHTNESS, RUN_STRAIGHT_PWM - 60, PidGain(0.1, 1, 0.11));
  straightRunner.runStraightToDistance(100, RUN_STRAIGHT_PWM - 50);
  straightRunner.runStraightToDistance(130, RUN_STRAIGHT_PWM - 40);

  //弧を描いて曲がる
  double startDiff
      = IS_LEFT_COURSE
            ? Mileage::calculateWheelMileage(measurer.getLeftCount())
                  - Mileage::calculateWheelMileage(measurer.getRightCount())
            : Mileage::calculateWheelMileage(measurer.getRightCount())
                  - Mileage::calculateWheelMileage(measurer.getLeftCount());  //開始時の差
  while(IS_LEFT_COURSE ? Mileage::calculateWheelMileage(measurer.getRightCount()) + startDiff
                             >= Mileage::calculateWheelMileage(measurer.getLeftCount()) - 200
                       : Mileage::calculateWheelMileage(measurer.getLeftCount()) + startDiff
                             >= Mileage::calculateWheelMileage(measurer.getRightCount()) - 200) {
    //モータのPWM値をセット
    controller.setRightMotorPwm(IS_LEFT_COURSE ? 50 : 80);
    controller.setLeftMotorPwm(IS_LEFT_COURSE ? 80 : 50);
    controller.sleep();
  }
  straightRunner.runStraightToDistance(200, RUN_STRAIGHT_PWM - 30);
  straightRunner.runStraightToColor(RUN_STRAIGHT_PWM - 30, COLOR::BLACK);
  straightRunner.runStraightToDistance(135, RUN_STRAIGHT_PWM - 50);
  //黒のラインまで下がる
  straightRunner.runStraightToDistance(50, -20);
  /*
  lineTracer.runToColor(TARGET_BRIGHTNESS, RUN_STRAIGHT_PWM - 40, PidGain(0.1, 1, 0.13));
  straightRunner.runStraightToDistance(150, RUN_STRAIGHT_PWM - 30);
  lineTracer.run(100, TARGET_BRIGHTNESS, RUN_STRAIGHT_PWM - 40, PidGain(0.11, 0.1, 0.11));
  */
  /*
  //センターマークの平行線上まで直進
  straightRunner.runStraightToDistance(100, RUN_STRAIGHT_PWM - 50);
  straightRunner.runStraightToDistance(100, RUN_STRAIGHT_PWM - 40);
  straightRunner.runStraightToDistance(240, RUN_STRAIGHT_PWM - 30);
  straightRunner.runStraightToDistance(75, RUN_STRAIGHT_PWM - 50);
  controller.sleep(500);
  // 90度ピボットターン
  IS_LEFT_COURSE ? rotation.turnForwardRightPivot(90, 20) : rotation.turnForwardLeftPivot(90, 20);
  controller.sleep(300);
  //センターマークまで直進する(黒→青→青→黒の順に認識する)
  straightRunner.runStraightToDistance(25, RUN_STRAIGHT_PWM - 70);
  straightRunner.runStraightToDistance(25, RUN_STRAIGHT_PWM - 60);
  straightRunner.runStraightToDistance(20, RUN_STRAIGHT_PWM - 50);
  straightRunner.runStraightToColor(RUN_STRAIGHT_PWM - 40, COLOR::BLACK);
  straightRunner.runStraightToColor(RUN_STRAIGHT_PWM - 30, COLOR::BLUE);
  straightRunner.runStraightToColor(RUN_STRAIGHT_PWM - 30, COLOR::BLUE);
  straightRunner.runStraightToColor(RUN_STRAIGHT_PWM - 30, COLOR::BLACK);
  straightRunner.runStraightToDistance(135, RUN_STRAIGHT_PWM - 50);
  //タイヤの中心を黒線に合わせる
  controller.sleep(500);
  straightRunner.runStraightToColor(-20, COLOR::BLACK);
  controller.sleep(200);
  straightRunner.runStraightToDistance(35, RUN_STRAIGHT_PWM - 60);
  */
}