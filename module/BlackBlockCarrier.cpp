/**
 * @file BlackBlockCarrier.cpp
 * @brief 黒ブロックを取得してセンターマークまで運搬する
 * @author kodama0720, yutotanaka24
 */
#include "BlackBlockCarrier.h"

void BlackBlockCarrier::carryBlackBlock()
{
  constexpr int RUN_PWM = 50;
  constexpr int FIRST_ANGLE = 90;          //１回目のターンの角度
  constexpr int SECOND_ANGLE = 100;        // 2回目のターンの角度
  constexpr int FIRST_TURN_PWM = 10;       // 1回目のターンのPWM値
  constexpr int SECOND_TURN_PWM = 40;      // 2回目のターンのPWM値
  constexpr int TARGET_BRIGHTNESS = 12;    //目標輝度
  constexpr double BLUE_DISTANCE = 280.0;  //青色のライン上を通過する距離
  constexpr double CURBE_DISTANCE = 750.0;  //カーブを曲がる間ライントレースする距離
  constexpr double CIRCLE_DISTANCE = 150.0;  //円を通過する距離
  constexpr double GREEN_CIRCLE_DISTANCE = 40.0;  //緑の円に到着後円の中心に移動する距離
  constexpr double TO_BLACK_LINE = 70.0;  //回頭後、円の中心から黒のラインまで前進する距離
  constexpr int TO_BLACK_LINE_PWM = 20;  //回頭後、円の中心から黒のラインまで前進するPWM値
  constexpr int TO_BLACK_BLOCK_PWM = 30;  //緑円から黒ブロックまでのライントレース時のPWM値
  constexpr double Y_DISTANCE = 420.0;  //黒ブロックの初期位置から目的地までの縦の距離
  constexpr int Y_PWM = 45;
  constexpr double X_DISTANCE = 760.0;  //黒ブロックの初期位置から目的地までの横の距離
  constexpr int X_PWM = 30;
  constexpr double BACK_BLACK_LINE_DISTANCE = 100;  //黒ブロック運搬後黒のラインまで戻る距離
  constexpr int BACK_BLACK_LINE_PWM = -30;
  const PidGain GAIN(4, 2, 2.2);        //カーブのライントレースに使用するゲイン
  const PidGain RUN_GAIN(1.5, 1, 1.5);  //直進のライントレースに使用するゲイン
  Rotation rotation;
  StraightRunner straightrunner;
  LineTracer linetracer(false);

  //青の線を通過
  straightrunner.runStraightToDistance(BLUE_DISTANCE, RUN_PWM);
  //青の線まで
  linetracer.run(CURBE_DISTANCE, TARGET_BRIGHTNESS, RUN_PWM, GAIN);
  //青の線を通過
  straightrunner.runStraightToDistance(BLUE_DISTANCE, RUN_PWM);
  //黄色の円まで
  linetracer.runToColor(TARGET_BRIGHTNESS, RUN_PWM, RUN_GAIN);
  //黄色の円を通過
  straightrunner.runStraightToDistance(CIRCLE_DISTANCE, RUN_PWM);
  //緑の円まで
  linetracer.runToColor(TARGET_BRIGHTNESS, RUN_PWM, RUN_GAIN);
  //緑の円の中心まで移動
  straightrunner.runStraightToDistance(RUN_PWM, GREEN_CIRCLE_DISTANCE);
  //右に９０度回頭
  rotation.rotateRight(FIRST_ANGLE, FIRST_TURN_PWM);
  //黒線まで直進
  straightrunner.runStraightToDistance(TO_BLACK_LINE, TO_BLACK_LINE_PWM);
  //黒ブロック手前まで直進
  linetracer.runToColor(TARGET_BRIGHTNESS, TO_BLACK_BLOCK_PWM, RUN_GAIN);
  //目標の奥行まで直進
  straightrunner.runStraightToDistance(Y_DISTANCE, Y_PWM);
  //右に９０度ピボットターン
  rotation.turnForwardRightPivot(SECOND_ANGLE, SECOND_TURN_PWM);
  //ビンゴの中心まで直進
  straightrunner.runStraightToDistance(X_DISTANCE, X_PWM);
  //黒のラインまで下がる
  straightrunner.runStraightToDistance(BACK_BLACK_LINE_DISTANCE, BACK_BLACK_LINE_PWM);
}