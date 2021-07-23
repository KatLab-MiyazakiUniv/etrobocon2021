/**
 * @file RouteCalculaterTest.cpp
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
    // std::vector<std::pair<Coordinate, Direction>> expected_route{
    //   { 2, 4, 1 }, { 2, 3, 1 }, { 2, 2, 1 }, { 1, 1, 0 }
    // };
    int expected_x = 2;
    int expected_y = 4;

    std::vector<std::pair<Coordinate, Direction>> actual_route
        = route.calculateRoute({ 2, 4 }, { 1, 1 });

    EXPECT_EQ(expected_x, actual_route[0].first.x);
    EXPECT_EQ(expected_y, actual_route[0].first.y);
  };
}  // namespace etrobocon2021_test