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
    LineTracer lineTracer(IS_LEFT_COURSE);
    Robot robot(IS_LEFT_COURSE);
    CourseInfo courseInfo;
    courseInfo.initCourseInfo();
    RouteCalculator route(courseInfo, robot, IS_LEFT_COURSE);
    MotionPerformer motionPerformer(lineTracer);
    MotionConverter motionConverter(motionPerformer, IS_LEFT_COURSE);
    std::vector<MOTION> expectedMotion;  //期待する動作を表す列挙子を記録していく動的配列
    MotionPerformer::motionLog.clear();  //他クラスで記録した履歴を消去する
    // BLOCK_ID::3の緑ブロックまで移動する
    Coordinate start = { 2, 3 };
    Coordinate goal = { 4, 2 };
    std::vector<std::pair<Coordinate, Direction>> minRoute = route.calculateRoute(start, goal);
    expectedMotion.push_back(MOTION::CDRC);
    expectedMotion.push_back(MOTION::CDRC);
    expectedMotion.push_back(MOTION::RTC);
    expectedMotion.push_back(MOTION::RR);
    expectedMotion.push_back(MOTION::RTC);
    motionConverter.convertToMotion(minRoute);
    EXPECT_EQ(expectedMotion, MotionPerformer::motionLog);
    robot.setDirection(Direction::E);  // 走行体の向きを更新

    // BLOCK_ID::3の緑ブロックをCIRCLE_ID::1の緑サークルまで移動させる
    start = { 4, 2 };
    goal = { 3, 1 };
    minRoute = route.calculateRoute(start, goal);
    expectedMotion.push_back(MOTION::SBPL);
    motionConverter.convertToMotion(minRoute);
    EXPECT_EQ(expectedMotion, MotionPerformer::motionLog);
    courseInfo.moveBlock(CIRCLE_ID::ID1, BLOCK_ID::ID3);
    robot.setDirection(Direction::E);  //走行体の向きを更新

    // BLOCK_ID::0の黄ブロックまで移動する
    start = { 4, 2 };
    goal = { 2, 0 };
    minRoute = route.calculateRoute(start, goal);
    expectedMotion.push_back(MOTION::CDRC);
    expectedMotion.push_back(MOTION::CDRC);
    expectedMotion.push_back(MOTION::RTC);
    expectedMotion.push_back(MOTION::RL);
    expectedMotion.push_back(MOTION::RTC);
    motionConverter.convertToMotion(minRoute);
    EXPECT_EQ(expectedMotion, MotionPerformer::motionLog);
    robot.setDirection(Direction::W);  //走行体の向きを更新

    // BLOCK_ID::0の黄ブロックをCIRCLE_ID::0の黄サークルまで移動させる
    start = { 2, 0 };
    goal = { 1, 1 };
    minRoute = route.calculateRoute(start, goal);
    expectedMotion.push_back(MOTION::SBTL);
    motionConverter.convertToMotion(minRoute);
    EXPECT_EQ(expectedMotion, MotionPerformer::motionLog);
    courseInfo.moveBlock(CIRCLE_ID::ID0, BLOCK_ID::ID0);
    robot.setDirection(Direction::SW);  //走行体の向きを更新

    // BLOCK_ID::4の黄ブロックまで移動する
    start = { 2, 0 };
    goal = { 2, 4 };
    minRoute = route.calculateRoute(start, goal);
    expectedMotion.push_back(MOTION::CDRC);
    expectedMotion.push_back(MOTION::RTC);
    expectedMotion.push_back(MOTION::RF);
    expectedMotion.push_back(MOTION::RTC);
    motionConverter.convertToMotion(minRoute);
    EXPECT_EQ(expectedMotion, MotionPerformer::motionLog);
    robot.setDirection(Direction::S);  //走行体の向きを更新

    // BLOCK_ID::4の黄ブロックをCIRCLE_ID::4の黄サークルまで移動させる
    start = { 2, 4 };
    goal = { 5, 3 };
    minRoute = route.calculateRoute(start, goal);
    expectedMotion.push_back(MOTION::CDRC);
    expectedMotion.push_back(MOTION::CDRC);
    expectedMotion.push_back(MOTION::RTC);
    expectedMotion.push_back(MOTION::SBTL);
    motionConverter.convertToMotion(minRoute);
    EXPECT_EQ(expectedMotion, MotionPerformer::motionLog);
    courseInfo.moveBlock(CIRCLE_ID::ID4, BLOCK_ID::ID4);
    robot.setDirection(Direction::NE);  //走行体の向きを更新

    // BLOCK_ID::7の青ブロックまで移動する
    start = { 4, 4 };
    goal = { 4, 6 };
    minRoute = route.calculateRoute(start, goal);
    expectedMotion.push_back(MOTION::CDC);
    expectedMotion.push_back(MOTION::CDC);
    expectedMotion.push_back(MOTION::CDC);
    expectedMotion.push_back(MOTION::RTC);
    motionConverter.convertToMotion(minRoute);
    EXPECT_EQ(expectedMotion, MotionPerformer::motionLog);
    robot.setDirection(Direction::S);  //走行体の向きを更新

    // BLOCK_ID::7の青ブロックをCIRCLE_ID::7の青サークルまで移動させる
    start = { 4, 6 };
    goal = { 5, 5 };
    minRoute = route.calculateRoute(start, goal);
    expectedMotion.push_back(MOTION::SBPL);
    motionConverter.convertToMotion(minRoute);
    EXPECT_EQ(expectedMotion, MotionPerformer::motionLog);
    courseInfo.moveBlock(CIRCLE_ID::ID7, BLOCK_ID::ID7);
    robot.setDirection(Direction::S);  //走行体の向きを更新

    // BLOCK_ID::6の緑ブロックまで移動する
    start = { 4, 6 };
    goal = { 0, 6 };
    minRoute = route.calculateRoute(start, goal);
    expectedMotion.push_back(MOTION::CDC);
    expectedMotion.push_back(MOTION::CDC);
    expectedMotion.push_back(MOTION::RTC);
    expectedMotion.push_back(MOTION::RF);
    expectedMotion.push_back(MOTION::RTC);
    motionConverter.convertToMotion(minRoute);
    EXPECT_EQ(expectedMotion, MotionPerformer::motionLog);
    robot.setDirection(Direction::W);  //走行体の向きを更新

    // BLOCK_ID::6の緑ブロックをCIRCLE_ID::5の緑サークルまで移動させる
    start = { 0, 6 };
    goal = { 1, 5 };
    minRoute = route.calculateRoute(start, goal);
    expectedMotion.push_back(MOTION::SBPR);
    motionConverter.convertToMotion(minRoute);
    EXPECT_EQ(expectedMotion, MotionPerformer::motionLog);
    courseInfo.moveBlock(CIRCLE_ID::ID5, BLOCK_ID::ID6);
    robot.setDirection(Direction::W);  //走行体の向きを更新

    // BLOCK_ID::2の赤ブロックまで移動する
    start = { 0, 6 };
    goal = { 0, 2 };
    minRoute = route.calculateRoute(start, goal);
    expectedMotion.push_back(MOTION::CDC);
    expectedMotion.push_back(MOTION::CDC);
    expectedMotion.push_back(MOTION::RTC);
    expectedMotion.push_back(MOTION::RF);
    expectedMotion.push_back(MOTION::RTC);
    motionConverter.convertToMotion(minRoute);
    EXPECT_EQ(expectedMotion, MotionPerformer::motionLog);
    robot.setDirection(Direction::N);  //走行体の向きを更新

    // BLOCK_ID::2の赤ブロックをCIRCLE_ID::6の赤サークルまで移動させる
    start = { 0, 2 };
    goal = { 3, 5 };
    minRoute = route.calculateRoute(start, goal);
    expectedMotion.push_back(MOTION::CDC);
    expectedMotion.push_back(MOTION::CDC);
    expectedMotion.push_back(MOTION::RTC);
    expectedMotion.push_back(MOTION::RR);
    expectedMotion.push_back(MOTION::RTC);
    expectedMotion.push_back(MOTION::SBTL);
    motionConverter.convertToMotion(minRoute);
    EXPECT_EQ(expectedMotion, MotionPerformer::motionLog);
    courseInfo.moveBlock(CIRCLE_ID::ID6, BLOCK_ID::ID2);
    robot.setDirection(Direction::SE);  //走行体の向きを更新

    // BLOCK_ID::5の赤ブロックまで移動する
    start = { 2, 4 };
    goal = { 6, 4 };
    minRoute = route.calculateRoute(start, goal);
    expectedMotion.push_back(MOTION::CDRC);
    expectedMotion.push_back(MOTION::RTC);
    expectedMotion.push_back(MOTION::RF);
    expectedMotion.push_back(MOTION::RTC);
    motionConverter.convertToMotion(minRoute);
    EXPECT_EQ(expectedMotion, MotionPerformer::motionLog);
    robot.setDirection(Direction::E);  //走行体の向きを更新

    // BLOCK_ID::5の赤ブロックをCIRCLE_ID::2の赤サークルまで移動させる
    start = { 6, 4 };
    goal = { 5, 1 };
    minRoute.clear();
    minRoute = route.calculateRoute(start, goal);
    expectedMotion.push_back(MOTION::CDRC);
    expectedMotion.push_back(MOTION::CDRC);
    expectedMotion.push_back(MOTION::RTC);
    expectedMotion.push_back(MOTION::SBTL);
    motionConverter.convertToMotion(minRoute);
    EXPECT_EQ(expectedMotion, MotionPerformer::motionLog);
    courseInfo.moveBlock(CIRCLE_ID::ID2, BLOCK_ID::ID5);
    robot.setDirection(Direction::NW);  //走行体の向きを更新

    // BLOCK_ID::1の青ブロックまで移動する
    start = { 6, 2 };
    goal = { 6, 0 };
    minRoute = route.calculateRoute(start, goal);
    expectedMotion.push_back(MOTION::CDC);
    expectedMotion.push_back(MOTION::RTC);
    motionConverter.convertToMotion(minRoute);
    EXPECT_EQ(expectedMotion, MotionPerformer::motionLog);
    robot.setDirection(Direction::N);  //走行体の向きを更新

    // BLOCK_ID::1の青ブロックをCIRCLE_ID::3の青サークルまで移動させる
    start = { 6, 0 };
    goal = { 1, 3 };
    minRoute = route.calculateRoute(start, goal);
    expectedMotion.push_back(MOTION::CDC);
    expectedMotion.push_back(MOTION::CDC);
    expectedMotion.push_back(MOTION::CDC);
    expectedMotion.push_back(MOTION::CDC);
    expectedMotion.push_back(MOTION::RTC);
    expectedMotion.push_back(MOTION::RR);
    expectedMotion.push_back(MOTION::RTC);
    expectedMotion.push_back(MOTION::RF);
    expectedMotion.push_back(MOTION::RTC);
    expectedMotion.push_back(MOTION::SBTL);
    motionConverter.convertToMotion(minRoute);
    EXPECT_EQ(expectedMotion, MotionPerformer::motionLog);
    courseInfo.moveBlock(CIRCLE_ID::ID3, BLOCK_ID::ID1);
    robot.setDirection(Direction::W);  //走行体の向きを更新
    // この時点でフルビンゴ
  };
}  // namespace etrobocon2021_test
