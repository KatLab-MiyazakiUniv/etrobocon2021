/**
 * @file ColorJudgeTest.cpp
 * @brief ColorJudgeクラスをテストする
 * @author hiroto0927, miyashita64
 */

#include "ColorJudge.h"
#include <gtest/gtest.h>

namespace etrobocon2021_test {
  /* isBlackWhite()のテスト */
  TEST(isBlackWhiteTest, isBlackWhiteByBlack)
  {
    rgb_raw_t color = rgb_raw_t{ 0, 0, 0 };
    rgb_raw_t& colorRef = color;
    bool expected = true;

    EXPECT_EQ(expected, ColorJudge::isBlackWhite(colorRef));
  }

  TEST(isBlackWhiteTest, isBlackWhiteByWhite)
  {
    rgb_raw_t color = rgb_raw_t{ 255, 255, 255 };
    rgb_raw_t& colorRef = color;
    bool expected = true;

    EXPECT_EQ(expected, ColorJudge::isBlackWhite(colorRef));
  }

  TEST(isBlackWhiteTest, isBlackWhiteByOtherColor)
  {
    rgb_raw_t color = rgb_raw_t{ 10, 100, 200 };
    rgb_raw_t& colorRef = color;
    bool expected = false;

    EXPECT_EQ(expected, ColorJudge::isBlackWhite(colorRef));
  }

  /* getColorNumber()のテスト */
  // 彩度の境界値テスト
  TEST(getColorNumberTest, getColorNumberByBlack)
  {
    rgb_raw_t color = rgb_raw_t{ 0, 0, 0 };
    rgb_raw_t& colorRef = color;
    COLOR_NUMBER expected = COLOR_NUMBER::COLOR_BLACK;

    EXPECT_EQ(expected, ColorJudge::getColorNumber(colorRef));
  }

  TEST(getColorNumberTest, getColorNumberByLowSaturationRed)
  {
    rgb_raw_t color = rgb_raw_t{ 30, 21, 21 };
    rgb_raw_t& colorRef = color;
    COLOR_NUMBER expected = COLOR_NUMBER::COLOR_RED;

    EXPECT_EQ(expected, ColorJudge::getColorNumber(colorRef));
  }

  TEST(getColorNumberTest, getColorNumberByLowSaturationBlack)
  {
    rgb_raw_t color = rgb_raw_t{ 30, 22, 22 };
    rgb_raw_t& colorRef = color;
    COLOR_NUMBER expected = COLOR_NUMBER::COLOR_BLACK;

    EXPECT_EQ(expected, ColorJudge::getColorNumber(colorRef));
  }

  // 色相(赤)の境界値テスト
  TEST(getColorNumberTest, getColorNumberByRedBorderYRed)
  {
    rgb_raw_t color = rgb_raw_t{ 255, 127, 0 };
    rgb_raw_t& colorRef = color;
    COLOR_NUMBER expected = COLOR_NUMBER::COLOR_RED;

    EXPECT_EQ(expected, ColorJudge::getColorNumber(colorRef));
  }

  TEST(getColorNumberTest, getColorNumberByRedBorderYellow)
  {
    rgb_raw_t color = rgb_raw_t{ 255, 128, 0 };
    rgb_raw_t& colorRef = color;
    COLOR_NUMBER expected = COLOR_NUMBER::COLOR_YELLOW;

    EXPECT_EQ(expected, ColorJudge::getColorNumber(colorRef));
  }

  TEST(getColorNumberTest, getColorNumberByRedBorderWhite)
  {
    rgb_raw_t color = rgb_raw_t{ 255, 179, 255 };
    rgb_raw_t& colorRef = color;
    COLOR_NUMBER expected = COLOR_NUMBER::COLOR_WHITE;

    EXPECT_EQ(expected, ColorJudge::getColorNumber(colorRef));
  }

  TEST(getColorNumberTest, getColorNumberByRedBorderWRed)
  {
    rgb_raw_t color = rgb_raw_t{ 255, 178, 255 };
    rgb_raw_t& colorRef = color;
    COLOR_NUMBER expected = COLOR_NUMBER::COLOR_RED;

    EXPECT_EQ(expected, ColorJudge::getColorNumber(colorRef));
  }

