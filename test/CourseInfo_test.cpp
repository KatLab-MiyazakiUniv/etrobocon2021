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
  // 輝度の入力が正の場合
  TEST(CourseInfoTest, newCourseInfoByPlusBrightness) { EXPECT_ANY_THROW(CourseInfo info(1)); }
  // 輝度の入力が0の場合
  TEST(CourseInfoTest, newCourseInfoByZeroBrightness) { EXPECT_ANY_THROW(CourseInfo info(0)); }
  // 輝度の入力が負の場合
  TEST(CourseInfoTest, newCourseInfoByMinusBrightness) { EXPECT_ANY_THROW(CourseInfo info(-1)); }

  // getBrightness()に関するテスト
  // 輝度を返す処理
  TEST(getBrughtnessTest, getBrightness)
  {
    CourseInfo info(1);
    int expected = 1;

    EXPECT_FLOAT_EQ(expected, info.getBrightness());
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

  // 負のidを受け取りエラーを返す処理
  TEST(getRangeNameByIdTest, getRangeNameByMinusId)
  {
    CourseInfo info(1);
    int id = -1;

    EXPECT_ANY_THROW(info.getRangeNameById(id));
  }

  // 大きすぎるidを受け取りエラーを返す処理
  TEST(getRangeNameByIdTest, getRangeNameByOverId)
  {
    CourseInfo info(1);
    int id = 7;

    EXPECT_ANY_THROW(info.getRangeNameById(id));
  }

  // 実数型のidを受け取りエラーを返す処理
  TEST(getRangeNameByIdTest, getRangeNameByFloatId)
  {
    CourseInfo info(1);
    float id = 5.5;

    EXPECT_ANY_THROW(info.getRangeNameById(id));
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

  // 負のidを受け取りエラーを返す処理
  TEST(getRangeDistanceByIdTest, getRangeDistanceByMinusId)
  {
    CourseInfo info(1);
    int id = -1;

    EXPECT_ANY_THROW(info.getRangeDistanceById(id));
  }

  // 大きすぎるidを受け取りエラーを返す処理
  TEST(getRangeDistanceByIdTest, getRangeDistanceByOverId)
  {
    CourseInfo info(1);
    int id = 7;

    EXPECT_ANY_THROW(info.getRangeDistanceById(id));
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

  // 空文字を受け取りエラーを返す処理
  TEST(getRangeDistanceByNameTest, getRangeDistanceByNullName)
  {
    CourseInfo info(1);
    std::string name = "";

    EXPECT_ANY_THROW(info.getRangeDistanceByName(name));
  }

  // 存在しない区画名を受け取りエラーを返す処理
  TEST(getRangeDistanceByNameTest, getRangeDistanceByNotExistName)
  {
    CourseInfo info(1);
    std::string name = "notNot";

    EXPECT_ANY_THROW(info.getRangeDistanceByName(name));
  }

}  // namespace etrobocon2021_test
