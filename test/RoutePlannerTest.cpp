/**
 * @file RoutePlannerTest.cpp
 * @brief RoutePlannerクラスをテストする
 * @author hiroto0927, miyashita64
 */

#include "RoutePlanner.h"
#include <gtest/gtest.h>
namespace etrobocon2021_test {
  // TEST(planBingoRouteTest, planBingoRouteLeft)
  // {
  //   constexpr bool IS_LEFT_COURSE = true;
  //   CourseInfo courseInfo(IS_LEFT_COURSE);
  //   courseInfo.initCourseInfo();
  //   RoutePlanner routePlanner(courseInfo, IS_LEFT_COURSE);
  //
  //   // 経路計画
  //   routePlanner.planBingoRoute();
  //
  //   // 全てのブロックサークルにブロックがあることを確認
  //   bool blockCircleExpected = true;
  //   for(int blockCircleNum = 0; blockCircleNum < 8; blockCircleNum++) {
  //     CIRCLE_ID blockCircleId = static_cast<CIRCLE_ID>(blockCircleNum);
  //     BlockCircle blockCircle = courseInfo.getBlockCircle(blockCircleId);
  //     Coordinate blockCircleCoord = blockCircle.getCoordinate();
  //     EXPECT_EQ(blockCircleExpected, courseInfo.existBlock(blockCircleCoord));
  //   }
  //
  //   // 全ての交点サークルにブロックがないことを確認
  //   bool crossCircleExpected = false;
  //   for(int crossCircleNum = 0; crossCircleNum < 16; crossCircleNum++) {
  //     CrossCircle crossCircle = courseInfo.getCrossCircle(crossCircleNum);
  //     Coordinate crossCircleCoord = crossCircle.getCoordinate();
  //     EXPECT_EQ(crossCircleExpected, courseInfo.existBlock(crossCircleCoord));
  //   }
  // }
  //
  // TEST(planBingoRouteTest, planBingoRouteRight)
  // {
  //   constexpr bool IS_LEFT_COURSE = false;
  //   CourseInfo courseInfo(IS_LEFT_COURSE);
  //   courseInfo.initCourseInfo();
  //   RoutePlanner routePlanner(courseInfo, IS_LEFT_COURSE);
  //
  //   // 経路計画
  //   routePlanner.planBingoRoute();
  //
  //   // 全てのブロックサークルにブロックがあることを確認
  //   bool blockCircleExpected = true;
  //   for(int blockCircleNum = 0; blockCircleNum < 8; blockCircleNum++) {
  //     CIRCLE_ID blockCircleId = static_cast<CIRCLE_ID>(blockCircleNum);
  //     BlockCircle blockCircle = courseInfo.getBlockCircle(blockCircleId);
  //     Coordinate blockCircleCoord = blockCircle.getCoordinate();
  //     EXPECT_EQ(blockCircleExpected, courseInfo.existBlock(blockCircleCoord));
  //   }
  //
  //   // 全ての交点サークルにブロックがないことを確認
  //   bool crossCircleExpected = false;
  //   for(int crossCircleNum = 0; crossCircleNum < 16; crossCircleNum++) {
  //     CrossCircle crossCircle = courseInfo.getCrossCircle(crossCircleNum);
  //     Coordinate crossCircleCoord = crossCircle.getCoordinate();
  //     EXPECT_EQ(crossCircleExpected, courseInfo.existBlock(crossCircleCoord));
  //   }
  // }

