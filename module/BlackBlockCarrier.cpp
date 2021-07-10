/**
 * @file BlackBlockCarrier.cpp
 * @brief 黒ブロックを取得してセンターマークまで運搬する
 * @author kodama0720, yutotanaka24
 */
#include "BlackBlockCarrier.h"

void BlackBlockCarrier::carryBlackBlock()
{
  bool _isLeftEdge;
  int runPwm = 50;
  int anglePwm = 40;
  int blackAngle = 90;
  int targetBrightness = 12;
  double circleDistance = 150.0;
  double firstBlackDistance = 450.0;
  double secondBlackDistance = 700.0;
  PidGain gain(1.2, 0.9, 0.9);
  PidGain rungain(0.5, 0.5, 0.5);
  Rotation rotation;
  StraightRunner straightrunner;
  LineTracer linetracer(true);

  //青の線を通過
  straightrunner.runStraightToDistance(300, runPwm);
  //青の線まで
  linetracer.runToColor(11, runPwm, gain);
  //青の線を通過
  straightrunner.runStraightToDistance(300, runPwm);
  //黄色の円まで
  linetracer.runToColor(targetBrightness, 60, rungain);
  //黄色の円を通過
  straightrunner.runStraightToDistance(circleDistance, 60);
  //緑の円まで
  linetracer.runToColor(targetBrightness, 60, rungain);
  //右に９０度ターン
  rotation.turnForwardRightPivot(blackAngle, anglePwm);
  //黒のラインまで直進
  straightrunner.runStraightToDistance(100, 60);
  //赤の円まで
  linetracer.runToColor(targetBrightness, 60, rungain);
  //目標の奥行まで直進
  straightrunner.runStraightToDistance(firstBlackDistance, 60);
  //右に９０度ターン
  rotation.turnForwardRightPivot(95, anglePwm);
  //ビンゴの中心まで直進
  straightrunner.runStraightToDistance(secondBlackDistance, 60);
}