  // 色相(緑)の境界値テスト
  TEST(getColorNumberTest, getColorNumberByGreenBorderGYellow)
  {
    rgb_raw_t color = rgb_raw_t{ 196, 255, 0 };
    rgb_raw_t& colorRef = color;
    COLOR_NUMBER expected = COLOR_NUMBER::COLOR_YELLOW;

    EXPECT_EQ(expected, ColorJudge::getColorNumber(colorRef));
  }

  TEST(getColorNumberTest, getColorNumberByGreenBorderYGreen)
  {
    rgb_raw_t color = rgb_raw_t{ 195, 255, 0 };
    rgb_raw_t& colorRef = color;
    COLOR_NUMBER expected = COLOR_NUMBER::COLOR_GREEN;

    EXPECT_EQ(expected, ColorJudge::getColorNumber(colorRef));
  }

  TEST(getColorNumberTest, getColorNumberByGreenBorderGBlue)
  {
    rgb_raw_t color = rgb_raw_t{ 0, 255, 192 };
    rgb_raw_t& colorRef = color;
    COLOR_NUMBER expected = COLOR_NUMBER::COLOR_BLUE;

    EXPECT_EQ(expected, ColorJudge::getColorNumber(colorRef));
  }

  TEST(getColorNumberTest, getColorNumberByGreenBorderBGreen)
  {
    rgb_raw_t color = rgb_raw_t{ 0, 255, 191 };
    rgb_raw_t& colorRef = color;
    COLOR_NUMBER expected = COLOR_NUMBER::COLOR_GREEN;

    EXPECT_EQ(expected, ColorJudge::getColorNumber(colorRef));
  }

  // 色相(青)の境界値テスト
  TEST(getColorNumberTest, getColorNumberByGreenBorderBRed)
  {
    rgb_raw_t color = rgb_raw_t{ 255, 0, 255 };
    rgb_raw_t& colorRef = color;
    COLOR_NUMBER expected = COLOR_NUMBER::COLOR_RED;

    EXPECT_EQ(expected, ColorJudge::getColorNumber(colorRef));
  }

  TEST(getColorNumberTest, getColorNumberByGreenBorderRBlue)
  {
    rgb_raw_t color = rgb_raw_t{ 254, 0, 255 };
    rgb_raw_t& colorRef = color;
    COLOR_NUMBER expected = COLOR_NUMBER::COLOR_BLUE;

    EXPECT_EQ(expected, ColorJudge::getColorNumber(colorRef));
  }

  TEST(getColorNumberTest, getColorNumberByGreenBorderBWhite)
  {
    rgb_raw_t color = rgb_raw_t{ 179, 255, 255 };
    rgb_raw_t& colorRef = color;
    COLOR_NUMBER expected = COLOR_NUMBER::COLOR_WHITE;

    EXPECT_EQ(expected, ColorJudge::getColorNumber(colorRef));
  }

  TEST(getColorNumberTest, getColorNumberByGreenBorderWBlue)
  {
    rgb_raw_t color = rgb_raw_t{ 178, 255, 255 };
    rgb_raw_t& colorRef = color;
    COLOR_NUMBER expected = COLOR_NUMBER::COLOR_BLUE;

    EXPECT_EQ(expected, ColorJudge::getColorNumber(colorRef));
  }

  // 明度の境界値テスト
  TEST(getColorNumberTest, getColorNumberByWhiteGray)
  {
    int tmp = 128;
    rgb_raw_t color = rgb_raw_t{ tmp, tmp, tmp };
    rgb_raw_t& colorRef = color;
    COLOR_NUMBER expected = COLOR_NUMBER::COLOR_WHITE;

    EXPECT_EQ(expected, ColorJudge::getColorNumber(colorRef));
  }

  TEST(getColorNumberTest, getColorNumberByBlackGray)
  {
    int tmp = 127;
    rgb_raw_t color = rgb_raw_t{ tmp, tmp, tmp };
    rgb_raw_t& colorRef = color;
    COLOR_NUMBER expected = COLOR_NUMBER::COLOR_BLACK;

    EXPECT_EQ(expected, ColorJudge::getColorNumber(colorRef));
  }
}  // namespace etrobocon2021_test
