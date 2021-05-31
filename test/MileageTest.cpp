#include "Mileage.h"
#include <math.h>
#include <gtest/gtest.h>

namespace etrobocon2021_test {
  TEST(calculateMileageTest, calculateMilage)
  {
    Mileage& mileage = Mileage::getInstance();
    double rightWheel = 2 * 10 * 45 * M_PI / 360;
    double leftWheel = 2 * 20 * 45 * M_PI / 360;
    double expected = (rightWheel + leftWheel) / 2;
    EXPECT_DOUBLE_EQ(expected, mileage.calculateMileage(10, 20));
  }

  TEST(calculateMileageTest, calculateMilage_minus)
  {
    Mileage& mileage = Mileage::getInstance();
    double rightWheel = 2 * -10 * 45 * M_PI / 360;
    double leftWheel = 2 * -20 * 45 * M_PI / 360;
    double expected = (rightWheel + leftWheel) / 2;
    EXPECT_DOUBLE_EQ(expected, mileage.calculateMileage(-10, -20));
  }

  TEST(calculateMileageTest, calculateMilage_zero)
  {
    Mileage& mileage = Mileage::getInstance();
    double rightWheel = 2 * 0 * 45 * M_PI / 360;
    double leftWheel = 2 * 0 * 45 * M_PI / 360;
    double expected = (rightWheel + leftWheel) / 2;
    EXPECT_DOUBLE_EQ(expected, mileage.calculateMileage(0, 0));
  }
}  // namespace etrobocon2021_test