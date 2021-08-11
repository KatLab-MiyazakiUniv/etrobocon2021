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
    int expected1 = 8;
    int expected2 = 111;
    int actual = measurer.getRawColor().r;

    ASSERT_TRUE( actual == expected1 || actual == expected2 );
  }
}  // namespace etrobocon2021_test