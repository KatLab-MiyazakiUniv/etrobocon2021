/**
 * @file	MotionConverter.cpp
 * @brief	動作変換クラス
 * @author	Hisataka-Hagiyama,uchyam
 */

#include "MotionConverter.h"

MotionConverter::MotionConverter() {}

MOTION MotionConverter::convertMove(std::pair<Coordinate, Direction> current,
                                    std::pair<Coordinate, Direction> next)
{
  int cx = current.first.x;       //現在のx座標
  int cy = current.first.y;       //現在のy座標
  Direction cd = current.second;  //現在の向き
  int nx = next.first.x;          //次のx座標
  int ny = next.first.y;          //次のy座標
  Direction nd = next.second;     //次の向き
  int angle = calculateAngle(cd, nd);
  if(cx % 2 == 0 && cy % 2 == 0 && ((nx % 2 == 1 && ny % 2 == 0) || (nx % 2 == 0 && ny % 2 == 1))) {
    //交点->中点の場合は交点内移動
    if(angle == 0) {
      //直進
      return MOTION::ST;
    } else if(angle == 90) {
      //右折
      return MOTION::TR;
    } else {
      //左折
      return MOTION::TL;
    }
  } else if((cx % 2 == 1 || cy % 2 == 1) && nx % 2 == 0 && ny % 2 == 0) {
    //中点->交点の場合は交点間移動
    return MOTION::BC;
  } else if(cx % 2 == 0 && cy % 2 == 0 && nx % 2 == 1 && ny % 2 == 1) {
    if(abs(angle) == 45)
      //投げ入れ設置
      return MOTION::TSET;
    else
      //ピボットターン設置
      return MOTION::PSET;
  } else {
    //方向転換
    if(angle == 90)
      return MOTION::RC90;
    else if(angle == -90)
      return MOTION::RRC90;
    else if(angle == 180)
      return MOTION::RC180;
    else
      return MOTION::RRC180;
  }
}

int MotionConverter::calculateAngle(Direction current, Direction next)
{
  int cangle = 0, nangle = 0;
  switch(static_cast<int>(current)) {
    case 0:
      cangle = 0;
      break;
    case 1:
      cangle = 45;
      break;
    case 2:
      cangle = 90;
      break;
    case 3:
      cangle = 315;
      break;
      break;
    case 5:
      cangle = 135;
      break;
    case 6:
      cangle = 270;
      break;
    case 7:
      cangle = 225;
      break;
    case 8:
      cangle = 180;
      break;
    default:
      nangle = 0;
      break;
  }
  switch(static_cast<int>(next)) {
    case 0:
      nangle = 0;
      break;
    case 1:
      nangle = 45;
      break;
    case 2:
      nangle = 90;
      break;
    case 3:
      nangle = 315;
      break;
      break;
    case 5:
      nangle = 135;
      break;
    case 6:
      nangle = 270;
      break;
    case 7:
      nangle = 225;
      break;
    case 8:
      nangle = 180;
      break;
    default:
      nangle = 0;
      break;
  }
  return nangle - cangle;
}

std::vector<MOTION> MotionConverter::convertMotion(
    std::vector<std::pair<Coordinate, Direction>>& route)
{
  std::vector<MOTION> motionList;
  for(int i = 0; i < static_cast<int>(route.size()) - 1; i++) {
    motionList.push_back(convertMove(route[i], route[i + 1]));
  }
  return motionList;
}
