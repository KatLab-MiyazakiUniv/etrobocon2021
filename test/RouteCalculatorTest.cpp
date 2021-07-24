#include "RouteCalculator.h"
#include <gtest/gtest.h>
namespace etrobocon2021_test {
  TEST(RouteCalculator, pattern1)
  {
    BingoArea bingoArea;
    bingoArea.initBingoArea();
    RouteCalculator route(bingoArea);
    Coordinate coordinate_start = { 2, 4 };
    Coordinate coordinate_1 = { 2, 2 };
    Coordinate coordinate_goal = { 1, 1 };
    std::vector<std::pair<Coordinate, Direction>> expected_route;
    expected_route.push_back(std::make_pair(coordinate_start, Direction::N));
    expected_route.push_back(std::make_pair(coordinate_1, Direction::N));
    expected_route.push_back(std::make_pair(coordinate_goal, Direction::NW));
    std::vector<std::pair<Coordinate, Direction>> actual_route
        = route.calculateRoute(coordinate_start, coordinate_goal);
    for(const auto& i : actual_route) {
      printf("%d %d %d\n", i.first.x, i.first.y, i.second);
    }
    EXPECT_EQ(expected_route, actual_route);
  };
}  // namespace etrobocon2021_test
