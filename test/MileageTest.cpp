#include "Mileage.h"
#include <math.h>
#include <gtest/gtest.h>

namespace etrobocon2021_test {
  TEST(calculateMileageTest, calculateMilage)
  {
    Mileage& mileage = Mileage::getInstance();
    double radius = 45;
    double rightAngle = 10;
    double leftAngle = 20;
    double rightWheel = 2 * rightAngle * radius * M_PI / 360;
    double leftWheel = 2 * leftAngle * radius * M_PI / 360;
    double expected = (rightWheel + leftWheel) / 2;
    EXPECT_DOUBLE_EQ(expected, mileage.calculateMileage(10, 20));
  }

  TEST(calculateMileageTest, calculateMilage_minus)
  {
    Mileage& mileage = Mileage::getInstance();
    double radius = 45;
    double rightAngle = -10;
    double leftAngle = -20;
    double rightWheel = 2 * rightAngle * radius * M_PI / 360;
    double leftWheel = 2 * leftAngle * radius * M_PI / 360;
    double expected = (rightWheel + leftWheel) / 2;
    EXPECT_DOUBLE_EQ(expected, mileage.calculateMileage(-10, -20));
  }

  TEST(calculateMileageTest, calculateMilage_zero)
  {
    Mileage& mileage = Mileage::getInstance();
    double radius = 45;
    double rightAngle = 0;
    double leftAngle = 0;
    double rightWheel = 2 * rightAngle * radius * M_PI / 360;
    double leftWheel = 2 * leftAngle * radius * M_PI / 360;
    double expected = (rightWheel + leftWheel) / 2;
    EXPECT_DOUBLE_EQ(expected, mileage.calculateMileage(0, 0));
  }
}  // namespace etrobocon2021_test