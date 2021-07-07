/**
 * @file DestinationList.h
 * @brief 運搬先決定クラス
 * @author hiroto0927, miyashita64
 */

#ifndef DESTINATION_LIST_H
#define DESTINATION_LIST_H

#include "array"
#include "ColorJudge.h"
/* // 本番環境
//#include "BingoArea.h"
/*/ // テスト環境
struct Coordinate {
  int x;  // x座標
  int y;  // y座標
};

struct Block {
  COLOR color;
  Coordinate coordinate;
};

// ブロック番号
enum class BlockNumber : int {
  B_0 = 0,
  B_1 = 1,
  B_2 = 2,
  B_3 = 3,
  B_4 = 4,
  B_5 = 5,
  B_6 = 6,
  B_7 = 7,
};
const int BLOCK_LENGTH = 8;

// ブロックサークル番号
enum class CircleNumber : int {
  C_0 = 0,
  C_1 = 1,
  C_2 = 2,
  C_3 = 3,
  C_4 = 4,
  C_5 = 5,
  C_6 = 6,
  C_7 = 7,
  C_8 = 8,
};
const int CIRCLE_LENGTH = 9;

class BingoArea {
 public:
  BingoArea()
    : blocks({ Block{ COLOR::RED, { 2, 0 } }, Block{ COLOR::RED, { 6, 0 } },
               Block{ COLOR::BLUE, { 0, 2 } }, Block{ COLOR::BLUE, { 4, 2 } },
               Block{ COLOR::YELLOW, { 2, 4 } }, Block{ COLOR::YELLOW, { 6, 4 } },
               Block{ COLOR::GREEN, { 0, 6 } }, Block{ COLOR::GREEN, { 4, 6 } } })
  {
  }
  Block getBlockInfo(BlockNumber blockNumber) { return blocks[static_cast<int>(blockNumber)]; }

 private:
  std::array<Block, BLOCK_LENGTH> blocks;
};
// 以上、テスト環境
//*/

class DestinationList {
 public:
  /**
   * コンストラクタ
   */
  DestinationList();

  /**
   * 指定されたブロックの運搬先サークル番号を返す
   * @param blockNumber ブロック番号
   * @return 運搬先サークル番号
   */
  CircleNumber getDestination(BlockNumber blockNumber);

 private:
  std::array<CircleNumber, BLOCK_LENGTH> destinations;  // 各ブロックの運搬先サークル番号

  /**
   * 指定したブロックとサークル間のマンハッタン距離を計算する
   * @param blockNumber ブロック番号
   * @param circleNumber サークル番号
   * @return マンハッタン距離(本)
   */
  int calculateDistance(BlockNumber blockNumber, CircleNumber circleNumber);

  // 以下、BingoAreaから取得するべき？
  /**
   * 指定番号のブロックの座標を返す
   * @param blockNumber ブロック番号
   * @return 座標
   */
  Coordinate convertBlockCoordinate(BlockNumber blockNumber);

  /**
   * 指定番号のサークルの座標を返す
   * @param circleNumber サークル番号
   * @return 座標
   */
  Coordinate convertCircleCoordinate(CircleNumber circleNumber);
  // 以上、BingoAreaから取得するべき？

  BingoArea bingoArea;  // コンストラクタで参照渡し or シングルトンにすべき？
};

#endif