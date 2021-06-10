/**
 * @file LineTracerTest.cpp
 * @brief ライントレーサークラスのテストファイル
 * @author yutotanaka24, kodama0720
 */
#include "LineTracer.h"
#include <gtest/gtest.h>

namespace etrobocon2021_test {

  TEST(LineTracerTest, run)
  {
    double targetDistance;
    int targetValue = 500;
    int pwm = 50;
    Pid pid(0.1, 0.1, 0.1);
    int edge = 1;
    double currentDistance = 100;
    double currentPid = pid.calculatePid(measurer.getBrightness()) * edge;
  }

  TEST(LineTracerTest, run)
  {
    double targetDistance = 500;
    int targetValue = 50;
    int pwm = 50;
    PidGain gain(0.1, 0.1, 0.1);
    int edge = -1;
    Pid pid(gain.kp, gain.ki, gain.kd, targetValue);
    // double currentDistance = 0;
    double currentPid = pid.calculatePid(measurer.getBrightness()) * edge;
  }
}  // namespace etrobocon2021_test
