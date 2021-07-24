/**
 * @file Robot.cpp
 * @brief ゲーム走行体クラス
 * @author hiroto0927, miyashita64
 */

#include "Robot.h"

void Robot::setDirection(Direction _direction)
{
  direction = _direction;
};

void Robot::setCoordinate(Coordinate _coordinate)
{
  coordinate.x = _coordinate.x;
  coordinate.y = _coordinate.y;
};

//走行体の進行方向を返す関数
Direction Robot::getDirection()
{
  return direction;
}

//走行体の現在の座標を返す関数
Coordinate Robot::getCoordinate()
{
  return coordinate;
}

//走行体の方向の初期化
Direction Robot::direction = Direction::N;
//走行体の座標の初期化
Coordinate Robot::coordinate = { 2, 3 };