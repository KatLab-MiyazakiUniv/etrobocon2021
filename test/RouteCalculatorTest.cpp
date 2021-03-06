/**
 * @file RouteCalculatorTest.cpp
 * @brief 経路計算クラスのテスト
 * @author Hisataka-Hagiyama,uchyam
 */

#include "RouteCalculator.h"
#include <gtest/gtest.h>
namespace etrobocon2021_test {
  //フルビンゴまでの挙動をテストする
  TEST(RouteCalculator, fullBingo)
  {
    constexpr bool IS_LEFT_COURSE = true;
    Robot robot(IS_LEFT_COURSE);
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    RouteCalculator route(courseInfo, robot, IS_LEFT_COURSE);
    Coordinate coordinate_start(0, 0);
    Coordinate route_1(0, 0);
    Coordinate route_2(0, 0);
    Coordinate route_3(0, 0);
    Coordinate route_4(0, 0);
    Coordinate route_5(0, 0);
    Coordinate route_6(0, 0);
    Coordinate coordinate_goal(0, 0);
    Coordinate coordinate_destination(0, 0);

    // BLOCK_ID::3の緑ブロックまで移動する
    coordinate_start = { 2, 3 };
    route_1 = { 2, 2 };
    route_2 = { 3, 2 };
    coordinate_goal = { 4, 2 };
    coordinate_destination = { 3, 1 };
    std::vector<std::pair<Coordinate, Direction>> expected_route;
    expected_route.push_back(std::make_pair(coordinate_start, Direction::E));
    expected_route.push_back(std::make_pair(route_1, Direction::N));
    expected_route.push_back(std::make_pair(route_2, Direction::E));
    expected_route.push_back(std::make_pair(coordinate_goal, Direction::E));
    std::vector<std::pair<Coordinate, Direction>> actual_route
        = route.calculateRoute(coordinate_start, coordinate_goal, coordinate_destination);
    EXPECT_EQ(expected_route, actual_route);
    robot.setDirection(Direction::E);  //走行体の向きを更新

    // BLOCK_ID::3の緑ブロックをCIRCLE_ID::1の緑サークルまで移動させる
    coordinate_start = { 4, 2 };
    coordinate_goal = { 3, 1 };
    coordinate_destination = { 3, 1 };
    expected_route.clear();
    actual_route.clear();
    expected_route.push_back(std::make_pair(coordinate_start, Direction::E));
    expected_route.push_back(std::make_pair(coordinate_goal, Direction::NW));
    actual_route = route.calculateRoute(coordinate_start, coordinate_goal, coordinate_destination);
    EXPECT_EQ(expected_route, actual_route);
    courseInfo.moveBlock(CIRCLE_ID::ID1, BLOCK_ID::ID3);
    robot.setDirection(Direction::E);  //走行体の向きを更新

    // BLOCK_ID::0の黄ブロックまで移動する
    coordinate_start = { 4, 2 };
    route_1 = { 4, 1 };
    route_2 = { 4, 0 };
    route_3 = { 3, 0 };
    coordinate_goal = { 2, 0 };
    coordinate_destination = { 1, 1 };
    expected_route.clear();
    actual_route.clear();
    expected_route.push_back(std::make_pair(coordinate_start, Direction::E));
    expected_route.push_back(std::make_pair(route_1, Direction::N));
    expected_route.push_back(std::make_pair(route_2, Direction::N));
    expected_route.push_back(std::make_pair(route_3, Direction::W));
    expected_route.push_back(std::make_pair(coordinate_goal, Direction::W));
    actual_route = route.calculateRoute(coordinate_start, coordinate_goal, coordinate_destination);
    EXPECT_EQ(expected_route, actual_route);
    robot.setDirection(Direction::W);  //走行体の向きを更新

    // BLOCK_ID::0の黄ブロックをCIRCLE_ID::0の黄サークルまで移動させる
    coordinate_start = { 2, 0 };
    coordinate_goal = { 1, 1 };
    coordinate_destination = { 1, 1 };
    expected_route.clear();
    actual_route.clear();
    expected_route.push_back(std::make_pair(coordinate_start, Direction::W));
    expected_route.push_back(std::make_pair(coordinate_goal, Direction::SW));
    actual_route = route.calculateRoute(coordinate_start, coordinate_goal, coordinate_destination);
    EXPECT_EQ(expected_route, actual_route);
    courseInfo.moveBlock(CIRCLE_ID::ID0, BLOCK_ID::ID0);
    robot.setDirection(Direction::SW);  //走行体の向きを更新

    // BLOCK_ID::4の黄ブロックまで移動する
    coordinate_start = { 2, 0 };
    route_1 = { 2, 1 };
    route_2 = { 2, 2 };
    route_3 = { 2, 3 };
    coordinate_goal = { 2, 4 };
    coordinate_destination = { 5, 3 };
    expected_route.clear();
    actual_route.clear();
    expected_route.push_back(std::make_pair(coordinate_start, Direction::SW));
    expected_route.push_back(std::make_pair(route_1, Direction::S));
    expected_route.push_back(std::make_pair(route_2, Direction::S));
    expected_route.push_back(std::make_pair(route_3, Direction::S));
    expected_route.push_back(std::make_pair(coordinate_goal, Direction::S));
    actual_route = route.calculateRoute(coordinate_start, coordinate_goal, coordinate_destination);
    EXPECT_EQ(expected_route, actual_route);
    robot.setDirection(Direction::S);  //走行体の向きを更新

    // BLOCK_ID::4の黄ブロックをCIRCLE_ID::4の黄サークルまで移動させる
    coordinate_start = { 2, 4 };
    route_1 = { 3, 4 };
    route_2 = { 4, 4 };
    coordinate_goal = { 5, 3 };
    coordinate_destination = { 5, 3 };
    expected_route.clear();
    actual_route.clear();
    expected_route.push_back(std::make_pair(coordinate_start, Direction::S));
    expected_route.push_back(std::make_pair(route_1, Direction::E));
    expected_route.push_back(std::make_pair(route_2, Direction::E));
    expected_route.push_back(std::make_pair(coordinate_goal, Direction::NE));
    actual_route = route.calculateRoute(coordinate_start, coordinate_goal, coordinate_destination);
    EXPECT_EQ(expected_route, actual_route);
    courseInfo.moveBlock(CIRCLE_ID::ID4, BLOCK_ID::ID4);
    robot.setDirection(Direction::NE);  //走行体の向きを更新

    // BLOCK_ID::7の青ブロックまで移動する
    coordinate_start = { 4, 4 };
    route_1 = { 4, 5 };
    coordinate_goal = { 4, 6 };
    coordinate_destination = { 5, 5 };
    expected_route.clear();
    actual_route.clear();
    expected_route.push_back(std::make_pair(coordinate_start, Direction::NE));
    expected_route.push_back(std::make_pair(route_1, Direction::S));
    expected_route.push_back(std::make_pair(coordinate_goal, Direction::S));
    actual_route = route.calculateRoute(coordinate_start, coordinate_goal, coordinate_destination);
    EXPECT_EQ(expected_route, actual_route);
    robot.setDirection(Direction::S);  //走行体の向きを更新

    // BLOCK_ID::7の青ブロックをCIRCLE_ID::7の青サークルまで移動させる
    coordinate_start = { 4, 6 };
    coordinate_goal = { 5, 5 };
    coordinate_destination = { 5, 5 };
    expected_route.clear();
    actual_route.clear();
    expected_route.push_back(std::make_pair(coordinate_start, Direction::S));
    expected_route.push_back(std::make_pair(coordinate_goal, Direction::NE));
    actual_route = route.calculateRoute(coordinate_start, coordinate_goal, coordinate_destination);
    EXPECT_EQ(expected_route, actual_route);
    courseInfo.moveBlock(CIRCLE_ID::ID7, BLOCK_ID::ID7);
    robot.setDirection(Direction::S);  //走行体の向きを更新

    // BLOCK_ID::6の緑ブロックまで移動する
    coordinate_start = { 4, 6 };
    route_1 = { 3, 6 };
    route_2 = { 2, 6 };
    route_3 = { 1, 6 };
    coordinate_goal = { 0, 6 };
    coordinate_destination = { 1, 5 };
    expected_route.clear();
    actual_route.clear();
    expected_route.push_back(std::make_pair(coordinate_start, Direction::S));
    expected_route.push_back(std::make_pair(route_1, Direction::W));
    expected_route.push_back(std::make_pair(route_2, Direction::W));
    expected_route.push_back(std::make_pair(route_3, Direction::W));
    expected_route.push_back(std::make_pair(coordinate_goal, Direction::W));
    actual_route = route.calculateRoute(coordinate_start, coordinate_goal, coordinate_destination);
    EXPECT_EQ(expected_route, actual_route);
    robot.setDirection(Direction::W);  //走行体の向きを更新

    // BLOCK_ID::6の緑ブロックをCIRCLE_ID::5の緑サークルまで移動させる
    coordinate_start = { 0, 6 };
    coordinate_goal = { 1, 5 };
    coordinate_destination = { 1, 5 };
    expected_route.clear();
    actual_route.clear();
    expected_route.push_back(std::make_pair(coordinate_start, Direction::W));
    expected_route.push_back(std::make_pair(coordinate_goal, Direction::NE));
    actual_route = route.calculateRoute(coordinate_start, coordinate_goal, coordinate_destination);
    EXPECT_EQ(expected_route, actual_route);
    courseInfo.moveBlock(CIRCLE_ID::ID5, BLOCK_ID::ID6);
    robot.setDirection(Direction::W);  //走行体の向きを更新

    // BLOCK_ID::2の赤ブロックまで移動する
    coordinate_start = { 0, 6 };
    route_1 = { 0, 5 };
    route_2 = { 0, 4 };
    route_3 = { 0, 3 };
    coordinate_goal = { 0, 2 };
    coordinate_destination = { 3, 5 };
    expected_route.clear();
    actual_route.clear();
    expected_route.push_back(std::make_pair(coordinate_start, Direction::W));
    expected_route.push_back(std::make_pair(route_1, Direction::N));
    expected_route.push_back(std::make_pair(route_2, Direction::N));
    expected_route.push_back(std::make_pair(route_3, Direction::N));
    expected_route.push_back(std::make_pair(coordinate_goal, Direction::N));
    actual_route = route.calculateRoute(coordinate_start, coordinate_goal, coordinate_destination);
    EXPECT_EQ(expected_route, actual_route);
    robot.setDirection(Direction::N);  //走行体の向きを更新

    // BLOCK_ID::2の赤ブロックをCIRCLE_ID::6の赤サークルまで移動させる
    coordinate_start = { 0, 2 };
    route_1 = { 1, 2 };
    route_2 = { 2, 2 };
    route_3 = { 2, 3 };
    route_4 = { 2, 4 };
    coordinate_goal = { 3, 5 };
    coordinate_destination = { 3, 5 };
    expected_route.clear();
    actual_route.clear();
    expected_route.push_back(std::make_pair(coordinate_start, Direction::N));
    expected_route.push_back(std::make_pair(route_1, Direction::E));
    expected_route.push_back(std::make_pair(route_2, Direction::E));
    expected_route.push_back(std::make_pair(route_3, Direction::S));
    expected_route.push_back(std::make_pair(route_4, Direction::S));
    expected_route.push_back(std::make_pair(coordinate_goal, Direction::SE));
    actual_route = route.calculateRoute(coordinate_start, coordinate_goal, coordinate_destination);
    EXPECT_EQ(expected_route, actual_route);
    courseInfo.moveBlock(CIRCLE_ID::ID6, BLOCK_ID::ID2);
    robot.setDirection(Direction::SE);  //走行体の向きを更新

    // BLOCK_ID::5の赤ブロックまで移動する
    coordinate_start = { 2, 4 };
    route_1 = { 3, 4 };
    route_2 = { 4, 4 };
    route_3 = { 5, 4 };
    coordinate_goal = { 6, 4 };
    coordinate_destination = { 5, 1 };
    expected_route.clear();
    actual_route.clear();
    expected_route.push_back(std::make_pair(coordinate_start, Direction::SE));
    expected_route.push_back(std::make_pair(route_1, Direction::E));
    expected_route.push_back(std::make_pair(route_2, Direction::E));
    expected_route.push_back(std::make_pair(route_3, Direction::E));
    expected_route.push_back(std::make_pair(coordinate_goal, Direction::E));
    actual_route = route.calculateRoute(coordinate_start, coordinate_goal, coordinate_destination);
    EXPECT_EQ(expected_route, actual_route);
    robot.setDirection(Direction::E);  //走行体の向きを更新

    // BLOCK_ID::5の赤ブロックをCIRCLE_ID::2の赤サークルまで移動させる
    coordinate_start = { 6, 4 };
    route_1 = { 6, 3 };
    route_2 = { 6, 2 };
    coordinate_goal = { 5, 1 };
    coordinate_destination = { 5, 1 };
    expected_route.clear();
    actual_route.clear();
    expected_route.push_back(std::make_pair(coordinate_start, Direction::E));
    expected_route.push_back(std::make_pair(route_1, Direction::N));
    expected_route.push_back(std::make_pair(route_2, Direction::N));
    expected_route.push_back(std::make_pair(coordinate_goal, Direction::NW));
    actual_route = route.calculateRoute(coordinate_start, coordinate_goal, coordinate_destination);
    EXPECT_EQ(expected_route, actual_route);
    courseInfo.moveBlock(CIRCLE_ID::ID2, BLOCK_ID::ID5);
    robot.setDirection(Direction::NW);  //走行体の向きを更新

    // BLOCK_ID::1の青ブロックまで移動する
    coordinate_start = { 6, 2 };
    route_1 = { 6, 1 };
    coordinate_goal = { 6, 0 };
    coordinate_destination = { 1, 3 };
    expected_route.clear();
    actual_route.clear();
    expected_route.push_back(std::make_pair(coordinate_start, Direction::NW));
    expected_route.push_back(std::make_pair(route_1, Direction::N));
    expected_route.push_back(std::make_pair(coordinate_goal, Direction::N));
    actual_route = route.calculateRoute(coordinate_start, coordinate_goal, coordinate_destination);
    EXPECT_EQ(expected_route, actual_route);
    robot.setDirection(Direction::N);  //走行体の向きを更新

    // BLOCK_ID::1の青ブロックをCIRCLE_ID::3の青サークルまで移動させる
    coordinate_start = { 6, 0 };
    route_1 = { 5, 0 };
    route_2 = { 4, 0 };
    route_3 = { 3, 0 };
    route_4 = { 2, 0 };
    route_5 = { 2, 1 };
    route_6 = { 2, 2 };
    coordinate_goal = { 1, 3 };
    coordinate_destination = { 1, 3 };
    expected_route.clear();
    actual_route.clear();
    expected_route.push_back(std::make_pair(coordinate_start, Direction::N));
    expected_route.push_back(std::make_pair(route_1, Direction::W));
    expected_route.push_back(std::make_pair(route_2, Direction::W));
    expected_route.push_back(std::make_pair(route_3, Direction::W));
    expected_route.push_back(std::make_pair(route_4, Direction::W));
    expected_route.push_back(std::make_pair(route_5, Direction::S));
    expected_route.push_back(std::make_pair(route_6, Direction::S));
    expected_route.push_back(std::make_pair(coordinate_goal, Direction::SW));
    actual_route = route.calculateRoute(coordinate_start, coordinate_goal, coordinate_destination);
    EXPECT_EQ(expected_route, actual_route);
    courseInfo.moveBlock(CIRCLE_ID::ID3, BLOCK_ID::ID1);
    robot.setDirection(Direction::SW);  //走行体の向きを更新
    //この時点でフルビンゴ
  };
}  // namespace etrobocon2021_test
