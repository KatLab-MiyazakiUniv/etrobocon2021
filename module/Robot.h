/**
 * @file Robot.h
 * @brief ゲーム走行体クラス
 * @author hiroto0927, miyashita64
 */

#ifndef ROBOT_H
#define ROBOT_H

#include "ColorJudge.h"
/* // 実際
#include "BingoArea.h"
/*/ // テスト用仮環境

struct Coordinate {
  int x;
  int y;
};

enum class BlockId : int {
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

/*
|NW|N|NE|      |6|7|8|
| W| | E|  =>  |3|x|5|
|SW|S|SE|      |0|1|2|
*/
enum class Direction : int {
  N = 7,
  NE = 8,
  E = 5,
  SE = 2,
  S = 1,
  SW = 0,
  W = 3,
  NW = 6,
};

class Robot {
 public:
  /**
   * 走行体の向きの設定
   * @param direction 方向
   */
  static void setDirection(Direction direction);

  /**
   * 走行体の座標の設定
   * @param coordinate
   */
  static void setCoordinate(Coordinate coordinate);

  /**
   * 走行体の向きの取得
   * @return 方向
   */
  static Direction getDirection();

  /**
   * 走行体の座標の取得
   * @return 座標
   */
  static Coordinate getCoordinate();

  //コンストラクタ
  Robot();

 private:
  static Coordinate coordinate;
  static Direction direction;
};

#endif