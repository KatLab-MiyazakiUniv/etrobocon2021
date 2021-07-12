/**
 * @file DestinationListTest.cpp
 * @brief DestinationListクラスをテストする
 * @author hiroto0927, miyashita64
 */

#include "DestinationList.h"
#include <gtest/gtest.h>

namespace etrobocon2021_test {

  TEST(getDestinatinoTest, getDestination1)
  {
    const int B_ZERO = static_cast<int>(BLOCK_ID::ID0);
    const int B_SIZE = static_cast<int>(BLOCK_ID::SIZE);

    // ブロックの初期配置
    COLOR blockColors[8] = { COLOR::RED, COLOR::BLUE, COLOR::YELLOW, COLOR::GREEN,
                             COLOR::RED, COLOR::BLUE, COLOR::YELLOW, COLOR::GREEN };

    // BingoAreaの初期化
    BingoArea bingoArea;
    bingoArea.initBingoArea();
    for(int i = B_ZERO; i < B_SIZE; i++) {
      BLOCK_ID blockId = static_cast<BLOCK_ID>(i);
      bingoArea.getBlockInfo(blockId).setBlock(blockId, blockColors[i]);
    }
    // 運搬先決定
    DestinationList destinationList(bingoArea);

    // 手計算で求めた運搬先
    CIRCLE_ID expected[B_SIZE] = { CIRCLE_ID::ID2, CIRCLE_ID::ID3, CIRCLE_ID::ID0, CIRCLE_ID::ID1,
                                   CIRCLE_ID::ID6, CIRCLE_ID::ID7, CIRCLE_ID::ID4, CIRCLE_ID::ID5 };

    // 正誤判定
    for(int i = B_ZERO; i < B_SIZE; i++) {
      BLOCK_ID blockId = static_cast<BLOCK_ID>(i);
      EXPECT_EQ(expected[i], destinationList.getDestination(blockId));
    }
  }

  TEST(getDestinatinoTest, getDestination2)
  {
    const int B_ZERO = static_cast<int>(BLOCK_ID::ID0);
    const int B_SIZE = static_cast<int>(BLOCK_ID::SIZE);

    // ブロックの初期配置
    COLOR blockColors[8] = { COLOR::RED,   COLOR::YELLOW, COLOR::BLUE, COLOR::YELLOW,
                             COLOR::GREEN, COLOR::BLUE,   COLOR::RED,  COLOR::GREEN };

    // BingoAreaの初期化
    BingoArea bingoArea;
    bingoArea.initBingoArea();
    for(int i = B_ZERO; i < B_SIZE; i++) {
      BLOCK_ID blockId = static_cast<BLOCK_ID>(i);
      bingoArea.getBlockInfo(blockId).setBlock(blockId, blockColors[i]);
    }
    // 運搬先決定
    DestinationList destinationList(bingoArea);

    // 手計算で求めた運搬先
    CIRCLE_ID expected[B_SIZE] = { CIRCLE_ID::ID2, CIRCLE_ID::ID4, CIRCLE_ID::ID3, CIRCLE_ID::ID0,
                                   CIRCLE_ID::ID5, CIRCLE_ID::ID7, CIRCLE_ID::ID6, CIRCLE_ID::ID1 };

    // 正誤判定
    for(int i = B_ZERO; i < B_SIZE; i++) {
      BLOCK_ID blockId = static_cast<BLOCK_ID>(i);
      EXPECT_EQ(expected[i], destinationList.getDestination(blockId));
    }
  }

