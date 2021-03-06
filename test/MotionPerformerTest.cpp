/**
 * @file MotionPerformerTest.cpp
 * @brief 動作実行クラスのテスト
 * @author Hisataka-Hagiyama,uchyam
 */
#include "MotionPerformer.h"
#include <gtest/gtest.h>

namespace etrobocon2021_test {
  TEST(MotionPerformerTest, test)
  {
    LineTracer trace(true);
    MotionPerformer motionPerformer(trace);
    std::vector<MOTION> expected_motionLog;
    MotionPerformer::motionLog.clear();  //他クラスで記録した履歴を消去する
    motionPerformer.runForward();
    expected_motionLog.push_back(MOTION::RF);
    motionPerformer.runRight();
    expected_motionLog.push_back(MOTION::RR);
    motionPerformer.runLeft();
    expected_motionLog.push_back(MOTION::RL);
    motionPerformer.runToCross();
    expected_motionLog.push_back(MOTION::RTC);
    motionPerformer.setBlockPivotTurn(true);
    expected_motionLog.push_back(MOTION::SBPR);
    motionPerformer.setBlockPivotTurn(false);
    expected_motionLog.push_back(MOTION::SBPL);
    motionPerformer.setBlockThrow(true);
    expected_motionLog.push_back(MOTION::SBTR);
    motionPerformer.setBlockThrow(false);
    expected_motionLog.push_back(MOTION::SBTL);
    motionPerformer.changeDirection(45, true);
    expected_motionLog.push_back(MOTION::CDC);
    motionPerformer.changeDirection(-180, true);
    for(int i = 0; i < 4; i++) {
      expected_motionLog.push_back(MOTION::CDRC);
    }

    EXPECT_EQ(MotionPerformer::motionLog, expected_motionLog);
  }
}  // namespace etrobocon2021_test
