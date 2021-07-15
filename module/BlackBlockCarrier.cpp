/**
 * @file BlackBlockCarrier.cpp
 * @brief 黒ブロックを取得してセンターマークまで運搬する
 * @author kodama0720, yutotanaka24
 */
#include "BlackBlockCarrier.h"

void BlackBlockCarrier::carryBlackBlock()
{
  constexpr int RUN_PWM = 50;
  constexpr int TARGET_BRIGHTNESS = 12;
  constexpr double CIRCLE_DISTANCE = 150.0;
  constexpr double FIRST_BLACK_DISTANCE = 420.0;
  constexpr double SECOND_BLACK_DISTANCE= 760.0;
  PidGain gain(4, 2, 2.2);
  PidGain rungain(1.5, 1, 1.5);
  Rotation rotation;
  StraightRunner straightrunner;
  LineTracer linetracer(false);
  //青の線を通過
  straightrunner.runStraightToDistance(280, RUN_PWM);
  //青の線まで
  linetracer.run(750, 12, RUN_PWM, gain);
  //青の線を通過
  straightrunner.runStraightToDistance(250, RUN_PWM);
  //黄色の円まで
  linetracer.runToColor(TARGET_BRIGHTNESS, 60, rungain);
  //黄色の円を通過
  straightrunner.runStraightToDistance(CIRCLE_DISTANCE, 60);
  //緑の円まで
  linetracer.runToColor(TARGET_BRIGHTNESS, 60, rungain);
  //緑の円の中心まで移動
  straightrunner.runStraightToDistance(60, 40);
  //右に９０度回頭
  rotation.rotateRight(90, 10);
  //黒線まで直進
  straightrunner.runStraightToDistance(70, 20);
  //黒ブロック手前まで直進
  linetracer.runToColor(TARGET_BRIGHTNESS, 30, rungain);
  //目標の奥行まで直進
  straightrunner.runStraightToDistance(FIRST_BLACK_DISTANCE, 45);
  //右に９０度ピボットターン
  rotation.turnForwardRightPivot(100, 40);
  //ビンゴの中心まで直進
  straightrunner.runStraightToDistance(SECOND_BLACK_DISTANCE, 30);
  //黒のラインまで下がる
  straightrunner.runStraightToDistance(100, -30);
}