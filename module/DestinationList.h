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
};

class BingoArea {
 public:
  static Block getBlockInfo(Coordinate coordinate) { return Block{ COLOR::RED }; }
};
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
  int getDestination(int blockNumber);

 private:
  static const int BLOCK_SIZE = 8;           // ブロックの数
  std::array<int, BLOCK_SIZE> destinations;  // 各ブロックの運搬先サークル番号

  /**
   * 指定したブロックとサークル間のマンハッタン距離を計算する
   * @param blockNumber ブロック番号
   * @param circleNumber サークル番号
   * @return マンハッタン距離(本)
   */
  int calculateDistance(int blockNumber, int circleNumber);

  /**
   * 指定番号のブロックの座標を返す
   * @param blockNumber ブロック番号
   * @return 座標
   */
  Coordinate convertBlockCoordinate(int blockNumber);

  /**
   * 指定番号のサークルの座標を返す
   * @param circleNumber サークル番号
   * @return 座標
   */
  Coordinate convertCircleCoordinate(int circleNumber);
};

#endif