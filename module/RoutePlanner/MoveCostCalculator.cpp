/**
 * @file  MoveCostCalculator.cpp
 * @brief 移動コスト計算クラス
 * @author  Hisataka-Hagiyama
 */

#include "MoveCostCalculator.h"

MoveCostCalculator::MoveCostCalculator(MotionPerformer& _motionPerformer)
  : motionPerformer(_motionPerformer)
{
}

double MoveCostCalculator::calculateMoveCost(std::pair<Coordinate, Direction> current,
                                             std::pair<Coordinate, Direction> next,
                                             bool isLeftCourse)
{
  MOTION nextMotion = MotionConverter::decideMotion(current, next);

  // 時間コストと誤差コストの比
  double timeRatio = 0.7;
  double riskRatio = 1.0 - timeRatio;

  switch(static_cast<int>(nextMotion)) {
    case 0:
      return motionPerformer.getMotionTimeRunForward() * timeRatio
             + motionPerformer.getFailureRiskRunForward() * riskRatio;
      break;
    case 1:
      return motionPerformer.getMotionTimeRunRight() * timeRatio
             + motionPerformer.getFailureRiskRunRight() * riskRatio;
      break;
    case 2:
      return motionPerformer.getMotionTimeRunLeft() * timeRatio
             + motionPerformer.getFailureRiskRunLeft() * riskRatio;
      break;
    case 3:
      return motionPerformer.getMotionTimeRunToCross() * timeRatio
             + motionPerformer.getFailureRiskRunToCross() * riskRatio;
      break;
    case 4:
      return motionPerformer.getMotionTimePivotTurn() * timeRatio
             + motionPerformer.getFailureRiskPivotTurn() * riskRatio;
      break;
    case 5:
      return motionPerformer.getMotionTimePivotTurn() * timeRatio
             + motionPerformer.getFailureRiskPivotTurn() * riskRatio;
      break;
    case 6:
      return motionPerformer.getMotionTimeThrowBlock() * timeRatio
             + motionPerformer.getFailureRiskThrowBlock() * riskRatio;
      break;
    case 7:
      return motionPerformer.getMotionTimeThrowBlock() * timeRatio
             + motionPerformer.getFailureRiskThrowBlock() * riskRatio;
      break;
    default:
      int angle = MotionConverter::calculateAngle(current.second, next.second);
      return motionPerformer.getMotionTimeChangeDirection(abs(angle)) * timeRatio
             + motionPerformer.getFailureRiskChangeDirection(abs(angle)) * riskRatio;
      break;
  }
}
