/**
 * @file BingoArea.cpp
 * @brief ビンゴエリアを攻略するクラス
 * @author Hisataka-Hagiyama,uchyam
 */

#include "BingoArea.h"

void BingoArea::runBingoArea()
{
  Controller controller;
  LineTracer lineTracer(IS_LEFT_COURSE);
  MotionPerformer motionPerformer(lineTracer);
  MotionConverter motionConverter(motionPerformer, IS_LEFT_COURSE);
  //黒ブロックを運搬する
  BlackBlockCarrier::carryBlackBlock();

  while(RoutePlanner::plannerFlag == false) {
    controller.sleep();
  }
  //運搬経路リストを動作に変換していく
  for(const auto& i : RoutePlanner::carryRoute) {
    motionConverter.convertToMotion(i);
  }
}
