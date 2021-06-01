/**
 * @file CourseInfo_test.cpp
 * @brief コース情報のテスト
 * @author higuchi, miyashita
 */

#include "CourseInfo.h"

#include <gtest/gtest.h>

namespace etrobocon2021_test {

  // CourseInfoコンストラクタに関するテスト

  // getInstance()に関するテスト
  // 複数回getInstance()が呼ばれた場合でも、目標輝度を保持する
  TEST(getInstanceTest, getInstanceSaveTargetBrightness)
  {
    CourseInfo& info = CourseInfo::getInstance(10);
    CourseInfo& info2 = CourseInfo::getInstance(20);
    int expected = 10;

    EXPECT_EQ(expected, info2.getTargetBrightness());
  }

  /*
    // getBrightness()に関するテスト
    // 輝度を返す処理
    TEST(getTargetBrightnessTest, getTargetBrightness)
    {
      CourseInfo& info = CourseInfo::getInstance(1);
      int expected = 1;

      EXPECT_EQ(expected, info.getTargetBrightness());
    }

    // 輝度0を返す処理
    TEST(getTargetBrightnessTest, getTargetBrightnessByZeroValue)
    {
      CourseInfo& info = CourseInfo::getInstance(0);
      int expected = 0;

      EXPECT_EQ(expected, info.getTargetBrightness());
    }
    //輝度100を返す処理
    TEST(getTargetBrightnessTest, getTargetBrightnessByOneHundredValue)
    {
      CourseInfo& info = CourseInfo::getInstance(100);
      int expected = 100;

      EXPECT_EQ(expected, info.getTargetBrightness());
    }

    // 負の輝度-1が入力された場合に、50を保持し返す処理
    TEST(getTargetBrightnessTest, geTargetBrightnessByMinusValue)
    {
      CourseInfo& info = CourseInfo::getInstance(-1);
      int expected = 50;

      EXPECT_EQ(expected, info.getTargetBrightness());
    }

    // 大きすぎる値101が入力された場合に、50を保持し返す処理
    TEST(getTargetBrightnessTest, getTargetBrightnessByBoundaryValue)
    {
      CourseInfo& info = CourseInfo::getInstance(101);
      int expected = 50;

      EXPECT_EQ(expected, info.getTargetBrightness());
    }
    //*/

  // getCourseDistances()に関するテスト
  // 各区間の距離配列のポインタを返す
  TEST(getCourseDistancesTest, getCourseDistances)
  {
    CourseInfo& info = CourseInfo::getInstance(10);
    float expected = 10.0f;
    int id = 0;

    EXPECT_EQ(expected, info.getCourseDistances()[id]);
  }
}  // namespace etrobocon2021_test
