/**
 * @file MotionConverter.cpp
 * @brief 動作変換クラス
 * @author Hisataka-Hagiyama,uchyam
 */

#include "MotionConverter.h"

MotionConverter::MotionConverter(bool isLeftEdge) : isLeftEdge(isLeftEdge) {}

MOTION MotionConverter::decideMotion(std::pair<Coordinate, Direction> current,
                                     std::pair<Coordinate, Direction> next)
{
  int cx = current.first.x;            //現在のx座標
  int cy = current.first.y;            //現在のy座標
  Direction cd = current.second;       //現在の向き
  int nx = next.first.x;               //次のx座標
  int ny = next.first.y;               //次のy座標
  Direction nd = next.second;          //次の向き
  int angle = calculateAngle(cd, nd);  //角度

  if(cx % 2 == 0 && cy % 2 == 0 && ((nx % 2 == 1 && ny % 2 == 0) || (nx % 2 == 0 && ny % 2 == 1))) {
    //交点->中点の場合は交点内移動
    if(angle == 0) {
      return MOTION::ST;  //直進
    } else if(angle == 90) {
      return MOTION::TR;  //右折
    } else {
      return MOTION::TL;  //左折
    }
  } else if((cx % 2 == 1 || cy % 2 == 1) && nx % 2 == 0 && ny % 2 == 0) {
    //中点->交点の場合は交点間移動
    return MOTION::BC;
  } else {
    if(angle == 45) {
      return MOTION::TSET;  //投げ入れ設置(時計回り)
    } else if(angle == -45) {
      return MOTION::TSET;  //投げ入れ設置(反時計回り)
    } else if(angle == 135) {
      return MOTION::PSET;  //ピボットターン設置(時計回り)
    } else {
      return MOTION::PSET;  //ピボットターン設置(反時計回り)
    }
  }
}

int MotionConverter::calculateAngle(Direction current, Direction next)
{
  constexpr int MIN_ANGLE = 45;  //角度の最小単位(45度)
  int cdirect = static_cast<int>(current);
  int ndirect = static_cast<int>(next);
  int angle = (ndirect - cdirect) * MIN_ANGLE;
  if(angle > 180) {
    angle -= 360;
  } else if(angle < -180) {
    angle += 360;
  }
  return angle;
}

void MotionConverter::convertToMotion(std::vector<std::pair<Coordinate, Direction>>& route)
{
  LineTracer lineTracer(isLeftEdge);
  MotionPerformer motionPerformer(lineTracer);

  //方向転換が必要かどうか判定する
  int angle = calculateAngle(route[0].second, route[1].second);
  if(route[1].first.x % 2 == 0 || route[1].first.y % 2 == 0) {
    if(angle == 45) {
      motionPerformer.turnAround(45, true);
    } else if(angle == 90) {
      motionPerformer.turnAround(90, true);
    } else if(angle == 135) {
      motionPerformer.turnAround(135, true);
    } else if(angle == -45) {
      motionPerformer.turnAround(45, false);
    } else if(angle == -90) {
      motionPerformer.turnAround(90, false);
    } else if(angle == -135) {
      motionPerformer.turnAround(135, false);
    } else if(abs(angle) == 180) {
      motionPerformer.turnAround(180, true);
    }
  }
  // (方向転換があれば方向転換後の)動作を求める
  for(int i = (route[0].first.x % 2 == 0 && route[0].first.y % 2 == 0) && route.size() > 2 ? 1 : 0;
      i < static_cast<int>(route.size()) - 1; i++) {
    MOTION nextMotion = decideMotion(route[i], route[i + 1]);
    switch(static_cast<int>(nextMotion)) {
      case 0:
        motionPerformer.moveStraight();
        break;
      case 1:
        motionPerformer.turnRight();
        break;
      case 2:
        motionPerformer.turnLeft();
        break;
      case 3:
        motionPerformer.moveBetweenCross();
        break;
      case 4:
        motionPerformer.pibotTurn(true);
        break;
      case 5:
        motionPerformer.throwBlock(true);
        break;
      default:
        motionPerformer.moveStraight();
        break;
    }
  }
}
