/**
 * @file MotionConverter.cpp
 * @brief 動作変換クラス
 * @author Hisataka-Hagiyama,uchyam
 */

#include "MotionConverter.h"

MotionConverter::MotionConverter() {}

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
  } else {
    if(abs(angle) == 45)
      //投げ入れ設置
      return MOTION::TSET;
    else
      //ピボットターン設置
      return MOTION::PSET;
  }
}

int MotionConverter::calculateAngle(Direction current, Direction next)
{
  constexpr int MIN_ANGLE = 45;  //角度の最小単位(45度)
  // 2点の座標を角度に変換するためのテーブル(4を除く0~8を添え字とした8*8の配列)
  std::array<std::array<int, 8>, 8> table = { { { 0, 1, 2, -1, 3, -2, -3, 4 },
                                                { -1, 0, 1, -2, 2, -3, 4, 3 },
                                                { -2, -1, 0, -3, 1, 4, 3, 2 },
                                                { 1, 2, 3, 0, 4, -1, -2, -3 },
                                                { -3, -2, -1, 4, 0, 3, 2, 1 },
                                                { 2, 3, 4, 1, -3, 0, -1, -1 },
                                                { 3, 4, -3, 2, -2, 1, 0, -1 },
                                                { 4, -3, -2, 3, -1, 2, 1, 0 } } };
  int cindex = static_cast<int>(current);
  int nindex = static_cast<int>(next);
  // Directionに4がないため5以上の場合は-1する
  if(cindex >= 5) cindex--;
  if(nindex >= 5) nindex--;
  return table[cindex][nindex] * MIN_ANGLE;
}

std::vector<MOTION> MotionConverter::convertToMotion(
    std::vector<std::pair<Coordinate, Direction>>& route)
{
  std::vector<MOTION> motionList;  //動作を格納するための動的配列
  //方向転換が必要かどうか判定する
  int angle = calculateAngle(route[0].second, route[1].second);
  if(angle == 90) {
    motionList.push_back(MOTION::TAC90);
  } else if(angle == -90) {
    motionList.push_back(MOTION::TARC90);
  } else if(abs(angle) == 180) {
    motionList.push_back(MOTION::TA180);
  }
  // (方向転換があれば方向転換後の)動作を求める
  for(int i = (route[0].first.x % 2 == 0 && route[0].first.y % 2 == 0) && route.size() > 2 ? 1 : 0;
      i < static_cast<int>(route.size()) - 1; i++) {
    motionList.push_back(decideMotion(route[i], route[i + 1]));
  }
  return motionList;
}
