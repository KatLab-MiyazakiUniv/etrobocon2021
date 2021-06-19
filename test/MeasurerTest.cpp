/**
 * @file MeasurerTest.cpp
 * @brief Measurerクラスをテストする
 * @author hiroto0927, miyashita64
 */

#include "Measurer.h"
#include <gtest/gtest.h>

namespace etrobocon2021_test {
  TEST(getColorIdTest, getColorIdByTrueId)
  {
    Measurer measurer;
    colorid_t expected = colorid_t::COLOR_WHITE;

    EXPECT_EQ(expected, measurer.getColorId());
  }
}  // namespace etrobocon2021_test
