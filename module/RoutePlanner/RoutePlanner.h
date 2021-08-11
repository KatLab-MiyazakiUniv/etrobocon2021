/**
 * @file RoutePlanner.h
 * @brief 経路計画クラス
 * @author hiroto0927, miyashita64
 */

#include "BingoArea.h"
#include "DestinationList.h"
#include "BlockSelector.h"
#include "RouteCalculator.h"

class RoutePlanner {
 public:
  /**
   * コンストラクタ
   */
  RoutePlanner(BingoArea& _bingoArea, const bool IS_LEFT_COURSE);

  /**
   * 1つのブロックを運搬するまでの経路を計画する
   */
  void planBingoRoute();

 private:
  BingoArea& bingoArea;
  bool isLeftCourse;
};