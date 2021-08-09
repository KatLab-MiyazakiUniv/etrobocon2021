/**
 * @file RoutePlanner.cpp
 * @brief 経路計画クラス
 * @author hiroto0927, miyashita64
 */

#include "RoutePlanner.h"

// コンストラクタ
RoutePlanner::RoutePlanner(BingoArea& _bingoArea, const bool IS_LEFT_COURSE)
  : bingoArea(_bingoArea), isLeftCourse(IS_LEFT_COURSE)
{
}

// 経路計画を立てる
void RoutePlanner::planBingoRoute()
{
  Robot robot(isLeftCourse);  // 経路計画用の仮想走行体インスタンス生成
  DestinationList destinationList(bingoArea);  // 運搬先を決定する
  BlockSelector blockSelector(bingoArea, destinationList, robot);
  RouteCalculator routeCalculator(bingoArea, robot);

  while(true) {
    // 運搬ブロックを決定する
    BLOCK_ID carryBlockId = blockSelector.selectBlock();
    // 運搬ブロックが存在しない場合、ループを抜ける
    if(carryBlockId == BLOCK_ID::NONE) break;

    // 運搬ブロックの座標を取得する
    Coordinate carryBlockCoord = bingoArea.getNode(carryBlockId).getCoordinate();
    // 目標サークルの座標を取得する
    CIRCLE_ID targetCircleId = destinationList.getDestination(carryBlockId);
    Coordinate targetCircleCoord = bingoArea.getBlockCircle(targetCircleId).getCoordinate();
    // 走行体から運搬ブロックまでの経路を決定する
    std::vector<std::pair<Coordinate, Direction>> toBlockRoute
        = routeCalculator.calculateRoute(robot.getCoordinate(), carryBlockCoord);
    // 走行体が運搬ブロックを取得したとして、走行体の情報を更新する
    robot.setCoordinate(toBlockRoute.back().first);
    robot.setDirection(toBlockRoute.back().second);

    // 運搬ブロックから目標サークルまでの経路を決定する
    std::vector<std::pair<Coordinate, Direction>> toCircleRoute
        = routeCalculator.calculateRoute(carryBlockCoord, targetCircleCoord);
    int routeSize = toCircleRoute.size();

    // 運搬ブロックを設置する目標サークル
    std::pair<Coordinate, Direction> goal = toCircleRoute[routeSize - 1];
    // ブロック設置動作を開始する交点サークル
    std::pair<Coordinate, Direction> prevGoal = toCircleRoute[routeSize - 2];

    // 運搬ブロックを設置したとして、走行体の情報を更新する
    // 走行体の座標を更新
    robot.setCoordinate(prevGoal.first);

    // 目標サークルとその直前との走行体の方向の差を(-4~4)の範囲に変形する
    int dd = static_cast<int>(goal.second) - static_cast<int>(prevGoal.second);
    if(dd > 4) {
      dd -= 8;
    } else if(dd < -4) {
      dd += 8;
    }

    // 走行体の方向を更新
    if(std::abs(dd) < 2) {
      // 目標が前方にある場合、投げ入れ設置のため目標を向く
      robot.setDirection(goal.second);
    } else {
      // 目標が後方にある場合、ピボット設置のため設置動作前の方向を向く
      robot.setDirection(prevGoal.second);
    }

    // ブロックを運搬したとして、ビンゴエリア情報を更新する
    bingoArea.moveBlock(targetCircleId, carryBlockId);
  }
}