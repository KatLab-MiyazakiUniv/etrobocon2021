/**
 * @file BlackBlockCarrier.cpp
 * @brief 黒ブロックを取得してセンターマークまで運搬する
 * @author kodama0720, yutotanaka24
 */
#include "BlackBlockCarrier.h"
/*
LineTracer::LineTracer(bool _isLeftEdge) : isLeftEdge(_isLeftEdge) {}
*/
void BlackBlockCarrier::carryBlackBlock()
{
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