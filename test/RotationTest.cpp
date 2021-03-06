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

  //左回頭のテスト

  TEST(Rotation, rotateLeft)
  {
    Measurer measurer;
    Rotation rotation;
    double leftExpected, rightExpected;
    double leftActual, rightActual;
    double leftMotorCount;
    double rightMotorCount;
    double targetDistance;
    double tread = 132.0;
    double error = M_PI * tread / 360;  //誤差1度
    int angle, pwm;

    // 90度左回頭の回頭誤差が１度未満かテスト
    angle = 90;
    pwm = 30;
    targetDistance = M_PI * tread * abs(angle) / 360;
    // 期待する走行距離
    rightExpected = Mileage::calculateWheelMileage(measurer.getRightCount()) + targetDistance;
    // 回頭
    rotation.rotateLeft(angle, pwm);
    // 関数実行後の走行距離
    rightActual = Mileage::calculateWheelMileage(measurer.getRightCount());
    // 誤差のテスト
    EXPECT_LE(rightExpected, rightActual);
    EXPECT_GE(rightExpected + error, rightActual);

    // 180度左回頭の回頭誤差が１度未満かテスト
    angle = 180;
    pwm = 30;
    targetDistance = M_PI * tread * abs(angle) / 360;

    rightExpected = Mileage::calculateWheelMileage(measurer.getRightCount()) + targetDistance;

    rotation.rotateLeft(angle, pwm);

    rightActual = Mileage::calculateWheelMileage(measurer.getRightCount());

    EXPECT_LE(rightExpected, rightActual);
    EXPECT_GE(rightExpected + error, rightActual);

    // 360度左回頭の回頭誤差が１度未満かテスト
    angle = 360;
    pwm = 30;
    targetDistance = M_PI * tread * abs(angle) / 360;

    rightExpected = Mileage::calculateWheelMileage(measurer.getRightCount()) + targetDistance;

    rotation.rotateLeft(angle, pwm);

    rightActual = Mileage::calculateWheelMileage(measurer.getRightCount());

    EXPECT_LE(rightExpected, rightActual);
    EXPECT_GE(rightExpected + error, rightActual);
  }

  TEST(Rotation, rotateLeft_zero)
  {
    Measurer measurer;
    Rotation rotation;
    double leftExpected, rightExpected;
    double leftActual, rightActual;
    double leftMotorCount;
    double rightMotorCount;
    double targetDistance;
    double tread = 132.0;
    double error = M_PI * tread / 360;  //誤差1度
    int angle, pwm;

    // 0度左回頭のテスト
    angle = 0;
    pwm = 30;
    targetDistance = M_PI * tread * abs(angle) / 360;

    rightExpected = Mileage::calculateWheelMileage(measurer.getRightCount()) + targetDistance;

    rotation.rotateLeft(angle, pwm);

    rightActual = Mileage::calculateWheelMileage(measurer.getRightCount());

    EXPECT_DOUBLE_EQ(rightExpected, rightActual);
  }

  TEST(Rotation, rotateLeft_maxpwm)
  {
    Measurer measurer;
    Rotation rotation;
    double leftExpected, rightExpected;
    double leftActual, rightActual;
    double leftMotorCount;
    double rightMotorCount;
    double targetDistance;
    double tread = 132.0;
    double error = M_PI * tread / 360;  //誤差1度
    int angle, pwm;

    // PWM値が100の時のテスト
    angle = 90;
    pwm = 100;
    targetDistance = M_PI * tread * abs(angle) / 360;

    rightExpected = Mileage::calculateWheelMileage(measurer.getRightCount()) + targetDistance;

    rotation.rotateLeft(angle, pwm);

    rightActual = Mileage::calculateWheelMileage(measurer.getRightCount());

    EXPECT_LE(rightExpected, rightActual);
    EXPECT_GE(rightExpected + error, rightActual);
  }

  TEST(Rotation, rotateLeft_minus)
  {
    Measurer measurer;
    Rotation rotation;
    double leftExpected, rightExpected;
    double leftActual, rightActual;
    double leftMotorCount;
    double rightMotorCount;
    double targetDistance;
    double tread = 132.0;
    double error = M_PI * tread / 360;  //誤差1度
    int angle, pwm;

    // 回転角度がマイナス
    angle = -90;
    pwm = 100;
    targetDistance = M_PI * tread * abs(angle) / 360;

    rightExpected = Mileage::calculateWheelMileage(measurer.getRightCount()) + targetDistance;

    rotation.rotateLeft(angle, pwm);

    rightActual = Mileage::calculateWheelMileage(measurer.getRightCount());

    EXPECT_LE(rightExpected, rightActual);
    EXPECT_GE(rightExpected + error, rightActual);

    // PWM値がマイナス
    angle = 90;
    pwm = -100;
    targetDistance = M_PI * tread * abs(angle) / 360;

    rightExpected = Mileage::calculateWheelMileage(measurer.getRightCount()) + targetDistance;

    rotation.rotateLeft(angle, pwm);

    rightActual = Mileage::calculateWheelMileage(measurer.getRightCount());

    EXPECT_LE(rightExpected, rightActual);
    EXPECT_GE(rightExpected + error, rightActual);
  }

  //右回頭のテスト

  TEST(Rotation, rotateRight)
  {
    Measurer measurer;
    Controller controller;
    Rotation rotation;
    double leftExpected, rightExpected;
    double leftActual, rightActual;
    double leftMotorCount;
    double rightMotorCount;
    double targetDistance;
    double tread = 132.0;
    double error = M_PI * tread / 360;  //誤差1度
    int angle, pwm;

    // 90度右回頭の回頭誤差が１度未満かテスト
    angle = 90;
    pwm = 30;
    targetDistance = M_PI * tread * abs(angle) / 360;

    leftExpected = Mileage::calculateWheelMileage(measurer.getLeftCount()) + targetDistance;

    rotation.rotateRight(angle, pwm);

    leftActual = Mileage::calculateWheelMileage(measurer.getLeftCount());

    EXPECT_LE(leftExpected, leftActual);
    EXPECT_GE(leftExpected + error, leftActual);

    // 180度右回頭の回頭誤差が１度未満かテスト
    angle = 180;
    pwm = 30;
    targetDistance = M_PI * tread * abs(angle) / 360;

    leftExpected = Mileage::calculateWheelMileage(measurer.getLeftCount()) + targetDistance;

    rotation.rotateRight(angle, pwm);

    leftActual = Mileage::calculateWheelMileage(measurer.getLeftCount());

    EXPECT_LE(leftExpected, leftActual);
    EXPECT_GE(leftExpected + error, leftActual);
  }

  TEST(Rotation, rotateRight_zero)
  {
    Measurer measurer;
    Rotation rotation;
    double leftExpected, rightExpected;
    double leftActual, rightActual;
    double leftMotorCount;
    double rightMotorCount;
    double targetDistance;
    double tread = 132.0;
    double error = M_PI * tread / 360;  //誤差1度
    int angle, pwm;

    // 0度右回頭のテスト
    angle = 0;
    pwm = 30;
    targetDistance = M_PI * tread * abs(angle) / 360;

    leftExpected = Mileage::calculateWheelMileage(measurer.getLeftCount()) + targetDistance;

    rotation.rotateRight(angle, pwm);

    leftActual = Mileage::calculateWheelMileage(measurer.getLeftCount());

    EXPECT_DOUBLE_EQ(leftExpected, leftActual);
  }

  TEST(Rotation, rotateRight_maxpwm)
  {
    Measurer measurer;
    Rotation rotation;
    double leftExpected, rightExpected;
    double leftActual, rightActual;
    double leftMotorCount;
    double rightMotorCount;
    double targetDistance;
    double tread = 132.0;
    double error = M_PI * tread / 360;  //誤差1度
    int angle, pwm;

    // PWM値が100の時のテスト
    angle = 90;
    pwm = 100;
    targetDistance = M_PI * tread * abs(angle) / 360;

    leftExpected = Mileage::calculateWheelMileage(measurer.getLeftCount()) + targetDistance;

    rotation.rotateRight(angle, pwm);

    leftActual = Mileage::calculateWheelMileage(measurer.getLeftCount());

    EXPECT_LE(leftExpected, leftActual);
    EXPECT_GE(leftExpected + error, leftActual);
  }

  TEST(Rotation, rotateRight_minus)
  {
    Measurer measurer;
    Rotation rotation;
    double leftExpected, rightExpected;
    double leftActual, rightActual;
    double leftMotorCount;
    double rightMotorCount;
    double targetDistance;
    double tread = 132.0;
    double error = M_PI * tread / 360;  //誤差1度
    int angle, pwm;

    // 回転角度がマイナス
    angle = -90;
    pwm = 100;
    targetDistance = M_PI * tread * abs(angle) / 360;

    leftExpected = Mileage::calculateWheelMileage(measurer.getLeftCount()) + targetDistance;

    rotation.rotateRight(angle, pwm);

    leftActual = Mileage::calculateWheelMileage(measurer.getLeftCount());

    EXPECT_LE(leftExpected, leftActual);
    EXPECT_GE(leftExpected + error, leftActual);

    // PWM値がマイナス
    angle = 90;
    pwm = -100;
    targetDistance = M_PI * tread * abs(angle) / 360;

    leftExpected = Mileage::calculateWheelMileage(measurer.getLeftCount()) + targetDistance;

    rotation.rotateRight(angle, pwm);

    leftActual = Mileage::calculateWheelMileage(measurer.getLeftCount());

    EXPECT_LE(leftExpected, leftActual);
    EXPECT_GE(leftExpected + error, leftActual);
  }

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
