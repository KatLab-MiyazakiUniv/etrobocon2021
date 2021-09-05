/**
 * @file CourseInfoTest.cpp
 * @brief ビンゴエリアクラスのテスト
 * @author Hisataka-Hagiyama,uchyam
 */

#include "CourseInfo.h"
#include <gtest/gtest.h>

namespace etrobocon2021_test {
  TEST(getNode, getNode_ID0)
  {
    const bool IS_LEFT_COURSE = true;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_id_coordinate_x = 2;
    int expected_id_coordinate_y = 0;
    int actual_id_coordinate_x = courseInfo.getNode(BLOCK_ID::ID0).getCoordinate().x;
    int actual_id_coordinate_y = courseInfo.getNode(BLOCK_ID::ID0).getCoordinate().y;
    COLOR expected_Color = COLOR::YELLOW;
    COLOR actualColor = courseInfo.getNode(BLOCK_ID::ID0).getBlock().blockColor;
    EXPECT_EQ(expected_id_coordinate_x, actual_id_coordinate_x);
    EXPECT_EQ(expected_id_coordinate_y, actual_id_coordinate_y);
    EXPECT_EQ(expected_Color, actualColor);
  }

  TEST(getNode, getNode_ID1)
  {
    const bool IS_LEFT_COURSE = true;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_id_coordinate_x = 6;
    int expected_id_coordinate_y = 0;
    int actual_id_coordinate_x = courseInfo.getNode(BLOCK_ID::ID1).getCoordinate().x;
    int actual_id_coordinate_y = courseInfo.getNode(BLOCK_ID::ID1).getCoordinate().y;
    COLOR expected_Color = COLOR::BLUE;
    COLOR actualColor = courseInfo.getNode(BLOCK_ID::ID1).getBlock().blockColor;
    EXPECT_EQ(expected_id_coordinate_x, actual_id_coordinate_x);
    EXPECT_EQ(expected_id_coordinate_y, actual_id_coordinate_y);
    EXPECT_EQ(expected_Color, actualColor);
  }

  TEST(getNode, getNode_ID2)
  {
    const bool IS_LEFT_COURSE = true;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_id_coordinate_x = 0;
    int expected_id_coordinate_y = 2;
    int actual_id_coordinate_x = courseInfo.getNode(BLOCK_ID::ID2).getCoordinate().x;
    int actual_id_coordinate_y = courseInfo.getNode(BLOCK_ID::ID2).getCoordinate().y;
    COLOR expected_Color = COLOR::RED;
    COLOR actualColor = courseInfo.getNode(BLOCK_ID::ID2).getBlock().blockColor;
    EXPECT_EQ(expected_id_coordinate_x, actual_id_coordinate_x);
    EXPECT_EQ(expected_id_coordinate_y, actual_id_coordinate_y);
    EXPECT_EQ(expected_Color, actualColor);
  }

  TEST(getNode, getNode_ID3)
  {
    const bool IS_LEFT_COURSE = true;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_id_coordinate_x = 4;
    int expected_id_coordinate_y = 2;
    int actual_id_coordinate_x = courseInfo.getNode(BLOCK_ID::ID3).getCoordinate().x;
    int actual_id_coordinate_y = courseInfo.getNode(BLOCK_ID::ID3).getCoordinate().y;
    COLOR expected_Color = COLOR::GREEN;
    COLOR actualColor = courseInfo.getNode(BLOCK_ID::ID3).getBlock().blockColor;
    EXPECT_EQ(expected_id_coordinate_x, actual_id_coordinate_x);
    EXPECT_EQ(expected_id_coordinate_y, actual_id_coordinate_y);
    EXPECT_EQ(expected_Color, actualColor);
  }

  TEST(getNode, getNode_ID4)
  {
    const bool IS_LEFT_COURSE = true;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_id_coordinate_x = 2;
    int expected_id_coordinate_y = 4;
    int actual_id_coordinate_x = courseInfo.getNode(BLOCK_ID::ID4).getCoordinate().x;
    int actual_id_coordinate_y = courseInfo.getNode(BLOCK_ID::ID4).getCoordinate().y;
    COLOR expected_Color = COLOR::YELLOW;
    COLOR actualColor = courseInfo.getNode(BLOCK_ID::ID4).getBlock().blockColor;
    EXPECT_EQ(expected_id_coordinate_x, actual_id_coordinate_x);
    EXPECT_EQ(expected_id_coordinate_y, actual_id_coordinate_y);
    EXPECT_EQ(expected_Color, actualColor);
  }

  TEST(getNode, getNode_ID5)
  {
    const bool IS_LEFT_COURSE = true;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_id_coordinate_x = 6;
    int expected_id_coordinate_y = 4;
    int actual_id_coordinate_x = courseInfo.getNode(BLOCK_ID::ID5).getCoordinate().x;
    int actual_id_coordinate_y = courseInfo.getNode(BLOCK_ID::ID5).getCoordinate().y;
    COLOR expected_Color = COLOR::RED;
    COLOR actualColor = courseInfo.getNode(BLOCK_ID::ID5).getBlock().blockColor;
    EXPECT_EQ(expected_id_coordinate_x, actual_id_coordinate_x);
    EXPECT_EQ(expected_id_coordinate_y, actual_id_coordinate_y);
    EXPECT_EQ(expected_Color, actualColor);
  }

  TEST(getNode, getNode_ID6)
  {
    const bool IS_LEFT_COURSE = true;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_id_coordinate_x = 0;
    int expected_id_coordinate_y = 6;
    int actual_id_coordinate_x = courseInfo.getNode(BLOCK_ID::ID6).getCoordinate().x;
    int actual_id_coordinate_y = courseInfo.getNode(BLOCK_ID::ID6).getCoordinate().y;
    COLOR expected_Color = COLOR::GREEN;
    COLOR actualColor = courseInfo.getNode(BLOCK_ID::ID6).getBlock().blockColor;
    EXPECT_EQ(expected_id_coordinate_x, actual_id_coordinate_x);
    EXPECT_EQ(expected_id_coordinate_y, actual_id_coordinate_y);
    EXPECT_EQ(expected_Color, actualColor);
  }

  TEST(getNode, getNode_ID7)
  {
    const bool IS_LEFT_COURSE = true;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_id_coordinate_x = 4;
    int expected_id_coordinate_y = 6;
    int actual_id_coordinate_x = courseInfo.getNode(BLOCK_ID::ID7).getCoordinate().x;
    int actual_id_coordinate_y = courseInfo.getNode(BLOCK_ID::ID7).getCoordinate().y;
    COLOR expected_Color = COLOR::BLUE;
    COLOR actualColor = courseInfo.getNode(BLOCK_ID::ID7).getBlock().blockColor;
    EXPECT_EQ(expected_id_coordinate_x, actual_id_coordinate_x);
    EXPECT_EQ(expected_id_coordinate_y, actual_id_coordinate_y);
    EXPECT_EQ(expected_Color, actualColor);
  }

