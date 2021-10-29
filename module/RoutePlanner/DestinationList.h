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

  /**
   * 指定されたブロックのもう１つの運搬先サークルIDを返す
   * @param blockId ブロックID
   * @return もう１つの運搬先サークルID
   */
  CIRCLE_ID getDestinationAlt(BLOCK_ID blockId);

  /**
   * ブロックの運搬先を、もう１つの同じ色のブロックの運搬先と入れ替える
   * @param blockId ブロックID
   */
  void swapDestination(BLOCK_ID blockId);

 private:
  // 各ブロックの運搬先サークルID(BLOCK0~7について、決定した運搬先ともう１つの運搬先の2つを保持)
  std::array<std::array<CIRCLE_ID, 2>, static_cast<int>(BLOCK_ID::ID7) + 1> destinations;

  /**
   * 座標間のマンハッタン距離を計算する
   * @param blockCoord ブロックの座標
   * @param circleCoord サークルの座標
   * @return マンハッタン距離
   */
  int calculateDistance(Coordinate& blockCoord, Coordinate& circleCoord);
};

#endif
