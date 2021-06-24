/**
 * @file ColorJudgeTest.cpp
 * @brief ColorJudgeクラスをテストする
 * @author hiroto0927, miyashita64
 */

#include "ColorJudge.h"
#include <gtest/gtest.h>

namespace etrobocon2021_test {
  /*
  // 彩度の境界値テスト
  TEST(getColorTest, getColorByBlack)
  {
    rgb_raw_t color = rgb_raw_t{ 0, 0, 0 };
    rgb_raw_t& colorRef = color;
    COLOR expected = COLOR::BLACK;

    EXPECT_EQ(expected, ColorJudge::getColor(colorRef));
  }

  TEST(getColorTest, getColorByLowSaturationRed)
  {
    rgb_raw_t color = rgb_raw_t{ 30, 21, 21 };
    rgb_raw_t& colorRef = color;
    COLOR expected = COLOR::BLACK;

    EXPECT_EQ(expected, ColorJudge::getColor(colorRef));
  }

  TEST(getColorTest, getColorByLowSaturationBlack)
  {
    rgb_raw_t color = rgb_raw_t{ 30, 22, 22 };
    rgb_raw_t& colorRef = color;
    COLOR expected = COLOR::BLACK;

    EXPECT_EQ(expected, ColorJudge::getColor(colorRef));
  }

  // 色相(赤)の境界値テスト
  TEST(getColorTest, getColorByRedBorderYRed)
  {
    rgb_raw_t color = rgb_raw_t{ 255, 127, 0 };
    rgb_raw_t& colorRef = color;
    COLOR expected = COLOR::RED;

    EXPECT_EQ(expected, ColorJudge::getColor(colorRef));
  }

  TEST(getColorTest, getColorByRedBorderYellow)
  {
    rgb_raw_t color = rgb_raw_t{ 255, 128, 0 };
    rgb_raw_t& colorRef = color;
    COLOR expected = COLOR::YELLOW;

    EXPECT_EQ(expected, ColorJudge::getColor(colorRef));
  }

  TEST(getColorTest, getColorByRedBorderWhite)
  {
    rgb_raw_t color = rgb_raw_t{ 255, 179, 255 };
    rgb_raw_t& colorRef = color;
    COLOR expected = COLOR::WHITE;

    EXPECT_EQ(expected, ColorJudge::getColor(colorRef));
  }

  TEST(getColorTest, getColorByRedBorderWRed)
  {
    rgb_raw_t color = rgb_raw_t{ 255, 178, 255 };
    rgb_raw_t& colorRef = color;
    COLOR expected = COLOR::RED;

    EXPECT_EQ(expected, ColorJudge::getColor(colorRef));
  }

  // 色相(緑)の境界値テスト
  TEST(getColorTest, getColorByGreenBorderGYellow)
  {
    rgb_raw_t color = rgb_raw_t{ 196, 255, 0 };
    rgb_raw_t& colorRef = color;
    COLOR expected = COLOR::YELLOW;

    EXPECT_EQ(expected, ColorJudge::getColor(colorRef));
  }

  TEST(getColorTest, getColorByGreenBorderYGreen)
  {
    rgb_raw_t color = rgb_raw_t{ 195, 255, 0 };
    rgb_raw_t& colorRef = color;
    COLOR expected = COLOR::GREEN;

    EXPECT_EQ(expected, ColorJudge::getColor(colorRef));
  }

  TEST(getColorTest, getColorByGreenBorderGBlue)
  {
    rgb_raw_t color = rgb_raw_t{ 0, 255, 192 };
    rgb_raw_t& colorRef = color;
    COLOR expected = COLOR::BLUE;

    EXPECT_EQ(expected, ColorJudge::getColor(colorRef));
  }

  TEST(getColorTest, getColorByGreenBorderBGreen)
  {
    rgb_raw_t color = rgb_raw_t{ 0, 255, 191 };
    rgb_raw_t& colorRef = color;
    COLOR expected = COLOR::GREEN;

    EXPECT_EQ(expected, ColorJudge::getColor(colorRef));
  }

  // 色相(青)の境界値テスト
  TEST(getColorTest, getColorByGreenBorderBRed)
  {
    rgb_raw_t color = rgb_raw_t{ 255, 0, 255 };
    rgb_raw_t& colorRef = color;
    COLOR expected = COLOR::RED;

    EXPECT_EQ(expected, ColorJudge::getColor(colorRef));
  }

  TEST(getColorTest, getColorByGreenBorderRBlue)
  {
    rgb_raw_t color = rgb_raw_t{ 254, 0, 255 };
    rgb_raw_t& colorRef = color;
    COLOR expected = COLOR::BLUE;

    EXPECT_EQ(expected, ColorJudge::getColor(colorRef));
  }

  TEST(getColorTest, getColorByGreenBorderBWhite)
  {
    rgb_raw_t color = rgb_raw_t{ 179, 255, 255 };
    rgb_raw_t& colorRef = color;
    COLOR expected = COLOR::WHITE;

    EXPECT_EQ(expected, ColorJudge::getColor(colorRef));
  }

  TEST(getColorTest, getColorByGreenBorderWBlue)
  {
    rgb_raw_t color = rgb_raw_t{ 178, 255, 255 };
    rgb_raw_t& colorRef = color;
    COLOR expected = COLOR::BLUE;

    EXPECT_EQ(expected, ColorJudge::getColor(colorRef));
  }

  // 明度の境界値テスト
  TEST(getColorTest, getColorByWhiteGray)
  {
    int tmp = 128;
    rgb_raw_t color = rgb_raw_t{ tmp, tmp, tmp };
    rgb_raw_t& colorRef = color;
    COLOR expected = COLOR::WHITE;

    EXPECT_EQ(expected, ColorJudge::getColor(colorRef));
  }

  TEST(getColorTest, getColorByBlackGray)
  {
    int tmp = 127;
    rgb_raw_t color = rgb_raw_t{ tmp, tmp, tmp };
    rgb_raw_t& colorRef = color;
    COLOR expected = COLOR::BLACK;

    EXPECT_EQ(expected, ColorJudge::getColor(colorRef));
  }
  */
}  // namespace etrobocon2021_test
