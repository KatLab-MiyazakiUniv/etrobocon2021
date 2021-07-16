/**
 * @file BlockSelector.h
 * @brief 運搬ブロック決定クラス
 * @author hiroto0927, miyashita64
 */

#ifndef BLOCK_SELECTOR_H
#define BLOCK_SELECTOR_H

#include <array>
#include "BingoArea.h"
#include "DestinationList.h"
#include "Robot.h"

const bool T = true;
const bool F = false;

class BlockSelector {
 public:
  /**
   * コンストラクタ
   */
  BlockSelector(BingoArea& _bingoArea, DestinationList& _destinationList);

  /**
   * 運搬するブロックのIdを返す
   * @return ブロックのId
   */
  BLOCK_ID selectBlock();

 private:
  BingoArea& bingoArea;
  DestinationList destinationList;

  // 走行体が運びうるブロック
  std::array<bool, static_cast<int>(BLOCK_ID::ID7) + 1> arrivableBlocks;
  // 走行体がブロックを運びうるサークル
  std::array<bool, static_cast<int>(CIRCLE_ID::ID7) + 1> arrivableCircles;

  // ブロックがなくなった際、到着可能になるサークル
  const std::array<std::array<bool, static_cast<int>(CIRCLE_ID::ID7) + 1>,
                   static_cast<int>(BLOCK_ID::ID7) + 1>
      // ブロックが運搬された際に開放されるブロックサークル
      OPEN_CIRCLE_ID = { {
          { T, T, T, T, F, F, F, F },
          { F, T, T, F, T, F, F, F },
          { T, T, F, T, F, T, F, F },
          { T, T, T, T, T, F, T, T },
          { T, T, F, T, T, T, T, T },
          { F, F, T, F, T, F, T, T },
          { F, F, F, T, F, T, T, F },
          { F, F, F, F, T, T, T, T },
      } };
  // ブロックが運搬された際に開放されるブロック
  const std::array<std::array<bool, static_cast<int>(BLOCK_ID::ID7) + 1>,
                   static_cast<int>(BLOCK_ID::ID7) + 1>
      // ブロックが運搬された際に開放されるブロック
      OPEN_BLOCK_ID = { {
          { T, T, T, T, T, F, F, F },
          { T, T, F, T, F, T, F, F },
          { T, F, T, T, T, F, T, F },
          { T, T, T, T, T, T, F, T },
          { T, F, T, T, T, T, T, T },
          { F, T, F, T, T, T, F, T },
          { F, F, T, F, T, F, T, T },
          { F, F, F, T, T, T, T, T },
      } };

  /**
   * ブロックが運搬済みかを判定する
   * @return 運搬済み(true) | 未運搬(false)
   */
  bool isCarriedBlock(BLOCK_ID blockId);
};

#endif