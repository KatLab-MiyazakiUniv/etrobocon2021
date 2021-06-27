/**
 * @file MeasurerTest.cpp
 * @brief Measurerクラスをテストする
 * @author hiroto0927, miyashita64
 */

#include "Measurer.h"
#include <gtest/gtest.h>

namespace etrobocon2021_test {
  TEST(getRawColorTest, getRawColorRed)
  {
    Measurer measurer;
    int expected = 8;

    EXPECT_EQ(expected, measurer.getRawColor().r);
  }
}  // namespace etrobocon2021_test