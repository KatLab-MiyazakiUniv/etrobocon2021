/**
 * @file DestinationList.h
 * @brief 運搬先決定クラス
 * @author hiroto0927, miyashita64
 */

#ifndef DESTINATION_LIST_H
#define DESTINATION_LIST_H

#include "array"
#include "ColorJudge.h"
#include "BingoArea.h"

class DestinationList {
 public:
  /**
   * コンストラクタ
   */
  DestinationList(BingoArea& _bingoArea);

  /**
   * 指定されたブロックの運搬先サークル番号を返す
   * @param blockNumber ブロック番号
   * @return 運搬先サークル番号
   */
  CircleNumber getDestination(BlockNumber blockNumber);

 private:
  std::array<CircleNumber, BlockNumber::BLOCK_LENGTH>
      destinations;  // 各ブロックの運搬先サークル番号

  /**
   * 指定したブロックとサークル間のマンハッタン距離を計算する
   * @param blockNumber ブロック番号
   * @param circleNumber サークル番号
   * @return マンハッタン距離(本)
   */
  int calculateDistance(BlockNumber blockNumber, CircleNumber circleNumber);

  BingoArea& bingoArea;
};

#endif