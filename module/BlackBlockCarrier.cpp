/**
 * @file BlackBlockCarrier.cpp
 * @brief 黒ブロックを取得してセンターマークまで運搬する
 * @author kodama0720, yutotanaka24
 */
#include "BlackBlockCarrier.h"

void BlackBlockCarrier::carryBlackBlock()
{
  bool _isLeftEdge;
  int runPwm = 100;
  int anglePwm = 60;
  int blackAngle = 90;
  int targetBrightness = 12;
  double circleDistance = 50.0;
  double firstBlackDistance = 200.0;
  double secondBlackDistance = 300.0;
  PidGain gain(3.0, 1, 1);
  Rotation rotation;
  StraightRunner straightrunner;
  LineTracer linetracer(false);

  //青の線まで
  linetracer.runToColor(targetBrightness, runPwm, gain);
  //青の線を通過
  straightrunner.runStraightToDistance(100, runPwm);
  //黄色の円まで
  linetracer.runToColor(targetBrightness, runPwm, gain);
  //黄色の円を通過
  straightrunner.runStraightToDistance(circleDistance, runPwm);
  //緑の円まで
  linetracer.runToColor(targetBrightness, runPwm, gain);
  //緑の中心まで
  straightrunner.runStraightToDistance((circleDistance / 2), runPwm);
  //右に９０度回頭
  rotation.rotateRight(blackAngle, anglePwm);
  //黒のラインまで直進
  straightrunner.runStraightToDistance((circleDistance / 2), runPwm);
  //赤の円まで
  linetracer.runToColor(targetBrightness, runPwm, gain);
  //赤の円を通過
  straightrunner.runStraightToDistance(circleDistance, runPwm);
  //目標の奥行まで直進
  straightrunner.runStraightToDistance(firstBlackDistance, runPwm);
  //右に９０度回頭
  rotation.rotateRight(blackAngle, anglePwm);
  //ビンゴの中心まで直進
  straightrunner.runStraightToDistance(secondBlackDistance, runPwm);
}