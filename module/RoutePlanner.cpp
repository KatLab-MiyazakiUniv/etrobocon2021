/**
 * @file RoutePlanner.cpp
 * @brief 経路計画クラス
 * @author hiroto0927, miyashita64
 */

#include "RoutePlanner.h"

RoutePlanner::RoutePlanner()
{
  bingoArea = BingoArea();
  destinationList = DestinationList(bingoArea);
  blockSelector = BlockSelector(bingoArea, destinationList);
}