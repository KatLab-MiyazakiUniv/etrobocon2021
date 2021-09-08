/**
 * @file MotionConverter.cpp
 * @brief 動作変換クラス
 * @author Hisataka-Hagiyama,uchyam
 */

#include "MotionConverter.h"

MotionConverter::MotionConverter(MotionPerformer& motionPerformer, const bool IS_LEFT_COURSE)
  : motionPerformer(motionPerformer),
    isLeftCourse(IS_LEFT_COURSE),
    preDirection(IS_LEFT_COURSE ? Direction::E : Direction::W)
{
}

MOTION MotionConverter::decideMotion(std::pair<Coordinate, Direction> current,
                                     std::pair<Coordinate, Direction> next)
{
  int cx = current.first.x;            //現在のx座標
  int cy = current.first.y;            //現在のy座標
  Direction cd = current.second;       //現在の向き
  int nx = next.first.x;               //次のx座標
  int ny = next.first.y;               //次のy座標
  Direction nd = next.second;          //次の向き
  int angle = calculateAngle(cd, nd);  //角度の変化

  if(cx % 2 == 0 && cy % 2 == 0 && ((nx % 2 == 1 && ny % 2 == 0) || (nx % 2 == 0 && ny % 2 == 1))) {
    //交点->中点の場合は交点内移動
    if(angle == 0) {
      return MOTION::RF;  //直進
    } else if(angle == 90) {
      return MOTION::RR;  //右折
    } else {
      return MOTION::RL;  //左折
    }
  } else if(((cx % 2 == 1 && cy % 2 == 0) || (cx % 2 == 0 && cy % 2 == 1)) && nx % 2 == 0
            && ny % 2 == 0) {
    //中点->交点の場合は交点間移動
    return MOTION::RTC;
  } else {
    if(angle == 45) {
      return MOTION::SBTR;  //投げ入れ設置(右回り)
    } else if(angle == -45) {
      return MOTION::SBTL;  //投げ入れ設置(左回り)
    } else if(angle == 135) {
      return MOTION::SBPR;  //ピボットターン設置(右回り)
    } else {
      return MOTION::SBPL;  //ピボットターン設置(左回り)
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

void MotionConverter::convertToMotion(const std::vector<std::pair<Coordinate, Direction>>& route)
{
  //方向転換がある場合は方向転換を行う
  if(route[1].first.x % 2 == 0 || route[1].first.y % 2 == 0) {
    int rotateAngle = calculateAngle(route[0].second, route[1].second);
    int changeAngle = calculateAngle(preDirection, route[1].second);

    motionPerformer.changeDirection(rotateAngle, changeAngle);
  }

  //経路を実際の動作に変換し、動作を行う
  //交点から始まっており、経路のサイズが2より大きい場合は経路のスタートを1とする
  //(方向転換が無い場合と、黒ブロック運搬後に中点からスタートする場合の処理のみ処理が違うため)
  for(int i = (route[0].first.x % 2 == 0 && route[0].first.y % 2 == 0) && route.size() > 2 ? 1 : 0;
      i < static_cast<int>(route.size()) - 1; i++) {
    MOTION nextMotion = decideMotion(route[i], route[i + 1]);
    switch(static_cast<int>(nextMotion)) {
      case 0:
        motionPerformer.runForward();
        break;
      case 1:
        motionPerformer.runRight();
        break;
      case 2:
        motionPerformer.runLeft();
        break;
      case 3:
        motionPerformer.runToCross();
        break;
      case 4:
        motionPerformer.setBlockPivotTurn(true);
        break;
      case 5:
        motionPerformer.setBlockPivotTurn(false);
        break;
      case 6:
        motionPerformer.setBlockThrow(true);
        break;
      case 7:
        motionPerformer.setBlockThrow(false);
        break;
      default:
        motionPerformer.runForward();
        break;
    }
  }
  // 設置動作の直前の方角を保持する
  preDirection = route[static_cast<int>(route.size()) - 2].second;
}
