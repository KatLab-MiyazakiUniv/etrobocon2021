/**
 * @file ColorJudgeTest.cpp
 * @brief ColorJudgeクラスをテストする
 * @author hiroto0927, miyashita64
 */

#include "ColorJudge.h"
#include <gtest/gtest.h>

namespace etrobocon2021_test {
  // 彩度の境界値テスト
  TEST(getColorTest, getColorByBlack)
  {
    rgb_raw_t rgb = { 0, 0, 0 };
    COLOR expected = COLOR::BLACK;

    EXPECT_EQ(expected, ColorJudge::getColor(rgb));
  }

  TEST(getColorTest, getColorByMax)
  {
    rgb_raw_t rgb = { 112, 107, 152 };
    COLOR expected = COLOR::WHITE;

    EXPECT_EQ(expected, ColorJudge::getColor(rgb));
  }

}  // namespace etrobocon2021_test