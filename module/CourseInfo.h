/**
 *@file CourseInfo.h
 *@brief コース情報
 *@author higuchi/miyashita
 */

#ifndef COURSE_INFO_H
#define COURSE_INFO_H

#include "Range.h"

/**
 * コース情報を保持するクラス
 */
class CourseInfo {
 public:
  /**
   * 受け取った輝度の値を目標値に設定し、区画の名前と距離を初期化する
   * @param _brightness 目標とする輝度
   */
  CourseInfo(int _brightness);

  /**
   * 目標とする輝度を返す
   * @return 目標とする輝度
   */
  int getBrightness();

  /**
   * 受け取った区間IDに該当する区間名を返す
   * @param _id 区間ID
   * @return 区間名
   */
  std::string getRangeNameById(int _id);

  /**
   * 受け取った区間IDに該当する区間の距離を返す
   * @param _id 区間ID
   * @return 区間の距離
   */
  float getRangeDistanceById(int _id);

  /**
   * 受け取った区間名に該当する区間の距離を返す
   * @param _name 区間名
   * @return 区間の距離
   */
  float getRangeDistanceByName(std::string _name);

 private:
  // 目標とする輝度
  int brightness;
  // 各区画
  const Range ranges[7];
};

#endif