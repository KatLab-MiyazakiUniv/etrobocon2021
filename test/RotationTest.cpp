/**
 *  @file   RotationTest.cpp
 *  @brief  Rotationクラスのテストファイル
 *  @author mutotaka0426
 */
#include "Rotation.h"
#include "Controller.h"
#include "Measurer.h"
#include <gtest/gtest.h>

using namespace std;

namespace etrobocon2021_test {

  TEST(Rotation, rotateLeft)
  {
    Measurer measurer;
    Rotation rotation;
    double leftExpected, rightExpected;
    double leftActual, rightActual;
    double leftMotorCount;
    double rightMotorCount;
    double targetDistance;
    double tread = 140.0;
    double error = M_PI * tread / 360;  //誤差1度
    int angle, pwm;

    // 90度左回頭の回頭誤差が１度未満かテスト
    angle = 90;
    pwm = 30;
    targetDistance = M_PI * tread * abs(angle) / 360;
    // 期待する走行距離
    leftExpected = Mileage::calculateWheelMileage(measurer.getLeftCount()) - targetDistance;
    rightExpected = Mileage::calculateWheelMileage(measurer.getRightCount()) + targetDistance;
    // 回頭
    rotation.rotateLeft(angle, pwm);
    // 関数実行後の走行距離
    leftActual = Mileage::calculateWheelMileage(measurer.getLeftCount());
    rightActual = Mileage::calculateWheelMileage(measurer.getRightCount());
    // 誤差のテスト
    EXPECT_GE(leftExpected, leftActual);
    EXPECT_LE(rightExpected, rightActual);
    EXPECT_LE(leftExpected - error, leftActual);
    EXPECT_GE(rightExpected + error, rightActual);

    // 180度左回頭の回頭誤差が１度未満かテスト
    angle = 180;
    pwm = 30;
    targetDistance = M_PI * tread * abs(angle) / 360;

    leftExpected = Mileage::calculateWheelMileage(measurer.getLeftCount()) - targetDistance;
    rightExpected = Mileage::calculateWheelMileage(measurer.getRightCount()) + targetDistance;

    rotation.rotateLeft(angle, pwm);

    leftActual = Mileage::calculateWheelMileage(measurer.getLeftCount());
    rightActual = Mileage::calculateWheelMileage(measurer.getRightCount());

    EXPECT_GE(leftExpected, leftActual);
    EXPECT_LE(rightExpected, rightActual);
    EXPECT_LE(leftExpected - error, leftActual);
    EXPECT_GE(rightExpected + error, rightActual);

    // 360度左回頭の回頭誤差が１度未満かテスト
    angle = 360;
    pwm = 30;
    targetDistance = M_PI * tread * abs(angle) / 360;

    leftExpected = Mileage::calculateWheelMileage(measurer.getLeftCount()) - targetDistance;
    rightExpected = Mileage::calculateWheelMileage(measurer.getRightCount()) + targetDistance;

    rotation.rotateLeft(angle, pwm);

    leftActual = Mileage::calculateWheelMileage(measurer.getLeftCount());
    rightActual = Mileage::calculateWheelMileage(measurer.getRightCount());

    EXPECT_GE(leftExpected, leftActual);
    EXPECT_LE(rightExpected, rightActual);
    EXPECT_LE(leftExpected - error, leftActual);
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
    double tread = 140.0;
    double error = M_PI * tread / 360;  //誤差1度
    int angle, pwm;

    // 0度左回頭のテスト
    angle = 0;
    pwm = 30;
    targetDistance = M_PI * tread * abs(angle) / 360;

    leftExpected = Mileage::calculateWheelMileage(measurer.getLeftCount()) + targetDistance;
    rightExpected = Mileage::calculateWheelMileage(measurer.getRightCount()) - targetDistance;

    rotation.rotateLeft(angle, pwm);

    leftActual = Mileage::calculateWheelMileage(measurer.getLeftCount());
    rightActual = Mileage::calculateWheelMileage(measurer.getRightCount());

    EXPECT_DOUBLE_EQ(leftExpected, leftActual);
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
    double tread = 140.0;
    double error = M_PI * tread / 360;  //誤差1度
    int angle, pwm;

    // PWM値が100の時のテスト
    angle = 90;
    pwm = 100;
    targetDistance = M_PI * tread * abs(angle) / 360;

    leftExpected = Mileage::calculateWheelMileage(measurer.getLeftCount()) - targetDistance;
    rightExpected = Mileage::calculateWheelMileage(measurer.getRightCount()) + targetDistance;

    rotation.rotateLeft(angle, pwm);

    leftActual = Mileage::calculateWheelMileage(measurer.getLeftCount());
    rightActual = Mileage::calculateWheelMileage(measurer.getRightCount());

    EXPECT_GE(leftExpected, leftActual);
    EXPECT_LE(rightExpected, rightActual);
    EXPECT_LE(leftExpected - error, leftActual);
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
    double tread = 140.0;
    double error = M_PI * tread / 360;  //誤差1度
    int angle, pwm;

    // 回転角度がマイナス
    angle = -90;
    pwm = 100;
    targetDistance = M_PI * tread * abs(angle) / 360;

    leftExpected = Mileage::calculateWheelMileage(measurer.getLeftCount()) - targetDistance;
    rightExpected = Mileage::calculateWheelMileage(measurer.getRightCount()) + targetDistance;

    rotation.rotateLeft(angle, pwm);

    leftActual = Mileage::calculateWheelMileage(measurer.getLeftCount());
    rightActual = Mileage::calculateWheelMileage(measurer.getRightCount());

    EXPECT_GE(leftExpected, leftActual);
    EXPECT_LE(rightExpected, rightActual);
    EXPECT_LE(leftExpected - error, leftActual);
    EXPECT_GE(rightExpected + error, rightActual);

    // PWM値がマイナス
    angle = 90;
    pwm = -100;
    targetDistance = M_PI * tread * abs(angle) / 360;

    leftExpected = Mileage::calculateWheelMileage(measurer.getLeftCount()) - targetDistance;
    rightExpected = Mileage::calculateWheelMileage(measurer.getRightCount()) + targetDistance;

    rotation.rotateLeft(angle, pwm);

    leftActual = Mileage::calculateWheelMileage(measurer.getLeftCount());
    rightActual = Mileage::calculateWheelMileage(measurer.getRightCount());

    EXPECT_GE(leftExpected, leftActual);
    EXPECT_LE(rightExpected, rightActual);
    EXPECT_LE(leftExpected - error, leftActual);
    EXPECT_GE(rightExpected + error, rightActual);
  }

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
    double tread = 140.0;
    double error = M_PI * tread / 360;  //誤差1度
    int angle, pwm;

