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
    COLOR_NUMBER expected = COLOR_NUMBER::COLOR_WHITE;

    EXPECT_EQ(expected, measurer.getColorId());
  }
}  // namespace etrobocon2021_test
