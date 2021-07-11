/**
 * @file BlockSelector.h
 * @brief 運搬ブロック決定クラス
 * @author hiroto0927, miyashita64
 */

#ifndef BLOCK_SELECTOR_H
#define BLOCK_SELECTOR_H

#define T true
#define F false

#include <array>
#include "BingoAreaMock.h"
#include "DestinationList.h"
#include "Robot.h"

class BlockSelector {
 public:
  /**
   * コンストラクタ
   */
  BlockSelector(BingoArea& _bingoArea);

  /**
   * 運搬するブロックのIdを返す
   * @return ブロックのId
   */
  BLOCK_ID selectBlock();

 private:
  BingoArea& bingoArea;
  DestinationList destinationList;

  // 運搬可能ブロック
  std::array<bool, static_cast<int>(BLOCK_ID::SIZE)> arrivableBlocks;
  // 到着可能サークル
  std::array<bool, static_cast<int>(CIRCLE_ID::SIZE)> arrivableCircles;

  // ブロックがなくなった際、到着可能になるサークル
  std::array<std::array<bool, static_cast<int>(CIRCLE_ID::SIZE)>, static_cast<int>(BLOCK_ID::SIZE)>
      OPEN_CIRCLE_ID;

  // ブロックがなくなった際、運搬可能になるブロック
  std::array<std::array<bool, static_cast<int>(BLOCK_ID::SIZE)>, static_cast<int>(BLOCK_ID::SIZE)>
      OPEN_BLOCK_ID;

  /**
   * ブロックが運搬済みかを判定する
   * @return 運搬済み(true) | 未運搬(false)
   */
  bool isCarriedBlock(BLOCK_ID blockNumber);
};

#endif