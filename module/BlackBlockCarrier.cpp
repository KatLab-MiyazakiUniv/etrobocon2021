/**
 * @file BlackBlockCarrier.cpp
 * @brief 黒ブロックを取得してセンターマークまで運搬する
 * @author kodama0720, yutotanaka24
 */
#include "BlackBlockCarrier.h"

void BlackBlockCarrier::carryBlackBlock()
{
  constexpr int RUN_PWM = 50;
  constexpr int TARGET_BRIGHTNESS = 12;     //目標輝度
  const PidGain CURVE_GAIN(2, 0.2, 0.022);  //カーブのライントレースに使用するゲイン
  const PidGain RUN_GAIN(1.5, 0.1, 0.015);  //直進のライントレースに使用するゲイン
  Rotation rotation;
  StraightRunner straightrunner;
  LineTracer linetracer(false);

  //青の線を通過
  straightrunner.runStraightToDistance(280, RUN_PWM);
  //青の線まで
  linetracer.run(550, TARGET_BRIGHTNESS, RUN_PWM, CURVE_GAIN);
  linetracer.run(200, TARGET_BRIGHTNESS, RUN_PWM - 10, CURVE_GAIN);
  //青の線を通過
  straightrunner.runStraightToDistance(250, RUN_PWM - 10);
  // straightrunner.runStraightToBlackWhite(RUN_PWM - 10);
  //黄色の円まで
  linetracer.runToColor(TARGET_BRIGHTNESS, RUN_PWM + 10, RUN_GAIN);
  //黄色の円を通過
  straightrunner.runStraightToDistance(150, RUN_PWM + 10);
  //緑の円まで
  linetracer.runToColor(TARGET_BRIGHTNESS, RUN_PWM + 10, RUN_GAIN);
  //緑の円の中心まで移動
  straightrunner.runStraightToDistance(RUN_PWM, 40);
  //右に９０度回頭
  rotation.rotateRight(90, 10);
  //黒線まで直進
  straightrunner.runStraightToDistance(70, 20);
  //黒ブロック手前まで直進
  linetracer.runToColor(TARGET_BRIGHTNESS, 30, RUN_GAIN);
  //目標の奥行まで直進
  straightrunner.runStraightToDistance(420, RUN_PWM - 5);
  //右に９０度ピボットターン
  rotation.turnForwardRightPivot(100, 40);
  //ビンゴの中心まで直進
  straightrunner.runStraightToDistance(760, RUN_PWM - 20);
  //黒のラインまで下がる
  straightrunner.runStraightToDistance(100, -30);
}