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
  constexpr int TARGET_BRIGHTNESS = 12;  //目標輝度
  const PidGain CURVE_GAIN(3, 1, 1);     //カーブのライントレースに使用するゲイン
  const PidGain RUN_GAIN(1, 0.8, 1);     //直進のライントレースに使用するゲイン
  const PidGain TO_FRONT_GAIN(0.2, 1, 1);
  bool isLeftEdge = !IS_LEFT_COURSE;
  Rotation rotation;
  StraightRunner straightRunner;
  LineTracer lineTracer(isLeftEdge);
  Measurer measurer;
  Controller controller;
  InCrossLeft inCrossLeft(lineTracer);
  InCrossRight inCrossRight(lineTracer);

  //青の線を通過
  lineTracer.run(250, 20, RUN_PWM, RUN_STRAIGHT_PWM);
  //青の線まで
  lineTracer.run(650, TARGET_BRIGHTNESS, RUN_CURVE_PWM, CURVE_GAIN);
  //青の線を通過
  lineTracer.run(350, 20, RUN_STRAIGHT_PWM, RUN_GAIN);
  //黄色の円まで
  lineTracer.runToColor(TARGET_BRIGHTNESS, RUN_STRAIGHT_PWM, RUN_GAIN);
  //黄色の円を通過
  straightRunner.runStraightToDistance(120, RUN_STRAIGHT_PWM);
  //緑の円まで
  lineTracer.runToColor(TARGET_BRIGHTNESS, RUN_STRAIGHT_PWM, RUN_GAIN);
  //緑の円の中心まで移動
  straightRunner.runStraightToDistance(RUN_STRAIGHT_PWM, 55);
  //右に９０度回頭
  rotation.rotateRight(90, 10);
  // // *曲がる
  // if(isLeftEdge) {
  //   inCrossLeft.runLeft();
  // } else {
  //   inCrossRight.runRight();
  // }
  //黒線まで直進
  straightRunner.runStraightToDistance(70, 20);
  //黒ブロック手前までライントレース
  straightRunner.runStraightToColor(30);
  // //目標の奥行まで直進
  // straightRunner.runStraightToDistance(420, RUN_PWM - 5);
  // controller.stopMotor();
  // controller.sleep(2000);
  // //右に９０度回頭
  // rotation.rotateRight(90, 10);
  //*弧を描いて曲がる
  double startDiff = Mileage::calculateWheelMileage(measurer.getLeftCount())
                     - Mileage::calculateWheelMileage(measurer.getRightCount());  //開始時の差
  while(Mileage::calculateWheelMileage(measurer.getRightCount()) + startDiff
        >= Mileage::calculateWheelMileage(measurer.getLeftCount()) - 220) {
    //モータのPWM値をセット
    controller.setRightMotorPwm(41);
    controller.setLeftMotorPwm(58);
    controller.sleep();
  }
  controller.stopMotor();

  //ビンゴの中心まで直進
  straightRunner.runStraightToDistance(400, RUN_STRAIGHT_PWM - 20);
  //黒のラインまで下がる
  straightRunner.runStraightToDistance(85, -20);

  //ビンゴの中心まで直進
  // straightRunner.runStraightToDistance(760, RUN_PWM - 20);
  //黒のラインまで下がる
  // straightRunner.runStraightToDistance(100, -30);
}
