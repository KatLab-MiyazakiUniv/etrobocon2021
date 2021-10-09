#include "MoveCostCalculator.h"

int MoveCostCalculator::calculateMoveCost(std::pair<Coordinate, Direction> current,
                                          std::pair<Coordinate, Direction> next, bool isLeftCourse)
{
  MOTION nextMotion = MotionConverter::decideMotion(current, next);
  LineTracer lineTracer(isLeftCourse);
  MotionPerformer motionPerformer(lineTracer);

  switch(static_cast<int>(nextMotion)) {
    case 0:
      return motionPerformer.getMotionTimeRunForward() + motionPerformer.getFailureRiskRunForward();
      break;
    case 1:
      return motionPerformer.getMotionTimeRunRight() + motionPerformer.getFailureRiskRunRight();
      break;
    case 2:
      return motionPerformer.getMotionTimeRunLeft() + motionPerformer.getFailureRiskRunLeft();
      break;
    case 3:
      return motionPerformer.getMotionTimeRunToCross() + motionPerformer.getFailureRiskRunToCross();
      break;
    case 4:
      return motionPerformer.getMotionTimePivotTurn() + motionPerformer.getFailureRiskPivotTurn();
      break;
    case 5:
      return motionPerformer.getMotionTimePivotTurn() + motionPerformer.getFailureRiskPivotTurn();
      break;
    case 6:
      return motionPerformer.getMotionTimeThrowBlock() + motionPerformer.getFailureRiskThrowBlock();
      break;
    case 7:
      return motionPerformer.getMotionTimeThrowBlock() + motionPerformer.getFailureRiskThrowBlock();
      break;
    default:
      int angle = MotionConverter::calculateAngle(current.second, next.second);
      return motionPerformer.getMotionTimeChangeDirection(angle)
             + motionPerformer.getFailureRiskChangeDirection(angle);
      break;
  }
}
