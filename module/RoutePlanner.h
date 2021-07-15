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
   * ブロックビンゴエリアでの経路を計画する
   */
  static void planFullBingoRoute();

 private:
  // ブロックの運搬順
  std::array<BLOCK_ID, static_cast<int>(BLOCK_ID::ID7) + 1> blockOrder;

  /**
   * コンストラクタ
   * インスタンス化を禁止するためにprivateにし、処理については記述していない
   */
  RoutePlanner();
};