    // 90度右回頭の回頭誤差が１度未満かテスト
    angle = 90;
    pwm = 30;
    targetDistance = M_PI * tread * abs(angle) / 360;

    leftExpected = Mileage::calculateWheelMileage(measurer.getLeftCount()) + targetDistance;
    rightExpected = Mileage::calculateWheelMileage(measurer.getRightCount()) - targetDistance;

    rotation.rotateRight(angle, pwm);

    leftActual = Mileage::calculateWheelMileage(measurer.getLeftCount());
    rightActual = Mileage::calculateWheelMileage(measurer.getRightCount());

    EXPECT_LE(leftExpected, leftActual);
    EXPECT_GE(rightExpected, rightActual);
    EXPECT_GE(leftExpected + error, leftActual);
    EXPECT_LE(rightExpected - error, rightActual);

    // 180度右回頭の回頭誤差が１度未満かテスト
    angle = 180;
    pwm = 30;
    targetDistance = M_PI * tread * abs(angle) / 360;

    leftExpected = Mileage::calculateWheelMileage(measurer.getLeftCount()) + targetDistance;
    rightExpected = Mileage::calculateWheelMileage(measurer.getRightCount()) - targetDistance;

    rotation.rotateRight(angle, pwm);

    leftActual = Mileage::calculateWheelMileage(measurer.getLeftCount());
    rightActual = Mileage::calculateWheelMileage(measurer.getRightCount());

    EXPECT_LE(leftExpected, leftActual);
    EXPECT_GE(rightExpected, rightActual);
    EXPECT_GE(leftExpected + error, leftActual);
    EXPECT_LE(rightExpected - error, rightActual);
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
    double tread = 140.0;
    double error = M_PI * tread / 360;  //誤差1度
    int angle, pwm;

    // 0度右回頭のテスト
    angle = 0;
    pwm = 30;
    targetDistance = M_PI * tread * abs(angle) / 360;

    leftExpected = Mileage::calculateWheelMileage(measurer.getLeftCount()) + targetDistance;
    rightExpected = Mileage::calculateWheelMileage(measurer.getRightCount()) - targetDistance;

    rotation.rotateRight(angle, pwm);

    leftActual = Mileage::calculateWheelMileage(measurer.getLeftCount());
    rightActual = Mileage::calculateWheelMileage(measurer.getRightCount());

    EXPECT_DOUBLE_EQ(leftExpected, leftActual);
    EXPECT_DOUBLE_EQ(rightExpected, rightActual);
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
    double tread = 140.0;
    double error = M_PI * tread / 360;  //誤差1度
    int angle, pwm;

    // PWM値が100の時のテスト
    angle = 90;
    pwm = 100;
    targetDistance = M_PI * tread * abs(angle) / 360;

    leftExpected = Mileage::calculateWheelMileage(measurer.getLeftCount()) + targetDistance;
    rightExpected = Mileage::calculateWheelMileage(measurer.getRightCount()) - targetDistance;

    rotation.rotateRight(angle, pwm);

    leftActual = Mileage::calculateWheelMileage(measurer.getLeftCount());
    rightActual = Mileage::calculateWheelMileage(measurer.getRightCount());

    EXPECT_LE(leftExpected, leftActual);
    EXPECT_GE(rightExpected, rightActual);
    EXPECT_GE(leftExpected + error, leftActual);
    EXPECT_LE(rightExpected - error, rightActual);
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
    double tread = 140.0;
    double error = M_PI * tread / 360;  //誤差1度
    int angle, pwm;

