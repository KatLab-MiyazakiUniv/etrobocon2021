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

void MotionPerformer::turnAround(int angle, bool isClockwise)
{
  directionChanger.changeDirection(angle, isClockwise);

  int tmp = std::abs(angle / 45);
  for(int i = 0; i < tmp; i++) {
    if(angle>0){
      motionLog.push_back(MOTION::TAC);
    } else {
      motionLog.push_back(MOTION::TARC);
    }
  }
}

void MotionPerformer::pibotTurn(bool isClockwise)
{
  blockPivotTurn.setBlockPivotTurn(isClockwise);
  if(isClockwise){
    motionLog.push_back(MOTION::PSETR);
  } else {
    motionLog.push_back(MOTION::PSETL);
  }
}

void MotionPerformer::throwBlock(bool isClockwise)
{
  blockThrower.throwBlock(isClockwise);
  if(isClockwise){
    motionLog.push_back(MOTION::TSETR);
  } else {
    motionLog.push_back(MOTION::TSETL);
  }
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