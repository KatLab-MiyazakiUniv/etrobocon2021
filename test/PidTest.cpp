/**
 *  @file PidTest.cpp
 *  @brief PidGainクラス,Pidクラスをテストする
 *  @author Hisataka-Hagiyama,uchiyam
 */

#include "Pid.h"
#include <gtest/gtest.h>

namespace etrobocon2021_test {
  TEST(PidGainTest, gain)
  {
    PidGain myPidGain(0.1, 0.03, 0.612);
    EXPECT_DOUBLE_EQ(0.1, myPidGain.kp);
    EXPECT_DOUBLE_EQ(0.03, myPidGain.ki);
    EXPECT_DOUBLE_EQ(0.612, myPidGain.kd);
  }

  TEST(PidGainTest, gain_zero)
  {
    PidGain myPidGain(0.0, 0.0, 0.0);
    EXPECT_DOUBLE_EQ(0.0, myPidGain.kp);
    EXPECT_DOUBLE_EQ(0.0, myPidGain.ki);
    EXPECT_DOUBLE_EQ(0.0, myPidGain.kd);
  }

  TEST(PidGainTest, gain_minus)
  {
    PidGain myPidGain(-0.5, -0.2, -0.3);
    EXPECT_DOUBLE_EQ(-0.5, myPidGain.kp);
    EXPECT_DOUBLE_EQ(-0.2, myPidGain.ki);
    EXPECT_DOUBLE_EQ(-0.3, myPidGain.kd);
  }

  TEST(setPidGainTest, set)
  {
    Pid myPid(-0.5, -0.2, -0.3);
    myPid.setPidGain(0.5, 0.2, 0.3);
  }

  TEST(setPidGainTest, set_minus)
  {
    Pid myPid(0.32, 0.01, 0.05);
    myPid.setPidGain(-0.1, -0.09, -0.2);
  }

  TEST(setPidGainTest, set_zero)
  {
    Pid myPid(0.01, -0.9, 0.012);
    myPid.setPidGain(0.0, 0.0, 0.0);
  }

  TEST(PidTest, caluculatePid)
  {
    Pid myPid(0.6, 0.02, 0.03);
    double targetValue = 127.5;
    double presentValue = 20;
    double presentDeviation = (targetValue - presentValue);
    double p = presentDeviation * 0.6;
    double i = presentDeviation * DELTA * 0.02;
    double d = (presentDeviation - 0) * 0.03 / DELTA;
    double expected = p + i + d;
    EXPECT_DOUBLE_EQ(expected, myPid.calculatePid(targetValue, presentValue));
  }

  TEST(PidTest, caluculatePid_zero)
  {
    Pid myPid(0, 0, 0);
    double targetValue = 127.5;
    double presentValue = 20;
    double presentDeviation = (targetValue - presentValue);
    double p = presentDeviation * 0;
    double i = presentDeviation * DELTA * 0;
    double d = (presentDeviation - 0) * 0 / DELTA;
    double expected = p + i + d;
    EXPECT_DOUBLE_EQ(expected, myPid.calculatePid(targetValue, presentValue));
  }

  TEST(calculatePidTest, caluculatePid_minus)
  {
    Pid myPid(-0.3, -0.02, -0.175);
    double targetValue = 127.5;
    double presentValue = 20;
    double presentDeviation = (targetValue - presentValue);
    double p = presentDeviation * -0.3;
    double i = presentDeviation * DELTA * -0.02;
    double d = (presentDeviation - 0) * -0.175 / DELTA;
    double expected = p + i + d;
    EXPECT_DOUBLE_EQ(expected, myPid.calculatePid(targetValue, presentValue));
  }

  TEST(calculatePidTest, caluclatePid_twice)
  {
    Pid myPid(0.6, 0.05, 0.01);  // PIDゲインの初期化
    double targetValue = 80;
    double presentValue = 60;
    double presentDiviation = (targetValue - presentValue);  //現在の偏差
    double p = presentDiviation * 0.6;                       // P制御
    double i = presentDiviation * DELTA * 0.05;              // I制御(誤差の累積は0)
    double d = (presentDiviation - 0) * 0.01 / DELTA;        // D制御(前回の誤差は0)
    EXPECT_DOUBLE_EQ(p + i + d, myPid.calculatePid(targetValue, presentValue));

    double integral = presentDiviation * DELTA;  //誤差の累積
    double preDeviation = presentDiviation;      //前回の誤差の更新
    myPid.setPidGain(0.1, 0.2, 0.3);             // PIDゲインの更新
    targetValue = 90;
    presentValue = 100;
    presentDiviation = (targetValue - presentValue);
    integral += presentDiviation * DELTA;
    p = presentDiviation * 0.1;
    i = integral * 0.2;
    d = (presentDiviation - preDeviation) / DELTA * 0.3;
    EXPECT_DOUBLE_EQ(p + i + d, myPid.calculatePid(targetValue, presentValue));
  }

}  // namespace etrobocon2021_test
