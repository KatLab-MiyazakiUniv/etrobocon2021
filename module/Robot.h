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
   * インスタンスを返す
   * @return Robotインスタンス
   */
  static Robot& getInstance();

  /**
   * 走行体の向きの設定
   * @param direction 方向
   */
  void setDirection(Direction direction);

  /**
   * 走行体の座標の設定
   * @param coordinate
   */
  void setCoordinate(Coordinate coordinate);

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
  // コンストラクタ
  Robot();
  // コピーコンストラクタ
  Robot(const Robot& other);
  // 代入演算子
  Robot& operator=(const Robot& other);

  Coordinate coordinate;
  Direction direction;
};

#endif