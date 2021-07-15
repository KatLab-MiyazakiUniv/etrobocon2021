/**
 * @file RoutePlanner.h
 * @brief 経路計画クラス
 * @author hiroto0927, miyashita64
 */

#include "BingoArea.h"
#include "DestinationList.h"
#include "BlockSelector.h"

class RoutePlanner {
 public:
  /**
   * コンストラクタ
   */
  RoutePlanner();

 private:
  std::array<BLOCK_ID, static_cast<int>(BLOCK_ID::ID7) + 1> blockOrder;
  BingoArea bingoArea;
  DestinationList destinationList(BingoArea& bingoArea);
  BlockSelector blockSelector(BingoArea& bingoArea);
};