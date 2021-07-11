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
  for(int i = 0; i < 7; i += 2) {
    for(int j = 0; j < 7; j += 2) {
      COLOR initCircleColor = COLOR::NONE;
      int initEfgeNumber = 0;
      if((i == 0 && j == 0) || (i == 0 && j == 6) || (i == 6 && j == 0) || (i == 6 && j == 6)) {
        initEfgeNumber = 2;
      } else if((i == 2 && j == 2) || (i == 2 && j == 4) || (i == 4 && j == 2)
                || (i == 4 && j == 4)) {
        initEfgeNumber = 4;
      } else {
        initEfgeNumber = 3;
      }
      if(i == 0 || i == 2) {
        if(j == 0 || j == 2) {
          initCircleColor = COLOR::RED;
        } else if(j == 4 || j == 6) {
          initCircleColor = COLOR::BLUE;
        }
      } else if(i == 4 || i == 6) {
        if(j == 0 || j == 2) {
          initCircleColor = COLOR::YELLOW;
        } else if(j == 4 || j == 6) {
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
  for(int i = 1; i < 6; i += 2) {
    for(int j = 1; j < 6; j += 2) {
      COLOR initCircleColor = COLOR::NONE;
      if(i == 1 && j == 1) {
        initCircleColor = COLOR::YELLOW;
        id = CIRCLE_ID::ID0;
      } else if(i == 1 && j == 3) {
        initCircleColor = COLOR::GREEN;
        id = CIRCLE_ID::ID1;
      } else if(i == 1 && j == 5) {
        initCircleColor = COLOR::RED;
        id = CIRCLE_ID::ID2;
      } else if(i == 3 && j == 1) {
        initCircleColor = COLOR::BLUE;
        id = CIRCLE_ID::ID3;
      } else if(i == 3 && j == 5) {
        initCircleColor = COLOR::YELLOW;
        id = CIRCLE_ID::ID4;
      } else if(i == 5 && j == 1) {
        initCircleColor = COLOR::GREEN;
        id = CIRCLE_ID::ID5;
      } else if(i == 5 && j == 3) {
        initCircleColor = COLOR::RED;
        id = CIRCLE_ID::ID6;
      } else if(i == 5 && j == 5) {
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
  centerMark.setCoordinate(3, 3);
  centerMark.setCicleColor(COLOR::BLACK);
}

void BingoArea::setBlockInfo(int info, COLOR color)
{
  int index = 0;
  BLOCK_ID blockId = BLOCK_ID::ID0;
  if(info >= 65 && info <= 83 && info != 73 && info != 78 && info != 79) {
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

void BingoArea::moveBlock(CIRCLE_ID circleid, BLOCK_ID blockid)
{
  if(blockCircle[static_cast<int>(circleid)].getBlock().blockId == BLOCK_ID::NONE) {
    COLOR blockColor = getBlockInfo(blockid).getBlock().blockColor;
    //移動元のブロック情報を変更
    getBlockInfo(blockid).setBlock(BLOCK_ID::NONE, COLOR::NONE);
    //移動先のブロック情報を変更
    blockCircle[static_cast<int>(circleid)].setBlock(blockid, blockColor);
  }
}

Node& BingoArea::getBlockInfo(BLOCK_ID blockId)
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

BlockCircle& BingoArea::getBlockCircleInfo(CIRCLE_ID circleId)
{
  return blockCircle[static_cast<int>(circleId)];
}

CrossCircle& BingoArea::getCrossCircleInfo(int index)
{
  return crossCircle[index];
}

CenterMark& BingoArea::getCenterMarkInfo()
{
  return centerMark;
}