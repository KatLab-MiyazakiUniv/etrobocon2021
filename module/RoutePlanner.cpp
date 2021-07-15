/**
 * @file RoutePlanner.cpp
 * @brief 経路計画クラス
 * @author hiroto0927, miyashita64
 */

#include "RoutePlanner.h"

// コンストラクタ
RoutePlanner::RoutePlanner()
{
  for(int i = static_cast<int>(BLOCK_ID::ID0); i < static_cast<int>(BLOCK_ID::ID7) + 1; i++) {
    blockOrder[i] = blockSelector.selectBlock();
  }
}