/**
 * @file BingoAreaTest.cpp
 * @brief ビンゴエリアクラスのテスト
 * @author Hisataka-Hagiyama,uchyam
 */

#include "BingoArea.h"
#include <gtest/gtest.h>

namespace etrobocon2021_test {
  TEST(getBlockInfo, getBlockInfo_ID0)
  {
    BingoArea bingoArea;
    bingoArea.initBingoArea();
    int expected_id_coordinate_x = 0;
    int expected_id_coordinate_y = 2;
    int actual_id_coordinate_x = bingoArea.getBlockInfo(BLOCK_ID::ID0).getCoordinate().x;
    int actual_id_coordinate_y = bingoArea.getBlockInfo(BLOCK_ID::ID0).getCoordinate().y;
    COLOR expected_Color = COLOR::YELLOW;
    COLOR actualColor = bingoArea.getBlockInfo(BLOCK_ID::ID0).getBlock().blockColor;
    EXPECT_EQ(expected_id_coordinate_x, actual_id_coordinate_x);
    EXPECT_EQ(expected_id_coordinate_y, actual_id_coordinate_y);
    EXPECT_EQ(expected_Color, actualColor);
  }

  TEST(getBlockInfo, getBlockInfo_ID1)
  {
    BingoArea bingoArea;
    bingoArea.initBingoArea();
    int expected_id_coordinate_x = 0;
    int expected_id_coordinate_y = 6;
    int actual_id_coordinate_x = bingoArea.getBlockInfo(BLOCK_ID::ID1).getCoordinate().x;
    int actual_id_coordinate_y = bingoArea.getBlockInfo(BLOCK_ID::ID1).getCoordinate().y;
    COLOR expected_Color = COLOR::BLUE;
    COLOR actualColor = bingoArea.getBlockInfo(BLOCK_ID::ID1).getBlock().blockColor;
    EXPECT_EQ(expected_id_coordinate_x, actual_id_coordinate_x);
    EXPECT_EQ(expected_id_coordinate_y, actual_id_coordinate_y);
    EXPECT_EQ(expected_Color, actualColor);
  }

  TEST(getBlockInfo, getBlockInfo_ID2)
  {
    BingoArea bingoArea;
    bingoArea.initBingoArea();
    int expected_id_coordinate_x = 2;
    int expected_id_coordinate_y = 0;
    int actual_id_coordinate_x = bingoArea.getBlockInfo(BLOCK_ID::ID2).getCoordinate().x;
    int actual_id_coordinate_y = bingoArea.getBlockInfo(BLOCK_ID::ID2).getCoordinate().y;
    COLOR expected_Color = COLOR::RED;
    COLOR actualColor = bingoArea.getBlockInfo(BLOCK_ID::ID2).getBlock().blockColor;
    EXPECT_EQ(expected_id_coordinate_x, actual_id_coordinate_x);
    EXPECT_EQ(expected_id_coordinate_y, actual_id_coordinate_y);
    EXPECT_EQ(expected_Color, actualColor);
  }

  TEST(getBlockInfo, getBlockInfo_ID3)
  {
    BingoArea bingoArea;
    bingoArea.initBingoArea();
    int expected_id_coordinate_x = 2;
    int expected_id_coordinate_y = 4;
    int actual_id_coordinate_x = bingoArea.getBlockInfo(BLOCK_ID::ID3).getCoordinate().x;
    int actual_id_coordinate_y = bingoArea.getBlockInfo(BLOCK_ID::ID3).getCoordinate().y;
    COLOR expected_Color = COLOR::GREEN;
    COLOR actualColor = bingoArea.getBlockInfo(BLOCK_ID::ID3).getBlock().blockColor;
    EXPECT_EQ(expected_id_coordinate_x, actual_id_coordinate_x);
    EXPECT_EQ(expected_id_coordinate_y, actual_id_coordinate_y);
    EXPECT_EQ(expected_Color, actualColor);
  }

  TEST(getBlockInfo, getBlockInfo_ID4)
  {
    BingoArea bingoArea;
    bingoArea.initBingoArea();
    int expected_id_coordinate_x = 4;
    int expected_id_coordinate_y = 2;
    int actual_id_coordinate_x = bingoArea.getBlockInfo(BLOCK_ID::ID4).getCoordinate().x;
    int actual_id_coordinate_y = bingoArea.getBlockInfo(BLOCK_ID::ID4).getCoordinate().y;
    COLOR expected_Color = COLOR::YELLOW;
    COLOR actualColor = bingoArea.getBlockInfo(BLOCK_ID::ID4).getBlock().blockColor;
    EXPECT_EQ(expected_id_coordinate_x, actual_id_coordinate_x);
    EXPECT_EQ(expected_id_coordinate_y, actual_id_coordinate_y);
    EXPECT_EQ(expected_Color, actualColor);
  }

