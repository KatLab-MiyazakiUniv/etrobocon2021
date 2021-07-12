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
    BingoArea bingoArea;

    const int B_ZERO = static_cast<int>(BLOCK_ID::ID0);
    const int B_SIZE = static_cast<int>(BLOCK_ID::SIZE);

    // 初期配置
    COLOR initBlockColor[B_SIZE] = { COLOR::RED, COLOR::BLUE, COLOR::YELLOW, COLOR::GREEN,
                                     COLOR::RED, COLOR::BLUE, COLOR::YELLOW, COLOR::GREEN };

    // 手計算で求めた運搬ブロックの順番
    BLOCK_ID expecteds[B_SIZE] = {
      BLOCK_ID::ID4, BLOCK_ID::ID3, BLOCK_ID::ID2, BLOCK_ID::ID0,
      BLOCK_ID::ID5, BLOCK_ID::ID7, BLOCK_ID::ID6, BLOCK_ID::ID1,
    };

    // 初期化
    for(int i = B_ZERO; i < B_SIZE; i++) {
      BLOCK_ID blockId = static_cast<BLOCK_ID>(i);
      bingoArea.getBlockInfo(blockId).setBlock(blockId, initBlockColor[i]);
    }

    // フルビンゴになるまで運搬するブロックを探索し、正しいかを判定する
    DestinationList destinationList(bingoArea);
    BlockSelector blockSelector(bingoArea);
    for(int i = B_ZERO; i < B_SIZE; i++) {
      // 次に運搬するブロックを決定する
      BLOCK_ID targetBlockId = blockSelector.selectBlock();
      CIRCLE_ID targetCircleId = destinationList.getDestination(targetBlockId);
      EXPECT_EQ(expecteds[i], targetBlockId);

      // 運搬されたものとして、ブロックの座標を更新する
      bingoArea.moveBlock(targetCircleId, targetBlockId);
      // 運搬したものとして、走行体の座標と進行方向を更新する
      Coordinate currentCoord
          = bingoArea.getBlockInfo(targetBlockId).getCoordinate();  // 運搬ブロックの座標
      Coordinate targetCoord
          = bingoArea.getBlockCircleInfo(targetCircleId).getCoordinate();  // 運搬先の座標

      int dx = (targetCoord.x - currentCoord.x > 0) ? 1 : -1;
      int dy = (targetCoord.y - currentCoord.y > 0) ? 1 : -1;

      // 座標の更新
      Robot::setCoordinate({ targetCoord.x - dx, targetCoord.y - dy });
      // 進行方向の更新
      Robot::setDirection(static_cast<Direction>((dx + 1) + (1 - dy) * 3));
    }
  }

  TEST(selectBlockTest, selectBlockRoute2)
  {
    BingoArea bingoArea;

    const int B_ZERO = static_cast<int>(BLOCK_ID::ID0);
    const int B_SIZE = static_cast<int>(BLOCK_ID::SIZE);

    // 初期配置
    COLOR initBlockColor[B_SIZE] = { COLOR::RED,   COLOR::YELLOW, COLOR::BLUE, COLOR::YELLOW,
                                     COLOR::GREEN, COLOR::BLUE,   COLOR::RED,  COLOR::GREEN };

    // 手計算で求めた運搬ブロックの順番
    BLOCK_ID expecteds[B_SIZE] = {
      BLOCK_ID::ID4, BLOCK_ID::ID2, BLOCK_ID::ID3, BLOCK_ID::ID5,
      BLOCK_ID::ID1, BLOCK_ID::ID0, BLOCK_ID::ID7, BLOCK_ID::ID6,
    };

    // 初期化
    for(int i = B_ZERO; i < B_SIZE; i++) {
      BLOCK_ID blockId = static_cast<BLOCK_ID>(i);
      bingoArea.getBlockInfo(blockId).setBlock(blockId, initBlockColor[i]);
    }

    // フルビンゴになるまで運搬するブロックを探索し、正しいかを判定する
    DestinationList destinationList(bingoArea);
    BlockSelector blockSelector(bingoArea);
    for(int i = B_ZERO; i < B_SIZE; i++) {
      // 次に運搬するブロックを決定する
      BLOCK_ID targetBlockId = blockSelector.selectBlock();
      CIRCLE_ID targetCircleId = destinationList.getDestination(targetBlockId);
      EXPECT_EQ(expecteds[i], targetBlockId);

      // 運搬されたものとして、ブロックの座標を更新する
      bingoArea.moveBlock(targetCircleId, targetBlockId);
      // 運搬したものとして、走行体の座標と進行方向を更新する
      Coordinate currentCoord
          = bingoArea.getBlockInfo(targetBlockId).getCoordinate();  // 運搬ブロックの座標
      Coordinate targetCoord
          = bingoArea.getBlockCircleInfo(targetCircleId).getCoordinate();  // 運搬先の座標

      int dx = (targetCoord.x - currentCoord.x > 0) ? 1 : -1;
      int dy = (targetCoord.y - currentCoord.y > 0) ? 1 : -1;

      // 座標の更新
      Robot::setCoordinate({ targetCoord.x - dx, targetCoord.y - dy });
      // 進行方向の更新
      Robot::setDirection(static_cast<Direction>((dx + 1) + (1 - dy) * 3));
    }
  }

  TEST(selectBlockTest, selectBlockRoute3)
  {
    BingoArea bingoArea;

    const int B_ZERO = static_cast<int>(BLOCK_ID::ID0);
    const int B_SIZE = static_cast<int>(BLOCK_ID::SIZE);

    // 初期配置
    COLOR initBlockColor[B_SIZE] = { COLOR::GREEN,  COLOR::BLUE, COLOR::RED,   COLOR::BLUE,
                                     COLOR::YELLOW, COLOR::RED,  COLOR::GREEN, COLOR::YELLOW };

    // 手計算で求めた運搬ブロックの順番
    BLOCK_ID expecteds[B_SIZE] = {
      BLOCK_ID::ID4, BLOCK_ID::ID0, BLOCK_ID::ID3, BLOCK_ID::ID2,
      BLOCK_ID::ID6, BLOCK_ID::ID7, BLOCK_ID::ID5, BLOCK_ID::ID1,
    };

    // 初期化
    for(int i = B_ZERO; i < B_SIZE; i++) {
      BLOCK_ID blockId = static_cast<BLOCK_ID>(i);
      bingoArea.getBlockInfo(blockId).setBlock(blockId, initBlockColor[i]);
    }

    // フルビンゴになるまで運搬するブロックを探索し、正しいかを判定する
    DestinationList destinationList(bingoArea);
    BlockSelector blockSelector(bingoArea);
    for(int i = B_ZERO; i < B_SIZE; i++) {
      // 次に運搬するブロックを決定する
      BLOCK_ID targetBlockId = blockSelector.selectBlock();
      CIRCLE_ID targetCircleId = destinationList.getDestination(targetBlockId);
      EXPECT_EQ(expecteds[i], targetBlockId);

      // 運搬されたものとして、ブロックの座標を更新する
      bingoArea.moveBlock(targetCircleId, targetBlockId);
      // 運搬したものとして、走行体の座標と進行方向を更新する
      Coordinate currentCoord
          = bingoArea.getBlockInfo(targetBlockId).getCoordinate();  // 運搬ブロックの座標
      Coordinate targetCoord
          = bingoArea.getBlockCircleInfo(targetCircleId).getCoordinate();  // 運搬先の座標

      int dx = (targetCoord.x - currentCoord.x > 0) ? 1 : -1;
      int dy = (targetCoord.y - currentCoord.y > 0) ? 1 : -1;

      // 座標の更新
      Robot::setCoordinate({ targetCoord.x - dx, targetCoord.y - dy });
      // 進行方向の更新
      Robot::setDirection(static_cast<Direction>((dx + 1) + (1 - dy) * 3));
    }
  }

  TEST(selectBlockTest, selectBlockRoute4)
  {
    BingoArea bingoArea;

    const int B_ZERO = static_cast<int>(BLOCK_ID::ID0);
    const int B_SIZE = static_cast<int>(BLOCK_ID::SIZE);

    // 初期配置
    COLOR initBlockColor[B_SIZE] = { COLOR::YELLOW, COLOR::GREEN, COLOR::RED,  COLOR::GREEN,
                                     COLOR::BLUE,   COLOR::RED,   COLOR::BLUE, COLOR::YELLOW };

    // 手計算で求めた運搬ブロックの順番
    BLOCK_ID expecteds[B_SIZE] = {
      BLOCK_ID::ID4, BLOCK_ID::ID5, BLOCK_ID::ID1, BLOCK_ID::ID0,
      BLOCK_ID::ID3, BLOCK_ID::ID7, BLOCK_ID::ID6, BLOCK_ID::ID2,
    };

    // 初期化
    for(int i = B_ZERO; i < B_SIZE; i++) {
      BLOCK_ID blockId = static_cast<BLOCK_ID>(i);
      bingoArea.getBlockInfo(blockId).setBlock(blockId, initBlockColor[i]);
    }

    // フルビンゴになるまで運搬するブロックを探索し、正しいかを判定する
    DestinationList destinationList(bingoArea);
    BlockSelector blockSelector(bingoArea);
    for(int i = B_ZERO; i < B_SIZE; i++) {
      // 次に運搬するブロックを決定する
      BLOCK_ID targetBlockId = blockSelector.selectBlock();
      CIRCLE_ID targetCircleId = destinationList.getDestination(targetBlockId);
      EXPECT_EQ(expecteds[i], targetBlockId);

      // 運搬されたものとして、ブロックの座標を更新する
      bingoArea.moveBlock(targetCircleId, targetBlockId);
      // 運搬したものとして、走行体の座標と進行方向を更新する
      Coordinate currentCoord
          = bingoArea.getBlockInfo(targetBlockId).getCoordinate();  // 運搬ブロックの座標
      Coordinate targetCoord
          = bingoArea.getBlockCircleInfo(targetCircleId).getCoordinate();  // 運搬先の座標

      int dx = (targetCoord.x - currentCoord.x > 0) ? 1 : -1;
      int dy = (targetCoord.y - currentCoord.y > 0) ? 1 : -1;

      // 座標の更新
      Robot::setCoordinate({ targetCoord.x - dx, targetCoord.y - dy });
      // 進行方向の更新
      Robot::setDirection(static_cast<Direction>((dx + 1) + (1 - dy) * 3));
    }
  }

  TEST(selectBlockTest, selectBlockRoute5)
  {
    BingoArea bingoArea;

    const int B_ZERO = static_cast<int>(BLOCK_ID::ID0);
    const int B_SIZE = static_cast<int>(BLOCK_ID::SIZE);

    // 初期配置
    COLOR initBlockColor[B_SIZE] = { COLOR::GREEN, COLOR::GREEN, COLOR::YELLOW, COLOR::RED,
                                     COLOR::BLUE,  COLOR::RED,   COLOR::YELLOW, COLOR::BLUE };

    // 手計算で求めた運搬ブロックの順番
    BLOCK_ID expecteds[B_SIZE] = {
      BLOCK_ID::ID4, BLOCK_ID::ID3, BLOCK_ID::ID2, BLOCK_ID::ID0,
      BLOCK_ID::ID5, BLOCK_ID::ID7, BLOCK_ID::ID1, BLOCK_ID::ID6,
    };

    // 初期化
    for(int i = B_ZERO; i < B_SIZE; i++) {
      BLOCK_ID blockId = static_cast<BLOCK_ID>(i);
      bingoArea.getBlockInfo(blockId).setBlock(blockId, initBlockColor[i]);
    }

    // フルビンゴになるまで運搬するブロックを探索し、正しいかを判定する
    DestinationList destinationList(bingoArea);
    BlockSelector blockSelector(bingoArea);
    for(int i = B_ZERO; i < B_SIZE; i++) {
      // 次に運搬するブロックを決定する
      BLOCK_ID targetBlockId = blockSelector.selectBlock();
      CIRCLE_ID targetCircleId = destinationList.getDestination(targetBlockId);
      EXPECT_EQ(expecteds[i], targetBlockId);

      // 運搬されたものとして、ブロックの座標を更新する
      bingoArea.moveBlock(targetCircleId, targetBlockId);
      // 運搬したものとして、走行体の座標と進行方向を更新する
      Coordinate currentCoord
          = bingoArea.getBlockInfo(targetBlockId).getCoordinate();  // 運搬ブロックの座標
      Coordinate targetCoord
          = bingoArea.getBlockCircleInfo(targetCircleId).getCoordinate();  // 運搬先の座標

      int dx = (targetCoord.x - currentCoord.x > 0) ? 1 : -1;
      int dy = (targetCoord.y - currentCoord.y > 0) ? 1 : -1;

      // 座標の更新
      Robot::setCoordinate({ targetCoord.x - dx, targetCoord.y - dy });
      // 進行方向の更新
      Robot::setDirection(static_cast<Direction>((dx + 1) + (1 - dy) * 3));
    }
  }

}  // namespace etrobocon2021_test