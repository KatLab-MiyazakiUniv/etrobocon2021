/**
 * @file Robot.cpp
 * @brief ゲーム走行体クラス
 * @author hiroto0927, miyashita64
 */

#include "Robot.h"
//コンストラクタ
Robot::Robot() {}

//走行体の方向の初期化
Direction Robot::direction = Direction::N;

//走行体の座標の初期化
Coordinate Robot::coordinate = { 2, 3 };

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

/*
//シングルトン処理
Robot::Robot() {}
Robot::Robot(const Robot& other) {}
Robot& Robot::operator=(const Robot& other) {}

Robot& Robot::getInstance()
{
  static Robot runninginfo;
  return runninginfo;
}
*/