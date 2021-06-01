/**
 * @file CourseInfo.cpp
 * @brief コース情報
 * @author higuchi, miyashita
 */

#include "CourseInfo.h"
using std::string;

// コンストラクタ　目標とする輝度と、各区間の距離を設定する
CourseInfo::CourseInfo(int _brightness) : targetBrightness(_brightness)
{
  // 入力値が輝度の取りうる範囲外だった場合、50を目標の輝度とする
  if(_brightness < 0 || 100 < _brightness) {
    targetBrightness = 50;
    std::cout << "CourseInfo:期待しない値(" << _brightness << ")が入力されました。目標とする輝度を"
              << targetBrightness << "に設定します。\n";
  }
  // 各区間の距離配列を宣言
  static const std::array<float, 7> distancesArray
      = { 10.0f, 5.0f, 10.0f, 5.0f, 10.0f, 5.0f, 10.0f };
  // 配列のアドレスを保持
  distances = &distancesArray[0];
}

// コピーコンストラクタ
CourseInfo::CourseInfo(const CourseInfo& other)
  : targetBrightness(other.targetBrightness), distances(other.distances)
{
}

// 代入演算子
CourseInfo& CourseInfo::operator=(const CourseInfo& other)
{
  return *this;
}

// インスタンスを生成する
CourseInfo& CourseInfo::getInstance(int _brightness = -1)
{
  // 初期化時のみ、目標とする輝度をコンストラクタに渡す
  static CourseInfo info(_brightness);
  return info;
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

/*

int main()
{
  std::cout << CourseInfo::getInstance(10).getTargetBrightness() << "\n";
  std::cout << CourseInfo::getInstance().getTargetBrightness() << "\n";
  std::cout << CourseInfo::getInstance(20).getTargetBrightness() << "\n";
  std::cout << CourseInfo::getInstance().getCourseDistances()[1] << "\n";

  return 0;
}
//*/
