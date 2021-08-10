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

    motionPerformer.moveStraight();
    expected_motionLog.push_back(MOTION::ST);
    motionPerformer.turnRight();
    expected_motionLog.push_back(MOTION::TR);
    motionPerformer.turnLeft();
    expected_motionLog.push_back(MOTION::TL);
    motionPerformer.moveBetweenCross();
    expected_motionLog.push_back(MOTION::BC);
    motionPerformer.pibotTurn(true);
    expected_motionLog.push_back(MOTION::PSETR);
    motionPerformer.pibotTurn(false);
    expected_motionLog.push_back(MOTION::PSETL);
    motionPerformer.throwBlock(true);
    expected_motionLog.push_back(MOTION::TSETR);
    motionPerformer.throwBlock(false);
    expected_motionLog.push_back(MOTION::TSETL);
    motionPerformer.turnAround(45, true);
    expected_motionLog.push_back(MOTION::TAC);
    motionPerformer.turnAround(-180, true);
    for(int i = 0; i < 4; i++) {
      expected_motionLog.push_back(MOTION::TARC);
    }

    EXPECT_EQ(MotionPerformer::motionLog, expected_motionLog);
  }
}  // namespace etrobocon2021_test