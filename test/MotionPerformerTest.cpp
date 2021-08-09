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
    std::vector<MOTION> motionLog;
    std::vector<MOTION> expected_motionLog;

    motionPerformer.moveStraight();
    expected_motionLog.push_back(MOTION::ST);
    motionPerformer.turnLeft();
    expected_motionLog.push_back(MOTION::TL);
    motionPerformer.turnRight();
    expected_motionLog.push_back(MOTION::TR);
    motionPerformer.turnAround(45, true);
    expected_motionLog.push_back(MOTION::TAC);
    motionPerformer.turnAround(-90, true);
    for(int i = 0; i < 2; i++) {
      expected_motionLog.push_back(MOTION::TARC);
    }
    motionPerformer.turnAround(135, true);
    for(int i2 = 0; i2 < 3; i2++) {
      expected_motionLog.push_back(MOTION::TAC);
    }
    motionPerformer.turnAround(-180, true);
    for(int i3 = 0; i3 < 4; i3++) {
      expected_motionLog.push_back(MOTION::TARC);
    }
    motionPerformer.pibotTurn(true);
    expected_motionLog.push_back(MOTION::PSETR);
    motionPerformer.throwBlock(false);
    expected_motionLog.push_back(MOTION::TSETL);

    EXPECT_EQ(motionPerformer.motionLog, expected_motionLog);
  }
}  // namespace etrobocon2021_test