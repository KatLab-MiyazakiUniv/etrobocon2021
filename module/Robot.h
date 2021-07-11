/**
 * @file Robot.h
 * @brief ゲーム走行体クラス
 * @author hiroto0927, miyashita64
 */

#ifndef ROBOT_H
#define ROBOT_H

#include "ColorJudge.h"

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