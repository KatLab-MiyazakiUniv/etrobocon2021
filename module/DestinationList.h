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
   * 指定されたブロックの運搬先サークルIDを返す
   * @param blockId ブロックID
   * @return 運搬先サークルID
   */
  CircleId getDestination(BlockId blockId);

 private:
  std::array<CircleId, static_cast<int>(BlockId::SIZE)>
      destinations;  // 各ブロックの運搬先サークルID

  /**
   * 指定したブロックとサークル間のマンハッタン距離を計算する
   * @param blockCoord ブロックの座標
   * @param circleCoord サークルの座標
   * @return マンハッタン距離
   */
  int calculateDistance(Coordinate& blockCoord, Coordinate& circleCoord);

  /**
   * 指定したサークルIDに対応する座標を返す
   * @param _circleId サークルID
   * @return サークルの座標
   */
  Coordinate convertCircleCoordinate(CircleId _circleId);
};

#endif