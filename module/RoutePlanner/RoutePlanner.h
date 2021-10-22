/**
 * @file RoutePlanner.h
 * @brief 経路計画クラス
 * @author hiroto0927, miyashita64, Hisataka-Hagiyama, uchyam
 */

#ifndef ROUTE_PLANNER_H
#define ROUTE_PLANNER_H

#include "CourseInfo.h"
#include "DestinationList.h"
#include "BlockSelector.h"
#include "RouteCalculator.h"
#include "Controller.h"
#include <vector>
#include <utility>

class RoutePlanner {
 public:
  static bool plannerFlag;

  /**
   * 1つのブロックを運搬するまでの経路を計画し、取得経路、設置経路のリストを渡す
   */
  static void planBingoRoute();

  static std::array<std::vector<std::pair<Coordinate, Direction>>, 8> carryRoute;  //運搬経路リスト

 private:
  /**
   * コンストラクタ
   */
  RoutePlanner();
};

#endif
