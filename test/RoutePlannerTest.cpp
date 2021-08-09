/**
 * @file RoutePlannerTest.cpp
 * @brief RoutePlannerクラスをテストする
 * @author hiroto0927, miyashita64
 */

#include "RoutePlanner.h"
#include <gtest/gtest.h>
namespace etrobocon2021_test {
  TEST(planBingoRouteTest, planBingoRouteLeft)
  {
    constexpr bool IS_LEFT_COURSE = true;
    BingoArea bingoArea;
    bingoArea.initBingoArea();
    RoutePlanner routePlanner(bingoArea, IS_LEFT_COURSE);

    // 経路計画
    routePlanner.planBingoRoute();

    // 全てのブロックサークルにブロックがあることを確認
    bool blockCircleExpected = true;
    for(int blockCircleNum = 0; blockCircleNum < 8; blockCircleNum++) {
      CIRCLE_ID blockCircleId = static_cast<CIRCLE_ID>(blockCircleNum);
      BlockCircle blockCircle = bingoArea.getBlockCircle(blockCircleId);
      Coordinate blockCircleCoord = blockCircle.getCoordinate();
      EXPECT_EQ(blockCircleExpected, bingoArea.existBlock(blockCircleCoord));
    }

    // 全ての交点サークルにブロックがないことを確認
    bool crossCircleExpected = false;
    for(int crossCircleNum = 0; crossCircleNum < 16; crossCircleNum++) {
      CrossCircle crossCircle = bingoArea.getCrossCircle(crossCircleNum);
      Coordinate crossCircleCoord = crossCircle.getCoordinate();
      EXPECT_EQ(crossCircleExpected, bingoArea.existBlock(crossCircleCoord));
    }
  }

  TEST(planBingoRouteTest, planBingoRouteRight)
  {
    constexpr bool IS_LEFT_COURSE = false;
    BingoArea bingoArea;
    bingoArea.initBingoArea();
    RoutePlanner routePlanner(bingoArea, IS_LEFT_COURSE);

    // 経路計画
    routePlanner.planBingoRoute();

    // 全てのブロックサークルにブロックがあることを確認
    bool blockCircleExpected = true;
    for(int blockCircleNum = 0; blockCircleNum < 8; blockCircleNum++) {
      CIRCLE_ID blockCircleId = static_cast<CIRCLE_ID>(blockCircleNum);
      BlockCircle blockCircle = bingoArea.getBlockCircle(blockCircleId);
      Coordinate blockCircleCoord = blockCircle.getCoordinate();
      EXPECT_EQ(blockCircleExpected, bingoArea.existBlock(blockCircleCoord));
    }

    // 全ての交点サークルにブロックがないことを確認
    bool crossCircleExpected = false;
    for(int crossCircleNum = 0; crossCircleNum < 16; crossCircleNum++) {
      CrossCircle crossCircle = bingoArea.getCrossCircle(crossCircleNum);
      Coordinate crossCircleCoord = crossCircle.getCoordinate();
      EXPECT_EQ(crossCircleExpected, bingoArea.existBlock(crossCircleCoord));
    }
  }
}  // namespace etrobocon2021_test
