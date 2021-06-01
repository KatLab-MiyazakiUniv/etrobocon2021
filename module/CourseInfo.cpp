/**
 * @file CourseInfo.cpp
 * @brief コース情報
 * @author higuchi, miyashita
 */

#include "CourseInfo.h"
using std::string;

// 目標とする輝度と、各区間の名前と距離を設定する
CourseInfo::CourseInfo(int _brightness)
  : targetBrightness(_brightness), distances{ 10.0f, 5.0f, 10.0f, 5.0f, 10.0f, 5.0f, 10.0f }
{
  // 入力値が輝度の取りうる範囲外だった場合、50を目標の輝度とする
  if(_brightness < 0 || 100 < _brightness) {
    targetBrightness = 50;
    std::cout << "CourseInfo:期待しない値(" << _brightness << ")が入力されました。目標とする輝度を"
              << targetBrightness << "に設定します。\n";
  }
}

// 目標とする輝度を返す
int CourseInfo::getTargetBrightness()
{
  return targetBrightness;
}

// 各区間の距離配列のポインタを返す
const float* CourseInfo::getCourseDistances()
{
  return distances;
}
