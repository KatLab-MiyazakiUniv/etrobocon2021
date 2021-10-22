/**
 * @file RoutePlanner.cpp
 * @brief 経路計画クラス
 * @author hiroto0927, miyashita64, Hisataka-Hagiyama, uchyam
 */

#include "RoutePlanner.h"

std::array<std::vector<std::pair<Coordinate, Direction>>, 8> RoutePlanner::carryRoute = {};

bool RoutePlanner::plannerFlag = false;

// 経路計画を立てる
void RoutePlanner::planBingoRoute()
{
  printf("経路計画開始\n");
  Controller controller;
  CourseInfo courseInfo(IS_LEFT_COURSE);
  courseInfo.initCourseInfo();

  Robot robot(IS_LEFT_COURSE);  // 経路計画用の仮想走行体インスタンス生成
  DestinationList destinationList(courseInfo);  // 運搬先を決定する
  BlockSelector blockSelector(destinationList, IS_LEFT_COURSE);
  RouteCalculator routeCalculator(courseInfo, robot, IS_LEFT_COURSE);
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
      // controller.sleep();
    }

    // 走行体が運搬ブロックを取得したとして、走行体の情報を更新する
    robot.setCoordinate(toBlockRoute.back().first);
    robot.setDirection(toBlockRoute.back().second);

    // 運搬ブロックから目標サークルまでの設置経路を決定する
    std::vector<std::pair<Coordinate, Direction>> toCircleRoute
        = routeCalculator.calculateRoute(carryBlockCoord, targetCircleCoord);
    //設置経路を運搬経路リストに追加する
    for(int i = 1; i < static_cast<int>(toCircleRoute.size()); i++) {
      carryRoute[count].push_back(toCircleRoute[i]);
      // controller.sleep();
    }
    count++;

    int routeSize = static_cast<int>(toCircleRoute.size());
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
    robot.setDirection(goal.second);

    // ブロックを運搬したとして、ビンゴエリア情報を更新する
    courseInfo.moveBlock(targetCircleId, carryBlockId);

    controller.sleep();
  }

  // 経路計画を終了
  printf("経路計画終了\n");
  plannerFlag = true;
  for(int i = 0; i < 8; i++) {
    for(auto& carry : carryRoute[i]) {
      printf("(%d, %d)→ ", carry.first.x, carry.first.y);
    }
    printf("\n");
  }
}
