/**
 * @file Robot.h
 * @brief ゲーム走行体クラス
 * @author hiroto0927, miyashita64
 */

#ifndef ROBOT_H
#define ROBOT_H

#include "ColorJudge.h"
#include "BingoArea.h"

/*
|NW|N|NE|      |0|1|2|
| W| | E|  =>  |3|x|5|
|SW|S|SE|      |6|7|8|
*/
enum class Direction : int {
  N = 1,
  NE = 2,
  E = 5,
  SE = 8,
  S = 7,
  SW = 6,
  W = 3,
  NW = 0,
};

class Robot {
 public:
  //コンストラクタ
  Robot(bool const IS_LEFT_COURSE);

  /**
   * 走行体の向きの設定
   * @param direction 方向
   */
  void setDirection(Direction _direction);

  /**
   * 走行体の座標の設定
   * @param coordinate
   */
  void setCoordinate(Coordinate _coordinate);

  /**
   * 走行体の向きの取得
   * @return 方向
   */
  Direction getDirection();

  /**
   * 走行体の座標の取得
   * @return 座標
   */
  Coordinate getCoordinate();

 private:
  Coordinate coordinate;
  Direction direction;
};

#endif
