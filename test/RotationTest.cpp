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
    double tread = 140.0;

    Measurer measurer;
    Controller controller;
    Rotation rotation;
    double leftExpected, rightExpected;
    double leftActual, rightActual;
    double leftMotorCount;
    double rightMotorCount;
    double targetDistance;
    double error = M_PI * tread / 360;
    int angle, pwm;

    // 45度左回頭の回頭誤差が１度未満かテスト
    angle = 45;
    pwm = 30;
    targetDistance = M_PI * tread * abs(angle) / 360;
    printf("こここ\n");
    leftExpected = Mileage::calculateWheelMileage(controller.getLeftCount()) - targetDistance;
    rightExpected = Mileage::calculateWheelMileage(controller.getRightCount()) + targetDistance;
    printf("こここ%lf %lf\n", leftExpected, rightExpected);
    // int i = 0;
    // int a = 0;
    // while(i < 3) {
    //   // pwm値設定
    //   controller.setLeftMotorPwm(abs(pwm) * -1);
    //   controller.setRightMotorPwm(abs(pwm) * 1);

    //   // pwm値取得
    //   int a = controller.getRightCount();

    //   printf("%d\n", a);  // 1.5ずつ増えてほしい

    //    leftExpected = Mileage::calculateWheelMileage(controller.getLeftCount());
    //    rightExpected = Mileage::calculateWheelMileage(controller.getRightCount());

    //    printf("こここ%lf %lf\n", leftExpected, rightExpected);
    //   i++;
    // }
       rotation.rotateLeft(angle, pwm);

        leftActual = Mileage::calculateWheelMileage(controller.getLeftCount());
        rightActual = Mileage::calculateWheelMileage(controller.getRightCount());
   
        EXPECT_GE(leftExpected, leftActual);
        EXPECT_LE(rightExpected, rightActual);
        EXPECT_LE(leftExpected - error, leftActual);
        EXPECT_GE(rightExpected + error, rightActual);
  }
}
/*   
       // 90度左回頭の回頭誤差が１度未満かテスト
       angle = 90;
       pwm = 30;
       targetDistance = M_PI * Tread * abs(angle) / 360;
   
       leftExpected = Mileage::calculateWheelMileage(measurer.getLeftCount()) - targetDistance;
       rightExpected = Mileage::calculateWheelMileage(measurer.getRightCount()) + targetDistance;
   
       rotation.rotateLeft(angle, pwm);
   
       leftActual = Mileage::calculateWheelMileage(measurer.getLeftCount());
       rightActual = Mileage::calculateWheelMileage(measurer.getRightCount());
   
       ASSERT_GE(leftExpected, leftActual);
       ASSERT_LE(rightExpected, rightActual);
       ASSERT_LE(leftExpected - error, leftActual);
       ASSERT_GE(rightExpected + error, rightActual);
   
       // 180度左回頭の回頭誤差が１度未満かテスト
       angle = 180;
       pwm = 30;
       targetDistance = M_PI * Tread * abs(angle) / 360;
   
       leftExpected = Mileage::calculateWheelMileage(measurer.getLeftCount()) - targetDistance;
       rightExpected = Mileage::calculateWheelMileage(measurer.getRightCount()) + targetDistance;
   
       rotation.rotateLeft(angle, pwm);
   
       leftActual = Mileage::calculateWheelMileage(measurer.getLeftCount());
       rightActual = Mileage::calculateWheelMileage(measurer.getRightCount());
   
       ASSERT_GE(leftExpected, leftActual);
       ASSERT_LE(rightExpected, rightActual);
       ASSERT_LE(leftExpected - error, leftActual);
       ASSERT_GE(rightExpected + error, rightActual);
   
       // 360度左回頭の回頭誤差が１度未満かテスト
       angle = 360;
   
       pwm = 30;
       targetDistance = M_PI * Tread * abs(angle) / 360;
   
       leftExpected = Mileage::calculateWheelMileage(measurer.getLeftCount()) - targetDistance;
       rightExpected = Mileage::calculateWheelMileage(measurer.getRightCount()) + targetDistance;
   
       rotation.rotateLeft(angle, pwm);
   
       leftActual = Mileage::calculateWheelMileage(measurer.getLeftCount());
       rightActual = Mileage::calculateWheelMileage(measurer.getRightCount());
   
       ASSERT_GE(leftExpected, leftActual);
       ASSERT_LE(rightExpected, rightActual);
       ASSERT_LE(leftExpected - error, leftActual);
       ASSERT_GE(rightExpected + error, rightActual);
     }
     // namespace etrobocon2021_test
   */

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

}  // namespace etrobocon2021_test
*/