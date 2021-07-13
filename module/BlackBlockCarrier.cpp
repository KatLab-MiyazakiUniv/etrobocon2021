/**
 * @file BlackBlockCarrier.cpp
 * @brief 黒ブロックを取得してセンターマークまで運搬する
 * @author kodama0720, yutotanaka24
 */
#include "BlackBlockCarrier.h"

void BlackBlockCarrier::carryBlackBlock()
{
  int runPwm = 55;
  int anglePwm = 10;
  int blackAngle = 82;
  int targetBrightness = 12;
  double circleDistance = 150.0;
  double firstBlackDistance = 710.0;
  double secondBlackDistance = 750.0;
  PidGain gain(2.5, 1.2, 1.5);
  PidGain rungain(1.5, 1, 1.3);
  Rotation rotation;
  StraightRunner straightrunner;
  LineTracer linetracer(false);
  //青の線を通過
  straightrunner.runStraightToDistance(310, runPwm);
  //青の線まで
  linetracer.runToColor(12, runPwm, gain);
  //青の線を通過
  straightrunner.runStraightToDistance(200, runPwm);
  //黄色の円まで
  linetracer.runToColor(targetBrightness, 60, rungain);
  //黄色の円を通過
  straightrunner.runStraightToDistance(circleDistance, 60);
  //緑の円まで
  linetracer.runToColor(targetBrightness, 60, rungain);
  //緑の円の中心まで移動
  straightrunner.runStraightToDistance(60, 30);
  //右に９０度回頭
  rotation.rotateRight(blackAngle, anglePwm);
  //目標の奥行まで直進
  straightrunner.runStraightToDistance(firstBlackDistance, 60);
  //右に９０度ピボットターン
  rotation.turnForwardRightPivot(90, 55);
  //ビンゴの中心まで直進
  straightrunner.runStraightToDistance(secondBlackDistance, 50);
  //黒のラインまで下がる
  straightrunner.runStraightToDistance(40, -40);
}