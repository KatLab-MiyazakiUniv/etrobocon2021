/**
 * @file MotionConverterTest.cpp
 * @brief 動作変換クラスのテスト
 * @author Hisataka-Hagiyama,uchyam
 */

#include "MotionConverter.h"
#include "RouteCalculator.h"
#include <gtest/gtest.h>
namespace etrobocon2021_test {
  //フルビンゴまでの各径路に置ける挙動をテストする
  TEST(MotionConverter, fullBingo)
  {
    constexpr bool IS_LEFT_COURSE = true;
    Robot robot(IS_LEFT_COURSE);
    BingoArea bingoArea;
    bingoArea.initBingoArea();
    RouteCalculator route(bingoArea, robot);
    MotionConverter motionConverter;

    // BLOCK_ID::3の緑ブロックまで移動する
    Coordinate start = { 2, 3 };
    Coordinate goal = { 4, 2 };
    std::vector<std::pair<Coordinate, Direction>> minroute = route.calculateRoute(start, goal);
    std::vector<MOTION> expectedmotion = { MOTION::TARC90, MOTION::BC, MOTION::TR, MOTION::BC };
    std::vector<MOTION> actualmotion = motionConverter.convertToMotion(minroute);
    EXPECT_EQ(expectedmotion, actualmotion);
    robot.setDirection(Direction::E);  // 走行体の向きを更新

    // BLOCK_ID::3の緑ブロックをCIRCLE_ID::1の緑サークルまで移動させる
    start = { 4, 2 };
    goal = { 3, 1 };
    minroute.clear();
    minroute = route.calculateRoute(start, goal);
    expectedmotion = { MOTION::PSET };
    actualmotion = motionConverter.convertToMotion(minroute);
    EXPECT_EQ(expectedmotion, actualmotion);
    bingoArea.moveBlock(CIRCLE_ID::ID1, BLOCK_ID::ID3);
    robot.setDirection(Direction::E);  //走行体の向きを更新

    // BLOCK_ID::0の黄ブロックまで移動する
    start = { 4, 2 };
    goal = { 2, 0 };
    minroute.clear();
    minroute = route.calculateRoute(start, goal);
    expectedmotion = { MOTION::TARC90, MOTION::BC, MOTION::TL, MOTION::BC };
    actualmotion = motionConverter.convertToMotion(minroute);
    EXPECT_EQ(expectedmotion, actualmotion);
    robot.setDirection(Direction::W);  //走行体の向きを更新

    // BLOCK_ID::0の黄ブロックをCIRCLE_ID::0の黄サークルまで移動させる
    start = { 2, 0 };
    goal = { 1, 1 };
    minroute.clear();
    minroute = route.calculateRoute(start, goal);
    expectedmotion = { MOTION::TSET };
    actualmotion = motionConverter.convertToMotion(minroute);
    EXPECT_EQ(expectedmotion, actualmotion);
    bingoArea.moveBlock(CIRCLE_ID::ID0, BLOCK_ID::ID0);
    robot.setDirection(Direction::W);  //走行体の向きを更新

    // BLOCK_ID::4の黄ブロックまで移動する
    start = { 2, 0 };
    goal = { 2, 4 };
    minroute.clear();
    minroute = route.calculateRoute(start, goal);
    expectedmotion = { MOTION::TARC90, MOTION::BC, MOTION::ST, MOTION::BC };
    actualmotion = motionConverter.convertToMotion(minroute);
    EXPECT_EQ(expectedmotion, actualmotion);
    robot.setDirection(Direction::S);  //走行体の向きを更新

    // BLOCK_ID::4の黄ブロックをCIRCLE_ID::4の黄サークルまで移動させる
    start = { 2, 4 };
    goal = { 5, 3 };
    minroute.clear();
    minroute = route.calculateRoute(start, goal);
    expectedmotion = { MOTION::TARC90, MOTION::BC, MOTION::TSET };
    actualmotion = motionConverter.convertToMotion(minroute);
    EXPECT_EQ(expectedmotion, actualmotion);
    bingoArea.moveBlock(CIRCLE_ID::ID4, BLOCK_ID::ID4);
    robot.setDirection(Direction::E);  //走行体の向きを更新

    // BLOCK_ID::7の青ブロックまで移動する
    start = { 4, 4 };
    goal = { 4, 6 };
    minroute.clear();
    minroute = route.calculateRoute(start, goal);
    expectedmotion = { MOTION::TAC90, MOTION::BC };
    actualmotion = motionConverter.convertToMotion(minroute);
    EXPECT_EQ(expectedmotion, actualmotion);
    robot.setDirection(Direction::S);  //走行体の向きを更新

    // BLOCK_ID::7の青ブロックをCIRCLE_ID::7の青サークルまで移動させる
    start = { 4, 6 };
    goal = { 5, 5 };
    minroute.clear();
    minroute = route.calculateRoute(start, goal);
    expectedmotion = { MOTION::PSET };
    actualmotion = motionConverter.convertToMotion(minroute);
    EXPECT_EQ(expectedmotion, actualmotion);
    bingoArea.moveBlock(CIRCLE_ID::ID7, BLOCK_ID::ID7);
    robot.setDirection(Direction::S);  //走行体の向きを更新

    // BLOCK_ID::6の緑ブロックまで移動する
    start = { 4, 6 };
    goal = { 0, 6 };
    minroute.clear();
    minroute = route.calculateRoute(start, goal);
    expectedmotion = { MOTION::TAC90, MOTION::BC, MOTION::ST, MOTION::BC };
    actualmotion = motionConverter.convertToMotion(minroute);
    EXPECT_EQ(expectedmotion, actualmotion);
    robot.setDirection(Direction::W);  //走行体の向きを更新

    // BLOCK_ID::6の緑ブロックをCIRCLE_ID::5の緑サークルまで移動させる
    start = { 0, 6 };
    goal = { 1, 5 };
    minroute.clear();
    minroute = route.calculateRoute(start, goal);
    expectedmotion = { MOTION::PSET };
    actualmotion = motionConverter.convertToMotion(minroute);
    EXPECT_EQ(expectedmotion, actualmotion);
    bingoArea.moveBlock(CIRCLE_ID::ID5, BLOCK_ID::ID6);
    robot.setDirection(Direction::W);  //走行体の向きを更新

    // BLOCK_ID::2の赤ブロックまで移動する
    start = { 0, 6 };
    goal = { 0, 2 };
    minroute.clear();
    minroute = route.calculateRoute(start, goal);
    expectedmotion = { MOTION::TAC90, MOTION::BC, MOTION::ST, MOTION::BC };
    actualmotion = motionConverter.convertToMotion(minroute);
    EXPECT_EQ(expectedmotion, actualmotion);
    robot.setDirection(Direction::N);  //走行体の向きを更新

    // BLOCK_ID::2の赤ブロックをCIRCLE_ID::6の赤サークルまで移動させる
    start = { 0, 2 };
    goal = { 3, 5 };
    minroute.clear();
    minroute = route.calculateRoute(start, goal);
    expectedmotion = { MOTION::TAC90, MOTION::BC, MOTION::TR, MOTION::BC, MOTION::TSET };
    actualmotion = motionConverter.convertToMotion(minroute);
    EXPECT_EQ(expectedmotion, actualmotion);
    bingoArea.moveBlock(CIRCLE_ID::ID6, BLOCK_ID::ID2);
    robot.setDirection(Direction::S);  //走行体の向きを更新

    // BLOCK_ID::5の赤ブロックまで移動する
    start = { 2, 4 };
    goal = { 6, 4 };
    minroute.clear();
    minroute = route.calculateRoute(start, goal);
    expectedmotion = { MOTION::TARC90, MOTION::BC, MOTION::ST, MOTION::BC };
    actualmotion = motionConverter.convertToMotion(minroute);
    EXPECT_EQ(expectedmotion, actualmotion);
    robot.setDirection(Direction::E);  //走行体の向きを更新

    // BLOCK_ID::5の赤ブロックをCIRCLE_ID::2の赤サークルまで移動させる
    start = { 6, 4 };
    goal = { 5, 1 };
    minroute.clear();
    minroute = route.calculateRoute(start, goal);
    expectedmotion = { MOTION::TARC90, MOTION::BC, MOTION::TSET };
    actualmotion = motionConverter.convertToMotion(minroute);
    EXPECT_EQ(expectedmotion, actualmotion);
    bingoArea.moveBlock(CIRCLE_ID::ID2, BLOCK_ID::ID5);
    robot.setDirection(Direction::N);  //走行体の向きを更新

    // BLOCK_ID::1の青ブロックまで移動する
    start = { 6, 2 };
    goal = { 6, 0 };
    minroute.clear();
    minroute = route.calculateRoute(start, goal);
    expectedmotion = { MOTION::BC };
    actualmotion = motionConverter.convertToMotion(minroute);
    EXPECT_EQ(expectedmotion, actualmotion);
    robot.setDirection(Direction::N);  //走行体の向きを更新

    // BLOCK_ID::1の青ブロックをCIRCLE_ID::3の青サークルまで移動させる
    start = { 6, 0 };
    goal = { 1, 3 };
    minroute.clear();
    minroute = route.calculateRoute(start, goal);
    expectedmotion = { MOTION::TA180, MOTION::BC, MOTION::TR,  MOTION::BC,
                       MOTION::ST,    MOTION::BC, MOTION::TSET };
    actualmotion = motionConverter.convertToMotion(minroute);
    for(auto i : actualmotion) printf("%d\n", i);
    EXPECT_EQ(expectedmotion, actualmotion);
    bingoArea.moveBlock(CIRCLE_ID::ID3, BLOCK_ID::ID1);
    robot.setDirection(Direction::W);  //走行体の向きを更新
    //この時点でフルビンゴ
  };
}  // namespace etrobocon2021_test
