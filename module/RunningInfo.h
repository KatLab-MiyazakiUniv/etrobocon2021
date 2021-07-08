/**
 * @file RunningInfo.h
 * @brief ゲーム走行体クラス
 * @author hiroto0927, miyashita64
 */

#ifndef RUNNING_INFO_H
#define RUNNING_INFO_H

#include "ColorJudge.h"
/* // 実際
#include "BingoArea.h"
/*/ // テスト用仮環境
struct Coordinate {
  int x;
  int y;
};

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
// 仮環境終了
//*/

enum class Direction : int {
  SW = 0,
  S = 1,
  SE = 2,
  W = 3,
  E = 5,
  NW = 6,
  N = 7,
  NE = 8,
};

class RunningInfo {
 public:
  static void setDirection(Direction direction);
  static void setCoordinate(Coordinate coordinate);

  static Direction getDirection();
  static Coordinate getCoordinate();

 private:
  static Coordinate coordinate;
  static Direction direction;
  //コンストラクタ
  RunningInfo();
};

#endif