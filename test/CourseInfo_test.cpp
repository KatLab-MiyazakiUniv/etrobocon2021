/**
 * @file CourseInfo_test.cpp
 * @brief コース情報のテスト
 * @author higuchi, miyashita
 */

#include "CourseInfo.h"

#include <gtest/gtest.h>

namespace etrobocon2021_test {

  // CourseInfoコンストラクタに関するテスト
  // getBrightness()に関するテスト
  // 輝度を返す処理
  TEST(getTargetBrightnessTest, getTargetBrightness)
  {
    CourseInfo info(1);
    int expected = 1;

    EXPECT_EQ(expected, info.getTargetBrightness());
  }

  // 輝度を返す処理
  TEST(getTargetBrightnessTest, getTargetBrightnessByZeroValue)
  {
    CourseInfo info(0);
    int expected = 0;

    EXPECT_EQ(expected, info.getTargetBrightness());
  }

  // 負の輝度が入力された場合に、50を保持し返す処理
  TEST(getTargetBrightnessTest, geTargetBrightnessByMinusValue)
  {
    CourseInfo info(-1);
    int expected = 50;

    EXPECT_EQ(expected, info.getTargetBrightness());
  }

  // 大きすぎる輝度が入力された場合に、50を保持し返す処理
  TEST(getTargetBrightnessTest, getTargetBrightnessByOverValue)
  {
    CourseInfo info(500);
    int expected = 50;

    EXPECT_EQ(expected, info.getTargetBrightness());
  }

  // getCourseDistances()に関するテスト
  // 各区間の距離配列のポインタを返す
  TEST(getCourseDistancesTest, getCourseDistances)
  {
    CourseInfo info(10);
    float expected = 10.0f;
    int id = 0;

    EXPECT_EQ(expected, info.getCourseDistances()[id]);
  }

}  // namespace etrobocon2021_test
