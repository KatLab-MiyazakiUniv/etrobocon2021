/**
 * @file RoutePlanner.cpp
 * @brief 経路計画クラス
 * @author hiroto0927, miyashita64
 */

#include "RoutePlanner.h"

// コンストラクタ
RoutePlanner::RoutePlanner(BingoArea& _bingoArea)
  : bingoArea(_bingoArea), destinationList(_bingoArea), blockSelector(_bingoArea, destinationList)
{
}

// 経路計画を立てる
void RoutePlanner::planBingoRoute()
{
  // 運搬するブロックを決定する
  BLOCK_ID targetBlock = blockSelector.selectBlock();

  // 経路計算
  // 現在地→運搬ブロック
  // 運搬ブロック→運搬先ブロックサークル

  // return 経路;
}