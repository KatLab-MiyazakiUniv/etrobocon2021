/**
 * @file RoutePlanner.cpp
 * @brief 経路計画クラス
 * @author hiroto0927, miyashita64
 */

#include "RoutePlanner.h"

// コンストラクタ
RoutePlanner::RoutePlanner(BingoArea& _bingoArea, const bool IS_LEFT_COURSE)
  : bingoArea(_bingoArea), isLeftCourse(IS_LEFT_COURSE)
{
}

// 経路計画を立てる
void RoutePlanner::planBingoRoute()
{
  Robot robot(isLeftCourse);
  DestinationList destinationList(bingoArea);
  BlockSelector blockSelector(bingoArea, destinationList, robot);
  // 運搬するブロックを決定する
  BLOCK_ID targetBlock = blockSelector.selectBlock();

  // 経路計算
  // 現在地→運搬ブロック
  // 運搬ブロック→運搬先ブロックサークル

  // return 経路;
}
