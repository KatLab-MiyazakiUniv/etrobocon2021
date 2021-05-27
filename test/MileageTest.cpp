#include "Mileage.h"
#include <math.h>
#include <gtest/gtest.h>

namespace etrobocon2021_test {
  TEST(calculateWheelMileageTest, calculateWheelMileage)
  {
    Mileage mileage;
    double expected = 2 * 10 * 45 * M_PI / 360;
    EXPECT_DOUBLE_EQ(expected, mileage.calculateWheelMileage(10));
  }

  TEST(calculateWheelMileageTest, calculateWheelMileage_minus)
  {
    Mileage mileage;
    double expected = 2 * -10 * 45 * M_PI / 360;
    EXPECT_DOUBLE_EQ(expected, mileage.calculateWheelMileage(-10));
  }

  TEST(calculateWheelMileageTest, calculateWheelMileage_zero)
  {
    Mileage mileage;
    double expected = 2 * 0 * 45 * M_PI / 360;
    EXPECT_DOUBLE_EQ(expected, mileage.calculateWheelMileage(0));
  }

  TEST(calculateMileageTest, calculateMilage)
  {
    Mileage mileage;
    double rightWheel = 2 * 10 * 45 * M_PI / 360;
    double leftWheel = 2 * 20 * 45 * M_PI / 360;
    double expected = (rightWheel + leftWheel) / 2;
    EXPECT_DOUBLE_EQ(expected, mileage.calculateMileage(10, 20));
  }

  TEST(calculateMileageTest, calculateMilage_minus)
  {
    Mileage mileage;
    double rightWheel = 2 * -10 * 45 * M_PI / 360;
    double leftWheel = 2 * -20 * 45 * M_PI / 360;
    double expected = (rightWheel + leftWheel) / 2;
    EXPECT_DOUBLE_EQ(expected, mileage.calculateMileage(-10, -20));
  }

  TEST(calculateMileageTest, calculateMilage_zero)
  {
    Mileage mileage;
    double rightWheel = 2 * 0 * 45 * M_PI / 360;
    double leftWheel = 2 * 0 * 45 * M_PI / 360;
    double expected = (rightWheel + leftWheel) / 2;
    EXPECT_DOUBLE_EQ(expected, mileage.calculateMileage(0, 0));
  }
}  // namespace etrobocon2021_test