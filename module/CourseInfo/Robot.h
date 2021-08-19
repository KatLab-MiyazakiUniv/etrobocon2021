/**
 * @file Robot.h
 * @brief ゲーム走行体クラス
 * @author hiroto0927, miyashita64
 */

#ifndef ROBOT_H
#define ROBOT_H

#include "ColorJudge.h"
#include "CourseInfo.h"

enum class Direction : int {
  N = 0,
  NE = 1,
  E = 2,
  SE = 3,
  S = 4,
  SW = 5,
  W = 6,
  NW = 7,
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
