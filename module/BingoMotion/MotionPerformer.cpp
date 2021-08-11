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

void MotionPerformer::changeDirection(int angle, bool isClockwise)
{
  directionChanger.changeDirection(angle, isClockwise);

  int tmp = std::abs(angle / 45);
  for(int i = 0; i < tmp; i++) {
    if(angle > 0) {
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
  blockThrower.throwBlock(isClockwise);
  if(isClockwise) {
    motionLog.push_back(MOTION::SBTR);
  } else {
    motionLog.push_back(MOTION::SBTL);
  }
}

int MotionPerformer::getMotionTimeRunForward()
{
  return inCrossStraight.getMotionTime();
}

int MotionPerformer::getMotionTimeRunRight()
{
  return inCrossRight.getMotionTime();
}

int MotionPerformer::getMotionTimeRunLeft()
{
  return inCrossLeft.getMotionTime();
}

int MotionPerformer::getMotionTimeRunToCross()
{
  return toCrossMotion.getMotionTime();
}

int MotionPerformer::getMotionTimeChangeDirection()
{
  return directionChanger.getMotionTime();
}

int MotionPerformer::getMotionTimePivotTurn()
{
  return blockPivotTurn.getMotionTime();
}

int MotionPerformer::getMotionTimeThrowBlock()
{
  return blockThrower.getMotionTime();
}

int MotionPerformer::getFailureRiskRunForward()
{
  return inCrossStraight.getFailureRisk();
}

int MotionPerformer::getFailureRiskRunRight()
{
  return inCrossRight.getFailureRisk();
}

int MotionPerformer::getFailureRiskRunLeft()
{
  return inCrossLeft.getFailureRisk();
}

int MotionPerformer::getFailureRiskRunToCross()
{
  return toCrossMotion.getFailureRisk();
}

int MotionPerformer::getFailureRiskChangeDirection()
{
  return directionChanger.getFailureRisk();
}

int MotionPerformer::getFailureRiskPivotTurn()
{
  return blockPivotTurn.getFailureRisk();
}

int MotionPerformer::getFailureRiskThrowBlock()
{
  return blockThrower.getFailureRisk();
}