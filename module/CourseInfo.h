/**
 * @file CourseInfo.h
 * @brief コース情報
 * @author higuchi, miyashita
 */

#ifndef COURSE_INFO_H
#define COURSE_INFO_H

#include <stdio.h>

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
  int getTargetBrightness();

  /**
   * 各区間の距離配列のポインタを返す
   * @return 各区間の距離配列のポインタ
   */
  const float* getCourseDistances();

 private:
  // 目標とする輝度
  const int targetBrightness;
  // 各区画の距離
  const float distances[7];
};

#endif