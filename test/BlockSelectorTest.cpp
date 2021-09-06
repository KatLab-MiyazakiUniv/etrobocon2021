/**
 * @file BlockSelectorTest.cpp
 * @brief BlockSelectorクラスをテストする
 * @author hiroto0927, miyashita64
 */

#include "BlockSelector.h"
#include <gtest/gtest.h>
namespace etrobocon2021_test {
  TEST(selectBlockTest, selectBlockRoute1)
  {
    constexpr bool IS_LEFT_COURSE = true;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    Robot robot(IS_LEFT_COURSE);
    const int B_ZERO = static_cast<int>(BLOCK_ID::ID0);
    const int B_SIZE = static_cast<int>(BLOCK_ID::ID7) + 1;

    // 初期配置
    COLOR initBlockColor[B_SIZE] = { COLOR::RED, COLOR::BLUE, COLOR::YELLOW, COLOR::GREEN,
                                     COLOR::RED, COLOR::BLUE, COLOR::YELLOW, COLOR::GREEN };

    // 手計算で求めた運搬ブロックの順番
    BLOCK_ID expecteds[B_SIZE] = {
      BLOCK_ID::ID4, BLOCK_ID::ID3, BLOCK_ID::ID5, BLOCK_ID::ID7,
      BLOCK_ID::ID2, BLOCK_ID::ID0, BLOCK_ID::ID1, BLOCK_ID::ID6,
    };

    for(int i = B_ZERO; i < B_SIZE; i++) {
      BLOCK_ID blockId = static_cast<BLOCK_ID>(i);
      courseInfo.getNode(blockId).setBlock(blockId, initBlockColor[i]);
    }

    // フルビンゴになるまで運搬するブロックを探索し、正しいかを判定する
    DestinationList destinationList(courseInfo);
    BlockSelector blockSelector(destinationList, IS_LEFT_COURSE);
    for(int i = B_ZERO; i < B_SIZE; i++) {
      // 次に運搬するブロックを決定する
      BLOCK_ID targetBlockId = blockSelector.selectBlock();
      CIRCLE_ID targetCircleId = destinationList.getDestination(targetBlockId);
      // 正誤判定
      EXPECT_EQ(expecteds[i], targetBlockId);

      // 運搬したものとして、走行体の座標と進行方向を更新する
      Coordinate currentCoord
          = courseInfo.getNode(targetBlockId).getCoordinate();  // 運搬ブロックの座標
      Coordinate targetCoord
          = courseInfo.getBlockCircle(targetCircleId).getCoordinate();  // 運搬先の座標

      // 走行体は、運搬先サークル周辺の交点サークルの内、最も近いものから侵入する
      // 運搬先サークルに対し、右(1)から向かうか、左(-1)から向かうか
      int dx = (targetCoord.x - currentCoord.x > 0) ? 1 : -1;
      // 運搬先サークルに対し、下(1)から向かうか、上(-1)から向かうか
      int dy = (targetCoord.y - currentCoord.y > 0) ? 1 : -1;
      // 運搬後の方向を算出
      Direction direction;
      if(dy > 0) {
        if(dx > 0) {
          direction = Direction::SE;
        } else if(dx < 0) {
          direction = Direction::SW;
        } else {
          direction = Direction::S;
        }
      } else if(dy < 0) {
        if(dx > 0) {
          direction = Direction::NE;
        } else if(dx < 0) {
          direction = Direction::NW;
        } else {
          direction = Direction::N;
        }
      } else {
        if(dx > 0) {
          direction = Direction::E;
        } else {
          direction = Direction::W;
        }
      }
      // 走行体の座標を更新
      robot.setCoordinate({ targetCoord.x - dx, targetCoord.y - dy });
      // 走行体の進行方向を更新
      robot.setDirection(direction);

      // 運搬されたものとして、ブロックの座標を更新する
      courseInfo.moveBlock(targetCircleId, targetBlockId);
    }
  }

