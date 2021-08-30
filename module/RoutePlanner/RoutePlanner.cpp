/**
 * @file RoutePlanner.cpp
 * @brief 経路計画クラス
 * @author hiroto0927, miyashita64, Hisataka-Hagiyama, uchyam
 */

#include "RoutePlanner.h"

// コンストラクタ
RoutePlanner::RoutePlanner(CourseInfo& _courseInfo, const bool IS_LEFT_COURSE)
  : courseInfo(_courseInfo), isLeftCourse(IS_LEFT_COURSE)
{
}

// 経路計画を立てる
std::vector<std::vector<std::pair<Coordinate, Direction>>> RoutePlanner::planBingoRoute()
{
  std::vector<std::vector<std::pair<Coordinate, Direction>>> carryRoute(16);  //運搬経路リスト
  Robot robot(isLeftCourse);  // 経路計画用の仮想走行体インスタンス生成
  DestinationList destinationList(courseInfo);  // 運搬先を決定する
  BlockSelector blockSelector(courseInfo, destinationList, robot);
  RouteCalculator routeCalculator(courseInfo, robot);
  int count = 0;

  while(true) {
    // 運搬ブロックを決定する
    BLOCK_ID carryBlockId = blockSelector.selectBlock();
    // 運搬ブロックが存在しない場合、ループを抜ける
    if(carryBlockId == BLOCK_ID::NONE) break;

    // 運搬ブロックの座標を取得する
    Coordinate carryBlockCoord = courseInfo.getNode(carryBlockId).getCoordinate();
    // 目標サークルの座標を取得する
    CIRCLE_ID targetCircleId = destinationList.getDestination(carryBlockId);
    Coordinate targetCircleCoord = courseInfo.getBlockCircle(targetCircleId).getCoordinate();
    // 走行体から運搬ブロックまでの取得経路を決定する
    std::vector<std::pair<Coordinate, Direction>> toBlockRoute
        = routeCalculator.calculateRoute(robot.getCoordinate(), carryBlockCoord);
    //取得経路を運搬経路リストに追加する
    for(const auto& i : toBlockRoute) {
      carryRoute[count].push_back(i);
    }
    count++;
    // 走行体が運搬ブロックを取得したとして、走行体の情報を更新する
    robot.setCoordinate(toBlockRoute.back().first);
    robot.setDirection(toBlockRoute.back().second);

    // 運搬ブロックから目標サークルまでの設置経路を決定する
    std::vector<std::pair<Coordinate, Direction>> toCircleRoute
        = routeCalculator.calculateRoute(carryBlockCoord, targetCircleCoord);
    //設置経路を運搬経路リストに追加する
    for(const auto& i : toCircleRoute) {
      carryRoute[count].push_back(i);
    }
    count++;

    int routeSize = toCircleRoute.size();
    // 運搬ブロックを設置する目標サークル
    std::pair<Coordinate, Direction> goal = toCircleRoute[routeSize - 1];
    // ブロック設置動作を開始する交点サークル
    std::pair<Coordinate, Direction> prevGoal = toCircleRoute[routeSize - 2];

    // 運搬ブロックを設置したとして、走行体の情報を更新する
    // 走行体の座標を更新
    robot.setCoordinate(prevGoal.first);

    // 目標サークルとその直前との走行体の方向の差を(-4~4)の範囲に変形する
    int diffDirection = static_cast<int>(goal.second) - static_cast<int>(prevGoal.second);
    if(diffDirection > 4) {
      diffDirection -= 8;
    } else if(diffDirection < -4) {
      diffDirection += 8;
    }

    // 走行体の方向を更新
    if(std::abs(diffDirection) < 2) {
      // 目標が前方にある場合、投げ入れ設置のため目標を向く
      robot.setDirection(goal.second);
    } else {
      // 目標が後方にある場合、ピボット設置のため設置動作前の方向を向く
      robot.setDirection(prevGoal.second);
    }

    // ブロックを運搬したとして、ビンゴエリア情報を更新する
    courseInfo.moveBlock(targetCircleId, carryBlockId);
  }
  return carryRoute;
}
