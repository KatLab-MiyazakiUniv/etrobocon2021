/**
 * @file BlockSelector.h
 * @brief 運搬ブロック決定クラス
 * @author hiroto0927, miyashita64
 */

#ifndef BLOCK_SELECTOR_H
#define BLOCK_SELECTOR_H

#include "Robot.h"
#include <array>
#include "BingoAreaMock.h"
#include "DestinationList.h"
#define T true
#define F false

class BlockSelector {
 public:
  BlockSelector(BingoArea& bingoArea);

  /**
   * 運搬するブロックのIdを返す
   * @return ブロックのId
   */
  BlockId selectBlockId();

 private:
  /**
   * ブロックが運搬済みかを判定する
   * @return 運搬済み(true) | 未運搬(false)
   */
  bool isCarriedBlock(BlockNumber blockNumber);

  // 運搬可能ブロック
  std::array<bool, BLOCK_LENGTH> arrivableBlocks;
  // 到着可能サークル
  std::array<bool, CIRCLE_LENGTH> arrivableCircles;

  // ブロックがなくなった際、到着可能になるサークル
  static constexpr std::array<std::array<bool, CIRCLE_LENGTH>, BLOCK_LENGTH> OPEN_CIRCLE = { {
      { T, T, T, T, T, F, F, F, F },
      { F, T, T, F, F, T, F, F, F },
      { T, T, F, T, T, F, T, F, F },
      { T, T, T, T, T, T, F, T, T },
      { T, T, F, T, T, T, T, T, T },
      { F, F, T, F, T, T, F, T, T },
      { F, F, F, T, F, F, T, T, F },
      { F, F, F, F, T, T, T, T, T },
  } };

  // ブロックがなくなった際、運搬可能になるブロック
  static constexpr std::array<std::array<bool, BLOCK_LENGTH>, BLOCK_LENGTH> OPEN_BLOCK = { {
      { T, T, T, T, T, F, F, F },
      { T, T, F, T, F, T, F, F },
      { T, F, T, T, T, F, T, F },
      { T, T, T, T, T, T, F, T },
      { T, F, T, T, T, T, T, T },
      { F, T, F, T, T, T, F, T },
      { F, F, T, F, T, F, T, T },
      { F, F, F, T, T, T, T, T },
  } };

  BingoArea& bingoArea;
};
#endif