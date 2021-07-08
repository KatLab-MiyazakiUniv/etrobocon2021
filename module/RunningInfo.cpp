/**
 * @file RunningInfo.cpp
 * @brief ゲーム走行体クラス
 * @author hiroto0927, miyashita64
 */

#include "RunningInfo.h"

//走行体の方向の初期化
Direction RunningInfo::direction = Direction::N;

//走行体の座標の初期化
Coordinate RunningInfo::coordinate = { 2, 3 };

void RunningInfo::setDirection(Direction direction){};

void RunningInfo::setCoordinate(Coordinate Coordinate){};

//走行体の進行方向を返す関数
Direction RunningInfo::getDirection()
{
  return direction;
}

//走行体の現在の座標を返す関数
Coordinate RunningInfo::getCoordinate()
{
  return coordinate;
}

/*
//シングルトン処理
RunningInfo::RunningInfo() {}
RunningInfo::RunningInfo(const RunningInfo& other) {}
RunningInfo& RunningInfo::operator=(const RunningInfo& other) {}

RunningInfo& RunningInfo::getInstance()
{
  static RunningInfo runninginfo;
  return runninginfo;
}
*/