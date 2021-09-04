/**
 * @file Rotation.cpp
 * @brief Roationクラスをテストする
 * @author hiroto0927, miyashita64
 */

#include "Rotation.h"
#include <gtest/gtest.h>
#include <cmath>

namespace etrobocon2021_test {

  const double RADIUS = 45.0;  // 車輪の半径[mm]
  const double TREAD = 140;    // 走行体のトレッド幅（両輪の間の距離）[mm]
  const double transform = 2.0 * RADIUS / TREAD;

  //左軸前方向ピボットターン

  TEST(RotationTest, leftFrontZero)
  {
    int angle = 0;
    double expected = 0;
    double actual;
    Rotation rotation;
    Measurer measurer;

    rotation.turnForwardLeftPivot(angle, 100);
    double motorCount = (measurer.getLeftCount() + measurer.getRightCount()) / 2;

    actual = transform * motorCount;
    ASSERT_LE(expected, actual);
    ASSERT_GE(expected + 1.5, actual);
  }

  TEST(RotationTest, leftFront45)
  {
    int angle = 45;
    double expected = 45;
    double actual;
    Rotation rotation;
    Measurer measurer;

    rotation.turnForwardLeftPivot(angle, 100);
    double motorCount = (measurer.getLeftCount() + measurer.getRightCount()) / 2;

    actual = transform * motorCount;
    ASSERT_LE(expected, actual);
    ASSERT_GE(expected + 1.5, actual);
  }

  TEST(RotationTest, leftFront90)
  {
    int angle = 90;
    double expected = 90;
    double actual;
    Rotation rotation;
    Measurer measurer;

    rotation.turnForwardLeftPivot(angle, 100);
    double motorCount = (measurer.getLeftCount() + measurer.getRightCount()) / 2;

    actual = transform * motorCount;
    ASSERT_LE(expected, actual);
    ASSERT_GE(expected + 1.5, actual);
  }

  TEST(RotationTest, leftFront135)
  {
    int angle = 135;
    double expected = 135;
    double actual;
    Rotation rotation;
    Measurer measurer;

    rotation.turnForwardLeftPivot(angle, 100);
    double motorCount = (measurer.getLeftCount() + measurer.getRightCount()) / 2;

    actual = transform * motorCount;
    ASSERT_LE(expected, actual);
    ASSERT_GE(expected + 1.5, actual);
  }

  TEST(RotationTest, leftFront180)
  {
    int angle = 180;
    double expected = 180;
    double actual;
    Rotation rotation;
    Measurer measurer;

    rotation.turnForwardLeftPivot(angle, 100);
    double motorCount = (measurer.getLeftCount() + measurer.getRightCount()) / 2;

    actual = transform * motorCount;
    ASSERT_LE(expected, actual);
    ASSERT_GE(expected + 1.5, actual);
  }

  //右軸前方向ピボットターン

  TEST(RotationTest, rightFrontZero)
  {
    int angle = 0;
    double expected = 0;
    double actual;
    Rotation rotation;
    Measurer measurer;

    rotation.turnForwardRightPivot(angle, 100);
    double motorCount = (measurer.getLeftCount() + measurer.getRightCount()) / 2;

    actual = transform * motorCount;
    ASSERT_LE(expected, actual);
    ASSERT_GE(expected + 1.5, actual);
  }

  TEST(RotationTest, rightFront45)
  {
    int angle = 45;
    double expected = 45;
    double actual;
    Rotation rotation;
    Measurer measurer;

    rotation.turnForwardRightPivot(angle, 100);
    double motorCount = (measurer.getLeftCount() + measurer.getRightCount()) / 2;

    actual = transform * motorCount;
    ASSERT_LE(expected, actual);
    ASSERT_GE(expected + 1.5, actual);
  }

  TEST(RotationTest, rightFront90)
  {
    int angle = 90;
    double expected = 90;
    double actual;
    Rotation rotation;
    Measurer measurer;

    rotation.turnForwardRightPivot(angle, 100);
    double motorCount = (measurer.getLeftCount() + measurer.getRightCount()) / 2;

    actual = transform * motorCount;
    ASSERT_LE(expected, actual);
    ASSERT_GE(expected + 1.5, actual);
  }

  TEST(RotationTest, rightFront135)
  {
    int angle = 135;
    double expected = 135;
    double actual;
    Rotation rotation;
    Measurer measurer;

    rotation.turnForwardRightPivot(angle, 100);
    double motorCount = (measurer.getLeftCount() + measurer.getRightCount()) / 2;

    actual = transform * motorCount;
    ASSERT_LE(expected, actual);
    ASSERT_GE(expected + 1.5, actual);
  }

  TEST(RotationTest, rightFront180)
  {
    int angle = 180;
    double expected = 180;
    double actual;
    Rotation rotation;
    Measurer measurer;

    rotation.turnForwardRightPivot(angle, 100);
    double motorCount = (measurer.getLeftCount() + measurer.getRightCount()) / 2;

    actual = transform * motorCount;
    ASSERT_LE(expected, actual);
    ASSERT_GE(expected + 1.5, actual);
  }

  //左軸後ろピボットターン

