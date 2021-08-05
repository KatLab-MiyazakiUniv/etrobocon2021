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

void MotionPerformer::moveStraight()
{
  inCrossStraight.runForward();
  motionLog.push_back(MOTION::ST);
}

void MotionPerformer::turnRight()
{
  inCrossRight.runRight();
  motionLog.push_back(MOTION::TR);
}

void MotionPerformer::turnLeft()
{
  inCrossLeft.runLeft();
  motionLog.push_back(MOTION::TL);
}

void MotionPerformer::moveBetweenCross()
{
  toCrossMotion.runToCross();
  motionLog.push_back(MOTION::BC);
}

void MotionPerformer::turnAround()
{
  directionChanger.changeDirection(180, true);
  motionLog.push_back(MOTION::TA);
}

void MotionPerformer::pibotTurn(bool isClockwise)
{
  blockPivotTurn.setBlockPivotTurn(isClockwise);
  motionLog.push_back(MOTION::PSET);
}

void MotionPerformer::throwBlock(bool isClockwise)
{
  blockThrower.throwBlock(isClockwise);
  motionLog.push_back(MOTION::TSET);
}

int MotionPerformer::getMotionTimeStraight()
{
  return inCrossStraight.getMotionTime();
}

int MotionPerformer::getMotionTimeTurnRight()
{
  return inCrossRight.getMotionTime();
}

int MotionPerformer::getMotionTimeTurnLeft()
{
  return inCrossLeft.getMotionTime();
}

int MotionPerformer::getMotionTimeBetweenCross()
{
  return toCrossMotion.getMotionTime();
}

int MotionPerformer::getMotionTimeTurnAround()
{
  return directionChanger.getMotionTime();
}

int MotionPerformer::getMotionTimePibotTurn()
{
  return blockPivotTurn.getMotionTime();
}

int MotionPerformer::getMotionTimeThrowBlock()
{
  return blockThrower.getMotionTime();
}

int MotionPerformer::getFailureRiskStraight()
{
  return inCrossStraight.getFailureRisk();
}

int MotionPerformer::getFailureRiskTurnRight()
{
  return inCrossRight.getFailureRisk();
}

int MotionPerformer::getFailureRiskTurnLeft()
{
  return inCrossLeft.getFailureRisk();
}

int MotionPerformer::getFailureRiskBetweenCross()
{
  return toCrossMotion.getFailureRisk();
}

int MotionPerformer::getFailureRiskTurnAround()
{
  return directionChanger.getFailureRisk();
}

int MotionPerformer::getFailureRiskPibotTurn()
{
  return blockPivotTurn.getFailureRisk();
}

int MotionPerformer::getFailureRiskThrowBlock()
{
  return blockThrower.getFailureRisk();
}