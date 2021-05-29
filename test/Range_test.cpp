/**
 *@file Range_test.cpp
 *@brief　区間情報のテスト
 *@author higuchi/miyashita
 */

#include "Range.h"
#include <gtest/gtest.h>

namespace etrobocon2021_test {
  // Rangeコンストラクタに関するテスト
  /*
  //区画名と距離が適切な場合
  TEST(RangeTest, newRange) { EXPECT_NO_THROW(Range range("ST_1", 10.0f)); }
  //距離が0の場合
  TEST(RangeTest, newRangeByZeroRange) { EXPECT_ANY_THROW(Range range("ST_1", 0.0f)); }
  //距離が負の場合
  TEST(RangeTest, newRangeByminusRange) { EXPECT_ANY_THROW(Range range("ST_1", -10.0f)); }
  //区画名が空文字の場合
  TEST(RangeTest, newRangeByNullRange) { EXPECT_ANY_THROW(Range range("", 10.0f)); }
  */

  //関数getNameに関するテスト
  //区間名を返す処理
  TEST(getNameTest, getName)
  {
    Range range("ST_1", 10.0f);
    std::string expected = "ST_1";

    EXPECT_EQ(expected, range.getName());
  }

  //関数getDistanceに関するテスト
  //区間の距離を返す処理
  TEST(getDistanceTest, getDistance)
  {
    Range range("ST_1", 10.0f);
    float expected = 10.0f;

    EXPECT_EQ(expected, range.getDistance());
  }

}  // namespace etrobocon2021_test