  TEST(selectBlockTest, selectBlockRoute2)
  {
    constexpr bool IS_LEFT_COURSE = true;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    Robot robot(IS_LEFT_COURSE);
    const int B_ZERO = static_cast<int>(BLOCK_ID::ID0);
    const int B_SIZE = static_cast<int>(BLOCK_ID::ID7) + 1;

    // 初期配置
    COLOR initBlockColor[B_SIZE] = { COLOR::RED,   COLOR::YELLOW, COLOR::BLUE, COLOR::YELLOW,
                                     COLOR::GREEN, COLOR::BLUE,   COLOR::RED,  COLOR::GREEN };

    // 手計算で求めた運搬ブロックの順番
    BLOCK_ID expecteds[B_SIZE] = {
      BLOCK_ID::ID4, BLOCK_ID::ID2, BLOCK_ID::ID3, BLOCK_ID::ID0,
      BLOCK_ID::ID1, BLOCK_ID::ID5, BLOCK_ID::ID7, BLOCK_ID::ID6,
    };

    for(int i = B_ZERO; i < B_SIZE; i++) {
      BLOCK_ID blockId = static_cast<BLOCK_ID>(i);
      courseInfo.getNode(blockId).setBlock(blockId, initBlockColor[i]);
    }

    // フルビンゴになるまで運搬するブロックを探索し、正しいかを判定する
    DestinationList destinationList(courseInfo);
    BlockSelector blockSelector(destinationList, IS_LEFT_COURSE);
    for(int i = B_ZERO; i < B_SIZE; i++) {
      // 次に運搬するブロックを決定する
      BLOCK_ID targetBlockId = blockSelector.selectBlock();
      CIRCLE_ID targetCircleId = destinationList.getDestination(targetBlockId);
      // 正誤判定
      EXPECT_EQ(expecteds[i], targetBlockId);

      // 運搬したものとして、走行体の座標と進行方向を更新する
      Coordinate currentCoord
          = courseInfo.getNode(targetBlockId).getCoordinate();  // 運搬ブロックの座標
      Coordinate targetCoord
          = courseInfo.getBlockCircle(targetCircleId).getCoordinate();  // 運搬先の座標

      // 走行体は、運搬先サークル周辺の交点サークルの内、最も近いものから侵入する
      // 運搬先サークルに対し、右(1)から向かうか、左(-1)から向かうか
      int dx = (targetCoord.x - currentCoord.x > 0) ? 1 : -1;
      // 運搬先サークルに対し、下(1)から向かうか、上(-1)から向かうか
      int dy = (targetCoord.y - currentCoord.y > 0) ? 1 : -1;
      // 運搬後の方向を算出
      Direction direction;
      if(dy > 0) {
        if(dx > 0) {
          direction = Direction::SE;
        } else if(dx < 0) {
          direction = Direction::SW;
        } else {
          direction = Direction::S;
        }
      } else if(dy < 0) {
        if(dx > 0) {
          direction = Direction::NE;
        } else if(dx < 0) {
          direction = Direction::NW;
        } else {
          direction = Direction::N;
        }
      } else {
        if(dx > 0) {
          direction = Direction::E;
        } else {
          direction = Direction::W;
        }
      }

      // 走行体の座標を更新
      robot.setCoordinate({ targetCoord.x - dx, targetCoord.y - dy });
      // 走行体の進行方向を更新
      robot.setDirection(direction);

      // 運搬されたものとして、ブロックの座標を更新する
      courseInfo.moveBlock(targetCircleId, targetBlockId);
    }
  }

