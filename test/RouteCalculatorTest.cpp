/**
 * @file RouteCalculatorTest.cpp
 * @brief 経路計算クラスのテスト
 * @author Hisataka-Hagiyama,uchyam
 */

#include "RouteCalculator.h"
#include <gtest/gtest.h>
namespace etrobocon2021_test {
  TEST(RouteCalculator, pattern1)
  {
    BingoArea bingoArea;
    bingoArea.initBingoArea();
    RouteCalculator route(bingoArea);
    Coordinate coordinate_start = { 4, 2 };
    Coordinate coordinate_goal = { 3, 1 };
    std::vector<std::pair<Coordinate, Direction>> expected_route;
    expected_route.push_back(std::make_pair(coordinate_start, Direction::N));
    expected_route.push_back(std::make_pair(coordinate_goal, Direction::NW));
    std::vector<std::pair<Coordinate, Direction>> actual_route
        = route.calculateRoute(coordinate_start, coordinate_goal);
    EXPECT_EQ(expected_route, actual_route);

    bingoArea.moveBlock(CIRCLE_ID::ID1, BLOCK_ID::ID3);

    coordinate_start = { 2, 0 };
    coordinate_goal = { 1, 1 };
    std::vector<std::pair<Coordinate, Direction>> expected_route1;
    expected_route1.push_back(std::make_pair(coordinate_start, Direction::N));
    expected_route1.push_back(std::make_pair(coordinate_goal, Direction::SW));
    std::vector<std::pair<Coordinate, Direction>> actual_route1
        = route.calculateRoute(coordinate_start, coordinate_goal);
    EXPECT_EQ(expected_route1, actual_route1);

    bingoArea.moveBlock(CIRCLE_ID::ID0, BLOCK_ID::ID0);

    coordinate_start = { 2, 4 };
    Coordinate coordinate_1 = { 4, 4 };
    coordinate_goal = { 5, 3 };
    std::vector<std::pair<Coordinate, Direction>> expected_route2;
    expected_route2.push_back(std::make_pair(coordinate_start, Direction::N));
    expected_route2.push_back(std::make_pair(coordinate_1, Direction::E));
    expected_route2.push_back(std::make_pair(coordinate_goal, Direction::NE));
    std::vector<std::pair<Coordinate, Direction>> actual_route2
        = route.calculateRoute(coordinate_start, coordinate_goal);
    EXPECT_EQ(expected_route2, actual_route2);

    bingoArea.moveBlock(CIRCLE_ID::ID4, BLOCK_ID::ID4);

    coordinate_start = { 4, 6 };
    coordinate_goal = { 5, 5 };
    std::vector<std::pair<Coordinate, Direction>> expected_route3;
    expected_route3.push_back(std::make_pair(coordinate_start, Direction::N));
    expected_route3.push_back(std::make_pair(coordinate_goal, Direction::NE));
    std::vector<std::pair<Coordinate, Direction>> actual_route3
        = route.calculateRoute(coordinate_start, coordinate_goal);
    EXPECT_EQ(expected_route3, actual_route3);

    bingoArea.moveBlock(CIRCLE_ID::ID7, BLOCK_ID::ID7);

    coordinate_start = { 0, 6 };
    coordinate_goal = { 1, 5 };
    std::vector<std::pair<Coordinate, Direction>> expected_route4;
    expected_route4.push_back(std::make_pair(coordinate_start, Direction::N));
    expected_route4.push_back(std::make_pair(coordinate_goal, Direction::NE));
    std::vector<std::pair<Coordinate, Direction>> actual_route4
        = route.calculateRoute(coordinate_start, coordinate_goal);
    EXPECT_EQ(expected_route4, actual_route4);

    bingoArea.moveBlock(CIRCLE_ID::ID5, BLOCK_ID::ID6);

    coordinate_start = { 0, 2 };
    coordinate_1 = { 2, 2 };
    Coordinate coordinate_2 = { 2, 4 };
    coordinate_goal = { 3, 5 };
    std::vector<std::pair<Coordinate, Direction>> expected_route5;
    expected_route5.push_back(std::make_pair(coordinate_start, Direction::N));
    expected_route5.push_back(std::make_pair(coordinate_1, Direction::E));
    expected_route5.push_back(std::make_pair(coordinate_2, Direction::S));
    expected_route5.push_back(std::make_pair(coordinate_goal, Direction::SE));
    std::vector<std::pair<Coordinate, Direction>> actual_route5
        = route.calculateRoute(coordinate_start, coordinate_goal);
    EXPECT_EQ(expected_route5, actual_route5);

    bingoArea.moveBlock(CIRCLE_ID::ID6, BLOCK_ID::ID2);

    coordinate_start = { 6, 4 };
    coordinate_1 = { 6, 2 };
    coordinate_goal = { 5, 1 };
    std::vector<std::pair<Coordinate, Direction>> expected_route6;
    expected_route6.push_back(std::make_pair(coordinate_start, Direction::N));
    expected_route6.push_back(std::make_pair(coordinate_1, Direction::N));
    expected_route6.push_back(std::make_pair(coordinate_goal, Direction::NW));
    std::vector<std::pair<Coordinate, Direction>> actual_route6
        = route.calculateRoute(coordinate_start, coordinate_goal);
    EXPECT_EQ(expected_route6, actual_route6);

    bingoArea.moveBlock(CIRCLE_ID::ID2, BLOCK_ID::ID5);

    coordinate_start = { 6, 0 };
    coordinate_1 = { 6, 2 };
    coordinate_2 = { 4, 2 };
    Coordinate coordinate_3 = { 2, 2 };
    coordinate_goal = { 1, 3 };
    std::vector<std::pair<Coordinate, Direction>> expected_route7;
    expected_route7.push_back(std::make_pair(coordinate_start, Direction::N));
    expected_route7.push_back(std::make_pair(coordinate_1, Direction::S));
    expected_route7.push_back(std::make_pair(coordinate_2, Direction::W));
    expected_route7.push_back(std::make_pair(coordinate_3, Direction::W));
    expected_route7.push_back(std::make_pair(coordinate_goal, Direction::SW));
    std::vector<std::pair<Coordinate, Direction>> actual_route7
        = route.calculateRoute(coordinate_start, coordinate_goal);
    EXPECT_EQ(expected_route7, actual_route7);

    bingoArea.moveBlock(CIRCLE_ID::ID3, BLOCK_ID::ID1);
  };
}  // namespace etrobocon2021_test
