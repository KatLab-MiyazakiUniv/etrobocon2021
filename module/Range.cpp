/**
 *@file Range.cpp
 *@brief 区間情報
 *@author higuchi/miyashita
 */

#include "Range.h"
using std::string;

//区間名と距離の値を初期化
Range::Range(string _name, float _distance) : name(_name), distance(_distance)
{
  // 例外処理
  try {
    // _nameが空文字だった場合、Unexpected value errorエラー
    if(_name == "\0") throw "Unexpected value error.\n";
    // _distanceが負だった場合、Unexpected value errorエラー
    if(_distance <= 0) throw "Unexpected value error.\n";

  } catch(char* str) {
    std::cout << str;
  }
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