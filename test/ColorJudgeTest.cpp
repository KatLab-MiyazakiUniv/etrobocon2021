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
    COLOR_NUMBER color = COLOR_NUMBER::COLOR_BLACK;
    bool expected = true;

    EXPECT_EQ(expected, ColorJudge::isBlackWhite(color));
  }

  TEST(isBlackWhiteTest, getColorIdByWhiteId)
  {
    COLOR_NUMBER color = COLOR_NUMBER::COLOR_WHITE;
    bool expected = true;

    EXPECT_EQ(expected, ColorJudge::isBlackWhite(color));
  }

  TEST(isBlackWhiteTest, getColorIdByFalseColor)
  {
    COLOR_NUMBER color = COLOR_NUMBER::COLOR_RED;
    bool expected = false;

    EXPECT_EQ(expected, ColorJudge::isBlackWhite(color));
  }

  TEST(isBlackWhiteTest, getColorIdByColorNoneId)
  {
    COLOR_NUMBER color = COLOR_NUMBER::COLOR_NONE;
    bool expected = false;

    EXPECT_EQ(expected, ColorJudge::isBlackWhite(color));
  }

  TEST(isBlackWhiteTest, getColorIdByTnumColorId)
  {
    COLOR_NUMBER color = COLOR_NUMBER::TNUM_COLOR;
    bool expected = false;

    EXPECT_EQ(expected, ColorJudge::isBlackWhite(color));
  }
}  // namespace etrobocon2021_test
