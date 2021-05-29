/**
 *@file Range_test.cpp
 *@brief　区間情報のテスト
 *@author higuchi/miyashita
 */

#include "Range.h"
#include <gtest/gtest.h>

namespace etrobocon2021_test {
  // Rangeコンストラクタに関するテスト
  // 関数getNameに関するテスト
  // 区間名を返す処理
  TEST(getNameTest, getName)
  {
    Range range("ST_1", 10.0f);
    std::string expected = "ST_1";

    EXPECT_EQ(expected, range.getName());
  }

  // 区間の距離に0を与えてインスタンス化した区間の名前を返す処理
  TEST(getNameTest, getNameByZeroDistance)
  {
    Range range("ST_1", 0.0f);
    std::string expected = "ST_1";

    EXPECT_EQ(expected, range.getName());
  }

  // 区間名に空文字を与えてインスタンス化した区間の名前を返す処理
  TEST(getNameTest, getNameByNullName)
  {
    Range range("", 10.0f);
    std::string expected = "NO_EXIST";

    EXPECT_EQ(expected, range.getName());
  }

  // 関数getDistanceに関するテスト
  // 区間の距離を返す処理
  TEST(getDistanceTest, getDistance)
  {
    Range range("ST_1", 10.0f);
    float expected = 10.0f;

    EXPECT_EQ(expected, range.getDistance());
  }

  // 区間名に空文字を与えてインスタンス化した区間の距離を返す処理
  TEST(getDistanceTest, getDistanceByNullName)
  {
    Range range("", 10.0f);
    float expected = 0.0f;

    EXPECT_EQ(expected, range.getDistance());
  }

  // 区間の距離に0を与えてインスタンス化した区間の距離を返す処理
  TEST(getDistanceTest, getDistanceByZeroDistance)
  {
    Range range("ST_1", 0.0f);
    float expected = 0.0f;

    EXPECT_EQ(expected, range.getDistance());
  }

  // 区間の距離に負の値を与えてインスタンス化した区間の距離を返す処理
  TEST(getDistanceTest, getDistanceByMinusDistance)
  {
    Range range("ST_1", -10.0f);
    float expected = 0.0f;

    EXPECT_EQ(expected, range.getDistance());
  }

  // 区間名に空文字、距離に負の値を与えてインスタンス化した区間の距離を返す処理
  TEST(getDistanceTest, getDistanceByNullNameAndMinusDistance)
  {
    Range range("", -10.0f);
    float expected = 0.0f;

    EXPECT_EQ(expected, range.getDistance());
  }
}  // namespace etrobocon2021_test