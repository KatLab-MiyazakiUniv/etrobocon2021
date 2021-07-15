/**
 * @file RoutePlanner.cpp
 * @brief 経路計画クラス
 * @author hiroto0927, miyashita64
 */

#include "RoutePlanner.h"

// 経路計画を立てる
void RoutePlanner::planFullBingoRoute()
{
  BingoArea bingoArea;
  DestinationList destinationList(bingoArea);
  BlockSelector blockSelector(bingoArea, destinationList);

  // ブロックの運搬順を取得する
  std::array<BLOCK_ID, static_cast<int>(BLOCK_ID::ID7) + 1> blockOrder;
  for(int i = static_cast<int>(BLOCK_ID::ID0); i < static_cast<int>(BLOCK_ID::ID7) + 1; i++) {
    blockOrder[i] = blockSelector.selectBlock();
  }
}