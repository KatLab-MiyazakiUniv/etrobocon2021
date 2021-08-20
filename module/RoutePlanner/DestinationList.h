/**
 * @file DestinationList.h
 * @brief 運搬先決定クラス
 * @author hiroto0927, miyashita64
 */

#ifndef DESTINATION_LIST_H
#define DESTINATION_LIST_H

#include "array"
#include "ColorJudge.h"
#include "CourseInfo.h"

class DestinationList {
 public:
  /**
   * コンストラクタ
   */
  DestinationList(CourseInfo& _courseInfo);

  /**
   * 指定されたブロックの運搬先サークルIDを返す
   * @param blockId ブロックID
   * @return 運搬先サークルID
   */
  CIRCLE_ID getDestination(BLOCK_ID blockId);

 private:
  // 各ブロックの運搬先サークルID
  std::array<CIRCLE_ID, static_cast<int>(BLOCK_ID::ID7) + 1> destinations;

  /**
   * 座標間のマンハッタン距離を計算する
   * @param blockCoord ブロックの座標
   * @param circleCoord サークルの座標
   * @return マンハッタン距離
   */
  int calculateDistance(Coordinate& blockCoord, Coordinate& circleCoord);
};

#endif