  TEST(selectBlockTest, selectBlockRoute3)
  {
    constexpr bool IS_LEFT_COURSE = true;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    Robot robot(IS_LEFT_COURSE);
    const int B_ZERO = static_cast<int>(BLOCK_ID::ID0);
    const int B_SIZE = static_cast<int>(BLOCK_ID::ID7) + 1;

    // 初期配置
    COLOR initBlockColor[B_SIZE] = { COLOR::GREEN,  COLOR::BLUE, COLOR::RED,   COLOR::BLUE,
                                     COLOR::YELLOW, COLOR::RED,  COLOR::GREEN, COLOR::YELLOW };

    // 手計算で求めた運搬ブロックの順番
    BLOCK_ID expecteds[B_SIZE] = {
      BLOCK_ID::ID0, BLOCK_ID::ID3, BLOCK_ID::ID4, BLOCK_ID::ID2,
      BLOCK_ID::ID6, BLOCK_ID::ID7, BLOCK_ID::ID5, BLOCK_ID::ID1,
    };

    for(int i = B_ZERO; i < B_SIZE; i++) {
      BLOCK_ID blockId = static_cast<BLOCK_ID>(i);
      courseInfo.getNode(blockId).setBlock(blockId, initBlockColor[i]);
    }

    // フルビンゴになるまで運搬するブロックを探索し、正しいかを判定する
    DestinationList destinationList(courseInfo);
    BlockSelector blockSelector(destinationList, IS_LEFT_COURSE);
    for(int i = B_ZERO; i < B_SIZE; i++) {
      // 次に運搬するブロックを決定する
      BLOCK_ID targetBlockId = blockSelector.selectBlock();
      CIRCLE_ID targetCircleId = destinationList.getDestination(targetBlockId);
      // 正誤判定
      EXPECT_EQ(expecteds[i], targetBlockId);

      // 運搬したものとして、走行体の座標と進行方向を更新する
      Coordinate currentCoord
          = courseInfo.getNode(targetBlockId).getCoordinate();  // 運搬ブロックの座標
      Coordinate targetCoord
          = courseInfo.getBlockCircle(targetCircleId).getCoordinate();  // 運搬先の座標

      // 走行体は、運搬先サークル周辺の交点サークルの内、最も近いものから侵入する
      // 運搬先サークルに対し、右(1)から向かうか、左(-1)から向かうか
      int dx = (targetCoord.x - currentCoord.x > 0) ? 1 : -1;
      // 運搬先サークルに対し、下(1)から向かうか、上(-1)から向かうか
      int dy = (targetCoord.y - currentCoord.y > 0) ? 1 : -1;
      // 運搬後の方向を算出
      Direction direction;
      if(dy > 0) {
        if(dx > 0) {
          direction = Direction::SE;
        } else if(dx < 0) {
          direction = Direction::SW;
        } else {
          direction = Direction::S;
        }
      } else if(dy < 0) {
        if(dx > 0) {
          direction = Direction::NE;
        } else if(dx < 0) {
          direction = Direction::NW;
        } else {
          direction = Direction::N;
        }
      } else {
        if(dx > 0) {
          direction = Direction::E;
        } else {
          direction = Direction::W;
        }
      }

      // 走行体の座標を更新
      robot.setCoordinate({ targetCoord.x - dx, targetCoord.y - dy });
      // 走行体の進行方向を更新
      robot.setDirection(direction);

      // 運搬されたものとして、ブロックの座標を更新する
      courseInfo.moveBlock(targetCircleId, targetBlockId);
    }
  }

  TEST(selectBlockTest, selectBlockRoute4)
  {
    constexpr bool IS_LEFT_COURSE = true;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    Robot robot(IS_LEFT_COURSE);
    const int B_ZERO = static_cast<int>(BLOCK_ID::ID0);
    const int B_SIZE = static_cast<int>(BLOCK_ID::ID7) + 1;

    // 初期配置
    COLOR initBlockColor[B_SIZE] = { COLOR::YELLOW, COLOR::GREEN, COLOR::RED,  COLOR::GREEN,
                                     COLOR::BLUE,   COLOR::RED,   COLOR::BLUE, COLOR::YELLOW };

    // 手計算で求めた運搬ブロックの順番
    BLOCK_ID expecteds[B_SIZE] = {
      BLOCK_ID::ID4, BLOCK_ID::ID5, BLOCK_ID::ID0, BLOCK_ID::ID1,
      BLOCK_ID::ID3, BLOCK_ID::ID7, BLOCK_ID::ID6, BLOCK_ID::ID2,
    };

    for(int i = B_ZERO; i < B_SIZE; i++) {
      BLOCK_ID blockId = static_cast<BLOCK_ID>(i);
      courseInfo.getNode(blockId).setBlock(blockId, initBlockColor[i]);
    }

    // フルビンゴになるまで運搬するブロックを探索し、正しいかを判定する
    DestinationList destinationList(courseInfo);
    BlockSelector blockSelector(destinationList, IS_LEFT_COURSE);
    for(int i = B_ZERO; i < B_SIZE; i++) {
      // 次に運搬するブロックを決定する
      BLOCK_ID targetBlockId = blockSelector.selectBlock();
      CIRCLE_ID targetCircleId = destinationList.getDestination(targetBlockId);
      // 正誤判定
      EXPECT_EQ(expecteds[i], targetBlockId);

      // 運搬したものとして、走行体の座標と進行方向を更新する
      Coordinate currentCoord
          = courseInfo.getNode(targetBlockId).getCoordinate();  // 運搬ブロックの座標
      Coordinate targetCoord
          = courseInfo.getBlockCircle(targetCircleId).getCoordinate();  // 運搬先の座標

      // 走行体は、運搬先サークル周辺の交点サークルの内、最も近いものから侵入する
      // 運搬先サークルに対し、右(1)から向かうか、左(-1)から向かうか
      int dx = (targetCoord.x - currentCoord.x > 0) ? 1 : -1;
      // 運搬先サークルに対し、下(1)から向かうか、上(-1)から向かうか
      int dy = (targetCoord.y - currentCoord.y > 0) ? 1 : -1;
      // 運搬後の方向を算出
      Direction direction;
      if(dy > 0) {
        if(dx > 0) {
          direction = Direction::SE;
        } else if(dx < 0) {
          direction = Direction::SW;
        } else {
          direction = Direction::S;
        }
      } else if(dy < 0) {
        if(dx > 0) {
          direction = Direction::NE;
        } else if(dx < 0) {
          direction = Direction::NW;
        } else {
          direction = Direction::N;
        }
      } else {
        if(dx > 0) {
          direction = Direction::E;
        } else {
          direction = Direction::W;
        }
      }

      // 走行体の座標を更新
      robot.setCoordinate({ targetCoord.x - dx, targetCoord.y - dy });
      // 走行体の進行方向を更新
      robot.setDirection(direction);

      // 運搬されたものとして、ブロックの座標を更新する
      courseInfo.moveBlock(targetCircleId, targetBlockId);
    }
  }

