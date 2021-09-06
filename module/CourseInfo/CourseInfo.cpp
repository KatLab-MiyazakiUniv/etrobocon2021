/**
 * @file CourseInfo.cpp
 * @brief ビンゴエリアの情報を保持するクラス
 * @author Hisataka-Hagiyama,uchyam
 */

#include "CourseInfo.h"
CourseInfo::CourseInfo(const bool IS_LEFT_COURSE) : isLeftCourse(IS_LEFT_COURSE)
{
  //交点サークルにおけるサークルの色の初期値
  std::array<std::array<COLOR, 4>, 4> crossCircleColor
      = { { { COLOR::RED, COLOR::RED, COLOR::BLUE, COLOR::BLUE },
            { COLOR::RED, COLOR::RED, COLOR::BLUE, COLOR::BLUE },
            { COLOR::YELLOW, COLOR::YELLOW, COLOR::GREEN, COLOR::GREEN },
            { COLOR::YELLOW, COLOR::YELLOW, COLOR::GREEN, COLOR::GREEN } } };

  //黒線の数の初期値
  std::array<std::array<int, 4>, 4> initEdgeNumber
      = { { { 2, 3, 3, 2 }, { 3, 4, 4, 3 }, { 3, 4, 4, 3 }, { 2, 3, 3, 2 } } };

  //ブロックサークルにおけるサークルの色の初期値
  std::array<COLOR, 8> blockCircleColor{ COLOR::YELLOW, COLOR::GREEN, COLOR::RED, COLOR::BLUE,
                                         COLOR::YELLOW, COLOR::GREEN, COLOR::RED, COLOR::BLUE };

  //交点サークルの座標、サークルの色、黒線の本数をセット
  int index = 0;
  for(int y = 0; y < 4; y++) {
    for(int x = 0; x < 4; x++) {
      crossCircle[index].setCoordinate(x * 2, y * 2);
      crossCircle[index].setCircleColor(crossCircleColor[y][x]);
      crossCircle[index].setEdgeNumber(initEdgeNumber[y][x]);
      index++;
    }
  }

  //ブロックサークルの座標、サークルの色をセット
  int index2 = 0;
  for(int y = 0; y < 3; y++) {
    for(int x = 0; x < 3; x++) {
      if(x == 1 && y == 1) {
        centerMark.setCoordinate(x * 2 + 1, y * 2 + 1);
        centerMark.setCircleColor(COLOR::BLACK);
      } else {
        blockCircle[index2].setCoordinate(x * 2 + 1, y * 2 + 1);
        blockCircle[index2].setCircleColor(blockCircleColor[index2]);
        blockCircle[index2].setCircleId(static_cast<CIRCLE_ID>(index2));
        index2++;
      }
    }
  }
}

void CourseInfo::setBlockInfo(int info, COLOR color)
{
  int index = 0;
  BLOCK_ID blockId = BLOCK_ID::ID0;
  if(info >= 65 && info <= 83 && info != 73 && info != 78 && info != 79) {
    //交点サークルの場合
    switch(info) {
      case 65:  // Aのとき
        index = isLeftCourse ? 0 : 3;
        if(!isLeftCourse) blockId = BLOCK_ID ::ID1;
        break;
      case 66:  // Bのとき
        index = isLeftCourse ? 1 : 2;
        if(isLeftCourse) blockId = BLOCK_ID ::ID0;
        break;
      case 67:  // Cのとき
        index = isLeftCourse ? 2 : 1;
        if(!isLeftCourse) blockId = BLOCK_ID ::ID0;
        break;
      case 68:  // Dのとき
        index = isLeftCourse ? 3 : 0;
        if(isLeftCourse) blockId = BLOCK_ID ::ID1;
        break;
      case 69:  // Eのとき
        index = isLeftCourse ? 4 : 7;
        if(isLeftCourse) blockId = BLOCK_ID ::ID2;
        break;
      case 70:  // Fのとき
        index = isLeftCourse ? 5 : 6;
        if(!isLeftCourse) blockId = BLOCK_ID ::ID3;
        break;
      case 71:  // Gのとき
        index = isLeftCourse ? 6 : 5;
        if(isLeftCourse) blockId = BLOCK_ID ::ID3;
        break;
      case 72:  // Hのとき
        index = isLeftCourse ? 7 : 4;
        if(!isLeftCourse) blockId = BLOCK_ID ::ID2;
        break;
      case 74:  // Jのとき
        index = isLeftCourse ? 8 : 11;
        if(!isLeftCourse) blockId = BLOCK_ID ::ID5;
        break;
      case 75:  // Kのとき
        index = isLeftCourse ? 9 : 10;
        if(isLeftCourse) blockId = BLOCK_ID ::ID4;
        break;
      case 76:  // Lのとき
        index = isLeftCourse ? 10 : 9;
        if(!isLeftCourse) blockId = BLOCK_ID ::ID4;
        break;
      case 77:  // Mのとき
        index = isLeftCourse ? 11 : 8;
        if(isLeftCourse) blockId = BLOCK_ID ::ID5;
        break;
      case 80:  // Pのとき
        index = isLeftCourse ? 12 : 15;
        if(isLeftCourse) blockId = BLOCK_ID ::ID6;
        break;
      case 81:  // Qのとき
        index = isLeftCourse ? 13 : 14;
        if(!isLeftCourse) blockId = BLOCK_ID ::ID7;
        break;
      case 82:  // Rのとき
        index = isLeftCourse ? 14 : 13;
        if(isLeftCourse) blockId = BLOCK_ID ::ID7;
        break;
      case 83:  // Sのとき
        index = isLeftCourse ? 15 : 12;
        if(!isLeftCourse) blockId = BLOCK_ID ::ID6;
        break;
      default:
        index = -1;
    }
    crossCircle[index].setBlock(blockId, color);
  } else {
    //交点サークル以外の番号が来たときは何もしない
  }
}

