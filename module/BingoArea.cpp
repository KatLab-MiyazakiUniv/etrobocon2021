/**
 * @file BingoArea.cpp
 * @brief ビンゴエリアの情報を保持するクラス
 * @author Hisataka-Hagiyama,uchyam
 */

#include "BingoArea.h"
BingoArea::BingoArea()
{
  int index = 0, index2 = 0;  //交点サークルの番号、ブロックサークルの番号
  //交点サークルの座標、サークルの色、黒線の本数をセット
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      COLOR initCircleColor = COLOR::NONE;
      int initEfgeNumber = 0;
      if((i == 0 && j == 0) || (i == 0 && j == 3) || (i == 3 && j == 0) || (i == 3 && j == 3)) {
        initEfgeNumber = 2;
      } else if((i == 1 && j == 1) || (i == 1 && j == 2) || (i == 2 && j == 1)
                || (i == 2 && j == 2)) {
        initEfgeNumber = 4;
      } else {
        initEfgeNumber = 3;
      }
      if(i == 0 || i == 1) {
        if(j == 0 || j == 1) {
          initCircleColor = COLOR::RED;
        } else if(j == 2 || j == 3) {
          initCircleColor = COLOR::BLUE;
        }
      } else if(i == 2 || i == 3) {
        if(j == 0 || j == 1) {
          initCircleColor = COLOR::YELLOW;
        } else if(j == 2 || j == 3) {
          initCircleColor = COLOR::GREEN;
        }
      }
      crossCircle[index].setCoordinate(i, j);
      crossCircle[index].setCicleColor(initCircleColor);
      crossCircle[index].setEdgeNumber(initEfgeNumber);
      index++;
    }
  }

  //ブロックサークルの座標、サークルの色をセット
  CIRCLE_ID id = CIRCLE_ID::ID0;
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      COLOR initCircleColor = COLOR::NONE;
      if(i == 0 && j == 0) {
        initCircleColor = COLOR::YELLOW;
        id = CIRCLE_ID::ID0;
      } else if(i == 1 && j == 2) {
        initCircleColor = COLOR::YELLOW;
        id = CIRCLE_ID::ID1;
      } else if(i == 0 && j == 1) {
        initCircleColor = COLOR::GREEN;
        id = CIRCLE_ID::ID2;
      } else if(i == 2 && j == 0) {
        initCircleColor = COLOR::GREEN;
        id = CIRCLE_ID::ID3;
      } else if(i == 0 && j == 2) {
        initCircleColor = COLOR::RED;
        id = CIRCLE_ID::ID4;
      } else if(i == 2 && j == 1) {
        initCircleColor = COLOR::RED;
        id = CIRCLE_ID::ID5;
      } else if(i == 1 && j == 0) {
        initCircleColor = COLOR::BLUE;
        id = CIRCLE_ID::ID6;
      } else if(i == 2 && j == 2) {
        initCircleColor = COLOR::BLUE;
        id = CIRCLE_ID::ID7;
      } else {
        continue;
      }
      blockCircle[index2].setCoordinate(i, j);
      blockCircle[index2].setCicleColor(initCircleColor);
      blockCircle[index2].setCircleId(id);
      index2++;
    }
  }
  centerMark.setCicleColor(COLOR::BLACK);
}

void BingoArea::setBlockInfo(int info, COLOR color)
{
  int index = 0;
  BLOCK_ID blockId = BLOCK_ID::ID0;
  if(info >= 65 && info <= 83) {
    //交点サークルの場合
    switch(info) {
      case 65:  // Aのとき
        index = IS_LEFT_COURSE ? 0 : 3;
        break;
      case 66:  // Bのとき
        index = IS_LEFT_COURSE ? 1 : 2;
        blockId = BLOCK_ID ::ID0;
        break;
      case 67:  // Cのとき
        index = IS_LEFT_COURSE ? 2 : 1;
        break;
      case 68:  // Dのとき
        index = IS_LEFT_COURSE ? 3 : 0;
        blockId = BLOCK_ID ::ID1;
        break;
      case 69:  // Eのとき
        index = IS_LEFT_COURSE ? 4 : 7;
        blockId = BLOCK_ID ::ID2;
        break;
      case 70:  // Fのとき
        index = IS_LEFT_COURSE ? 5 : 6;
        break;
      case 71:  // Gのとき
        index = IS_LEFT_COURSE ? 6 : 5;
        blockId = BLOCK_ID ::ID3;
        break;
      case 72:  // Hのとき
        index = IS_LEFT_COURSE ? 7 : 4;
        break;
      case 74:  // Jのとき
        index = IS_LEFT_COURSE ? 8 : 11;
        break;
      case 75:  // Kのとき
        index = IS_LEFT_COURSE ? 9 : 10;
        blockId = BLOCK_ID ::ID4;
        break;
      case 76:  // Lのとき
        index = IS_LEFT_COURSE ? 10 : 9;
        break;
      case 77:  // Mのとき
        index = IS_LEFT_COURSE ? 11 : 8;
        blockId = BLOCK_ID ::ID5;
        break;
      case 80:  // Pのとき
        index = IS_LEFT_COURSE ? 12 : 15;
        blockId = BLOCK_ID ::ID6;
        break;
      case 81:  // Qのとき
        index = IS_LEFT_COURSE ? 13 : 14;
        break;
      case 82:  // Rのとき
        index = IS_LEFT_COURSE ? 14 : 13;
        blockId = BLOCK_ID ::ID7;
        break;
      case 83:  // Sのとき
        index = IS_LEFT_COURSE ? 15 : 12;
        break;
      default:
        index = -1;
    }
    crossCircle[index].setBlock(blockId, color);
  } else {
    //ブロックサークル以外の番号が来たときは何もしない
  }
}

void BingoArea::initBingoArea()
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

Node& BingoArea::getBlockInfo(BLOCK_ID blockId)
{
  for(int i = 0; i < 16; i++) {
    if(crossCircle[i].getBlock().blockId == blockId) {
      return crossCircle[i];
    }
  }
  for(int i = 0; i < 8; i++) {
    if(blockCircle[i].getBlock().blockId == blockId) {
      return blockCircle[i];
    }
  }
}

BlockCircle& BingoArea::getBlockCircleInfo(CIRCLE_ID circleId)
{
  return blockCircle[static_cast<int>(circleId)];
}

CrossCircle& BingoArea::getCrossCircleInfo(int index)
{
  return crossCircle[index];
}

// for Test
// x座標　y座標　ブロックの色　サークルの色 黒線の本数
void BingoArea::printinfo()
{
  for(int i = 0; i < 8; i++) {
    printf("%d %d %d %d\n", blockCircle[i].getCoordinate().x, blockCircle[i].getCoordinate().y,
           blockCircle[i].getBlock().blockColor, blockCircle[i].getCircleColor());
  }
}