  TEST(getBlockInfo, getBlockInfo_ID5)
  {
    BingoArea bingoArea;
    bingoArea.initBingoArea();
    int expected_id_coordinate_x = 4;
    int expected_id_coordinate_y = 6;
    int actual_id_coordinate_x = bingoArea.getBlockInfo(BLOCK_ID::ID5).getCoordinate().x;
    int actual_id_coordinate_y = bingoArea.getBlockInfo(BLOCK_ID::ID5).getCoordinate().y;
    COLOR expected_Color = COLOR::RED;
    COLOR actualColor = bingoArea.getBlockInfo(BLOCK_ID::ID5).getBlock().blockColor;
    EXPECT_EQ(expected_id_coordinate_x, actual_id_coordinate_x);
    EXPECT_EQ(expected_id_coordinate_y, actual_id_coordinate_y);
    EXPECT_EQ(expected_Color, actualColor);
  }

  TEST(getBlockInfo, getBlockInfo_ID6)
  {
    BingoArea bingoArea;
    bingoArea.initBingoArea();
    int expected_id_coordinate_x = 6;
    int expected_id_coordinate_y = 0;
    int actual_id_coordinate_x = bingoArea.getBlockInfo(BLOCK_ID::ID6).getCoordinate().x;
    int actual_id_coordinate_y = bingoArea.getBlockInfo(BLOCK_ID::ID6).getCoordinate().y;
    COLOR expected_Color = COLOR::GREEN;
    COLOR actualColor = bingoArea.getBlockInfo(BLOCK_ID::ID6).getBlock().blockColor;
    EXPECT_EQ(expected_id_coordinate_x, actual_id_coordinate_x);
    EXPECT_EQ(expected_id_coordinate_y, actual_id_coordinate_y);
    EXPECT_EQ(expected_Color, actualColor);
  }

  TEST(getBlockInfo, getBlockInfo_ID7)
  {
    BingoArea bingoArea;
    bingoArea.initBingoArea();
    int expected_id_coordinate_x = 6;
    int expected_id_coordinate_y = 4;
    int actual_id_coordinate_x = bingoArea.getBlockInfo(BLOCK_ID::ID7).getCoordinate().x;
    int actual_id_coordinate_y = bingoArea.getBlockInfo(BLOCK_ID::ID7).getCoordinate().y;
    COLOR expected_Color = COLOR::BLUE;
    COLOR actualColor = bingoArea.getBlockInfo(BLOCK_ID::ID7).getBlock().blockColor;
    EXPECT_EQ(expected_id_coordinate_x, actual_id_coordinate_x);
    EXPECT_EQ(expected_id_coordinate_y, actual_id_coordinate_y);
    EXPECT_EQ(expected_Color, actualColor);
  }

