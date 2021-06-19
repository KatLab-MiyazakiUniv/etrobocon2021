/**
 * @file ColorJudgeTest.cpp
 * @brief ColorJudgeクラスをテストする
 * @author hiroto0927, miyashita64
 */

#include "ColorJudge.h"
#include <gtest/gtest.h>

namespace etrobocon2021_test {
  TEST(isBlackWhiteTest, getColorIdByBlackId)
  {
    colorid_t color = colorid_t::COLOR_BLACK;
    bool expected = true;

    EXPECT_EQ(expected, ColorJudge::isBlackWhite(color));
  }

  TEST(isBlackWhiteTest, getColorIdByWhiteId)
  {
    colorid_t color = colorid_t::COLOR_WHITE;
    bool expected = true;

    EXPECT_EQ(expected, ColorJudge::isBlackWhite(color));
  }

  TEST(isBlackWhiteTest, getColorIdByFalseColor)
  {
    colorid_t color = colorid_t::COLOR_RED;
    bool expected = false;

    EXPECT_EQ(expected, ColorJudge::isBlackWhite(color));
  }

  TEST(isBlackWhiteTest, getColorIdByColorNoneId)
  {
    colorid_t color = colorid_t::COLOR_NONE;
    bool expected = false;

    EXPECT_EQ(expected, ColorJudge::isBlackWhite(color));
  }

  TEST(isBlackWhiteTest, getColorIdByTnumColorId)
  {
    colorid_t color = colorid_t::TNUM_COLOR;
    bool expected = false;

    EXPECT_EQ(expected, ColorJudge::isBlackWhite(color));
  }
}  // namespace etrobocon2021_test
