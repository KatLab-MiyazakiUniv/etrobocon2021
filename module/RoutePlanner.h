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
  RoutePlanner();

 private:
  BingoArea bingoArea;
  DestinationList destinationList;
  BlockSelector blockSelector;
};