  TEST(planBingoRouteTest, planBingoRoute_carryRoute)
  {
    constexpr bool IS_LEFT_COURSE = true;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    RoutePlanner routePlanner(courseInfo, IS_LEFT_COURSE);

    Coordinate coordinate_start(0, 0);
    Coordinate route_1(0, 0);
    Coordinate route_2(0, 0);
    Coordinate route_3(0, 0);
    Coordinate route_4(0, 0);
    Coordinate route_5(0, 0);
    Coordinate route_6(0, 0);
    Coordinate coordinate_goal(0, 0);

    std::vector<std::vector<std::pair<Coordinate, Direction>>> actual_route
        = routePlanner.planBingoRoute();
    std::vector<std::vector<std::pair<Coordinate, Direction>>> expected_route(8);

    // BLOCK_ID::3の緑ブロックまで移動する
    coordinate_start = { 2, 3 };
    route_1 = { 2, 2 };
    route_2 = { 3, 2 };
    coordinate_goal = { 4, 2 };
    expected_route[0].push_back(std::make_pair(coordinate_start, Direction::E));
    expected_route[0].push_back(std::make_pair(route_1, Direction::N));
    expected_route[0].push_back(std::make_pair(route_2, Direction::E));
    expected_route[0].push_back(std::make_pair(coordinate_goal, Direction::E));

    // BLOCK_ID::3の緑ブロックをCIRCLE_ID::1の緑サークルまで移動させる
    coordinate_start = { 4, 2 };
    coordinate_goal = { 3, 1 };
    // expected_route[0].push_back(std::make_pair(coordinate_start, Direction::E));
    expected_route[0].push_back(std::make_pair(coordinate_goal, Direction::NW));

    // BLOCK_ID::0の黄ブロックまで移動する
    coordinate_start = { 4, 2 };
    route_1 = { 4, 1 };
    route_2 = { 4, 0 };
    route_3 = { 3, 0 };
    coordinate_goal = { 2, 0 };
    expected_route[1].push_back(std::make_pair(coordinate_start, Direction::E));
    expected_route[1].push_back(std::make_pair(route_1, Direction::N));
    expected_route[1].push_back(std::make_pair(route_2, Direction::N));
    expected_route[1].push_back(std::make_pair(route_3, Direction::W));
    expected_route[1].push_back(std::make_pair(coordinate_goal, Direction::W));

    // BLOCK_ID::0の黄ブロックをCIRCLE_ID::0の黄サークルまで移動させる
    coordinate_goal = { 1, 1 };
    expected_route[1].push_back(std::make_pair(coordinate_goal, Direction::SW));

    // BLOCK_ID::4の黄ブロックまで移動する
    coordinate_start = { 2, 0 };
    route_1 = { 2, 1 };
    route_2 = { 2, 2 };
    route_3 = { 2, 3 };
    coordinate_goal = { 2, 4 };
    expected_route[2].push_back(std::make_pair(coordinate_start, Direction::SW));
    expected_route[2].push_back(std::make_pair(route_1, Direction::S));
    expected_route[2].push_back(std::make_pair(route_2, Direction::S));
    expected_route[2].push_back(std::make_pair(route_3, Direction::S));
    expected_route[2].push_back(std::make_pair(coordinate_goal, Direction::S));

    // BLOCK_ID::4の黄ブロックをCIRCLE_ID::4の黄サークルまで移動させる
    route_1 = { 3, 4 };
    route_2 = { 4, 4 };
    coordinate_goal = { 5, 3 };
    expected_route[2].push_back(std::make_pair(route_1, Direction::E));
    expected_route[2].push_back(std::make_pair(route_2, Direction::E));
    expected_route[2].push_back(std::make_pair(coordinate_goal, Direction::NE));

    // BLOCK_ID::7の青ブロックまで移動する
    coordinate_start = { 4, 4 };
    route_1 = { 4, 5 };
    coordinate_goal = { 4, 6 };
    expected_route[3].push_back(std::make_pair(coordinate_start, Direction::NE));
    expected_route[3].push_back(std::make_pair(route_1, Direction::S));
    expected_route[3].push_back(std::make_pair(coordinate_goal, Direction::S));

    // BLOCK_ID::7の青ブロックをCIRCLE_ID::7の青サークルまで移動させる
    coordinate_goal = { 5, 5 };
    expected_route[3].push_back(std::make_pair(coordinate_goal, Direction::NE));

    // BLOCK_ID::6の緑ブロックまで移動する
    coordinate_start = { 4, 6 };
    route_1 = { 3, 6 };
    route_2 = { 2, 6 };
    route_3 = { 1, 6 };
    coordinate_goal = { 0, 6 };
    expected_route[4].push_back(std::make_pair(coordinate_start, Direction::S));
    expected_route[4].push_back(std::make_pair(route_1, Direction::W));
    expected_route[4].push_back(std::make_pair(route_2, Direction::W));
    expected_route[4].push_back(std::make_pair(route_3, Direction::W));
    expected_route[4].push_back(std::make_pair(coordinate_goal, Direction::W));

    // BLOCK_ID::6の緑ブロックをCIRCLE_ID::5の緑サークルまで移動させる
    coordinate_goal = { 1, 5 };
    expected_route[4].push_back(std::make_pair(coordinate_goal, Direction::NE));

    // BLOCK_ID::2の赤ブロックまで移動する
    coordinate_start = { 0, 6 };
    route_1 = { 0, 5 };
    route_2 = { 0, 4 };
    route_3 = { 0, 3 };
    coordinate_goal = { 0, 2 };
    expected_route[5].push_back(std::make_pair(coordinate_start, Direction::W));
    expected_route[5].push_back(std::make_pair(route_1, Direction::N));
    expected_route[5].push_back(std::make_pair(route_2, Direction::N));
    expected_route[5].push_back(std::make_pair(route_3, Direction::N));
    expected_route[5].push_back(std::make_pair(coordinate_goal, Direction::N));

    // BLOCK_ID::2の赤ブロックをCIRCLE_ID::6の赤サークルまで移動させる
    route_1 = { 1, 2 };
    route_2 = { 2, 2 };
    route_3 = { 2, 3 };
    route_4 = { 2, 4 };
    coordinate_goal = { 3, 5 };
    expected_route[5].push_back(std::make_pair(route_1, Direction::E));
    expected_route[5].push_back(std::make_pair(route_2, Direction::E));
    expected_route[5].push_back(std::make_pair(route_3, Direction::S));
    expected_route[5].push_back(std::make_pair(route_4, Direction::S));
    expected_route[5].push_back(std::make_pair(coordinate_goal, Direction::SE));

    // BLOCK_ID::5の赤ブロックまで移動する
    coordinate_start = { 2, 4 };
    route_1 = { 3, 4 };
    route_2 = { 4, 4 };
    route_3 = { 5, 4 };
    coordinate_goal = { 6, 4 };
    expected_route[6].push_back(std::make_pair(coordinate_start, Direction::SE));
    expected_route[6].push_back(std::make_pair(route_1, Direction::E));
    expected_route[6].push_back(std::make_pair(route_2, Direction::E));
    expected_route[6].push_back(std::make_pair(route_3, Direction::E));
    expected_route[6].push_back(std::make_pair(coordinate_goal, Direction::E));

    // BLOCK_ID::5の赤ブロックをCIRCLE_ID::2の赤サークルまで移動させる
    route_1 = { 6, 3 };
    route_2 = { 6, 2 };
    coordinate_goal = { 5, 1 };
    expected_route[6].push_back(std::make_pair(route_1, Direction::N));
    expected_route[6].push_back(std::make_pair(route_2, Direction::N));
    expected_route[6].push_back(std::make_pair(coordinate_goal, Direction::NW));

    // BLOCK_ID::1の青ブロックまで移動する
    coordinate_start = { 6, 2 };
    route_1 = { 6, 1 };
    coordinate_goal = { 6, 0 };
    expected_route[7].push_back(std::make_pair(coordinate_start, Direction::NW));
    expected_route[7].push_back(std::make_pair(route_1, Direction::N));
    expected_route[7].push_back(std::make_pair(coordinate_goal, Direction::N));

    // BLOCK_ID::1の青ブロックをCIRCLE_ID::3の青サークルまで移動させる
    route_1 = { 6, 1 };
    route_2 = { 6, 2 };
    route_3 = { 5, 2 };
    route_4 = { 4, 2 };
    route_5 = { 3, 2 };
    route_6 = { 2, 2 };
    coordinate_goal = { 1, 3 };
    expected_route[7].push_back(std::make_pair(route_1, Direction::S));
    expected_route[7].push_back(std::make_pair(route_2, Direction::S));
    expected_route[7].push_back(std::make_pair(route_3, Direction::W));
    expected_route[7].push_back(std::make_pair(route_4, Direction::W));
    expected_route[7].push_back(std::make_pair(route_5, Direction::W));
    expected_route[7].push_back(std::make_pair(route_6, Direction::W));
    expected_route[7].push_back(std::make_pair(coordinate_goal, Direction::SW));

    EXPECT_EQ(expected_route, actual_route);
  }
}  // namespace etrobocon2021_test
