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
    BingoArea bingoArea;
    bingoArea.initBingoArea();
    RouteCalculator route(bingoArea, robot);

    // BLOCK_ID::3の緑ブロックまで移動する
    Coordinate coordinate_start = { 2, 3 };
    Coordinate route_1 = { 2, 2 };
    Coordinate coordinate_goal = { 4, 2 };
    std::vector<std::pair<Coordinate, Direction>> expected_route;
    expected_route.push_back(std::make_pair(coordinate_start, Direction::E));
    expected_route.push_back(std::make_pair(route_1, Direction::N));
    expected_route.push_back(std::make_pair(coordinate_goal, Direction::E));
    std::vector<std::pair<Coordinate, Direction>> actual_route
        = route.calculateRoute(coordinate_start, coordinate_goal);
    EXPECT_EQ(expected_route, actual_route);
    robot.setDirection(Direction::E);  //走行体の向きを更新

    // BLOCK_ID::3の緑ブロックをCIRCLE_ID::1の緑サークルまで移動させる
    coordinate_start = { 4, 2 };
    coordinate_goal = { 3, 1 };
    expected_route.clear();
    actual_route.clear();
    expected_route.push_back(std::make_pair(coordinate_start, Direction::E));
    expected_route.push_back(std::make_pair(coordinate_goal, Direction::NW));
    actual_route = route.calculateRoute(coordinate_start, coordinate_goal);
    EXPECT_EQ(expected_route, actual_route);
    bingoArea.moveBlock(CIRCLE_ID::ID1, BLOCK_ID::ID3);
    robot.setDirection(Direction::E);  //走行体の向きを更新

    // BLOCK_ID::0の黄ブロックまで移動する
    coordinate_start = { 4, 2 };
    route_1 = { 4, 0 };
    coordinate_goal = { 2, 0 };
    expected_route.clear();
    actual_route.clear();
    expected_route.push_back(std::make_pair(coordinate_start, Direction::E));
    expected_route.push_back(std::make_pair(route_1, Direction::N));
    expected_route.push_back(std::make_pair(coordinate_goal, Direction::W));
    actual_route = route.calculateRoute(coordinate_start, coordinate_goal);
    EXPECT_EQ(expected_route, actual_route);
    robot.setDirection(Direction::W);  //走行体の向きを更新

    // BLOCK_ID::0の黄ブロックをCIRCLE_ID::0の黄サークルまで移動させる
    coordinate_start = { 2, 0 };
    coordinate_goal = { 1, 1 };
    expected_route.clear();
    actual_route.clear();
    expected_route.push_back(std::make_pair(coordinate_start, Direction::W));
    expected_route.push_back(std::make_pair(coordinate_goal, Direction::SW));
    actual_route = route.calculateRoute(coordinate_start, coordinate_goal);
    EXPECT_EQ(expected_route, actual_route);
    bingoArea.moveBlock(CIRCLE_ID::ID0, BLOCK_ID::ID0);
    robot.setDirection(Direction::W);  //走行体の向きを更新

    // BLOCK_ID::4の黄ブロックまで移動する
    coordinate_start = { 2, 0 };
    route_1 = { 2, 2 };
    coordinate_goal = { 2, 4 };
    expected_route.clear();
    actual_route.clear();
    expected_route.push_back(std::make_pair(coordinate_start, Direction::W));
    expected_route.push_back(std::make_pair(route_1, Direction::S));
    expected_route.push_back(std::make_pair(coordinate_goal, Direction::S));
    actual_route = route.calculateRoute(coordinate_start, coordinate_goal);
    EXPECT_EQ(expected_route, actual_route);
    robot.setDirection(Direction::S);  //走行体の向きを更新

    // BLOCK_ID::4の黄ブロックをCIRCLE_ID::4の黄サークルまで移動させる
    coordinate_start = { 2, 4 };
    coordinate_goal = { 4, 4 };
    expected_route.clear();
    actual_route.clear();
    expected_route.push_back(std::make_pair(coordinate_start, Direction::S));
    expected_route.push_back(std::make_pair(coordinate_goal, Direction::E));
    actual_route = route.calculateRoute(coordinate_start, coordinate_goal);
    EXPECT_EQ(expected_route, actual_route);
    bingoArea.moveBlock(CIRCLE_ID::ID4, BLOCK_ID::ID4);
    robot.setDirection(Direction::S);  //走行体の向きを更新

    // BLOCK_ID::7の青ブロックまで移動する
    coordinate_start = { 4, 4 };
    coordinate_goal = { 4, 6 };
    expected_route.clear();
    actual_route.clear();
    expected_route.push_back(std::make_pair(coordinate_start, Direction::S));
    expected_route.push_back(std::make_pair(coordinate_goal, Direction::S));
    actual_route = route.calculateRoute(coordinate_start, coordinate_goal);
    EXPECT_EQ(expected_route, actual_route);
    robot.setDirection(Direction::S);  //走行体の向きを更新

    // BLOCK_ID::7の青ブロックをCIRCLE_ID::7の青サークルまで移動させる
    coordinate_start = { 4, 6 };
    coordinate_goal = { 5, 5 };
    expected_route.clear();
    actual_route.clear();
    expected_route.push_back(std::make_pair(coordinate_start, Direction::S));
    expected_route.push_back(std::make_pair(coordinate_goal, Direction::NE));
    actual_route = route.calculateRoute(coordinate_start, coordinate_goal);
    EXPECT_EQ(expected_route, actual_route);
    bingoArea.moveBlock(CIRCLE_ID::ID7, BLOCK_ID::ID7);
    robot.setDirection(Direction::S);  //走行体の向きを更新

    // BLOCK_ID::6の緑ブロックまで移動する
    coordinate_start = { 4, 6 };
    route_1 = { 2, 6 };
    coordinate_goal = { 0, 6 };
    expected_route.clear();
    actual_route.clear();
    expected_route.push_back(std::make_pair(coordinate_start, Direction::S));
    expected_route.push_back(std::make_pair(route_1, Direction::W));
    expected_route.push_back(std::make_pair(coordinate_goal, Direction::W));
    actual_route = route.calculateRoute(coordinate_start, coordinate_goal);
    EXPECT_EQ(expected_route, actual_route);
    robot.setDirection(Direction::W);  //走行体の向きを更新

    // BLOCK_ID::6の緑ブロックをCIRCLE_ID::5の緑サークルまで移動させる
    coordinate_start = { 0, 6 };
    coordinate_goal = { 1, 5 };
    expected_route.clear();
    actual_route.clear();
    expected_route.push_back(std::make_pair(coordinate_start, Direction::W));
    expected_route.push_back(std::make_pair(coordinate_goal, Direction::NE));
    actual_route = route.calculateRoute(coordinate_start, coordinate_goal);
    EXPECT_EQ(expected_route, actual_route);
    bingoArea.moveBlock(CIRCLE_ID::ID5, BLOCK_ID::ID6);
    robot.setDirection(Direction::E);  //走行体の向きを更新

    // BLOCK_ID::2の赤ブロックまで移動する
    coordinate_start = { 0, 6 };
    route_1 = { 0, 4 };
    coordinate_goal = { 0, 2 };
    expected_route.clear();
    actual_route.clear();
    expected_route.push_back(std::make_pair(coordinate_start, Direction::E));
    expected_route.push_back(std::make_pair(route_1, Direction::N));
    expected_route.push_back(std::make_pair(coordinate_goal, Direction::N));
    actual_route = route.calculateRoute(coordinate_start, coordinate_goal);
    EXPECT_EQ(expected_route, actual_route);
    robot.setDirection(Direction::N);  //走行体の向きを更新

    // BLOCK_ID::2の赤ブロックをCIRCLE_ID::6の赤サークルまで移動させる
    coordinate_start = { 0, 2 };
    route_1 = { 2, 2 };
    Coordinate route_2 = { 2, 4 };
    coordinate_goal = { 3, 5 };
    expected_route.clear();
    actual_route.clear();
    expected_route.push_back(std::make_pair(coordinate_start, Direction::N));
    expected_route.push_back(std::make_pair(route_1, Direction::E));
    expected_route.push_back(std::make_pair(route_2, Direction::S));
    expected_route.push_back(std::make_pair(coordinate_goal, Direction::SE));
    actual_route = route.calculateRoute(coordinate_start, coordinate_goal);
    EXPECT_EQ(expected_route, actual_route);
    bingoArea.moveBlock(CIRCLE_ID::ID6, BLOCK_ID::ID2);
    robot.setDirection(Direction::S);  //走行体の向きを更新

    // BLOCK_ID::5の赤ブロックまで移動する
    coordinate_start = { 2, 4 };
    route_1 = { 4, 4 };
    coordinate_goal = { 6, 4 };
    expected_route.clear();
    actual_route.clear();
    expected_route.push_back(std::make_pair(coordinate_start, Direction::S));
    expected_route.push_back(std::make_pair(route_1, Direction::E));
    expected_route.push_back(std::make_pair(coordinate_goal, Direction::E));
    actual_route = route.calculateRoute(coordinate_start, coordinate_goal);
    EXPECT_EQ(expected_route, actual_route);
    robot.setDirection(Direction::E);  //走行体の向きを更新

    // BLOCK_ID::5の赤ブロックをCIRCLE_ID::2の赤サークルまで移動させる
    coordinate_start = { 6, 4 };
    route_1 = { 6, 2 };
    coordinate_goal = { 5, 1 };
    expected_route.clear();
    actual_route.clear();
    expected_route.push_back(std::make_pair(coordinate_start, Direction::E));
    expected_route.push_back(std::make_pair(route_1, Direction::N));
    expected_route.push_back(std::make_pair(coordinate_goal, Direction::NW));
    actual_route = route.calculateRoute(coordinate_start, coordinate_goal);
    EXPECT_EQ(expected_route, actual_route);
    bingoArea.moveBlock(CIRCLE_ID::ID2, BLOCK_ID::ID5);
    robot.setDirection(Direction::N);  //走行体の向きを更新

    // BLOCK_ID::1の青ブロックまで移動する
    coordinate_start = { 6, 2 };
    coordinate_goal = { 6, 0 };
    expected_route.clear();
    actual_route.clear();
    expected_route.push_back(std::make_pair(coordinate_start, Direction::N));
    expected_route.push_back(std::make_pair(coordinate_goal, Direction::N));
    actual_route = route.calculateRoute(coordinate_start, coordinate_goal);
    EXPECT_EQ(expected_route, actual_route);
    robot.setDirection(Direction::N);  //走行体の向きを更新

    // BLOCK_ID::1の青ブロックをCIRCLE_ID::3の青サークルまで移動させる
    coordinate_start = { 6, 0 };
    route_1 = { 6, 2 };
    route_2 = { 4, 2 };
    Coordinate route_3 = { 2, 2 };
    coordinate_goal = { 1, 3 };
    expected_route.clear();
    actual_route.clear();
    expected_route.push_back(std::make_pair(coordinate_start, Direction::N));
    expected_route.push_back(std::make_pair(route_1, Direction::S));
    expected_route.push_back(std::make_pair(route_2, Direction::W));
    expected_route.push_back(std::make_pair(route_3, Direction::W));
    expected_route.push_back(std::make_pair(coordinate_goal, Direction::SW));
    actual_route = route.calculateRoute(coordinate_start, coordinate_goal);
    EXPECT_EQ(expected_route, actual_route);
    bingoArea.moveBlock(CIRCLE_ID::ID3, BLOCK_ID::ID1);
    robot.setDirection(Direction::W);  //走行体の向きを更新
    //この時点でフルビンゴ
  };
}  // namespace etrobocon2021_test
