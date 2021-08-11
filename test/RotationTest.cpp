/**
 *  @file   RotationTest.cpp
 *  @brief  Rotationクラスのテストファイル
 *  @author kodama0720, yutotanaka24, Hisataka-Hagiyama
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
    double error = M_PI * tread / 360 * 5;  //誤差5度
    int angle, pwm;

    // 90度左回頭の回頭誤差が5度未満かテスト

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

    // 180度左回頭の回頭誤差が5度未満かテスト
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

    // 360度左回頭の回頭誤差が5度未満かテスト
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
    double error = M_PI * tread / 360 * 5;  //誤差5度
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
    double error = M_PI * tread / 360 * 5;  //誤差5度
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
    double error = M_PI * tread / 360 * 5;  //誤差5度
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
    double error = M_PI * tread / 360 * 5;  //誤差5度
    int angle, pwm;

    // 90度右回頭の回頭誤差が5度未満かテスト
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

    // 180度右回頭の回頭誤差が5度未満かテスト
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
    double error = M_PI * tread / 360 * 5;  //誤差5度
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
    double error = M_PI * tread / 360 * 5;  //誤差5度
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
    double error = M_PI * tread / 360 * 5;  //誤差5度
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

  TEST(Rotation, turnForwardRightPivot)
  {
    Measurer measurer;
    Rotation rotation;
    double leftExpected;
    double leftActual;
    double leftMotorCount;
    double distance;
    double tread = 140.0;
    double error = 2 * M_PI * tread / 360 * 5;  //誤差5度
    int angle, pwm;

    // 90度右軸前方ピボットターン誤差が5度未満かテスト
    angle = 90;
    pwm = 30;
    distance = 2 * M_PI * tread * angle / 360;
    // 期待する走行距離
    leftExpected = Mileage::calculateWheelMileage(measurer.getLeftCount()) + distance;
    // 右軸前方ピボットターン
    rotation.turnForwardRightPivot(angle, pwm);
    // 関数実行後の走行距離
    leftActual = Mileage::calculateWheelMileage(measurer.getLeftCount());
    // 誤差のテスト
    EXPECT_LE(leftExpected, leftActual);
    EXPECT_GE(leftExpected + error, leftActual);

    // 180度右軸前方ピボットターン誤差が5度未満かテスト
    angle = 180;
    pwm = 30;
    distance = 2 * M_PI * tread * angle / 360;
    // 期待する走行距離
    leftExpected = Mileage::calculateWheelMileage(measurer.getLeftCount()) + distance;
    // 右軸前方ピボットターン
    rotation.turnForwardRightPivot(angle, pwm);
    // 関数実行後の走行距離
    leftActual = Mileage::calculateWheelMileage(measurer.getLeftCount());
    // 誤差のテスト
    EXPECT_LE(leftExpected, leftActual);
    EXPECT_GE(leftExpected + error, leftActual);

    // 360度右軸前方ピボットターン誤差が5度未満かテスト
    angle = 360;
    pwm = 30;
    distance = 2 * M_PI * tread * angle / 360;
    // 期待する走行距離
    leftExpected = Mileage::calculateWheelMileage(measurer.getLeftCount()) + distance;
    // 右軸前方ピボットターン
    rotation.turnForwardRightPivot(angle, pwm);
    // 関数実行後の走行距離
    leftActual = Mileage::calculateWheelMileage(measurer.getLeftCount());
    // 誤差のテスト
    EXPECT_LE(leftExpected, leftActual);
    EXPECT_GE(leftExpected + error, leftActual);
  }

  TEST(Rotation, turnForwardRightPivot_zero)
  {
    Measurer measurer;
    Rotation rotation;
    double leftExpected;
    double leftActual;
    double leftMotorCount;
    double distance;
    double tread = 140.0;
    double error = 2 * M_PI * tread / 360 * 5;  //誤差5度
    int angle, pwm;

    // 0度右軸前方ピボットターンのテスト
    angle = 0;
    pwm = 30;
    distance = 2 * M_PI * tread * angle / 360;

    leftExpected = Mileage::calculateWheelMileage(measurer.getLeftCount()) + distance;

    rotation.turnForwardRightPivot(angle, pwm);

    leftActual = Mileage::calculateWheelMileage(measurer.getLeftCount());

    EXPECT_DOUBLE_EQ(leftExpected, leftActual);
  }

  TEST(Rotation, turnForwardRightPivot_maxpwm)
  {
    Measurer measurer;
    Rotation rotation;
    double leftExpected;
    double leftActual;
    double leftMotorCount;
    double distance;
    double tread = 140.0;
    double error = 2 * M_PI * tread / 360 * 5;  //誤差5度
    int angle, pwm;

    // PWM値が100の時のテスト
    angle = 90;
    pwm = 100;
    distance = 2 * M_PI * tread * angle / 360;

    leftExpected = Mileage::calculateWheelMileage(measurer.getLeftCount()) + distance;

    rotation.turnForwardRightPivot(angle, pwm);

    leftActual = Mileage::calculateWheelMileage(measurer.getLeftCount());

    EXPECT_LE(leftExpected, leftActual);
    EXPECT_GE(leftExpected + error, leftActual);
  }

  TEST(Rotation, turnBackRightPivot)
  {
    Measurer measurer;
    Rotation rotation;
    double leftExpected;
    double leftActual;
    double leftMotorCount;
    double distance;
    double tread = 140.0;
    double error = 2 * M_PI * tread / 360 * 5;  //誤差5度
    int angle, pwm;

    // 90度右軸後方ピボットターン誤差が5度未満かテスト
    angle = 90;
    pwm = 30;
    distance = 2 * M_PI * tread * angle / 360;
    // 期待する走行距離
    leftExpected = Mileage::calculateWheelMileage(measurer.getLeftCount()) - distance;
    // 右軸後方ピボットターン
    rotation.turnBackRightPivot(angle, pwm);
    // 関数実行後の走行距離
    leftActual = Mileage::calculateWheelMileage(measurer.getLeftCount());
    // 誤差のテスト
    EXPECT_GE(leftExpected, leftActual);
    EXPECT_LE(leftExpected - error, leftActual);

    // 180度右軸後方ピボットターン誤差が5度未満かテスト
    angle = 180;
    pwm = 30;
    distance = 2 * M_PI * tread * angle / 360;
    // 期待する走行距離
    leftExpected = Mileage::calculateWheelMileage(measurer.getLeftCount()) - distance;
    // 右軸後方ピボットターン
    rotation.turnBackRightPivot(angle, pwm);
    // 関数実行後の走行距離
    leftActual = Mileage::calculateWheelMileage(measurer.getLeftCount());
    // 誤差のテスト
    EXPECT_GE(leftExpected, leftActual);
    EXPECT_LE(leftExpected - error, leftActual);

    // 360度右軸後方ピボットターン誤差が5度未満かテスト
    angle = 360;
    pwm = 30;
    distance = 2 * M_PI * tread * angle / 360;
    // 期待する走行距離
    leftExpected = Mileage::calculateWheelMileage(measurer.getLeftCount()) - distance;
    // 右軸後方ピボットターン
    rotation.turnBackRightPivot(angle, pwm);
    // 関数実行後の走行距離
    leftActual = Mileage::calculateWheelMileage(measurer.getLeftCount());
    // 誤差のテスト
    EXPECT_GE(leftExpected, leftActual);
    EXPECT_LE(leftExpected - error, leftActual);
  }

  TEST(Rotation, turnBackdRightPivot_zero)
  {
    Measurer measurer;
    Rotation rotation;
    double leftExpected;
    double leftActual;
    double leftMotorCount;
    double distance;
    double tread = 140.0;
    double error = 2 * M_PI * tread / 360 * 5;  //誤差5度
    int angle, pwm;

    // 0度右軸後方ピボットターンのテスト
    angle = 0;
    pwm = 30;
    distance = 2 * M_PI * tread * angle / 360;

    leftExpected = Mileage::calculateWheelMileage(measurer.getLeftCount()) - distance;

    rotation.turnBackRightPivot(angle, pwm);

    leftActual = Mileage::calculateWheelMileage(measurer.getLeftCount());

    EXPECT_DOUBLE_EQ(leftExpected, leftActual);
  }

  TEST(Rotation, turnBackRightPivot_maxpwm)
  {
    Measurer measurer;
    Rotation rotation;
    double leftExpected;
    double leftActual;
    double leftMotorCount;
    double distance;
    double tread = 140.0;
    double error = 2 * M_PI * tread / 360 * 5;  //誤差5度
    int angle, pwm;

    // PWM値が100の時のテスト
    angle = 90;
    pwm = 100;
    distance = 2 * M_PI * tread * angle / 360;

    leftExpected = Mileage::calculateWheelMileage(measurer.getLeftCount()) - distance;

    rotation.turnBackRightPivot(angle, pwm);

    leftActual = Mileage::calculateWheelMileage(measurer.getLeftCount());

    EXPECT_GE(leftExpected, leftActual);
    EXPECT_LE(leftExpected - error, leftActual);
  }

  TEST(Rotation, turnForwardLeftPivot)
  {
    Measurer measurer;
    Rotation rotation;
    double rightExpected;
    double rightActual;
    double rightMotorCount;
    double distance;
    double tread = 140.0;
    double error = 2 * M_PI * tread / 360 * 5;  //誤差5度
    int angle, pwm;

    // 90度左軸前方ピボットターン誤差が5度未満かテスト
    angle = 90;
    pwm = 30;
    distance = 2 * M_PI * tread * angle / 360;
    // 期待する走行距離
    rightExpected = Mileage::calculateWheelMileage(measurer.getRightCount()) + distance;
    // 左軸前方ピボットターン
    rotation.turnForwardLeftPivot(angle, pwm);
    // 関数実行後の走行距離
    rightActual = Mileage::calculateWheelMileage(measurer.getRightCount());
    // 誤差のテスト
    EXPECT_LE(rightExpected, rightActual);
    EXPECT_GE(rightExpected + error, rightActual);

    // 180度左軸前方ピボットターン誤差が5度未満かテスト
    angle = 180;
    pwm = 30;
    distance = 2 * M_PI * tread * angle / 360;
    // 期待する走行距離
    rightExpected = Mileage::calculateWheelMileage(measurer.getRightCount()) + distance;
    // 左軸前方ピボットターン
    rotation.turnForwardLeftPivot(angle, pwm);
    // 関数実行後の走行距離
    rightActual = Mileage::calculateWheelMileage(measurer.getRightCount());
    // 誤差のテスト
    EXPECT_LE(rightExpected, rightActual);
    EXPECT_GE(rightExpected + error, rightActual);

    // 360度左軸前方ピボットターン誤差が5度未満かテスト
    angle = 360;
    pwm = 30;
    distance = 2 * M_PI * tread * angle / 360;
    // 期待する走行距離
    rightExpected = Mileage::calculateWheelMileage(measurer.getRightCount()) + distance;
    // 左軸前方ピボットターン
    rotation.turnForwardLeftPivot(angle, pwm);
    // 関数実行後の走行距離
    rightActual = Mileage::calculateWheelMileage(measurer.getRightCount());
    // 誤差のテスト
    EXPECT_LE(rightExpected, rightActual);
    EXPECT_GE(rightExpected + error, rightActual);
  }

  TEST(Rotation, turnForwardLeftPivot_zero)
  {
    Measurer measurer;
    Rotation rotation;
    double rightExpected;
    double rightActual;
    double rightMotorCount;
    double distance;
    double tread = 140.0;
    double error = 2 * M_PI * tread / 360 * 5;  //誤差5度
    int angle, pwm;

    // 0度左軸前方ピボットターンのテスト
    angle = 0;
    pwm = 30;
    distance = 2 * M_PI * tread * angle / 360;

    rightExpected = Mileage::calculateWheelMileage(measurer.getRightCount()) + distance;

    rotation.turnForwardLeftPivot(angle, pwm);

    rightActual = Mileage::calculateWheelMileage(measurer.getRightCount());

    EXPECT_DOUBLE_EQ(rightExpected, rightActual);
  }

  TEST(Rotation, turnForwardLeftPivot_maxpwm)
  {
    Measurer measurer;
    Rotation rotation;
    double rightExpected;
    double rightActual;
    double rightMotorCount;
    double distance;
    double tread = 140.0;
    double error = 2 * M_PI * tread / 360 * 5;  //誤差5度
    int angle, pwm;

    // PWM値が100の時のテスト
    angle = 90;
    pwm = 100;
    distance = 2 * M_PI * tread * angle / 360;

    rightExpected = Mileage::calculateWheelMileage(measurer.getRightCount()) + distance;

    rotation.turnForwardLeftPivot(angle, pwm);

    rightActual = Mileage::calculateWheelMileage(measurer.getRightCount());

    EXPECT_LE(rightExpected, rightActual);
    EXPECT_GE(rightExpected + error, rightActual);
  }

  TEST(Rotation, turnBackLeftPivot)
  {
    Measurer measurer;
    Rotation rotation;
    double rightExpected;
    double rightActual;
    double rightMotorCount;
    double distance;
    double tread = 140.0;
    double error = 2 * M_PI * tread / 360 * 5;  //誤差5度
    int angle, pwm;

    // 90度左軸後方ピボットターン誤差が5度未満かテスト
    angle = 90;
    pwm = 30;
    distance = 2 * M_PI * tread * angle / 360;
    // 期待する走行距離
    rightExpected = Mileage::calculateWheelMileage(measurer.getRightCount()) - distance;
    // 左軸後方ピボットターン
    rotation.turnBackLeftPivot(angle, pwm);
    // 関数実行後の走行距離
    rightActual = Mileage::calculateWheelMileage(measurer.getRightCount());
    // 誤差のテスト
    EXPECT_GE(rightExpected, rightActual);
    EXPECT_LE(rightExpected - error, rightActual);

    // 180度左軸後方ピボットターン誤差が5度未満かテスト
    angle = 180;
    pwm = 30;
    distance = 2 * M_PI * tread * angle / 360;
    // 期待する走行距離
    rightExpected = Mileage::calculateWheelMileage(measurer.getRightCount()) - distance;
    // 左軸後方ピボットターン
    rotation.turnBackLeftPivot(angle, pwm);
    // 関数実行後の走行距離
    rightActual = Mileage::calculateWheelMileage(measurer.getRightCount());
    // 誤差のテスト
    EXPECT_GE(rightExpected, rightActual);
    EXPECT_LE(rightExpected - error, rightActual);

    // 360度左軸後方ピボットターン誤差が5度未満かテスト
    angle = 360;
    pwm = 30;
    distance = 2 * M_PI * tread * angle / 360;
    // 期待する走行距離
    rightExpected = Mileage::calculateWheelMileage(measurer.getRightCount()) - distance;
    // 左軸後方ピボットターン
    rotation.turnBackLeftPivot(angle, pwm);
    // 関数実行後の走行距離
    rightActual = Mileage::calculateWheelMileage(measurer.getRightCount());
    // 誤差のテスト
    EXPECT_GE(rightExpected, rightActual);
    EXPECT_LE(rightExpected - error, rightActual);
  }

  TEST(Rotation, turnBackLeftPivot_zero)
  {
    Measurer measurer;
    Rotation rotation;
    double rightExpected;
    double rightActual;
    double rightMotorCount;
    double distance;
    double tread = 140.0;
    double error = 2 * M_PI * tread / 360 * 5;  //誤差5度
    int angle, pwm;

    // 0度左軸後方ピボットターンのテスト
    angle = 0;
    pwm = 30;
    distance = 2 * M_PI * tread * angle / 360;

    rightExpected = Mileage::calculateWheelMileage(measurer.getRightCount()) - distance;

    rotation.turnBackLeftPivot(angle, pwm);

    rightActual = Mileage::calculateWheelMileage(measurer.getRightCount());

    EXPECT_DOUBLE_EQ(rightExpected, rightActual);
  }

  TEST(Rotation, turnBackLeftPivot_maxpwm)
  {
    Measurer measurer;
    Rotation rotation;
    double rightExpected;
    double rightActual;
    double rightMotorCount;
    double distance;
    double tread = 140.0;
    double error = 2 * M_PI * tread / 360 * 5;  //誤差5度
    int angle, pwm;

    // PWM値が100の時のテスト
    //誤差2度未満
    angle = 90;
    pwm = 100;
    distance = 2 * M_PI * tread * angle / 360;

    rightExpected = Mileage::calculateWheelMileage(measurer.getRightCount()) - distance;

    rotation.turnBackLeftPivot(angle, pwm);

    rightActual = Mileage::calculateWheelMileage(measurer.getRightCount());

    EXPECT_GE(rightExpected, rightActual);
    EXPECT_LE(rightExpected - 2 * error, rightActual);
  }

}  // namespace etrobocon2021_test
