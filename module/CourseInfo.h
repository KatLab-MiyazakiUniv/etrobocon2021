/**
 * @file CourseInfo.h
 * @brief コース情報
 * @author higuchi, miyashita
 */

#ifndef COURSE_INFO_H
#define COURSE_INFO_H

#include <iostream>
#include <array>

/**
 * コース情報を保持するクラス
 */
class CourseInfo {
 public:
  /**
   * インスタンスを生成する。受け取った輝度の値をコンストラクタに渡す
   * @param _brightness 目標とする輝度
   */
  static CourseInfo& getInstance(int _brightness);

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
  int targetBrightness;

  // 各区画の距離のポインタ
  const float* distances;

  /**
   * コンストラクタ
   * @param _brightness 目標とする輝度
   */
  CourseInfo(int _brightness);

  /**
   * コピーコンストラクタ
   * @param other 静的なCourseInfoの参照
   */
  CourseInfo(const CourseInfo& other);

  /**
   * 代入演算子
   */
  CourseInfo& operator=(const CourseInfo& other);
};

#endif