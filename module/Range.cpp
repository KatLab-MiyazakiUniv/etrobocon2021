/**
 *@file Range.cpp
 *@brief 区間情報
 *@author higuchi/miyashita
 */

#include "Range.h"
using std::string;

//区間名と距離の値を初期化
Range::Range(string _name, float _distance)
  : name((_name != "\0") ? _name : "NO_EXIST"),
    distance((_name != "\0" && _distance > 0) ? _distance : 0.0f)
{
}

// 区間名を返す
string Range::getName() const
{
  return name;
}

// 区間の距離を返す
float Range::getDistance() const
{
  return distance;
}