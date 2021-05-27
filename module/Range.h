/**
 *@file Range.h
 *@brief 区間情報
 *@author higuchi/miyashita
 */

#ifndef RANGE_H
#define RANGE_H

#include <string>
#include <iostream>

class Range {
 public:
  /**
   * 区間名とその距離を受け取り、初期化する
   * @param _name     区画名
   * @param _distance 区間の距離
   */
  Range(std::string _name, float _distance);

  /**
   * 区間名を返す
   * @return 区間名
   */
  std::string getName() const;

  /**
   * 区間の距離を返す
   * @return 区間の距離
   */
  float getDistance() const;

 private:
  // 区間名
  const std::string name;
  // 区間の距離
  const float distance;
};

#endif