  TEST(getBlockCircle, getBlockCircle_ID0)
  {
    const bool IS_LEFT_COURSE = true;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_id_coordinate_x = 1;
    int expected_id_coordinate_y = 1;
    int actual_id_coordinate_x = courseInfo.getBlockCircle(CIRCLE_ID::ID0).getCoordinate().x;
    int actual_id_coordinate_y = courseInfo.getBlockCircle(CIRCLE_ID::ID0).getCoordinate().y;
    COLOR expected_BlockColor = COLOR::NONE;
    COLOR actualBlockColor = courseInfo.getBlockCircle(CIRCLE_ID::ID0).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::YELLOW;
    COLOR actualCircleColor = courseInfo.getBlockCircle(CIRCLE_ID::ID0).getCircleColor();
    EXPECT_EQ(expected_id_coordinate_x, actual_id_coordinate_x);
    EXPECT_EQ(expected_id_coordinate_y, actual_id_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
  }

  TEST(getBlockCircle, getBlockCircle_ID1)
  {
    const bool IS_LEFT_COURSE = true;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_id_coordinate_x = 3;
    int expected_id_coordinate_y = 1;
    int actual_id_coordinate_x = courseInfo.getBlockCircle(CIRCLE_ID::ID1).getCoordinate().x;
    int actual_id_coordinate_y = courseInfo.getBlockCircle(CIRCLE_ID::ID1).getCoordinate().y;
    COLOR expected_BlockColor = COLOR::NONE;
    COLOR actualBlockColor = courseInfo.getBlockCircle(CIRCLE_ID::ID1).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::GREEN;
    COLOR actualCircleColor = courseInfo.getBlockCircle(CIRCLE_ID::ID1).getCircleColor();
    EXPECT_EQ(expected_id_coordinate_x, actual_id_coordinate_x);
    EXPECT_EQ(expected_id_coordinate_y, actual_id_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
  }

  TEST(getBlockCircle, getBlockCircle_ID2)
  {
    const bool IS_LEFT_COURSE = true;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_id_coordinate_x = 5;
    int expected_id_coordinate_y = 1;
    int actual_id_coordinate_x = courseInfo.getBlockCircle(CIRCLE_ID::ID2).getCoordinate().x;
    int actual_id_coordinate_y = courseInfo.getBlockCircle(CIRCLE_ID::ID2).getCoordinate().y;
    COLOR expected_BlockColor = COLOR::NONE;
    COLOR actualBlockColor = courseInfo.getBlockCircle(CIRCLE_ID::ID2).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::RED;
    COLOR actualCircleColor = courseInfo.getBlockCircle(CIRCLE_ID::ID2).getCircleColor();
    EXPECT_EQ(expected_id_coordinate_x, actual_id_coordinate_x);
    EXPECT_EQ(expected_id_coordinate_y, actual_id_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
  }
  TEST(getBlockCircle, getBlockCircle_ID3)
  {
    const bool IS_LEFT_COURSE = true;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_id_coordinate_x = 1;
    int expected_id_coordinate_y = 3;
    int actual_id_coordinate_x = courseInfo.getBlockCircle(CIRCLE_ID::ID3).getCoordinate().x;
    int actual_id_coordinate_y = courseInfo.getBlockCircle(CIRCLE_ID::ID3).getCoordinate().y;
    COLOR expected_BlockColor = COLOR::NONE;
    COLOR actualBlockColor = courseInfo.getBlockCircle(CIRCLE_ID::ID3).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::BLUE;
    COLOR actualCircleColor = courseInfo.getBlockCircle(CIRCLE_ID::ID3).getCircleColor();
    EXPECT_EQ(expected_id_coordinate_x, actual_id_coordinate_x);
    EXPECT_EQ(expected_id_coordinate_y, actual_id_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
  }
  TEST(getBlockCircle, getBlockCircle_ID4)
  {
    const bool IS_LEFT_COURSE = true;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_id_coordinate_x = 5;
    int expected_id_coordinate_y = 3;
    int actual_id_coordinate_x = courseInfo.getBlockCircle(CIRCLE_ID::ID4).getCoordinate().x;
    int actual_id_coordinate_y = courseInfo.getBlockCircle(CIRCLE_ID::ID4).getCoordinate().y;
    COLOR expected_BlockColor = COLOR::NONE;
    COLOR actualBlockColor = courseInfo.getBlockCircle(CIRCLE_ID::ID4).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::YELLOW;
    COLOR actualCircleColor = courseInfo.getBlockCircle(CIRCLE_ID::ID4).getCircleColor();
    EXPECT_EQ(expected_id_coordinate_x, actual_id_coordinate_x);
    EXPECT_EQ(expected_id_coordinate_y, actual_id_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
  }
  TEST(getBlockCircle, getBlockCircle_ID5)
  {
    const bool IS_LEFT_COURSE = true;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_id_coordinate_x = 1;
    int expected_id_coordinate_y = 5;
    int actual_id_coordinate_x = courseInfo.getBlockCircle(CIRCLE_ID::ID5).getCoordinate().x;
    int actual_id_coordinate_y = courseInfo.getBlockCircle(CIRCLE_ID::ID5).getCoordinate().y;
    COLOR expected_BlockColor = COLOR::NONE;
    COLOR actualBlockColor = courseInfo.getBlockCircle(CIRCLE_ID::ID5).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::GREEN;
    COLOR actualCircleColor = courseInfo.getBlockCircle(CIRCLE_ID::ID5).getCircleColor();
    EXPECT_EQ(expected_id_coordinate_x, actual_id_coordinate_x);
    EXPECT_EQ(expected_id_coordinate_y, actual_id_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
  }
  TEST(getBlockCircle, getBlockCircle_ID6)
  {
    const bool IS_LEFT_COURSE = true;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_id_coordinate_x = 3;
    int expected_id_coordinate_y = 5;
    int actual_id_coordinate_x = courseInfo.getBlockCircle(CIRCLE_ID::ID6).getCoordinate().x;
    int actual_id_coordinate_y = courseInfo.getBlockCircle(CIRCLE_ID::ID6).getCoordinate().y;
    COLOR expected_BlockColor = COLOR::NONE;
    COLOR actualBlockColor = courseInfo.getBlockCircle(CIRCLE_ID::ID6).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::RED;
    COLOR actualCircleColor = courseInfo.getBlockCircle(CIRCLE_ID::ID6).getCircleColor();
    EXPECT_EQ(expected_id_coordinate_x, actual_id_coordinate_x);
    EXPECT_EQ(expected_id_coordinate_y, actual_id_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
  }
  TEST(getBlockCircle, getBlockCircle_ID7)
  {
    const bool IS_LEFT_COURSE = true;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_id_coordinate_x = 5;
    int expected_id_coordinate_y = 5;
    int actual_id_coordinate_x = courseInfo.getBlockCircle(CIRCLE_ID::ID7).getCoordinate().x;
    int actual_id_coordinate_y = courseInfo.getBlockCircle(CIRCLE_ID::ID7).getCoordinate().y;
    COLOR expected_BlockColor = COLOR::NONE;
    COLOR actualBlockColor = courseInfo.getBlockCircle(CIRCLE_ID::ID7).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::BLUE;
    COLOR actualCircleColor = courseInfo.getBlockCircle(CIRCLE_ID::ID7).getCircleColor();
    EXPECT_EQ(expected_id_coordinate_x, actual_id_coordinate_x);
    EXPECT_EQ(expected_id_coordinate_y, actual_id_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
  }

  TEST(getCrossCircle, getCrossCircle_index0)
  {
    const bool IS_LEFT_COURSE = true;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_coordinate_x = 0;
    int expected_coordinate_y = 0;
    int actual_coordinate_x = courseInfo.getCrossCircle(0).getCoordinate().x;
    int actual_coordinate_y = courseInfo.getCrossCircle(0).getCoordinate().y;
    int expected_edgeNumber = 2;
    int actual_edgeNumber = courseInfo.getCrossCircle(0).getEdgeNumber();
    COLOR expected_BlockColor = COLOR::NONE;
    COLOR actualBlockColor = courseInfo.getCrossCircle(0).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::RED;
    COLOR actualCircleColor = courseInfo.getCrossCircle(0).getCircleColor();
    EXPECT_EQ(expected_coordinate_x, actual_coordinate_x);
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    EXPECT_EQ(expected_edgeNumber, actual_edgeNumber);
  }

  TEST(getCrossCircle, getCrossCircle_index1)
  {
    const bool IS_LEFT_COURSE = true;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_coordinate_x = 2;
    int expected_coordinate_y = 0;
    int actual_coordinate_x = courseInfo.getCrossCircle(1).getCoordinate().x;
    int actual_coordinate_y = courseInfo.getCrossCircle(1).getCoordinate().y;
    int expected_edgeNumber = 3;
    int actual_edgeNumber = courseInfo.getCrossCircle(1).getEdgeNumber();
    COLOR expected_BlockColor = COLOR::YELLOW;
    COLOR actualBlockColor = courseInfo.getCrossCircle(1).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::RED;
    COLOR actualCircleColor = courseInfo.getCrossCircle(1).getCircleColor();
    EXPECT_EQ(expected_coordinate_x, actual_coordinate_x);
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    EXPECT_EQ(expected_edgeNumber, actual_edgeNumber);
  }

  TEST(getCrossCircle, getCrossCircle_index2)
  {
    const bool IS_LEFT_COURSE = true;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_coordinate_x = 4;
    int expected_coordinate_y = 0;
    int actual_coordinate_x = courseInfo.getCrossCircle(2).getCoordinate().x;
    int actual_coordinate_y = courseInfo.getCrossCircle(2).getCoordinate().y;
    int expected_edgeNumber = 3;
    int actual_edgeNumber = courseInfo.getCrossCircle(2).getEdgeNumber();
    COLOR expected_BlockColor = COLOR::NONE;
    COLOR actualBlockColor = courseInfo.getCrossCircle(2).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::BLUE;
    COLOR actualCircleColor = courseInfo.getCrossCircle(2).getCircleColor();
    EXPECT_EQ(expected_coordinate_x, actual_coordinate_x);
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    EXPECT_EQ(expected_edgeNumber, actual_edgeNumber);
  }

  TEST(getCrossCircle, getCrossCircle_index3)
  {
    const bool IS_LEFT_COURSE = true;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_coordinate_x = 6;
    int expected_coordinate_y = 0;
    int actual_coordinate_x = courseInfo.getCrossCircle(3).getCoordinate().x;
    int actual_coordinate_y = courseInfo.getCrossCircle(3).getCoordinate().y;
    int expected_edgeNumber = 2;
    int actual_edgeNumber = courseInfo.getCrossCircle(3).getEdgeNumber();
    COLOR expected_BlockColor = COLOR::BLUE;
    COLOR actualBlockColor = courseInfo.getCrossCircle(3).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::BLUE;
    COLOR actualCircleColor = courseInfo.getCrossCircle(3).getCircleColor();
    EXPECT_EQ(expected_coordinate_x, actual_coordinate_x);
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    EXPECT_EQ(expected_edgeNumber, actual_edgeNumber);
  }

  TEST(getCrossCircle, getCrossCircle_index4)
  {
    const bool IS_LEFT_COURSE = true;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_coordinate_x = 0;
    int expected_coordinate_y = 2;
    int actual_coordinate_x = courseInfo.getCrossCircle(4).getCoordinate().x;
    int actual_coordinate_y = courseInfo.getCrossCircle(4).getCoordinate().y;
    int expected_edgeNumber = 3;
    int actual_edgeNumber = courseInfo.getCrossCircle(4).getEdgeNumber();
    COLOR expected_BlockColor = COLOR::RED;
    COLOR actualBlockColor = courseInfo.getCrossCircle(4).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::RED;
    COLOR actualCircleColor = courseInfo.getCrossCircle(4).getCircleColor();
    EXPECT_EQ(expected_coordinate_x, actual_coordinate_x);
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    EXPECT_EQ(expected_edgeNumber, actual_edgeNumber);
  }

  TEST(getCrossCircle, getCrossCircle_index5)
  {
    const bool IS_LEFT_COURSE = true;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_coordinate_x = 2;
    int expected_coordinate_y = 2;
    int actual_coordinate_x = courseInfo.getCrossCircle(5).getCoordinate().x;
    int actual_coordinate_y = courseInfo.getCrossCircle(5).getCoordinate().y;
    int expected_edgeNumber = 4;
    int actual_edgeNumber = courseInfo.getCrossCircle(5).getEdgeNumber();
    COLOR expected_BlockColor = COLOR::NONE;
    COLOR actualBlockColor = courseInfo.getCrossCircle(5).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::RED;
    COLOR actualCircleColor = courseInfo.getCrossCircle(5).getCircleColor();
    EXPECT_EQ(expected_coordinate_x, actual_coordinate_x);
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    EXPECT_EQ(expected_edgeNumber, actual_edgeNumber);
  }

  TEST(getCrossCircle, getCrossCircle_index6)
  {
    const bool IS_LEFT_COURSE = true;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_coordinate_x = 4;
    int expected_coordinate_y = 2;
    int actual_coordinate_x = courseInfo.getCrossCircle(6).getCoordinate().x;
    int actual_coordinate_y = courseInfo.getCrossCircle(6).getCoordinate().y;
    int expected_edgeNumber = 4;
    int actual_edgeNumber = courseInfo.getCrossCircle(6).getEdgeNumber();
    COLOR expected_BlockColor = COLOR::GREEN;
    COLOR actualBlockColor = courseInfo.getCrossCircle(6).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::BLUE;
    COLOR actualCircleColor = courseInfo.getCrossCircle(6).getCircleColor();
    EXPECT_EQ(expected_coordinate_x, actual_coordinate_x);
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    EXPECT_EQ(expected_edgeNumber, actual_edgeNumber);
  }

  TEST(getCrossCircle, getCrossCircle_index7)
  {
    const bool IS_LEFT_COURSE = true;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_coordinate_x = 6;
    int expected_coordinate_y = 2;
    int actual_coordinate_x = courseInfo.getCrossCircle(7).getCoordinate().x;
    int actual_coordinate_y = courseInfo.getCrossCircle(7).getCoordinate().y;
    int expected_edgeNumber = 3;
    int actual_edgeNumber = courseInfo.getCrossCircle(7).getEdgeNumber();
    COLOR expected_BlockColor = COLOR::NONE;
    COLOR actualBlockColor = courseInfo.getCrossCircle(7).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::BLUE;
    COLOR actualCircleColor = courseInfo.getCrossCircle(7).getCircleColor();
    EXPECT_EQ(expected_coordinate_x, actual_coordinate_x);
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    EXPECT_EQ(expected_edgeNumber, actual_edgeNumber);
  }

  TEST(getCrossCircle, getCrossCircle_index8)
  {
    const bool IS_LEFT_COURSE = true;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_coordinate_x = 0;
    int expected_coordinate_y = 4;
    int actual_coordinate_x = courseInfo.getCrossCircle(8).getCoordinate().x;
    int actual_coordinate_y = courseInfo.getCrossCircle(8).getCoordinate().y;
    int expected_edgeNumber = 3;
    int actual_edgeNumber = courseInfo.getCrossCircle(8).getEdgeNumber();
    COLOR expected_BlockColor = COLOR::NONE;
    COLOR actualBlockColor = courseInfo.getCrossCircle(8).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::YELLOW;
    COLOR actualCircleColor = courseInfo.getCrossCircle(8).getCircleColor();
    EXPECT_EQ(expected_coordinate_x, actual_coordinate_x);
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    EXPECT_EQ(expected_edgeNumber, actual_edgeNumber);
  }

  TEST(getCrossCircle, getCrossCircle_index9)
  {
    const bool IS_LEFT_COURSE = true;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_coordinate_x = 2;
    int expected_coordinate_y = 4;
    int actual_coordinate_x = courseInfo.getCrossCircle(9).getCoordinate().x;
    int actual_coordinate_y = courseInfo.getCrossCircle(9).getCoordinate().y;
    int expected_edgeNumber = 4;
    int actual_edgeNumber = courseInfo.getCrossCircle(9).getEdgeNumber();
    COLOR expected_BlockColor = COLOR::YELLOW;
    COLOR actualBlockColor = courseInfo.getCrossCircle(9).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::YELLOW;
    COLOR actualCircleColor = courseInfo.getCrossCircle(9).getCircleColor();
    EXPECT_EQ(expected_coordinate_x, actual_coordinate_x);
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    EXPECT_EQ(expected_edgeNumber, actual_edgeNumber);
  }

  TEST(getCrossCircle, getCrossCircle_index10)
  {
    const bool IS_LEFT_COURSE = true;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_coordinate_x = 4;
    int expected_coordinate_y = 4;
    int actual_coordinate_x = courseInfo.getCrossCircle(10).getCoordinate().x;
    int actual_coordinate_y = courseInfo.getCrossCircle(10).getCoordinate().y;
    int expected_edgeNumber = 4;
    int actual_edgeNumber = courseInfo.getCrossCircle(10).getEdgeNumber();
    COLOR expected_BlockColor = COLOR::NONE;
    COLOR actualBlockColor = courseInfo.getCrossCircle(10).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::GREEN;
    COLOR actualCircleColor = courseInfo.getCrossCircle(10).getCircleColor();
    EXPECT_EQ(expected_coordinate_x, actual_coordinate_x);
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    EXPECT_EQ(expected_edgeNumber, actual_edgeNumber);
  }

  TEST(getCrossCircle, getCrossCircle_index11)
  {
    const bool IS_LEFT_COURSE = true;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_coordinate_x = 6;
    int expected_coordinate_y = 4;
    int actual_coordinate_x = courseInfo.getCrossCircle(11).getCoordinate().x;
    int actual_coordinate_y = courseInfo.getCrossCircle(11).getCoordinate().y;
    int expected_edgeNumber = 3;
    int actual_edgeNumber = courseInfo.getCrossCircle(11).getEdgeNumber();
    COLOR expected_BlockColor = COLOR::RED;
    COLOR actualBlockColor = courseInfo.getCrossCircle(11).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::GREEN;
    COLOR actualCircleColor = courseInfo.getCrossCircle(11).getCircleColor();
    EXPECT_EQ(expected_coordinate_x, actual_coordinate_x);
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    EXPECT_EQ(expected_edgeNumber, actual_edgeNumber);
  }

  TEST(getCrossCircle, getCrossCircle_index12)
  {
    const bool IS_LEFT_COURSE = true;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_coordinate_x = 0;
    int expected_coordinate_y = 6;
    int actual_coordinate_x = courseInfo.getCrossCircle(12).getCoordinate().x;
    int actual_coordinate_y = courseInfo.getCrossCircle(12).getCoordinate().y;
    int expected_edgeNumber = 2;
    int actual_edgeNumber = courseInfo.getCrossCircle(12).getEdgeNumber();
    COLOR expected_BlockColor = COLOR::GREEN;
    COLOR actualBlockColor = courseInfo.getCrossCircle(12).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::YELLOW;
    COLOR actualCircleColor = courseInfo.getCrossCircle(12).getCircleColor();
    EXPECT_EQ(expected_coordinate_x, actual_coordinate_x);
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    EXPECT_EQ(expected_edgeNumber, actual_edgeNumber);
  }

  TEST(getCrossCircle, getCrossCircle_index13)
  {
    const bool IS_LEFT_COURSE = true;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_coordinate_x = 2;
    int expected_coordinate_y = 6;
    int actual_coordinate_x = courseInfo.getCrossCircle(13).getCoordinate().x;
    int actual_coordinate_y = courseInfo.getCrossCircle(13).getCoordinate().y;
    int expected_edgeNumber = 3;
    int actual_edgeNumber = courseInfo.getCrossCircle(13).getEdgeNumber();
    COLOR expected_BlockColor = COLOR::NONE;
    COLOR actualBlockColor = courseInfo.getCrossCircle(13).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::YELLOW;
    COLOR actualCircleColor = courseInfo.getCrossCircle(13).getCircleColor();
    EXPECT_EQ(expected_coordinate_x, actual_coordinate_x);
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    EXPECT_EQ(expected_edgeNumber, actual_edgeNumber);
  }

  TEST(getCrossCircle, getCrossCircle_index14)
  {
    const bool IS_LEFT_COURSE = true;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_coordinate_x = 4;
    int expected_coordinate_y = 6;
    int actual_coordinate_x = courseInfo.getCrossCircle(14).getCoordinate().x;
    int actual_coordinate_y = courseInfo.getCrossCircle(14).getCoordinate().y;
    int expected_edgeNumber = 3;
    int actual_edgeNumber = courseInfo.getCrossCircle(14).getEdgeNumber();
    COLOR expected_BlockColor = COLOR::BLUE;
    COLOR actualBlockColor = courseInfo.getCrossCircle(14).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::GREEN;
    COLOR actualCircleColor = courseInfo.getCrossCircle(14).getCircleColor();
    EXPECT_EQ(expected_coordinate_x, actual_coordinate_x);
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    EXPECT_EQ(expected_edgeNumber, actual_edgeNumber);
  }

  TEST(getCrossCircle, getCrossCircle_index15)
  {
    const bool IS_LEFT_COURSE = true;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_coordinate_x = 6;
    int expected_coordinate_y = 6;
    int actual_coordinate_x = courseInfo.getCrossCircle(15).getCoordinate().x;
    int actual_coordinate_y = courseInfo.getCrossCircle(15).getCoordinate().y;
    int expected_edgeNumber = 2;
    int actual_edgeNumber = courseInfo.getCrossCircle(15).getEdgeNumber();
    COLOR expected_BlockColor = COLOR::NONE;
    COLOR actualBlockColor = courseInfo.getCrossCircle(15).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::GREEN;
    COLOR actualCircleColor = courseInfo.getCrossCircle(15).getCircleColor();
    EXPECT_EQ(expected_coordinate_x, actual_coordinate_x);
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    EXPECT_EQ(expected_edgeNumber, actual_edgeNumber);
  }

  TEST(getCenterMark, getCenterMark)
  {
    const bool IS_LEFT_COURSE = true;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_coordinate_x = 3;
    int expected_coordinate_y = 3;
    int actual_coordinate_x = courseInfo.getCenterMark().getCoordinate().x;
    int actual_coordinate_y = courseInfo.getCenterMark().getCoordinate().y;
    COLOR expected_BlockColor = COLOR::NONE;
    COLOR actualBlockColor = courseInfo.getCenterMark().getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::BLACK;
    COLOR actualCircleColor = courseInfo.getCenterMark().getCircleColor();
    EXPECT_EQ(expected_coordinate_x, actual_coordinate_x);
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
  }

  //ブロックID0のブロックをサークルID0のブロックサークルに移動させる
  TEST(moveBlock, moveBlock_CIRCLEID0_BLOCKID0)
  {
    const bool IS_LEFT_COURSE = true;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    courseInfo.moveBlock(CIRCLE_ID::ID0, BLOCK_ID::ID0);
    int expected_coordinate_x = 1;
    int expected_coordinate_y = 1;
    int actual_coordinate_x = courseInfo.getNode(BLOCK_ID::ID0).getCoordinate().x;
    int actual_coordinate_y = courseInfo.getNode(BLOCK_ID::ID0).getCoordinate().y;
    COLOR expected_CircleColor = COLOR::YELLOW;
    COLOR actualCircleColor = courseInfo.getNode(BLOCK_ID::ID0).getCircleColor();
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    BLOCK_ID expected_Id = BLOCK_ID::NONE;
    BLOCK_ID actualId = courseInfo.getCrossCircle(1).getBlock().blockId;
    EXPECT_EQ(expected_Id, actualId);
  }

  //ブロックID5のブロックをサークルID2のブロックサークルに移動させる
  TEST(moveBlock, moveBlock_CIRCLEID2_BLOCKID5)
  {
    const bool IS_LEFT_COURSE = true;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    courseInfo.moveBlock(CIRCLE_ID::ID2, BLOCK_ID::ID5);
    int expected_coordinate_x = 5;
    int expected_coordinate_y = 1;
    int actual_coordinate_x = courseInfo.getNode(BLOCK_ID::ID5).getCoordinate().x;
    int actual_coordinate_y = courseInfo.getNode(BLOCK_ID::ID5).getCoordinate().y;
    COLOR expected_CircleColor = COLOR::RED;
    COLOR actualCircleColor = courseInfo.getNode(BLOCK_ID::ID5).getCircleColor();
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    BLOCK_ID expected_Id = BLOCK_ID::NONE;
    BLOCK_ID actualId = courseInfo.getCrossCircle(11).getBlock().blockId;
    EXPECT_EQ(expected_Id, actualId);
  }

  TEST(getNodeRight, getNode_ID0)
  {
    setIsLeft(false);
    const bool IS_LEFT_COURSE = false;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_id_coordinate_x = 2;
    int expected_id_coordinate_y = 0;
    int actual_id_coordinate_x = courseInfo.getNode(BLOCK_ID::ID0).getCoordinate().x;
    int actual_id_coordinate_y = courseInfo.getNode(BLOCK_ID::ID0).getCoordinate().y;
    COLOR expected_Color = COLOR::YELLOW;
    COLOR actualColor = courseInfo.getNode(BLOCK_ID::ID0).getBlock().blockColor;
    EXPECT_EQ(expected_id_coordinate_x, actual_id_coordinate_x);
    EXPECT_EQ(expected_id_coordinate_y, actual_id_coordinate_y);
    EXPECT_EQ(expected_Color, actualColor);
  }

  TEST(getNodeRight, getNode_ID1)
  {
    const bool IS_LEFT_COURSE = false;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_id_coordinate_x = 6;
    int expected_id_coordinate_y = 0;
    int actual_id_coordinate_x = courseInfo.getNode(BLOCK_ID::ID1).getCoordinate().x;
    int actual_id_coordinate_y = courseInfo.getNode(BLOCK_ID::ID1).getCoordinate().y;
    COLOR expected_Color = COLOR::BLUE;
    COLOR actualColor = courseInfo.getNode(BLOCK_ID::ID1).getBlock().blockColor;
    EXPECT_EQ(expected_id_coordinate_x, actual_id_coordinate_x);
    EXPECT_EQ(expected_id_coordinate_y, actual_id_coordinate_y);
    EXPECT_EQ(expected_Color, actualColor);
  }

  TEST(getNodeRight, getNode_ID2)
  {
    const bool IS_LEFT_COURSE = false;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_id_coordinate_x = 0;
    int expected_id_coordinate_y = 2;
    int actual_id_coordinate_x = courseInfo.getNode(BLOCK_ID::ID2).getCoordinate().x;
    int actual_id_coordinate_y = courseInfo.getNode(BLOCK_ID::ID2).getCoordinate().y;
    COLOR expected_Color = COLOR::RED;
    COLOR actualColor = courseInfo.getNode(BLOCK_ID::ID2).getBlock().blockColor;
    EXPECT_EQ(expected_id_coordinate_x, actual_id_coordinate_x);
    EXPECT_EQ(expected_id_coordinate_y, actual_id_coordinate_y);
    EXPECT_EQ(expected_Color, actualColor);
  }

  TEST(getNodeRight, getNode_ID3)
  {
    const bool IS_LEFT_COURSE = false;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_id_coordinate_x = 4;
    int expected_id_coordinate_y = 2;
    int actual_id_coordinate_x = courseInfo.getNode(BLOCK_ID::ID3).getCoordinate().x;
    int actual_id_coordinate_y = courseInfo.getNode(BLOCK_ID::ID3).getCoordinate().y;
    COLOR expected_Color = COLOR::GREEN;
    COLOR actualColor = courseInfo.getNode(BLOCK_ID::ID3).getBlock().blockColor;
    EXPECT_EQ(expected_id_coordinate_x, actual_id_coordinate_x);
    EXPECT_EQ(expected_id_coordinate_y, actual_id_coordinate_y);
    EXPECT_EQ(expected_Color, actualColor);
  }

  TEST(getNodeRight, getNode_ID4)
  {
    const bool IS_LEFT_COURSE = false;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_id_coordinate_x = 2;
    int expected_id_coordinate_y = 4;
    int actual_id_coordinate_x = courseInfo.getNode(BLOCK_ID::ID4).getCoordinate().x;
    int actual_id_coordinate_y = courseInfo.getNode(BLOCK_ID::ID4).getCoordinate().y;
    COLOR expected_Color = COLOR::YELLOW;
    COLOR actualColor = courseInfo.getNode(BLOCK_ID::ID4).getBlock().blockColor;
    EXPECT_EQ(expected_id_coordinate_x, actual_id_coordinate_x);
    EXPECT_EQ(expected_id_coordinate_y, actual_id_coordinate_y);
    EXPECT_EQ(expected_Color, actualColor);
  }

  TEST(getNodeRight, getNode_ID5)
  {
    const bool IS_LEFT_COURSE = false;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_id_coordinate_x = 6;
    int expected_id_coordinate_y = 4;
    int actual_id_coordinate_x = courseInfo.getNode(BLOCK_ID::ID5).getCoordinate().x;
    int actual_id_coordinate_y = courseInfo.getNode(BLOCK_ID::ID5).getCoordinate().y;
    COLOR expected_Color = COLOR::RED;
    COLOR actualColor = courseInfo.getNode(BLOCK_ID::ID5).getBlock().blockColor;
    EXPECT_EQ(expected_id_coordinate_x, actual_id_coordinate_x);
    EXPECT_EQ(expected_id_coordinate_y, actual_id_coordinate_y);
    EXPECT_EQ(expected_Color, actualColor);
  }

  TEST(getNodeRight, getNode_ID6)
  {
    const bool IS_LEFT_COURSE = false;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_id_coordinate_x = 0;
    int expected_id_coordinate_y = 6;
    int actual_id_coordinate_x = courseInfo.getNode(BLOCK_ID::ID6).getCoordinate().x;
    int actual_id_coordinate_y = courseInfo.getNode(BLOCK_ID::ID6).getCoordinate().y;
    COLOR expected_Color = COLOR::GREEN;
    COLOR actualColor = courseInfo.getNode(BLOCK_ID::ID6).getBlock().blockColor;
    EXPECT_EQ(expected_id_coordinate_x, actual_id_coordinate_x);
    EXPECT_EQ(expected_id_coordinate_y, actual_id_coordinate_y);
    EXPECT_EQ(expected_Color, actualColor);
  }

  TEST(getNodeRight, getNode_ID7)
  {
    const bool IS_LEFT_COURSE = false;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_id_coordinate_x = 4;
    int expected_id_coordinate_y = 6;
    int actual_id_coordinate_x = courseInfo.getNode(BLOCK_ID::ID7).getCoordinate().x;
    int actual_id_coordinate_y = courseInfo.getNode(BLOCK_ID::ID7).getCoordinate().y;
    COLOR expected_Color = COLOR::BLUE;
    COLOR actualColor = courseInfo.getNode(BLOCK_ID::ID7).getBlock().blockColor;
    EXPECT_EQ(expected_id_coordinate_x, actual_id_coordinate_x);
    EXPECT_EQ(expected_id_coordinate_y, actual_id_coordinate_y);
    EXPECT_EQ(expected_Color, actualColor);
  }

  TEST(getBlockCircleRight, getBlockCircle_ID0)
  {
    const bool IS_LEFT_COURSE = false;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_id_coordinate_x = 1;
    int expected_id_coordinate_y = 1;
    int actual_id_coordinate_x = courseInfo.getBlockCircle(CIRCLE_ID::ID0).getCoordinate().x;
    int actual_id_coordinate_y = courseInfo.getBlockCircle(CIRCLE_ID::ID0).getCoordinate().y;
    COLOR expected_BlockColor = COLOR::NONE;
    COLOR actualBlockColor = courseInfo.getBlockCircle(CIRCLE_ID::ID0).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::YELLOW;
    COLOR actualCircleColor = courseInfo.getBlockCircle(CIRCLE_ID::ID0).getCircleColor();
    EXPECT_EQ(expected_id_coordinate_x, actual_id_coordinate_x);
    EXPECT_EQ(expected_id_coordinate_y, actual_id_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
  }

  TEST(getBlockCircleRight, getBlockCircle_ID1)
  {
    const bool IS_LEFT_COURSE = false;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_id_coordinate_x = 3;
    int expected_id_coordinate_y = 1;
    int actual_id_coordinate_x = courseInfo.getBlockCircle(CIRCLE_ID::ID1).getCoordinate().x;
    int actual_id_coordinate_y = courseInfo.getBlockCircle(CIRCLE_ID::ID1).getCoordinate().y;
    COLOR expected_BlockColor = COLOR::NONE;
    COLOR actualBlockColor = courseInfo.getBlockCircle(CIRCLE_ID::ID1).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::GREEN;
    COLOR actualCircleColor = courseInfo.getBlockCircle(CIRCLE_ID::ID1).getCircleColor();
    EXPECT_EQ(expected_id_coordinate_x, actual_id_coordinate_x);
    EXPECT_EQ(expected_id_coordinate_y, actual_id_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
  }

  TEST(getBlockCircleRight, getBlockCircle_ID2)
  {
    const bool IS_LEFT_COURSE = false;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_id_coordinate_x = 5;
    int expected_id_coordinate_y = 1;
    int actual_id_coordinate_x = courseInfo.getBlockCircle(CIRCLE_ID::ID2).getCoordinate().x;
    int actual_id_coordinate_y = courseInfo.getBlockCircle(CIRCLE_ID::ID2).getCoordinate().y;
    COLOR expected_BlockColor = COLOR::NONE;
    COLOR actualBlockColor = courseInfo.getBlockCircle(CIRCLE_ID::ID2).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::RED;
    COLOR actualCircleColor = courseInfo.getBlockCircle(CIRCLE_ID::ID2).getCircleColor();
    EXPECT_EQ(expected_id_coordinate_x, actual_id_coordinate_x);
    EXPECT_EQ(expected_id_coordinate_y, actual_id_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
  }
  TEST(getBlockCircleRight, getBlockCircle_ID3)
  {
    const bool IS_LEFT_COURSE = false;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_id_coordinate_x = 1;
    int expected_id_coordinate_y = 3;
    int actual_id_coordinate_x = courseInfo.getBlockCircle(CIRCLE_ID::ID3).getCoordinate().x;
    int actual_id_coordinate_y = courseInfo.getBlockCircle(CIRCLE_ID::ID3).getCoordinate().y;
    COLOR expected_BlockColor = COLOR::NONE;
    COLOR actualBlockColor = courseInfo.getBlockCircle(CIRCLE_ID::ID3).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::BLUE;
    COLOR actualCircleColor = courseInfo.getBlockCircle(CIRCLE_ID::ID3).getCircleColor();
    EXPECT_EQ(expected_id_coordinate_x, actual_id_coordinate_x);
    EXPECT_EQ(expected_id_coordinate_y, actual_id_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
  }
  TEST(getBlockCircleRight, getBlockCircle_ID4)
  {
    const bool IS_LEFT_COURSE = false;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_id_coordinate_x = 5;
    int expected_id_coordinate_y = 3;
    int actual_id_coordinate_x = courseInfo.getBlockCircle(CIRCLE_ID::ID4).getCoordinate().x;
    int actual_id_coordinate_y = courseInfo.getBlockCircle(CIRCLE_ID::ID4).getCoordinate().y;
    COLOR expected_BlockColor = COLOR::NONE;
    COLOR actualBlockColor = courseInfo.getBlockCircle(CIRCLE_ID::ID4).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::YELLOW;
    COLOR actualCircleColor = courseInfo.getBlockCircle(CIRCLE_ID::ID4).getCircleColor();
    EXPECT_EQ(expected_id_coordinate_x, actual_id_coordinate_x);
    EXPECT_EQ(expected_id_coordinate_y, actual_id_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
  }
  TEST(getBlockCircleRight, getBlockCircle_ID5)
  {
    const bool IS_LEFT_COURSE = false;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_id_coordinate_x = 1;
    int expected_id_coordinate_y = 5;
    int actual_id_coordinate_x = courseInfo.getBlockCircle(CIRCLE_ID::ID5).getCoordinate().x;
    int actual_id_coordinate_y = courseInfo.getBlockCircle(CIRCLE_ID::ID5).getCoordinate().y;
    COLOR expected_BlockColor = COLOR::NONE;
    COLOR actualBlockColor = courseInfo.getBlockCircle(CIRCLE_ID::ID5).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::GREEN;
    COLOR actualCircleColor = courseInfo.getBlockCircle(CIRCLE_ID::ID5).getCircleColor();
    EXPECT_EQ(expected_id_coordinate_x, actual_id_coordinate_x);
    EXPECT_EQ(expected_id_coordinate_y, actual_id_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
  }
  TEST(getBlockCircleRight, getBlockCircle_ID6)
  {
    const bool IS_LEFT_COURSE = false;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_id_coordinate_x = 3;
    int expected_id_coordinate_y = 5;
    int actual_id_coordinate_x = courseInfo.getBlockCircle(CIRCLE_ID::ID6).getCoordinate().x;
    int actual_id_coordinate_y = courseInfo.getBlockCircle(CIRCLE_ID::ID6).getCoordinate().y;
    COLOR expected_BlockColor = COLOR::NONE;
    COLOR actualBlockColor = courseInfo.getBlockCircle(CIRCLE_ID::ID6).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::RED;
    COLOR actualCircleColor = courseInfo.getBlockCircle(CIRCLE_ID::ID6).getCircleColor();
    EXPECT_EQ(expected_id_coordinate_x, actual_id_coordinate_x);
    EXPECT_EQ(expected_id_coordinate_y, actual_id_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
  }
  TEST(getBlockCircleRight, getBlockCircle_ID7)
  {
    const bool IS_LEFT_COURSE = false;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_id_coordinate_x = 5;
    int expected_id_coordinate_y = 5;
    int actual_id_coordinate_x = courseInfo.getBlockCircle(CIRCLE_ID::ID7).getCoordinate().x;
    int actual_id_coordinate_y = courseInfo.getBlockCircle(CIRCLE_ID::ID7).getCoordinate().y;
    COLOR expected_BlockColor = COLOR::NONE;
    COLOR actualBlockColor = courseInfo.getBlockCircle(CIRCLE_ID::ID7).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::BLUE;
    COLOR actualCircleColor = courseInfo.getBlockCircle(CIRCLE_ID::ID7).getCircleColor();
    EXPECT_EQ(expected_id_coordinate_x, actual_id_coordinate_x);
    EXPECT_EQ(expected_id_coordinate_y, actual_id_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
  }

  TEST(getCrossCircleRight, getCrossCircle_index0)
  {
    const bool IS_LEFT_COURSE = false;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_coordinate_x = 0;
    int expected_coordinate_y = 0;
    int actual_coordinate_x = courseInfo.getCrossCircle(0).getCoordinate().x;
    int actual_coordinate_y = courseInfo.getCrossCircle(0).getCoordinate().y;
    int expected_edgeNumber = 2;
    int actual_edgeNumber = courseInfo.getCrossCircle(0).getEdgeNumber();
    COLOR expected_BlockColor = COLOR::NONE;
    COLOR actualBlockColor = courseInfo.getCrossCircle(0).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::RED;
    COLOR actualCircleColor = courseInfo.getCrossCircle(0).getCircleColor();
    EXPECT_EQ(expected_coordinate_x, actual_coordinate_x);
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    EXPECT_EQ(expected_edgeNumber, actual_edgeNumber);
  }

  TEST(getCrossCircleRight, getCrossCircle_index1)
  {
    const bool IS_LEFT_COURSE = false;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_coordinate_x = 2;
    int expected_coordinate_y = 0;
    int actual_coordinate_x = courseInfo.getCrossCircle(1).getCoordinate().x;
    int actual_coordinate_y = courseInfo.getCrossCircle(1).getCoordinate().y;
    int expected_edgeNumber = 3;
    int actual_edgeNumber = courseInfo.getCrossCircle(1).getEdgeNumber();
    COLOR expected_BlockColor = COLOR::YELLOW;
    COLOR actualBlockColor = courseInfo.getCrossCircle(1).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::RED;
    COLOR actualCircleColor = courseInfo.getCrossCircle(1).getCircleColor();
    EXPECT_EQ(expected_coordinate_x, actual_coordinate_x);
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    EXPECT_EQ(expected_edgeNumber, actual_edgeNumber);
  }

  TEST(getCrossCircleRight, getCrossCircle_index2)
  {
    const bool IS_LEFT_COURSE = false;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_coordinate_x = 4;
    int expected_coordinate_y = 0;
    int actual_coordinate_x = courseInfo.getCrossCircle(2).getCoordinate().x;
    int actual_coordinate_y = courseInfo.getCrossCircle(2).getCoordinate().y;
    int expected_edgeNumber = 3;
    int actual_edgeNumber = courseInfo.getCrossCircle(2).getEdgeNumber();
    COLOR expected_BlockColor = COLOR::NONE;
    COLOR actualBlockColor = courseInfo.getCrossCircle(2).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::BLUE;
    COLOR actualCircleColor = courseInfo.getCrossCircle(2).getCircleColor();
    EXPECT_EQ(expected_coordinate_x, actual_coordinate_x);
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    EXPECT_EQ(expected_edgeNumber, actual_edgeNumber);
  }

  TEST(getCrossCircleRight, getCrossCircle_index3)
  {
    const bool IS_LEFT_COURSE = false;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_coordinate_x = 6;
    int expected_coordinate_y = 0;
    int actual_coordinate_x = courseInfo.getCrossCircle(3).getCoordinate().x;
    int actual_coordinate_y = courseInfo.getCrossCircle(3).getCoordinate().y;
    int expected_edgeNumber = 2;
    int actual_edgeNumber = courseInfo.getCrossCircle(3).getEdgeNumber();
    COLOR expected_BlockColor = COLOR::BLUE;
    COLOR actualBlockColor = courseInfo.getCrossCircle(3).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::BLUE;
    COLOR actualCircleColor = courseInfo.getCrossCircle(3).getCircleColor();
    EXPECT_EQ(expected_coordinate_x, actual_coordinate_x);
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    EXPECT_EQ(expected_edgeNumber, actual_edgeNumber);
  }

  TEST(getCrossCircleRight, getCrossCircle_index4)
  {
    const bool IS_LEFT_COURSE = false;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_coordinate_x = 0;
    int expected_coordinate_y = 2;
    int actual_coordinate_x = courseInfo.getCrossCircle(4).getCoordinate().x;
    int actual_coordinate_y = courseInfo.getCrossCircle(4).getCoordinate().y;
    int expected_edgeNumber = 3;
    int actual_edgeNumber = courseInfo.getCrossCircle(4).getEdgeNumber();
    COLOR expected_BlockColor = COLOR::RED;
    COLOR actualBlockColor = courseInfo.getCrossCircle(4).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::RED;
    COLOR actualCircleColor = courseInfo.getCrossCircle(4).getCircleColor();
    EXPECT_EQ(expected_coordinate_x, actual_coordinate_x);
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    EXPECT_EQ(expected_edgeNumber, actual_edgeNumber);
  }

  TEST(getCrossCircleRight, getCrossCircle_index5)
  {
    const bool IS_LEFT_COURSE = false;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_coordinate_x = 2;
    int expected_coordinate_y = 2;
    int actual_coordinate_x = courseInfo.getCrossCircle(5).getCoordinate().x;
    int actual_coordinate_y = courseInfo.getCrossCircle(5).getCoordinate().y;
    int expected_edgeNumber = 4;
    int actual_edgeNumber = courseInfo.getCrossCircle(5).getEdgeNumber();
    COLOR expected_BlockColor = COLOR::NONE;
    COLOR actualBlockColor = courseInfo.getCrossCircle(5).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::RED;
    COLOR actualCircleColor = courseInfo.getCrossCircle(5).getCircleColor();
    EXPECT_EQ(expected_coordinate_x, actual_coordinate_x);
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    EXPECT_EQ(expected_edgeNumber, actual_edgeNumber);
  }

  TEST(getCrossCircleRight, getCrossCircle_index6)
  {
    const bool IS_LEFT_COURSE = false;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_coordinate_x = 4;
    int expected_coordinate_y = 2;
    int actual_coordinate_x = courseInfo.getCrossCircle(6).getCoordinate().x;
    int actual_coordinate_y = courseInfo.getCrossCircle(6).getCoordinate().y;
    int expected_edgeNumber = 4;
    int actual_edgeNumber = courseInfo.getCrossCircle(6).getEdgeNumber();
    COLOR expected_BlockColor = COLOR::GREEN;
    COLOR actualBlockColor = courseInfo.getCrossCircle(6).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::BLUE;
    COLOR actualCircleColor = courseInfo.getCrossCircle(6).getCircleColor();
    EXPECT_EQ(expected_coordinate_x, actual_coordinate_x);
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    EXPECT_EQ(expected_edgeNumber, actual_edgeNumber);
  }

  TEST(getCrossCircleRight, getCrossCircle_index7)
  {
    const bool IS_LEFT_COURSE = false;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_coordinate_x = 6;
    int expected_coordinate_y = 2;
    int actual_coordinate_x = courseInfo.getCrossCircle(7).getCoordinate().x;
    int actual_coordinate_y = courseInfo.getCrossCircle(7).getCoordinate().y;
    int expected_edgeNumber = 3;
    int actual_edgeNumber = courseInfo.getCrossCircle(7).getEdgeNumber();
    COLOR expected_BlockColor = COLOR::NONE;
    COLOR actualBlockColor = courseInfo.getCrossCircle(7).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::BLUE;
    COLOR actualCircleColor = courseInfo.getCrossCircle(7).getCircleColor();
    EXPECT_EQ(expected_coordinate_x, actual_coordinate_x);
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    EXPECT_EQ(expected_edgeNumber, actual_edgeNumber);
  }

  TEST(getCrossCircleRight, getCrossCircle_index8)
  {
    const bool IS_LEFT_COURSE = false;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_coordinate_x = 0;
    int expected_coordinate_y = 4;
    int actual_coordinate_x = courseInfo.getCrossCircle(8).getCoordinate().x;
    int actual_coordinate_y = courseInfo.getCrossCircle(8).getCoordinate().y;
    int expected_edgeNumber = 3;
    int actual_edgeNumber = courseInfo.getCrossCircle(8).getEdgeNumber();
    COLOR expected_BlockColor = COLOR::NONE;
    COLOR actualBlockColor = courseInfo.getCrossCircle(8).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::YELLOW;
    COLOR actualCircleColor = courseInfo.getCrossCircle(8).getCircleColor();
    EXPECT_EQ(expected_coordinate_x, actual_coordinate_x);
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    EXPECT_EQ(expected_edgeNumber, actual_edgeNumber);
  }

  TEST(getCrossCircleRight, getCrossCircle_index9)
  {
    const bool IS_LEFT_COURSE = false;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_coordinate_x = 2;
    int expected_coordinate_y = 4;
    int actual_coordinate_x = courseInfo.getCrossCircle(9).getCoordinate().x;
    int actual_coordinate_y = courseInfo.getCrossCircle(9).getCoordinate().y;
    int expected_edgeNumber = 4;
    int actual_edgeNumber = courseInfo.getCrossCircle(9).getEdgeNumber();
    COLOR expected_BlockColor = COLOR::YELLOW;
    COLOR actualBlockColor = courseInfo.getCrossCircle(9).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::YELLOW;
    COLOR actualCircleColor = courseInfo.getCrossCircle(9).getCircleColor();
    EXPECT_EQ(expected_coordinate_x, actual_coordinate_x);
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    EXPECT_EQ(expected_edgeNumber, actual_edgeNumber);
  }

  TEST(getCrossCircleRight, getCrossCircle_index10)
  {
    const bool IS_LEFT_COURSE = false;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_coordinate_x = 4;
    int expected_coordinate_y = 4;
    int actual_coordinate_x = courseInfo.getCrossCircle(10).getCoordinate().x;
    int actual_coordinate_y = courseInfo.getCrossCircle(10).getCoordinate().y;
    int expected_edgeNumber = 4;
    int actual_edgeNumber = courseInfo.getCrossCircle(10).getEdgeNumber();
    COLOR expected_BlockColor = COLOR::NONE;
    COLOR actualBlockColor = courseInfo.getCrossCircle(10).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::GREEN;
    COLOR actualCircleColor = courseInfo.getCrossCircle(10).getCircleColor();
    EXPECT_EQ(expected_coordinate_x, actual_coordinate_x);
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    EXPECT_EQ(expected_edgeNumber, actual_edgeNumber);
  }

  TEST(getCrossCircleRight, getCrossCircle_index11)
  {
    const bool IS_LEFT_COURSE = false;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_coordinate_x = 6;
    int expected_coordinate_y = 4;
    int actual_coordinate_x = courseInfo.getCrossCircle(11).getCoordinate().x;
    int actual_coordinate_y = courseInfo.getCrossCircle(11).getCoordinate().y;
    int expected_edgeNumber = 3;
    int actual_edgeNumber = courseInfo.getCrossCircle(11).getEdgeNumber();
    COLOR expected_BlockColor = COLOR::RED;
    COLOR actualBlockColor = courseInfo.getCrossCircle(11).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::GREEN;
    COLOR actualCircleColor = courseInfo.getCrossCircle(11).getCircleColor();
    EXPECT_EQ(expected_coordinate_x, actual_coordinate_x);
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    EXPECT_EQ(expected_edgeNumber, actual_edgeNumber);
  }

  TEST(getCrossCircleRight, getCrossCircle_index12)
  {
    const bool IS_LEFT_COURSE = false;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_coordinate_x = 0;
    int expected_coordinate_y = 6;
    int actual_coordinate_x = courseInfo.getCrossCircle(12).getCoordinate().x;
    int actual_coordinate_y = courseInfo.getCrossCircle(12).getCoordinate().y;
    int expected_edgeNumber = 2;
    int actual_edgeNumber = courseInfo.getCrossCircle(12).getEdgeNumber();
    COLOR expected_BlockColor = COLOR::GREEN;
    COLOR actualBlockColor = courseInfo.getCrossCircle(12).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::YELLOW;
    COLOR actualCircleColor = courseInfo.getCrossCircle(12).getCircleColor();
    EXPECT_EQ(expected_coordinate_x, actual_coordinate_x);
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    EXPECT_EQ(expected_edgeNumber, actual_edgeNumber);
  }

  TEST(getCrossCircleRight, getCrossCircle_index13)
  {
    const bool IS_LEFT_COURSE = false;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_coordinate_x = 2;
    int expected_coordinate_y = 6;
    int actual_coordinate_x = courseInfo.getCrossCircle(13).getCoordinate().x;
    int actual_coordinate_y = courseInfo.getCrossCircle(13).getCoordinate().y;
    int expected_edgeNumber = 3;
    int actual_edgeNumber = courseInfo.getCrossCircle(13).getEdgeNumber();
    COLOR expected_BlockColor = COLOR::NONE;
    COLOR actualBlockColor = courseInfo.getCrossCircle(13).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::YELLOW;
    COLOR actualCircleColor = courseInfo.getCrossCircle(13).getCircleColor();
    EXPECT_EQ(expected_coordinate_x, actual_coordinate_x);
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    EXPECT_EQ(expected_edgeNumber, actual_edgeNumber);
  }

  TEST(getCrossCircleRight, getCrossCircle_index14)
  {
    const bool IS_LEFT_COURSE = false;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_coordinate_x = 4;
    int expected_coordinate_y = 6;
    int actual_coordinate_x = courseInfo.getCrossCircle(14).getCoordinate().x;
    int actual_coordinate_y = courseInfo.getCrossCircle(14).getCoordinate().y;
    int expected_edgeNumber = 3;
    int actual_edgeNumber = courseInfo.getCrossCircle(14).getEdgeNumber();
    COLOR expected_BlockColor = COLOR::BLUE;
    COLOR actualBlockColor = courseInfo.getCrossCircle(14).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::GREEN;
    COLOR actualCircleColor = courseInfo.getCrossCircle(14).getCircleColor();
    EXPECT_EQ(expected_coordinate_x, actual_coordinate_x);
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    EXPECT_EQ(expected_edgeNumber, actual_edgeNumber);
  }

  TEST(getCrossCircleRight, getCrossCircle_index15)
  {
    const bool IS_LEFT_COURSE = false;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_coordinate_x = 6;
    int expected_coordinate_y = 6;
    int actual_coordinate_x = courseInfo.getCrossCircle(15).getCoordinate().x;
    int actual_coordinate_y = courseInfo.getCrossCircle(15).getCoordinate().y;
    int expected_edgeNumber = 2;
    int actual_edgeNumber = courseInfo.getCrossCircle(15).getEdgeNumber();
    COLOR expected_BlockColor = COLOR::NONE;
    COLOR actualBlockColor = courseInfo.getCrossCircle(15).getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::GREEN;
    COLOR actualCircleColor = courseInfo.getCrossCircle(15).getCircleColor();
    EXPECT_EQ(expected_coordinate_x, actual_coordinate_x);
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    EXPECT_EQ(expected_edgeNumber, actual_edgeNumber);
  }

  TEST(getCenterMarkRight, getCenterMark)
  {
    const bool IS_LEFT_COURSE = true;
    CourseInfo courseInfo(IS_LEFT_COURSE);
    courseInfo.initCourseInfo();
    int expected_coordinate_x = 3;
    int expected_coordinate_y = 3;
    int actual_coordinate_x = courseInfo.getCenterMark().getCoordinate().x;
    int actual_coordinate_y = courseInfo.getCenterMark().getCoordinate().y;
    COLOR expected_BlockColor = COLOR::NONE;
    COLOR actualBlockColor = courseInfo.getCenterMark().getBlock().blockColor;
    COLOR expected_CircleColor = COLOR::BLACK;
    COLOR actualCircleColor = courseInfo.getCenterMark().getCircleColor();
    EXPECT_EQ(expected_coordinate_x, actual_coordinate_x);
    EXPECT_EQ(expected_coordinate_y, actual_coordinate_y);
    EXPECT_EQ(expected_BlockColor, actualBlockColor);
    EXPECT_EQ(expected_CircleColor, actualCircleColor);
    setIsLeft(true);
  }

}  // namespace etrobocon2021_test