  TEST(getDestinatinoTest, getDestination3)
  {
    const int B_ZERO = static_cast<int>(BLOCK_ID::ID0);
    const int B_SIZE = static_cast<int>(BLOCK_ID::SIZE);

    // ブロックの初期配置
    COLOR blockColors[8] = { COLOR::GREEN,  COLOR::BLUE, COLOR::RED,   COLOR::BLUE,
                             COLOR::YELLOW, COLOR::RED,  COLOR::GREEN, COLOR::YELLOW };

    // BingoAreaの初期化
    BingoArea bingoArea;
    bingoArea.initBingoArea();
    for(int i = B_ZERO; i < B_SIZE; i++) {
      BLOCK_ID blockId = static_cast<BLOCK_ID>(i);
      bingoArea.getBlockInfo(blockId).setBlock(blockId, blockColors[i]);
    }
    // 運搬先決定
    DestinationList destinationList(bingoArea);

    // 正誤判定// 手計算で求めた運搬先
    CIRCLE_ID expected[B_SIZE] = { CIRCLE_ID::ID1, CIRCLE_ID::ID7, CIRCLE_ID::ID6, CIRCLE_ID::ID3,
                                   CIRCLE_ID::ID0, CIRCLE_ID::ID2, CIRCLE_ID::ID5, CIRCLE_ID::ID4 };

    // 正誤判定
    for(int i = B_ZERO; i < B_SIZE; i++) {
      BLOCK_ID blockId = static_cast<BLOCK_ID>(i);
      EXPECT_EQ(expected[i], destinationList.getDestination(blockId));
    }
  }

  TEST(getDestinatinoTest, getDestination4)
  {
    const int B_ZERO = static_cast<int>(BLOCK_ID::ID0);
    const int B_SIZE = static_cast<int>(BLOCK_ID::SIZE);

    // ブロックの初期配置
    COLOR blockColors[8] = { COLOR::YELLOW, COLOR::GREEN, COLOR::RED,  COLOR::GREEN,
                             COLOR::BLUE,   COLOR::RED,   COLOR::BLUE, COLOR::YELLOW };

    // BingoAreaの初期化
    BingoArea bingoArea;
    bingoArea.initBingoArea();
    for(int i = B_ZERO; i < B_SIZE; i++) {
      BLOCK_ID blockId = static_cast<BLOCK_ID>(i);
      bingoArea.getBlockInfo(blockId).setBlock(blockId, blockColors[i]);
    }
    // 運搬先決定
    DestinationList destinationList(bingoArea);

    // 手計算で求めた運搬先
    CIRCLE_ID expected[B_SIZE] = { CIRCLE_ID::ID0, CIRCLE_ID::ID1, CIRCLE_ID::ID6, CIRCLE_ID::ID5,
                                   CIRCLE_ID::ID7, CIRCLE_ID::ID2, CIRCLE_ID::ID3, CIRCLE_ID::ID4 };

    // 正誤判定
    for(int i = B_ZERO; i < B_SIZE; i++) {
      BLOCK_ID blockId = static_cast<BLOCK_ID>(i);
      EXPECT_EQ(expected[i], destinationList.getDestination(blockId));
    }
  }

  TEST(getDestinatinoTest, getDestination5)
  {
    const int B_ZERO = static_cast<int>(BLOCK_ID::ID0);
    const int B_SIZE = static_cast<int>(BLOCK_ID::SIZE);

    // ブロックの初期配置
    COLOR blockColors[8] = { COLOR::GREEN, COLOR::GREEN, COLOR::YELLOW, COLOR::RED,
                             COLOR::BLUE,  COLOR::RED,   COLOR::YELLOW, COLOR::BLUE };

    // BingoAreaの初期化
    BingoArea bingoArea;
    bingoArea.initBingoArea();
    for(int i = B_ZERO; i < B_SIZE; i++) {
      BLOCK_ID blockId = static_cast<BLOCK_ID>(i);
      bingoArea.getBlockInfo(blockId).setBlock(blockId, blockColors[i]);
    }
    // 運搬先決定
    DestinationList destinationList(bingoArea);

    // 手計算で求めた運搬先
    CIRCLE_ID expected[B_SIZE] = { CIRCLE_ID::ID5, CIRCLE_ID::ID1, CIRCLE_ID::ID0, CIRCLE_ID::ID2,
                                   CIRCLE_ID::ID3, CIRCLE_ID::ID6, CIRCLE_ID::ID4, CIRCLE_ID::ID7 };

    // 正誤判定
    for(int i = B_ZERO; i < B_SIZE; i++) {
      BLOCK_ID blockId = static_cast<BLOCK_ID>(i);
      EXPECT_EQ(expected[i], destinationList.getDestination(blockId));
    }
  }
}  // namespace etrobocon2021_test