  TEST(RotationTest, leftBacktZero)
  {
    int angle = 0;
    double expected = std::abs(angle);
    double actual;
    Rotation rotation;
    Measurer measurer;

    rotation.turnBackLeftPivot(angle, 100);
    double motorCount
        = (std::abs(measurer.getLeftCount()) + std::abs(measurer.getRightCount())) / 2;

    actual = transform * motorCount;
    ASSERT_GE(expected + 1.5, actual);
    ASSERT_LE(expected - 1.5, actual);
  }

  TEST(RotationTest, leftBack45)
  {
    int angle = -45;
    double expected = std::abs(angle);
    double actual;
    Rotation rotation;
    Measurer measurer;

    rotation.turnBackLeftPivot(angle, 100);
    double motorCount
        = (std::abs(measurer.getLeftCount()) + std::abs(measurer.getRightCount())) / 2;

    actual = transform * motorCount;
    ASSERT_GE(expected + 1.5, actual);
    ASSERT_LE(expected - 1.5, actual);
  }

  TEST(RotationTest, leftBack90)
  {
    int angle = -90;
    double expected = std::abs(angle);
    double actual;
    Rotation rotation;
    Measurer measurer;

    rotation.turnBackLeftPivot(angle, 100);
    double motorCount
        = (std::abs(measurer.getLeftCount()) + std::abs(measurer.getRightCount())) / 2;

    actual = transform * motorCount;
    ASSERT_GE(expected + 1.5, actual);
    ASSERT_LE(expected - 1.5, actual);
  }

  TEST(RotationTest, leftBack135)
  {
    int angle = -135;
    double expected = std::abs(angle);
    double actual;
    Rotation rotation;
    Measurer measurer;

    rotation.turnBackLeftPivot(angle, 100);
    double motorCount
        = (std::abs(measurer.getLeftCount()) + std::abs(measurer.getRightCount())) / 2;

    actual = transform * motorCount;
    ASSERT_GE(expected + 1.5, actual);
    ASSERT_LE(expected - 1.5, actual);
  }

  TEST(RotationTest, leftBack180)
  {
    int angle = -180;
    double expected = std::abs(angle);
    double actual;
    Rotation rotation;
    Measurer measurer;

    rotation.turnBackLeftPivot(angle, 100);
    double motorCount
        = (std::abs(measurer.getLeftCount()) + std::abs(measurer.getRightCount())) / 2;

    actual = transform * motorCount;
    ASSERT_GE(expected + 1.5, actual);
    ASSERT_LE(expected - 1.5, actual);
  }

  //右軸後ろピボットターン

  TEST(RotationTest, rightBacktZero)
  {
    int angle = 0;
    double expected = std::abs(angle);
    double actual;
    Rotation rotation;
    Measurer measurer;

    rotation.turnBackRightPivot(angle, 100);
    double motorCount
        = (std::abs(measurer.getLeftCount()) + std::abs(measurer.getRightCount())) / 2;

    actual = transform * motorCount;
    ASSERT_GE(expected + 1.5, actual);
    ASSERT_LE(expected - 1.5, actual);
  }

  TEST(RotationTest, rightBack45)
  {
    int angle = -45;
    double expected = std::abs(angle);
    double actual;
    Rotation rotation;
    Measurer measurer;

    rotation.turnBackRightPivot(angle, 100);
    double motorCount
        = (std::abs(measurer.getLeftCount()) + std::abs(measurer.getRightCount())) / 2;

    actual = transform * motorCount;
    ASSERT_GE(expected + 1.5, actual);
    ASSERT_LE(expected - 1.5, actual);
  }

  TEST(RotationTest, rightBack90)
  {
    int angle = -90;
    double expected = std::abs(angle);
    double actual;
    Rotation rotation;
    Measurer measurer;

    rotation.turnBackRightPivot(angle, 100);
    double motorCount
        = (std::abs(measurer.getLeftCount()) + std::abs(measurer.getRightCount())) / 2;

    actual = transform * motorCount;
    ASSERT_GE(expected + 1.5, actual);
    ASSERT_LE(expected - 1.5, actual);
  }

  TEST(RotationTest, rightBack135)
  {
    int angle = -135;
    double expected = std::abs(angle);
    double actual;
    Rotation rotation;
    Measurer measurer;

    rotation.turnBackRightPivot(angle, 100);
    double motorCount
        = (std::abs(measurer.getLeftCount()) + std::abs(measurer.getRightCount())) / 2;

    actual = transform * motorCount;
    ASSERT_GE(expected + 1.5, actual);
    ASSERT_LE(expected - 1.5, actual);
  }

  TEST(RotationTest, rightBack180)
  {
    int angle = -180;
    double expected = std::abs(angle);
    double actual;
    Rotation rotation;
    Measurer measurer;

    rotation.turnBackRightPivot(angle, 100);
    double motorCount
        = (std::abs(measurer.getLeftCount()) + std::abs(measurer.getRightCount())) / 2;

    actual = transform * motorCount;
    ASSERT_GE(expected + 1.5, actual);
    ASSERT_LE(expected - 1.5, actual);
  }
}  // namespace etrobocon2021_test