void CourseInfo::initCourseInfo()
{
  setBlockInfo(measurer.getCourseInfo(ETROBOC_COURSE_INFO_BLOCK_POS_RED1),
               COLOR::RED);  //赤ブロック1を設置
  setBlockInfo(measurer.getCourseInfo(ETROBOC_COURSE_INFO_BLOCK_POS_RED2),
               COLOR::RED);  //赤ブロック2を設置
  setBlockInfo(measurer.getCourseInfo(ETROBOC_COURSE_INFO_BLOCK_POS_YELLOW1),
               COLOR::YELLOW);  //黄ブロック1を設置
  setBlockInfo(measurer.getCourseInfo(ETROBOC_COURSE_INFO_BLOCK_POS_YELLOW2),
               COLOR::YELLOW);  //黄ブロック2を設置
  setBlockInfo(measurer.getCourseInfo(ETROBOC_COURSE_INFO_BLOCK_POS_BLUE1),
               COLOR::BLUE);  //青ブロック1を設置
  setBlockInfo(measurer.getCourseInfo(ETROBOC_COURSE_INFO_BLOCK_POS_BLUE2),
               COLOR::BLUE);  //青ブロック2を設置
  setBlockInfo(measurer.getCourseInfo(ETROBOC_COURSE_INFO_BLOCK_POS_GREEN1),
               COLOR::GREEN);  //緑ブロック1を設置
  setBlockInfo(measurer.getCourseInfo(ETROBOC_COURSE_INFO_BLOCK_POS_GREEN2),
               COLOR::GREEN);  //緑ブロック2を設置
}

void CourseInfo::moveBlock(CIRCLE_ID circleid, BLOCK_ID blockid)
{
  if(blockCircle[static_cast<int>(circleid)].getBlock().blockId == BLOCK_ID::NONE) {
    COLOR blockColor = getNode(blockid).getBlock().blockColor;
    //移動元のブロック情報を変更
    getNode(blockid).setBlock(BLOCK_ID::NONE, COLOR::NONE);
    //移動先のブロック情報を変更
    blockCircle[static_cast<int>(circleid)].setBlock(blockid, blockColor);
  }
}

Node& CourseInfo::getNode(BLOCK_ID blockId)
{
  for(int i = 0; i < static_cast<int>(crossCircle.size()); i++) {
    if(crossCircle[i].getBlock().blockId == blockId) {
      return crossCircle[i];
    }
  }
  for(int i = 0; i < static_cast<int>(blockCircle.size()); i++) {
    if(blockCircle[i].getBlock().blockId == blockId) {
      return blockCircle[i];
    }
  }
  //交点サークルにもブロックサークルにも置かれていない時
  return centerMark;
}

BlockCircle& CourseInfo::getBlockCircle(CIRCLE_ID circleId)
{
  return blockCircle[static_cast<int>(circleId)];
}

CrossCircle& CourseInfo::getCrossCircle(int index)
{
  return crossCircle[index];
}

CenterMark& CourseInfo::getCenterMark()
{
  return centerMark;
}

bool CourseInfo::existBlock(Coordinate& coordinate)
{
  //中点の場合は必ずブロックは置かれていない
  if(coordinate.x % 2 != coordinate.y % 2) {
    return false;
  }
  for(int i = 0; i < static_cast<int>(blockCircle.size()); i++) {
    if(blockCircle[i].getCoordinate() == coordinate
       && blockCircle[i].getBlock().blockId == BLOCK_ID::NONE) {
      return false;
    }
  }
  for(int i = 0; i < static_cast<int>(crossCircle.size()); i++) {
    if(crossCircle[i].getCoordinate() == coordinate
       && crossCircle[i].getBlock().blockId == BLOCK_ID::NONE) {
      return false;
    }
  }
  return true;
}
