/**
 *@file CourseInfo_test.cpp
 *@brief コース情報のテスト
 *@author higuchi/miyashita
 */

#include "Range.h"
#include "CourseInfo.h"

#include <gtest/gtest.h>

namespace etrobocon2021_test {

  // CourseInfoコンストラクタに関するテスト
  // getBrightness()に関するテスト
  // 輝度を返す処理
  TEST(getBrightnessTest, getBrightness)
  {
    CourseInfo info(1);
    int expected = 1;

    EXPECT_EQ(expected, info.getBrightness());
  }

  // 輝度を返す処理
  TEST(getBrightnessTest, getBrightnessByZeroValue)
  {
    CourseInfo info(0);
    int expected = 0;

    EXPECT_EQ(expected, info.getBrightness());
  }

  // 負の輝度が入力された場合に、128を保持し返す処理
  TEST(getBrightnessTest, getBrightnessByMinusValue)
  {
    CourseInfo info(-1);
    int expected = 128;

    EXPECT_EQ(expected, info.getBrightness());
  }

  // 大きすぎる輝度が入力された場合に、128を保持し返す処理
  TEST(getBrightnessTest, getBrightnessByOverValue)
  {
    CourseInfo info(500);
    int expected = 128;

    EXPECT_EQ(expected, info.getBrightness());
  }

  // getRangeNameById()に関するテスト
  // idを受け取り区画の距離を返す処理
  TEST(getRangeNameByIdTest, getRangeNameById)
  {
    CourseInfo info(1);
    int id = 1;
    std::string expected = "CV_1";

    EXPECT_EQ(expected, info.getRangeNameById(id));
  }

  // id=0を受け取り区画の距離を返す処理
  TEST(getRangeNameByIdTest, getRangeNameByZeroId)
  {
    CourseInfo info(1);
    int id = 0;
    std::string expected = "ST_1";

    EXPECT_EQ(expected, info.getRangeNameById(id));
  }

  // 負のidを受け取り空文字を返す処理
  TEST(getRangeNameByIdTest, getRangeNameByMinusId)
  {
    CourseInfo info(1);
    int id = -1;
    std::string expected = "\0";

    EXPECT_EQ(expected, info.getRangeNameById(id));
  }

  // 大きすぎるidを受け取り空文字を返す処理
  TEST(getRangeNameByIdTest, getRangeNameByOverId)
  {
    CourseInfo info(1);
    int id = 50;
    std::string expected = "\0";

    EXPECT_EQ(expected, info.getRangeNameById(id));
  }

  // getRangeDistanceById()に関するテスト
  // idを受け取り区画の距離を返す処理
  TEST(getRangeDistanceByIdTest, getRangeDistanceById)
  {
    CourseInfo info(1);
    int id = 1;
    float expected = 5.0f;

    EXPECT_EQ(expected, info.getRangeDistanceById(id));
  }

  // id=0を受け取り区画の距離を返す処理
  TEST(getRangeDistanceByIdTest, getRangeDistanceByZeroId)
  {
    CourseInfo info(1);
    int id = 0;
    float expected = 10.0f;

    EXPECT_EQ(expected, info.getRangeDistanceById(id));
  }

  // 負のidを受け取り0を返す処理
  TEST(getRangeDistanceByIdTest, getRangeDistanceByMinusId)
  {
    CourseInfo info(1);
    int id = -1;
    float expected = 0.0f;

    EXPECT_EQ(expected, info.getRangeDistanceById(id));
  }

  // 大きすぎるidを受け取り0を返す処理
  TEST(getRangeDistanceByIdTest, getRangeDistanceByOverId)
  {
    CourseInfo info(1);
    int id = 50;
    float expected = 0.0f;

    EXPECT_EQ(expected, info.getRangeDistanceById(id));
  }

  // getRangeDistanceByName()に関するテスト
  // 名前を受け取り区画の距離を返す処理
  TEST(getRangeDistanceByNameTest, getRangeDistanceByName)
  {
    CourseInfo info(1);
    std::string name = "ST_1";
    float expected = 10.0f;

    EXPECT_EQ(expected, info.getRangeDistanceByName(name));
  }

  // 空文字を受け取り0を返す処理
  TEST(getRangeDistanceByNameTest, getRangeDistanceByNullName)
  {
    CourseInfo info(1);
    std::string name = "";
    float expected = 0.0f;

    EXPECT_EQ(expected, info.getRangeDistanceByName(name));
  }

  // 存在しない区画名を受け取りエラーを返す処理
  TEST(getRangeDistanceByNameTest, getRangeDistanceByNotExistName)
  {
    CourseInfo info(1);
    std::string name = "noExistRangeName";
    float expected = 0.0f;

    EXPECT_EQ(expected, info.getRangeDistanceByName(name));
  }

}  // namespace etrobocon2021_test
