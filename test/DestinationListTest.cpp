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
    const int NUMZERO = static_cast<int>(BLOCK_ID::ID0);
    const int NUMSIZE = static_cast<int>(BLOCK_ID::SIZE);

    BingoArea bingoArea;
    // ブロックの初期配置
    COLOR blockColors[8] = { COLOR::RED, COLOR::BLUE, COLOR::YELLOW, COLOR::GREEN,
                             COLOR::RED, COLOR::BLUE, COLOR::YELLOW, COLOR::GREEN };
    int circleNum[NUMSIZE] = { 1, 3, 4, 6, 9, 11, 12, 14 };
    for(int i = NUMZERO; i < NUMSIZE; i++) {
      BLOCK_ID blockId = static_cast<BLOCK_ID>(i);
      bingoArea.getCrossCircleInfo(circleNum[i]).setBlock(blockId, blockColors[i]);
    }
    DestinationList destinationList(bingoArea);

    CIRCLE_ID expected[NUMSIZE]
        = { CIRCLE_ID::ID2, CIRCLE_ID::ID3, CIRCLE_ID::ID0, CIRCLE_ID::ID1,
            CIRCLE_ID::ID6, CIRCLE_ID::ID7, CIRCLE_ID::ID4, CIRCLE_ID::ID5 };

    for(int blockId = NUMZERO; blockId < NUMSIZE; blockId++) {
      BLOCK_ID _blockId = static_cast<BLOCK_ID>(blockId);
      EXPECT_EQ(expected[blockId], destinationList.getDestination(_blockId));
    }
  }

  TEST(getDestinatinoTest, getDestination2)
  {
    const int NUMZERO = static_cast<int>(BLOCK_ID::ID0);
    const int NUMSIZE = static_cast<int>(BLOCK_ID::SIZE);

    BingoArea bingoArea;
    // ブロックの初期配置
    COLOR blockColors[8] = { COLOR::RED,   COLOR::YELLOW, COLOR::BLUE, COLOR::YELLOW,
                             COLOR::GREEN, COLOR::BLUE,   COLOR::RED,  COLOR::GREEN };
    int circleNum[NUMSIZE] = { 1, 3, 4, 6, 9, 11, 12, 14 };
    for(int i = NUMZERO; i < NUMSIZE; i++) {
      BLOCK_ID blockId = static_cast<BLOCK_ID>(i);
      bingoArea.getCrossCircleInfo(circleNum[i]).setBlock(blockId, blockColors[i]);
    }
    DestinationList destinationList(bingoArea);

    CIRCLE_ID expected[NUMSIZE]
        = { CIRCLE_ID::ID2, CIRCLE_ID::ID4, CIRCLE_ID::ID3, CIRCLE_ID::ID0,
            CIRCLE_ID::ID5, CIRCLE_ID::ID7, CIRCLE_ID::ID6, CIRCLE_ID::ID1 };

    for(int blockId = NUMZERO; blockId < NUMSIZE; blockId++) {
      BLOCK_ID _blockId = static_cast<BLOCK_ID>(blockId);
      EXPECT_EQ(expected[blockId], destinationList.getDestination(_blockId));
    }
  }

  TEST(getDestinatinoTest, getDestination3)
  {
    const int NUMZERO = static_cast<int>(BLOCK_ID::ID0);
    const int NUMSIZE = static_cast<int>(BLOCK_ID::SIZE);

    BingoArea bingoArea;
    // ブロックの初期配置
    COLOR blockColors[8] = { COLOR::GREEN,  COLOR::BLUE, COLOR::RED,   COLOR::BLUE,
                             COLOR::YELLOW, COLOR::RED,  COLOR::GREEN, COLOR::YELLOW };
    int circleNum[NUMSIZE] = { 1, 3, 4, 6, 9, 11, 12, 14 };
    for(int i = NUMZERO; i < NUMSIZE; i++) {
      BLOCK_ID blockId = static_cast<BLOCK_ID>(i);
      bingoArea.getCrossCircleInfo(circleNum[i]).setBlock(blockId, blockColors[i]);
    }
    DestinationList destinationList(bingoArea);

    CIRCLE_ID expected[NUMSIZE]
        = { CIRCLE_ID::ID1, CIRCLE_ID::ID7, CIRCLE_ID::ID6, CIRCLE_ID::ID3,
            CIRCLE_ID::ID0, CIRCLE_ID::ID2, CIRCLE_ID::ID5, CIRCLE_ID::ID4 };

    for(int i = NUMZERO; i < NUMSIZE; i++) {
      BLOCK_ID blockId = static_cast<BLOCK_ID>(i);
      EXPECT_EQ(expected[i], destinationList.getDestination(blockId));
    }
  }

  TEST(getDestinatinoTest, getDestination4)
  {
    const int NUMZERO = static_cast<int>(BLOCK_ID::ID0);
    const int NUMSIZE = static_cast<int>(BLOCK_ID::SIZE);

    BingoArea bingoArea;
    // ブロックの初期配置
    COLOR blockColors[8] = { COLOR::YELLOW, COLOR::GREEN, COLOR::RED,  COLOR::GREEN,
                             COLOR::BLUE,   COLOR::RED,   COLOR::BLUE, COLOR::YELLOW };
    int circleNum[NUMSIZE] = { 1, 3, 4, 6, 9, 11, 12, 14 };
    for(int i = NUMZERO; i < NUMSIZE; i++) {
      BLOCK_ID blockId = static_cast<BLOCK_ID>(i);
      bingoArea.getCrossCircleInfo(circleNum[i]).setBlock(blockId, blockColors[i]);
    }
    DestinationList destinationList(bingoArea);

    CIRCLE_ID expected[NUMSIZE]
        = { CIRCLE_ID::ID0, CIRCLE_ID::ID1, CIRCLE_ID::ID6, CIRCLE_ID::ID5,
            CIRCLE_ID::ID7, CIRCLE_ID::ID2, CIRCLE_ID::ID3, CIRCLE_ID::ID4 };

    for(int i = NUMZERO; i < NUMSIZE; i++) {
      BLOCK_ID blockId = static_cast<BLOCK_ID>(i);
      EXPECT_EQ(expected[i], destinationList.getDestination(blockId));
    }
  }

  TEST(getDestinatinoTest, getDestination5)
  {
    const int NUMZERO = static_cast<int>(BLOCK_ID::ID0);
    const int NUMSIZE = static_cast<int>(BLOCK_ID::SIZE);

    BingoArea bingoArea;
    // ブロックの初期配置
    COLOR blockColors[8] = { COLOR::GREEN, COLOR::GREEN, COLOR::YELLOW, COLOR::RED,
                             COLOR::BLUE,  COLOR::RED,   COLOR::YELLOW, COLOR::BLUE };
    int circleNum[NUMSIZE] = { 1, 3, 4, 6, 9, 11, 12, 14 };
    for(int i = NUMZERO; i < NUMSIZE; i++) {
      BLOCK_ID blockId = static_cast<BLOCK_ID>(i);
      bingoArea.getCrossCircleInfo(circleNum[i]).setBlock(blockId, blockColors[i]);
    }
    DestinationList destinationList(bingoArea);

    CIRCLE_ID expected[NUMSIZE]
        = { CIRCLE_ID::ID5, CIRCLE_ID::ID1, CIRCLE_ID::ID0, CIRCLE_ID::ID2,
            CIRCLE_ID::ID3, CIRCLE_ID::ID6, CIRCLE_ID::ID4, CIRCLE_ID::ID7 };

    for(int blockId = NUMZERO; blockId < NUMSIZE; blockId++) {
      BLOCK_ID _blockId = static_cast<BLOCK_ID>(blockId);
      EXPECT_EQ(expected[blockId], destinationList.getDestination(_blockId));
    }
  }
}  // namespace etrobocon2021_test