  TEST(selectBlockTest, selectBlockRoute5)
  {
    constexpr bool IS_LEFT_COURSE = true;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    Robot robot(IS_LEFT_COURSE);

    const int B_ZERO = static_cast<int>(BLOCK_ID::ID0);
    const int B_SIZE = static_cast<int>(BLOCK_ID::ID7) + 1;

    // 初期配置
    COLOR initBlockColor[B_SIZE] = { COLOR::GREEN, COLOR::GREEN, COLOR::YELLOW, COLOR::RED,
                                     COLOR::BLUE,  COLOR::RED,   COLOR::YELLOW, COLOR::BLUE };

    // 手計算で求めた運搬ブロックの順番
    BLOCK_ID expecteds[B_SIZE] = {
      BLOCK_ID::ID4, BLOCK_ID::ID3, BLOCK_ID::ID7, BLOCK_ID::ID5,
      BLOCK_ID::ID2, BLOCK_ID::ID0, BLOCK_ID::ID6, BLOCK_ID::ID1,
    };

    for(int i = B_ZERO; i < B_SIZE; i++) {
      BLOCK_ID blockId = static_cast<BLOCK_ID>(i);
      courseInfo.getNode(blockId).setBlock(blockId, initBlockColor[i]);
    }

    // フルビンゴになるまで運搬するブロックを探索し、正しいかを判定する
    DestinationList destinationList(courseInfo);
    BlockSelector blockSelector(destinationList, IS_LEFT_COURSE);
    for(int i = B_ZERO; i < B_SIZE; i++) {
      // 次に運搬するブロックを決定する
      BLOCK_ID targetBlockId = blockSelector.selectBlock();
      CIRCLE_ID targetCircleId = destinationList.getDestination(targetBlockId);
      // 正誤判定
      EXPECT_EQ(expecteds[i], targetBlockId);

      // 運搬したものとして、走行体の座標と進行方向を更新する
      Coordinate currentCoord
          = courseInfo.getNode(targetBlockId).getCoordinate();  // 運搬ブロックの座標
      Coordinate targetCoord
          = courseInfo.getBlockCircle(targetCircleId).getCoordinate();  // 運搬先の座標

      // 走行体は、運搬先サークル周辺の交点サークルの内、最も近いものから侵入する
      // 運搬先サークルに対し、右(1)から向かうか、左(-1)から向かうか
      int dx = (targetCoord.x - currentCoord.x > 0) ? 1 : -1;
      // 運搬先サークルに対し、下(1)から向かうか、上(-1)から向かうか
      int dy = (targetCoord.y - currentCoord.y > 0) ? 1 : -1;
      // 運搬後の方向を算出
      Direction direction;
      if(dy > 0) {
        if(dx > 0) {
          direction = Direction::SE;
        } else if(dx < 0) {
          direction = Direction::SW;
        } else {
          direction = Direction::S;
        }
      } else if(dy < 0) {
        if(dx > 0) {
          direction = Direction::NE;
        } else if(dx < 0) {
          direction = Direction::NW;
        } else {
          direction = Direction::N;
        }
      } else {
        if(dx > 0) {
          direction = Direction::E;
        } else {
          direction = Direction::W;
        }
      }

      // 走行体の座標を更新
      robot.setCoordinate({ targetCoord.x - dx, targetCoord.y - dy });
      // 走行体の進行方向を更新
      robot.setDirection(direction);

      // 運搬されたものとして、ブロックの座標を更新する
      courseInfo.moveBlock(targetCircleId, targetBlockId);
    }
  }

}  // namespace etrobocon2021_test
