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
  const PidGain BLUE_LINE_GAIN(0.2, 1, 0.5);
  const PidGain LAST_LINE_GAIN(0.1, 0.8, 0.14);
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
  lineTracer.runToColor(TARGET_BRIGHTNESS, RUN_STRAIGHT_PWM-30, RUN_GAIN);
  //右に９０度ピボットターン
  IS_LEFT_COURSE ? inCrossRight.runRight() : inCrossLeft.runLeft();
  //黒ブロック手前まで直進
  lineTracer.runToColor(TARGET_BRIGHTNESS, 30, LAST_LINE_GAIN);
  //弧を描いて曲がる
  double startDiff
      = IS_LEFT_COURSE
            ? Mileage::calculateWheelMileage(measurer.getLeftCount())
                  - Mileage::calculateWheelMileage(measurer.getRightCount())
            : Mileage::calculateWheelMileage(measurer.getRightCount())
                  - Mileage::calculateWheelMileage(measurer.getLeftCount());  //開始時の差
  while(IS_LEFT_COURSE ? Mileage::calculateWheelMileage(measurer.getRightCount()) + startDiff
                             >= Mileage::calculateWheelMileage(measurer.getLeftCount()) - 215
                       : Mileage::calculateWheelMileage(measurer.getLeftCount()) + startDiff
                             >= Mileage::calculateWheelMileage(measurer.getRightCount()) - 210) {
    //モータのPWM値をセット
    controller.setRightMotorPwm(IS_LEFT_COURSE ? 44 : 58);
    controller.setLeftMotorPwm(IS_LEFT_COURSE ? 57.5 : 41);
    controller.sleep();
  }
  controller.stopMotor();

  //ビンゴの中心まで直進
  straightRunner.runStraightToDistance(130, RUN_STRAIGHT_PWM - 20);
  straightRunner.runStraightToDistance(100, RUN_STRAIGHT_PWM - 60);
  //黒のラインまで下がる
  straightRunner.runStraightToDistance(68, -20);
}
