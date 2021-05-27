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
  // 例外処理
  try {
    // _brightnessが負だった場合、Unexpected value errorエラー
    if(_brightness < 0 || 256 <= _brightness) throw "Unexpected value error.\n";
  } catch(char* str) {
    std::cout << str;
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
  // 例外処理
  try {
    int len = sizeof(ranges) / sizeof(ranges[0]);

    // 引数が負、もしくは配列長以上の値だった場合、Out of rangeエラー
    if(_id < 0 || len <= _id) throw "Out of range.\n";

  } catch(char* str) {
    std::cout << str;
  }

  // 区間名を返す
  return ranges[_id].getName();
}

// 区間番号を受けて当該区間の距離を返す
float CourseInfo::getRangeDistanceById(int _id)
{
  try {
    int len = sizeof(ranges) / sizeof(ranges[0]);

    // 引数が負、もしくは配列長以上の値だった場合、Out of rangeエラー
    if(_id < 0 || len <= _id) throw "Out of range.\n";

  } catch(char* str) {
    std::cout << str;
  }

  // 区間の距離を返す
  return ranges[_id].getDistance();
}

float CourseInfo::getRangeDistanceByName(std::string _name)
{
  int id;
  try {
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

    // 名前が一致する区間が見つからなかった場合は、Not foundエラー
    if(i == len) throw "Not found.\n";

  } catch(char* str) {
    std::cout << str;
  }

  // 区間の距離を返す
  return ranges[id].getDistance();
}