/**
 *@file CourseInfo.cpp
 *@brief コース情報
 *@author higuchi/miyashita
 */

#include "CourseInfo.h"
using std::string;

// 目標とする輝度と、各区間の名前と距離を設定する
CourseInfo::CourseInfo(int _brightness)
  : brightness(_brightness), ranges{ Range("ST_1", 10.0f), Range("CV_1", 5.0f),
                                     Range("ST_2", 10.0f), Range("CV_2", 5.0f),
                                     Range("ST_3", 10.0f), Range("CV_3", 5.0f),
                                     Range("ST_4", 10.0f) }
{
  // 入力値が輝度の取りうる範囲外だった場合、128を目標の輝度とする
  if(_brightness < 0 || 256 <= _brightness) {
    brightness = 128;
    std::cout << "CourseInfo:期待しない値(" << _brightness << ")が入力されました。目標とする輝度を"
              << brightness << "に設定します。\n";
  }
}

// 目標とする輝度を返す
int CourseInfo::getBrightness()
{
  return brightness;
}

// 区間番号を受けて当該区間の区間名を返す
string CourseInfo::getRangeNameById(int _id)
{
  // 引数が負、もしくは配列長以上の値だった場合、空文字を返す
  int len = sizeof(ranges) / sizeof(ranges[0]);
  if(_id < 0 || len <= _id) {
    std::cout << "CourseInfo:該当する区間は存在しません。\n";
    std::string str = "\0";
    return str;
  }

  // 区間名を返す
  return ranges[_id].getName();
}

// 区間番号を受けて当該区間の距離を返す
float CourseInfo::getRangeDistanceById(int _id)
{
  // 引数が負、もしくは配列長以上の値だった場合、0を返す
  int len = sizeof(ranges) / sizeof(ranges[0]);
  if(_id < 0 || len <= _id) {
    std::cout << "CourseInfo:該当する区間は存在しません。\n";
    return 0;
  }

  // 区間の距離を返す
  return ranges[_id].getDistance();
}

float CourseInfo::getRangeDistanceByName(std::string _name)
{
  int id;
  int len = sizeof(ranges) / sizeof(ranges[0]);
  int i;

  // 名前が一致する区間を探索
  for(i = 0; i < len; i++) {
    // 発見時はidを保持し、探索終了
    if(ranges[i].getName() == _name) {
      id = i;
      break;
    }
  }

  // 名前が一致する区間が見つからなかった場合、0を返す
  if(i == len) {
    std::cout << "CourseInfo:該当する区間は存在しません。\n";
    return 0;
  }

  // 区間の距離を返す
  return ranges[id].getDistance();
}