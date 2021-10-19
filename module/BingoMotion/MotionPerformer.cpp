/**
 * @file	MotionPerformer.cpp
 * @brief	動作実行クラス
 * @author	Hisataka-Hagiyama,uchyam
 */

#include "MotionPerformer.h"

MotionPerformer::MotionPerformer(LineTracer& _lineTracer)
  : lineTracer(_lineTracer),
    inCrossRight(_lineTracer),
    inCrossLeft(_lineTracer),
    toCrossMotion(_lineTracer),
    directionChanger(_lineTracer)
{
}

std::vector<MOTION> MotionPerformer::motionLog = {};

void MotionPerformer::runForward()
{
  inCrossStraight.runForward();
  motionLog.push_back(MOTION::RF);
}

void MotionPerformer::runRight()
{
  inCrossRight.runRight();
  motionLog.push_back(MOTION::RR);
}

void MotionPerformer::runLeft()
{
  inCrossLeft.runLeft();
  motionLog.push_back(MOTION::RL);
}

void MotionPerformer::runToCross()
{
  toCrossMotion.runToCross();
  motionLog.push_back(MOTION::RTC);
}

void MotionPerformer::changeDirection(int rotateAngle, int changeAngle)
{
  directionChanger.changeDirection(rotateAngle, changeAngle);

  int tmp = std::abs(rotateAngle / 45);
  for(int i = 0; i < tmp; i++) {
    if(rotateAngle > 0) {
      motionLog.push_back(MOTION::CDC);
    } else {
      motionLog.push_back(MOTION::CDRC);
    }
  }
}

void MotionPerformer::setBlockPivotTurn(bool isClockwise)
{
  blockPivotTurn.setBlockPivotTurn(isClockwise);
  if(isClockwise) {
    motionLog.push_back(MOTION::SBPR);
  } else {
    motionLog.push_back(MOTION::SBPL);
  }
}

void MotionPerformer::setBlockThrow(bool isClockwise)
{
  blockThrower.setBlockThrow(isClockwise);
  if(isClockwise) {
    motionLog.push_back(MOTION::SBTR);
  } else {
    motionLog.push_back(MOTION::SBTL);
  }
}

double MotionPerformer::getMotionTimeRunForward()
{
  return inCrossStraight.getMotionTime();
}

double MotionPerformer::getMotionTimeRunRight()
{
  return inCrossRight.getMotionTime();
}

double MotionPerformer::getMotionTimeRunLeft()
{
  return inCrossLeft.getMotionTime();
}

double MotionPerformer::getMotionTimeRunToCross()
{
  return toCrossMotion.getMotionTime();
}

double MotionPerformer::getMotionTimeChangeDirection(int angle)
{
  // 時間コスト = (時間コスト係数)*回転角度 + オーバーヘッド
  return directionChanger.getMotionTime() * static_cast<double>(angle / 45.0) + 0.458;
}

double MotionPerformer::getMotionTimePivotTurn()
{
  return blockPivotTurn.getMotionTime();
}

double MotionPerformer::getMotionTimeThrowBlock()
{
  return blockThrower.getMotionTime();
}

double MotionPerformer::getFailureRiskRunForward()
{
  return inCrossStraight.getFailureRisk();
}

double MotionPerformer::getFailureRiskRunRight()
{
  return inCrossRight.getFailureRisk();
}

double MotionPerformer::getFailureRiskRunLeft()
{
  return inCrossLeft.getFailureRisk();
}

double MotionPerformer::getFailureRiskRunToCross()
{
  return toCrossMotion.getFailureRisk();
}

double MotionPerformer::getFailureRiskChangeDirection(int angle)
{
  // 誤差コスト = (誤差コスト係数)*回転角度 + オーバーヘッド
  return directionChanger.getFailureRisk() * static_cast<double>(angle / 45.0) + 0.048;
}

double MotionPerformer::getFailureRiskPivotTurn()
{
  return blockPivotTurn.getFailureRisk();
}

double MotionPerformer::getFailureRiskThrowBlock()
{
  return blockThrower.getFailureRisk();
}
