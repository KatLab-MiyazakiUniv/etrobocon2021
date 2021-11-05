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
  constexpr int BLUE_WHITE_BRIGHTNESS = 25;
  bool isLeftEdge = !IS_LEFT_COURSE;
  Rotation rotation;
  StraightRunner straightRunner;
  LineTracer lineTracer(isLeftEdge);
  Measurer measurer;
  Controller controller;
  //青の線までライントレース
  lineTracer.runToColor(TARGET_BRIGHTNESS, RUN_STRAIGHT_PWM, PidGain(0.1, 0.8, 0.12));
  //青の線を通過
  lineTracer.run(150, BLUE_WHITE_BRIGHTNESS, RUN_STRAIGHT_PWM, PidGain(0.12, 0.8, 0.12));
  //青の線まで
  lineTracer.run(770, TARGET_BRIGHTNESS, RUN_CURVE_PWM, PidGain(0.4, 0.8, 0.2));
  //青の線を通過
  lineTracer.run(150, BLUE_WHITE_BRIGHTNESS, RUN_STRAIGHT_PWM, PidGain(0.19, 0.8, 0.19));
  //黄色の円まで
  lineTracer.run(200, TARGET_BRIGHTNESS, RUN_STRAIGHT_PWM, PidGain(0.12, 0.8, 0.15));
  lineTracer.runToColor(TARGET_BRIGHTNESS, RUN_STRAIGHT_PWM - 20, PidGain(0.15, 0.8, 0.2));
  //黄色の円を通過
  straightRunner.runStraightToDistance(120, RUN_STRAIGHT_PWM - 20);
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

  // 黒ブロック取得後少し前進する
  straightRunner.runStraightToDistance(100, RUN_STRAIGHT_PWM - 50);
  // Lコースだと黒ブロック設置が下に寄りがちなので微調整
  const int tweak = IS_LEFT_COURSE ? 15 : 0;
  straightRunner.runStraightToDistance(130 + tweak, RUN_STRAIGHT_PWM - 40);
  //弧を描いて曲がる
  double startDiff
      = IS_LEFT_COURSE
            ? Mileage::calculateWheelMileage(measurer.getLeftCount())
                  - Mileage::calculateWheelMileage(measurer.getRightCount())
            : Mileage::calculateWheelMileage(measurer.getRightCount())
                  - Mileage::calculateWheelMileage(measurer.getLeftCount());  //開始時の差

  /*左右の移動距離の差が203mm（90度回転）になるまでループ*/
  while(IS_LEFT_COURSE ? Mileage::calculateWheelMileage(measurer.getRightCount()) + startDiff
                             >= Mileage::calculateWheelMileage(measurer.getLeftCount()) - 150
                       : Mileage::calculateWheelMileage(measurer.getLeftCount()) + startDiff
                             >= Mileage::calculateWheelMileage(measurer.getRightCount()) - 150) {
    //モータのPWM値をセット
    controller.setRightMotorPwm(IS_LEFT_COURSE ? 50 : 80);
    controller.setLeftMotorPwm(IS_LEFT_COURSE ? 80 : 50);
    controller.sleep();
  }
  //回転の誤差を抑えるために150mmから203mmの間、速度を抑える
  while(IS_LEFT_COURSE ? Mileage::calculateWheelMileage(measurer.getRightCount()) + startDiff
                             >= Mileage::calculateWheelMileage(measurer.getLeftCount()) - 203
                       : Mileage::calculateWheelMileage(measurer.getLeftCount()) + startDiff
                             >= Mileage::calculateWheelMileage(measurer.getRightCount()) - 203) {
    //モータのPWM値をセット
    controller.setRightMotorPwm(IS_LEFT_COURSE ? 30 : 50);
    controller.setLeftMotorPwm(IS_LEFT_COURSE ? 50 : 30);
    controller.sleep();
  }
  straightRunner.runStraightToDistance(150, RUN_STRAIGHT_PWM - 30);
  straightRunner.runStraightToColor(RUN_STRAIGHT_PWM - 30, COLOR::BLACK);
  straightRunner.runStraightToDistance(125, RUN_STRAIGHT_PWM - 50);
  //黒のラインまで下がる
  straightRunner.runStraightToDistance(40, -20);
}