  TEST(getBlockCircleInfo, getBlockCircleInfo_ID0)
  {
    BingoArea bingoArea;
    bingoArea.initBingoArea();
    int expected_id_coordinate_x = 1;
    int expected_id_coordinate_y = 1;
    int actual_id_coordinate_x = bingoArea.getBlockCircleInfo(CIRCLE_ID::ID0).getCoordinate().x;
    int actual_id_coordinate_y = bingoArea.getBlockCircleInfo(CIRCLE_ID::ID0).getCoordinate().y;
    COLOR expected_BlockColor = COLOR::NONE;
    COLOR actualBlockColor = bingoArea.getBlockCircleInfo(CIRCLE_ID::ID0).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::YELLOW;
    COLOR actualCircleColor = bingoArea.getBlockCircleInfo(CIRCLE_ID::ID0).getCircleColor();
    EXPECT_EQ(expected_id_coordinate_x, actual_id_coordinate_x);
    EXPECT_EQ(expected_id_coordinate_y, actual_id_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
  }

  TEST(getBlockCircleInfo, getBlockCircleInfo_ID1)
  {
    BingoArea bingoArea;
    bingoArea.initBingoArea();
    int expected_id_coordinate_x = 1;
    int expected_id_coordinate_y = 3;
    int actual_id_coordinate_x = bingoArea.getBlockCircleInfo(CIRCLE_ID::ID1).getCoordinate().x;
    int actual_id_coordinate_y = bingoArea.getBlockCircleInfo(CIRCLE_ID::ID1).getCoordinate().y;
    COLOR expected_BlockColor = COLOR::NONE;
    COLOR actualBlockColor = bingoArea.getBlockCircleInfo(CIRCLE_ID::ID1).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::GREEN;
    COLOR actualCircleColor = bingoArea.getBlockCircleInfo(CIRCLE_ID::ID1).getCircleColor();
    EXPECT_EQ(expected_id_coordinate_x, actual_id_coordinate_x);
    EXPECT_EQ(expected_id_coordinate_y, actual_id_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
  }

  TEST(getBlockCircleInfo, getBlockCircleInfo_ID2)
  {
    BingoArea bingoArea;
    bingoArea.initBingoArea();
    int expected_id_coordinate_x = 1;
    int expected_id_coordinate_y = 5;
    int actual_id_coordinate_x = bingoArea.getBlockCircleInfo(CIRCLE_ID::ID2).getCoordinate().x;
    int actual_id_coordinate_y = bingoArea.getBlockCircleInfo(CIRCLE_ID::ID2).getCoordinate().y;
    COLOR expected_BlockColor = COLOR::NONE;
    COLOR actualBlockColor = bingoArea.getBlockCircleInfo(CIRCLE_ID::ID2).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::RED;
    COLOR actualCircleColor = bingoArea.getBlockCircleInfo(CIRCLE_ID::ID2).getCircleColor();
    EXPECT_EQ(expected_id_coordinate_x, actual_id_coordinate_x);
    EXPECT_EQ(expected_id_coordinate_y, actual_id_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
  }
  TEST(getBlockCircleInfo, getBlockCircleInfo_ID3)
  {
    BingoArea bingoArea;
    bingoArea.initBingoArea();
    int expected_id_coordinate_x = 3;
    int expected_id_coordinate_y = 1;
    int actual_id_coordinate_x = bingoArea.getBlockCircleInfo(CIRCLE_ID::ID3).getCoordinate().x;
    int actual_id_coordinate_y = bingoArea.getBlockCircleInfo(CIRCLE_ID::ID3).getCoordinate().y;
    COLOR expected_BlockColor = COLOR::NONE;
    COLOR actualBlockColor = bingoArea.getBlockCircleInfo(CIRCLE_ID::ID3).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::BLUE;
    COLOR actualCircleColor = bingoArea.getBlockCircleInfo(CIRCLE_ID::ID3).getCircleColor();
    EXPECT_EQ(expected_id_coordinate_x, actual_id_coordinate_x);
    EXPECT_EQ(expected_id_coordinate_y, actual_id_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
  }
  TEST(getBlockCircleInfo, getBlockCircleInfo_ID4)
  {
    BingoArea bingoArea;
    bingoArea.initBingoArea();
    int expected_id_coordinate_x = 3;
    int expected_id_coordinate_y = 5;
    int actual_id_coordinate_x = bingoArea.getBlockCircleInfo(CIRCLE_ID::ID4).getCoordinate().x;
    int actual_id_coordinate_y = bingoArea.getBlockCircleInfo(CIRCLE_ID::ID4).getCoordinate().y;
    COLOR expected_BlockColor = COLOR::NONE;
    COLOR actualBlockColor = bingoArea.getBlockCircleInfo(CIRCLE_ID::ID4).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::YELLOW;
    COLOR actualCircleColor = bingoArea.getBlockCircleInfo(CIRCLE_ID::ID4).getCircleColor();
    EXPECT_EQ(expected_id_coordinate_x, actual_id_coordinate_x);
    EXPECT_EQ(expected_id_coordinate_y, actual_id_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
  }
  TEST(getBlockCircleInfo, getBlockCircleInfo_ID5)
  {
    BingoArea bingoArea;
    bingoArea.initBingoArea();
    int expected_id_coordinate_x = 5;
    int expected_id_coordinate_y = 1;
    int actual_id_coordinate_x = bingoArea.getBlockCircleInfo(CIRCLE_ID::ID5).getCoordinate().x;
    int actual_id_coordinate_y = bingoArea.getBlockCircleInfo(CIRCLE_ID::ID5).getCoordinate().y;
    COLOR expected_BlockColor = COLOR::NONE;
    COLOR actualBlockColor = bingoArea.getBlockCircleInfo(CIRCLE_ID::ID5).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::GREEN;
    COLOR actualCircleColor = bingoArea.getBlockCircleInfo(CIRCLE_ID::ID5).getCircleColor();
    EXPECT_EQ(expected_id_coordinate_x, actual_id_coordinate_x);
    EXPECT_EQ(expected_id_coordinate_y, actual_id_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
  }
  TEST(getBlockCircleInfo, getBlockCircleInfo_ID6)
  {
    BingoArea bingoArea;
    bingoArea.initBingoArea();
    int expected_id_coordinate_x = 5;
    int expected_id_coordinate_y = 3;
    int actual_id_coordinate_x = bingoArea.getBlockCircleInfo(CIRCLE_ID::ID6).getCoordinate().x;
    int actual_id_coordinate_y = bingoArea.getBlockCircleInfo(CIRCLE_ID::ID6).getCoordinate().y;
    COLOR expected_BlockColor = COLOR::NONE;
    COLOR actualBlockColor = bingoArea.getBlockCircleInfo(CIRCLE_ID::ID6).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::RED;
    COLOR actualCircleColor = bingoArea.getBlockCircleInfo(CIRCLE_ID::ID6).getCircleColor();
    EXPECT_EQ(expected_id_coordinate_x, actual_id_coordinate_x);
    EXPECT_EQ(expected_id_coordinate_y, actual_id_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
  }
  TEST(getBlockCircleInfo, getBlockCircleInfo_ID7)
  {
    BingoArea bingoArea;
    bingoArea.initBingoArea();
    int expected_id_coordinate_x = 5;
    int expected_id_coordinate_y = 5;
    int actual_id_coordinate_x = bingoArea.getBlockCircleInfo(CIRCLE_ID::ID7).getCoordinate().x;
    int actual_id_coordinate_y = bingoArea.getBlockCircleInfo(CIRCLE_ID::ID7).getCoordinate().y;
    COLOR expected_BlockColor = COLOR::NONE;
    COLOR actualBlockColor = bingoArea.getBlockCircleInfo(CIRCLE_ID::ID7).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::BLUE;
    COLOR actualCircleColor = bingoArea.getBlockCircleInfo(CIRCLE_ID::ID7).getCircleColor();
    EXPECT_EQ(expected_id_coordinate_x, actual_id_coordinate_x);
    EXPECT_EQ(expected_id_coordinate_y, actual_id_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
  }

  TEST(getCrossCircleInfo, getCrossCircleInfo_index0)
  {
    BingoArea bingoArea;
    bingoArea.initBingoArea();
    int expected_coordinate_x = 0;
    int expected_coordinate_y = 0;
    int actual_coordinate_x = bingoArea.getCrossCircleInfo(0).getCoordinate().x;
    int actual_coordinate_y = bingoArea.getCrossCircleInfo(0).getCoordinate().y;
    int expected_edgeNumber = 2;
    int actual_edgeNumber = bingoArea.getCrossCircleInfo(0).getEdgeNumber();
    COLOR expected_BlockColor = COLOR::NONE;
    COLOR actualBlockColor = bingoArea.getCrossCircleInfo(0).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::RED;
    COLOR actualCircleColor = bingoArea.getCrossCircleInfo(0).getCircleColor();
    EXPECT_EQ(expected_coordinate_x, actual_coordinate_x);
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    EXPECT_EQ(expected_edgeNumber, actual_edgeNumber);
  }

  TEST(getCrossCircleInfo, getCrossCircleInfo_index1)
  {
    BingoArea bingoArea;
    bingoArea.initBingoArea();
    int expected_coordinate_x = 0;
    int expected_coordinate_y = 2;
    int actual_coordinate_x = bingoArea.getCrossCircleInfo(1).getCoordinate().x;
    int actual_coordinate_y = bingoArea.getCrossCircleInfo(1).getCoordinate().y;
    int expected_edgeNumber = 3;
    int actual_edgeNumber = bingoArea.getCrossCircleInfo(1).getEdgeNumber();
    COLOR expected_BlockColor = COLOR::YELLOW;
    COLOR actualBlockColor = bingoArea.getCrossCircleInfo(1).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::RED;
    COLOR actualCircleColor = bingoArea.getCrossCircleInfo(1).getCircleColor();
    EXPECT_EQ(expected_coordinate_x, actual_coordinate_x);
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    EXPECT_EQ(expected_edgeNumber, actual_edgeNumber);
  }

  TEST(getCrossCircleInfo, getCrossCircleInfo_index2)
  {
    BingoArea bingoArea;
    bingoArea.initBingoArea();
    int expected_coordinate_x = 0;
    int expected_coordinate_y = 4;
    int actual_coordinate_x = bingoArea.getCrossCircleInfo(2).getCoordinate().x;
    int actual_coordinate_y = bingoArea.getCrossCircleInfo(2).getCoordinate().y;
    int expected_edgeNumber = 3;
    int actual_edgeNumber = bingoArea.getCrossCircleInfo(2).getEdgeNumber();
    COLOR expected_BlockColor = COLOR::NONE;
    COLOR actualBlockColor = bingoArea.getCrossCircleInfo(2).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::BLUE;
    COLOR actualCircleColor = bingoArea.getCrossCircleInfo(2).getCircleColor();
    EXPECT_EQ(expected_coordinate_x, actual_coordinate_x);
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    EXPECT_EQ(expected_edgeNumber, actual_edgeNumber);
  }

  TEST(getCrossCircleInfo, getCrossCircleInfo_index3)
  {
    BingoArea bingoArea;
    bingoArea.initBingoArea();
    int expected_coordinate_x = 0;
    int expected_coordinate_y = 6;
    int actual_coordinate_x = bingoArea.getCrossCircleInfo(3).getCoordinate().x;
    int actual_coordinate_y = bingoArea.getCrossCircleInfo(3).getCoordinate().y;
    int expected_edgeNumber = 2;
    int actual_edgeNumber = bingoArea.getCrossCircleInfo(3).getEdgeNumber();
    COLOR expected_BlockColor = COLOR::BLUE;
    COLOR actualBlockColor = bingoArea.getCrossCircleInfo(3).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::BLUE;
    COLOR actualCircleColor = bingoArea.getCrossCircleInfo(3).getCircleColor();
    EXPECT_EQ(expected_coordinate_x, actual_coordinate_x);
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    EXPECT_EQ(expected_edgeNumber, actual_edgeNumber);
  }

  TEST(getCrossCircleInfo, getCrossCircleInfo_index4)
  {
    BingoArea bingoArea;
    bingoArea.initBingoArea();
    int expected_coordinate_x = 2;
    int expected_coordinate_y = 0;
    int actual_coordinate_x = bingoArea.getCrossCircleInfo(4).getCoordinate().x;
    int actual_coordinate_y = bingoArea.getCrossCircleInfo(4).getCoordinate().y;
    int expected_edgeNumber = 3;
    int actual_edgeNumber = bingoArea.getCrossCircleInfo(4).getEdgeNumber();
    COLOR expected_BlockColor = COLOR::RED;
    COLOR actualBlockColor = bingoArea.getCrossCircleInfo(4).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::RED;
    COLOR actualCircleColor = bingoArea.getCrossCircleInfo(4).getCircleColor();
    EXPECT_EQ(expected_coordinate_x, actual_coordinate_x);
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    EXPECT_EQ(expected_edgeNumber, actual_edgeNumber);
  }

  TEST(getCrossCircleInfo, getCrossCircleInfo_index5)
  {
    BingoArea bingoArea;
    bingoArea.initBingoArea();
    int expected_coordinate_x = 2;
    int expected_coordinate_y = 2;
    int actual_coordinate_x = bingoArea.getCrossCircleInfo(5).getCoordinate().x;
    int actual_coordinate_y = bingoArea.getCrossCircleInfo(5).getCoordinate().y;
    int expected_edgeNumber = 4;
    int actual_edgeNumber = bingoArea.getCrossCircleInfo(5).getEdgeNumber();
    COLOR expected_BlockColor = COLOR::NONE;
    COLOR actualBlockColor = bingoArea.getCrossCircleInfo(5).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::RED;
    COLOR actualCircleColor = bingoArea.getCrossCircleInfo(5).getCircleColor();
    EXPECT_EQ(expected_coordinate_x, actual_coordinate_x);
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    EXPECT_EQ(expected_edgeNumber, actual_edgeNumber);
  }

  TEST(getCrossCircleInfo, getCrossCircleInfo_index6)
  {
    BingoArea bingoArea;
    bingoArea.initBingoArea();
    int expected_coordinate_x = 2;
    int expected_coordinate_y = 4;
    int actual_coordinate_x = bingoArea.getCrossCircleInfo(6).getCoordinate().x;
    int actual_coordinate_y = bingoArea.getCrossCircleInfo(6).getCoordinate().y;
    int expected_edgeNumber = 4;
    int actual_edgeNumber = bingoArea.getCrossCircleInfo(6).getEdgeNumber();
    COLOR expected_BlockColor = COLOR::GREEN;
    COLOR actualBlockColor = bingoArea.getCrossCircleInfo(6).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::BLUE;
    COLOR actualCircleColor = bingoArea.getCrossCircleInfo(6).getCircleColor();
    EXPECT_EQ(expected_coordinate_x, actual_coordinate_x);
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    EXPECT_EQ(expected_edgeNumber, actual_edgeNumber);
  }

  TEST(getCrossCircleInfo, getCrossCircleInfo_index7)
  {
    BingoArea bingoArea;
    bingoArea.initBingoArea();
    int expected_coordinate_x = 2;
    int expected_coordinate_y = 6;
    int actual_coordinate_x = bingoArea.getCrossCircleInfo(7).getCoordinate().x;
    int actual_coordinate_y = bingoArea.getCrossCircleInfo(7).getCoordinate().y;
    int expected_edgeNumber = 3;
    int actual_edgeNumber = bingoArea.getCrossCircleInfo(7).getEdgeNumber();
    COLOR expected_BlockColor = COLOR::NONE;
    COLOR actualBlockColor = bingoArea.getCrossCircleInfo(7).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::BLUE;
    COLOR actualCircleColor = bingoArea.getCrossCircleInfo(7).getCircleColor();
    EXPECT_EQ(expected_coordinate_x, actual_coordinate_x);
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    EXPECT_EQ(expected_edgeNumber, actual_edgeNumber);
  }

  TEST(getCrossCircleInfo, getCrossCircleInfo_index8)
  {
    BingoArea bingoArea;
    bingoArea.initBingoArea();
    int expected_coordinate_x = 4;
    int expected_coordinate_y = 0;
    int actual_coordinate_x = bingoArea.getCrossCircleInfo(8).getCoordinate().x;
    int actual_coordinate_y = bingoArea.getCrossCircleInfo(8).getCoordinate().y;
    int expected_edgeNumber = 3;
    int actual_edgeNumber = bingoArea.getCrossCircleInfo(8).getEdgeNumber();
    COLOR expected_BlockColor = COLOR::NONE;
    COLOR actualBlockColor = bingoArea.getCrossCircleInfo(8).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::YELLOW;
    COLOR actualCircleColor = bingoArea.getCrossCircleInfo(8).getCircleColor();
    EXPECT_EQ(expected_coordinate_x, actual_coordinate_x);
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    EXPECT_EQ(expected_edgeNumber, actual_edgeNumber);
  }

  TEST(getCrossCircleInfo, getCrossCircleInfo_index9)
  {
    BingoArea bingoArea;
    bingoArea.initBingoArea();
    int expected_coordinate_x = 4;
    int expected_coordinate_y = 2;
    int actual_coordinate_x = bingoArea.getCrossCircleInfo(9).getCoordinate().x;
    int actual_coordinate_y = bingoArea.getCrossCircleInfo(9).getCoordinate().y;
    int expected_edgeNumber = 4;
    int actual_edgeNumber = bingoArea.getCrossCircleInfo(9).getEdgeNumber();
    COLOR expected_BlockColor = COLOR::YELLOW;
    COLOR actualBlockColor = bingoArea.getCrossCircleInfo(9).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::YELLOW;
    COLOR actualCircleColor = bingoArea.getCrossCircleInfo(9).getCircleColor();
    EXPECT_EQ(expected_coordinate_x, actual_coordinate_x);
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    EXPECT_EQ(expected_edgeNumber, actual_edgeNumber);
  }

  TEST(getCrossCircleInfo, getCrossCircleInfo_index10)
  {
    BingoArea bingoArea;
    bingoArea.initBingoArea();
    int expected_coordinate_x = 4;
    int expected_coordinate_y = 4;
    int actual_coordinate_x = bingoArea.getCrossCircleInfo(10).getCoordinate().x;
    int actual_coordinate_y = bingoArea.getCrossCircleInfo(10).getCoordinate().y;
    int expected_edgeNumber = 4;
    int actual_edgeNumber = bingoArea.getCrossCircleInfo(10).getEdgeNumber();
    COLOR expected_BlockColor = COLOR::NONE;
    COLOR actualBlockColor = bingoArea.getCrossCircleInfo(10).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::GREEN;
    COLOR actualCircleColor = bingoArea.getCrossCircleInfo(10).getCircleColor();
    EXPECT_EQ(expected_coordinate_x, actual_coordinate_x);
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    EXPECT_EQ(expected_edgeNumber, actual_edgeNumber);
  }

  TEST(getCrossCircleInfo, getCrossCircleInfo_index11)
  {
    BingoArea bingoArea;
    bingoArea.initBingoArea();
    int expected_coordinate_x = 4;
    int expected_coordinate_y = 6;
    int actual_coordinate_x = bingoArea.getCrossCircleInfo(11).getCoordinate().x;
    int actual_coordinate_y = bingoArea.getCrossCircleInfo(11).getCoordinate().y;
    int expected_edgeNumber = 3;
    int actual_edgeNumber = bingoArea.getCrossCircleInfo(11).getEdgeNumber();
    COLOR expected_BlockColor = COLOR::RED;
    COLOR actualBlockColor = bingoArea.getCrossCircleInfo(11).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::GREEN;
    COLOR actualCircleColor = bingoArea.getCrossCircleInfo(11).getCircleColor();
    EXPECT_EQ(expected_coordinate_x, actual_coordinate_x);
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    EXPECT_EQ(expected_edgeNumber, actual_edgeNumber);
  }

  TEST(getCrossCircleInfo, getCrossCircleInfo_index12)
  {
    BingoArea bingoArea;
    bingoArea.initBingoArea();
    int expected_coordinate_x = 6;
    int expected_coordinate_y = 0;
    int actual_coordinate_x = bingoArea.getCrossCircleInfo(12).getCoordinate().x;
    int actual_coordinate_y = bingoArea.getCrossCircleInfo(12).getCoordinate().y;
    int expected_edgeNumber = 2;
    int actual_edgeNumber = bingoArea.getCrossCircleInfo(12).getEdgeNumber();
    COLOR expected_BlockColor = COLOR::GREEN;
    COLOR actualBlockColor = bingoArea.getCrossCircleInfo(12).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::YELLOW;
    COLOR actualCircleColor = bingoArea.getCrossCircleInfo(12).getCircleColor();
    EXPECT_EQ(expected_coordinate_x, actual_coordinate_x);
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    EXPECT_EQ(expected_edgeNumber, actual_edgeNumber);
  }

  TEST(getCrossCircleInfo, getCrossCircleInfo_index13)
  {
    BingoArea bingoArea;
    bingoArea.initBingoArea();
    int expected_coordinate_x = 6;
    int expected_coordinate_y = 2;
    int actual_coordinate_x = bingoArea.getCrossCircleInfo(13).getCoordinate().x;
    int actual_coordinate_y = bingoArea.getCrossCircleInfo(13).getCoordinate().y;
    int expected_edgeNumber = 3;
    int actual_edgeNumber = bingoArea.getCrossCircleInfo(13).getEdgeNumber();
    COLOR expected_BlockColor = COLOR::NONE;
    COLOR actualBlockColor = bingoArea.getCrossCircleInfo(13).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::YELLOW;
    COLOR actualCircleColor = bingoArea.getCrossCircleInfo(13).getCircleColor();
    EXPECT_EQ(expected_coordinate_x, actual_coordinate_x);
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    EXPECT_EQ(expected_edgeNumber, actual_edgeNumber);
  }

  TEST(getCrossCircleInfo, getCrossCircleInfo_index14)
  {
    BingoArea bingoArea;
    bingoArea.initBingoArea();
    int expected_coordinate_x = 6;
    int expected_coordinate_y = 4;
    int actual_coordinate_x = bingoArea.getCrossCircleInfo(14).getCoordinate().x;
    int actual_coordinate_y = bingoArea.getCrossCircleInfo(14).getCoordinate().y;
    int expected_edgeNumber = 3;
    int actual_edgeNumber = bingoArea.getCrossCircleInfo(14).getEdgeNumber();
    COLOR expected_BlockColor = COLOR::BLUE;
    COLOR actualBlockColor = bingoArea.getCrossCircleInfo(14).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::GREEN;
    COLOR actualCircleColor = bingoArea.getCrossCircleInfo(14).getCircleColor();
    EXPECT_EQ(expected_coordinate_x, actual_coordinate_x);
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    EXPECT_EQ(expected_edgeNumber, actual_edgeNumber);
  }

  TEST(getCrossCircleInfo, getCrossCircleInfo_index15)
  {
    BingoArea bingoArea;
    bingoArea.initBingoArea();
    int expected_coordinate_x = 6;
    int expected_coordinate_y = 6;
    int actual_coordinate_x = bingoArea.getCrossCircleInfo(15).getCoordinate().x;
    int actual_coordinate_y = bingoArea.getCrossCircleInfo(15).getCoordinate().y;
    int expected_edgeNumber = 2;
    int actual_edgeNumber = bingoArea.getCrossCircleInfo(15).getEdgeNumber();
    COLOR expected_BlockColor = COLOR::NONE;
    COLOR actualBlockColor = bingoArea.getCrossCircleInfo(15).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::GREEN;
    COLOR actualCircleColor = bingoArea.getCrossCircleInfo(15).getCircleColor();
    EXPECT_EQ(expected_coordinate_x, actual_coordinate_x);
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    EXPECT_EQ(expected_edgeNumber, actual_edgeNumber);
  }

  TEST(getCenterMarkInfo, getCenterMarkInfo)
  {
    BingoArea bingoArea;
    bingoArea.initBingoArea();
    int expected_coordinate_x = 3;
    int expected_coordinate_y = 3;
    int actual_coordinate_x = bingoArea.getCenterMarkInfo().getCoordinate().x;
    int actual_coordinate_y = bingoArea.getCenterMarkInfo().getCoordinate().y;
    COLOR expected_BlockColor = COLOR::NONE;
    COLOR actualBlockColor = bingoArea.getCenterMarkInfo().getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::BLACK;
    COLOR actualCircleColor = bingoArea.getCenterMarkInfo().getCircleColor();
    EXPECT_EQ(expected_coordinate_x, actual_coordinate_x);
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
  }

  //ブロックID0のブロックをサークルID0のブロックサークルに移動させる
  TEST(moveBlock, moveBlock_CIRCLEID0_BLOCKID0)
  {
    BingoArea bingoArea;
    bingoArea.initBingoArea();
    bingoArea.moveBlock(CIRCLE_ID::ID0, BLOCK_ID::ID0);
    int expected_coordinate_x = 1;
    int expected_coordinate_y = 1;
    int actual_coordinate_x = bingoArea.getBlockInfo(BLOCK_ID::ID0).getCoordinate().x;
    int actual_coordinate_y = bingoArea.getBlockInfo(BLOCK_ID::ID0).getCoordinate().y;
    COLOR expected_CircleColor = COLOR::YELLOW;
    COLOR actualCircleColor = bingoArea.getBlockInfo(BLOCK_ID::ID0).getCircleColor();
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    BLOCK_ID expected_Id = BLOCK_ID::NONE;
    BLOCK_ID actualId = bingoArea.getCrossCircleInfo(1).getBlock().blockId;
    EXPECT_EQ(expected_Id, actualId);
  }

  //ブロックID5のブロックをサークルID2のブロックサークルに移動させる
  TEST(moveBlock, moveBlock_CIRCLEID2_BLOCKID5)
  {
    BingoArea bingoArea;
    bingoArea.initBingoArea();
    bingoArea.moveBlock(CIRCLE_ID::ID2, BLOCK_ID::ID5);
    int expected_coordinate_x = 1;
    int expected_coordinate_y = 5;
    int actual_coordinate_x = bingoArea.getBlockInfo(BLOCK_ID::ID5).getCoordinate().x;
    int actual_coordinate_y = bingoArea.getBlockInfo(BLOCK_ID::ID5).getCoordinate().y;
    COLOR expected_CircleColor = COLOR::RED;
    COLOR actualCircleColor = bingoArea.getBlockInfo(BLOCK_ID::ID5).getCircleColor();
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    BLOCK_ID expected_Id = BLOCK_ID::NONE;
    BLOCK_ID actualId = bingoArea.getCrossCircleInfo(11).getBlock().blockId;
    EXPECT_EQ(expected_Id, actualId);
  }

}  // namespace etrobocon2021_test