/**
 * @file Robot.cpp
 * @brief ゲーム走行体クラス
 * @author hiroto0927, miyashita64
 */

#include "Robot.h"

Robot::Robot(const bool IS_LEFT_COURSE)
  : coordinate({ 2, 3 }), direction(IS_LEFT_COURSE ? Direction::E : Direction::W){};

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
