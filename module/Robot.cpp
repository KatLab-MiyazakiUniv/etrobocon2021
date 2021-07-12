/**
 * @file Robot.cpp
 * @brief ゲーム走行体クラス
 * @author hiroto0927, miyashita64
 */

#include "Robot.h"
//コンストラクタ
Robot::Robot() : coordinate({ 2, 3 }), direction(Direction::N) {}
Robot::Robot(const Robot& other) {}
Robot& Robot::operator=(const Robot& other)
{
  return *this;
}

//インスタンスを返す
Robot& Robot::getInstance()
{
  static Robot robot;
  return robot;
}

void Robot::setDirection(Direction direction){};

void Robot::setCoordinate(Coordinate Coordinate){};

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