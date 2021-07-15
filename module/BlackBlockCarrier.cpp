/**
 * @file BlackBlockCarrier.cpp
 * @brief 黒ブロックを取得してセンターマークまで運搬する
 * @author kodama0720, yutotanaka24
 */
#include "BlackBlockCarrier.h"

void BlackBlockCarrier::carryBlackBlock()
{
  constexpr int runPwm = 50;
  constexpr int targetBrightness = 12;
  constexpr double circleDistance = 150.0;
  constexpr double firstBlackDistance = 420.0;
  constexpr double secondBlackDistance = 760.0;
  PidGain gain(4, 2, 2.2);
  PidGain rungain(1.5, 1, 1.5);
  Rotation rotation;
  StraightRunner straightrunner;
  LineTracer linetracer(false);
  //青の線を通過
  straightrunner.runStraightToDistance(280, runPwm);
  //青の線まで
  linetracer.run(750, 12, runPwm, gain);
  //青の線を通過
  straightrunner.runStraightToDistance(250, runPwm);
  //黄色の円まで
  linetracer.runToColor(targetBrightness, 60, rungain);
  //黄色の円を通過
  straightrunner.runStraightToDistance(circleDistance, 60);
  //緑の円まで
  linetracer.runToColor(targetBrightness, 60, rungain);
  //緑の円の中心まで移動
  straightrunner.runStraightToDistance(60, 40);
  //右に９０度回頭
  rotation.rotateRight(90, 10);
  //黒線まで直進
  straightrunner.runStraightToDistance(70, 20);
  //黒ブロック手前まで直進
  linetracer.runToColor(targetBrightness, 30, rungain);
  //目標の奥行まで直進
  straightrunner.runStraightToDistance(firstBlackDistance, 45);
  //右に９０度ピボットターン
  rotation.turnForwardRightPivot(100, 40);
  //ビンゴの中心まで直進
  straightrunner.runStraightToDistance(secondBlackDistance, 30);
  //黒のラインまで下がる
  straightrunner.runStraightToDistance(100, -30);
}