    // 回転角度がマイナス
    angle = -90;
    pwm = 100;
    targetDistance = M_PI * tread * abs(angle) / 360;

    leftExpected = Mileage::calculateWheelMileage(measurer.getLeftCount()) + targetDistance;
    rightExpected = Mileage::calculateWheelMileage(measurer.getRightCount()) - targetDistance;

    rotation.rotateRight(angle, pwm);

    leftActual = Mileage::calculateWheelMileage(measurer.getLeftCount());
    rightActual = Mileage::calculateWheelMileage(measurer.getRightCount());

    EXPECT_LE(leftExpected, leftActual);
    EXPECT_GE(rightExpected, rightActual);
    EXPECT_GE(leftExpected + error, leftActual);
    EXPECT_LE(rightExpected - error, rightActual);

    // PWM値がマイナス
    angle = 90;
    pwm = -100;
    targetDistance = M_PI * tread * abs(angle) / 360;

    leftExpected = Mileage::calculateWheelMileage(measurer.getLeftCount()) + targetDistance;
    rightExpected = Mileage::calculateWheelMileage(measurer.getRightCount()) - targetDistance;

    rotation.rotateRight(angle, pwm);

    leftActual = Mileage::calculateWheelMileage(measurer.getLeftCount());
    rightActual = Mileage::calculateWheelMileage(measurer.getRightCount());

    EXPECT_LE(leftExpected, leftActual);
    EXPECT_GE(rightExpected, rightActual);
    EXPECT_GE(leftExpected + error, leftActual);
    EXPECT_LE(rightExpected - error, rightActual);
  }
  /*
      TEST(Rotation, turnForwardRightPivot)
      {
        constexpr double Radius = 45.0;
        constexpr double Tread = 140.0;
        constexpr double error = 2 * M_PI * Tread * 1 / 360;

        Measurer measurer;
        Rotation rotation;
        double expected, actual;
        double leftMotorCount;
        double Distance;
        int angle, pwm;

        // 45度右軸前方ピボットターン誤差が１度未満かテスト
        angle = 45;
        pwm = 30;
        Distance = 2 * M_PI * Tread * angle / 360;

        expected = Mileage::calculateWheelMileage(measurer.getLeftCount()) + Distance;

        rotation.turnForwardRightPivot(angle, pwm);

        actual = Mileage::calculateWheelMileage(measurer.getLeftCount());

        ASSERT_LE(expected, actual);
        ASSERT_GE(expected + error, actual);
      }

      TEST(Rotation, turnBackRightPivot)
      {
        constexpr double Radius = 45.0;
        constexpr double Tread = 140.0;
        constexpr double error = 2 * M_PI * Tread * 1 / 360;

        Measurer measurer;
        Rotation rotation;
        double expected, actual;
        double leftMotorCount;
        double Distance;
        int angle, pwm;

        // 45度右軸後方ピボットターン誤差が１度未満かテスト
        angle = 45;
        pwm = 30;
        Distance = 2 * M_PI * Tread * angle / 360;

        expected = Mileage::calculateWheelMileage(measurer.getLeftCount()) - Distance;

        rotation.turnBackRightPivot(angle, pwm);

        actual = Mileage::calculateWheelMileage(measurer.getLeftCount());

        ASSERT_LE(expected, actual);
        ASSERT_GE(expected - error, actual);
      }

      TEST(Rotation, turnForwardLeftPivot)
      {
        constexpr double Radius = 45.0;
        constexpr double Tread = 140.0;
        constexpr double error = 2 * M_PI * Tread * 1 / 360;

        Measurer measurer;
        Rotation rotation;
        double expected, actual;
        double rightMotorCount;
        double Distance;
        int angle, pwm;

        // 45度左軸前方ピボットターン誤差が１度未満かテスト
        angle = 45;
        pwm = 30;
        Distance = 2 * M_PI * Tread * angle / 360;

        expected = Mileage::calculateWheelMileage(measurer.getRightCount()) + Distance;

        rotation.turnForwardLeftPivot(angle, pwm);

        actual = Mileage::calculateWheelMileage(measurer.getRightCount());

        ASSERT_LE(expected, actual);
        ASSERT_GE(expected + error, actual);
      }

      TEST(Rotation, turnBackLeftPivot)
      {
        constexpr double Radius = 45.0;
        constexpr double Tread = 140.0;
        constexpr double error = 2 * M_PI * Tread * 1 / 360;

        Measurer measurer;
        Rotation rotation;
        double expected, actual;
        double rightMotorCount;
        double Distance;
        int angle, pwm;

        // 45度左軸後方ピボットターン誤差が１度未満かテスト
        angle = 45;
        pwm = 30;
        Distance = 2 * M_PI * Tread * angle / 360;

        expected = Mileage::calculateWheelMileage(measurer.getRightCount()) - Distance;

        rotation.turnBackLeftPivot(angle, pwm);

        actual = Mileage::calculateWheelMileage(measurer.getRightCount());

        ASSERT_LE(expected, actual);
        ASSERT_GE(expected - error, actual);
      }
*/
}  // namespace etrobocon2021_test
