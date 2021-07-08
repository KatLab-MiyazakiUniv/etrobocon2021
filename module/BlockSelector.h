/**
 * @file BlockSelector.h
 * @brief 運搬ブロック決定クラス
 * @author hiroto0927, miyashita64
 */

#ifndef BLOCK_SELECTOR_H
#define BLOCK_SELECTOR_H

#include "RunningInfo.h"
#include <array>

class BlockSelctor {
 public:
  BlockNumber selectBlockNumber();

 private:
  // 運搬可能ブロック
  std::array<bool, BLOCK_LENGTH> arrivableBlocks;
  // 到着可能サークル
  std::array<bool, CIRCLE_LENGTH> arrivableCircles;
  // 運搬済みブロック
  std::array<bool, BLOCK_LENGTH> carriedBlocks;

  // ブロックがなくなった際、到着可能になるサークル
  static constexpr std::array<std::array<bool, CIRCLE_LENGTH>, BLOCK_LENGTH> OPEN_CIRCLE = { {
      { true, true, true, true, true, false, false, false, false },
      { false, true, true, false, false, true, false, false, false },
      { true, true, false, true, true, false, true, false, false },
      { true, true, true, true, true, true, false, true, true },
      { true, true, false, true, true, true, true, true, true },
      { false, false, true, false, true, true, false, true, true },
      { false, false, false, true, false, false, true, true, false },
      { false, false, false, false, true, true, true, true, true },
  } };

  // ブロックがなくなった際、運搬可能になるブロック
  static constexpr std::array<std::array<bool, BLOCK_LENGTH>, BLOCK_LENGTH> OPEN_BLOCK = { {
      { true, true, true, true, true, false, false, false },
      { true, true, false, true, false, true, false, false },
      { true, false, true, true, true, false, true, false },
      { true, true, true, true, true, true, false, true },
      { true, false, true, true, true, true, true, true },
      { false, true, false, true, true, true, false, true },
      { false, false, true, false, true, false, true, true },
      { false, false, false, true, true, true, true, true },
  } };
};
#endif