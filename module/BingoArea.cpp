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
      leftCrossCircle[index].setCoordinate(i, j);
      if((i == 0 && j == 0) || (i == 0 && j == 3) || (i == 3 && j == 0) || (i == 3 && j == 3)) {
        leftCrossCircle[index].setEdgeNumber(2);
      } else if((i == 1 && j == 1) || (i == 1 && j == 2) || (i == 2 && j == 1)
                || (i == 2 && j == 2)) {
        leftCrossCircle[index].setEdgeNumber(4);
      } else {
        leftCrossCircle[index].setEdgeNumber(3);
      }
      if(i == 0 || i == 1) {
        if(j == 0 || j == 1) {
          leftCrossCircle[index].setCicleColor(COLOR::RED);
        } else if(j == 2 || j == 3) {
          leftCrossCircle[index].setCicleColor(COLOR::BLUE);
        }
      } else if(i == 2 || i == 3) {
        if(j == 0 || j == 1) {
          leftCrossCircle[index].setCicleColor(COLOR::YELLOW);
        } else if(j == 2 || j == 3) {
          leftCrossCircle[index].setCicleColor(COLOR::GREEN);
        }
      }
      index++;
    }
  }
  //ブロックサークルの座標、サークルの色をセット
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      leftBlockCircle[index2].setCoordinate(i, j);
      if((i == 0 && j == 0) || (i == 1 && j == 2)) {
        leftBlockCircle[index2].setCicleColor(COLOR::YELLOW);
      } else if((i == 0 && j == 1) || (i == 2 && j == 0)) {
        leftBlockCircle[index2].setCicleColor(COLOR::GREEN);
      } else if((i == 0 && j == 2) || (i == 2 && j == 1)) {
        leftBlockCircle[index2].setCicleColor(COLOR::RED);
      } else if((i == 1 && j == 0) || (i == 2 && j == 2)) {
        leftBlockCircle[index2].setCicleColor(COLOR::BLUE);
      } else {
        index2--;
      }
      index2++;
    }
  }
}

void BingoArea::setBlockInfo(int info, int blockId, COLOR color)
{
  int index = 0, index2 = 0;
  if(info >= 65 && info <= 83) {
    //交点サークルの場合
    switch(info) {
      case 65:  // Aのとき
        index = 0;
        break;
      case 66:  // Bのとき
        index = 1;
        break;
      case 67:  // Cのとき
        index = 2;
        break;
      case 68:  // Dのとき
        index = 3;
        break;
      case 69:  // Eのとき
        index = 4;
        break;
      case 70:  // Fのとき
        index = 5;
        break;
      case 71:  // Gのとき
        index = 6;
        break;
      case 72:  // Hのとき
        index = 7;
        break;
      case 74:  // Jのとき
        index = 8;
        break;
      case 75:  // Kのとき
        index = 9;
        break;
      case 76:  // Lのとき
        index = 10;
        break;
      case 77:  // Mのとき
        index = 11;
        break;
      case 80:  // Pのとき
        index = 12;
        break;
      case 81:  // Qのとき
        index = 13;
        break;
      case 82:  // Rのとき
        index = 14;
        break;
      case 83:  // Sのとき
        index = 15;
        break;
    }
    IS_LEFT_COURSE ? leftCrossCircle[index].setBlock(blockId, color)
                   : rightCrossCircle[index].setBlock(blockId, color);
  } else if(info >= 49 && info <= 57) {
    //ブロックサークルの場合
    switch(info) {
      case 49:  // 1のとき
        index2 = 0;
        break;
      case 50:  // 2のとき
        index2 = 1;
        break;
      case 51:  // 3のとき
        index2 = 2;
        break;
      case 52:  // 4のとき
        index2 = 3;
        break;
      case 53:  // 5のとき
        index2 = 4;
        break;
      case 54:  // 6のとき
        index2 = 5;
        break;
      case 55:  // 7のとき
        index2 = 6;
        break;
      case 56:  // 8のとき
        index2 = 7;
        break;
    }
    IS_LEFT_COURSE ? leftBlockCircle[index2].setBlock(blockId, color)
                   : rightBlockCircle[index2].setBlock(blockId, color);
  }
}

void BingoArea::setBingoArea()
{
  setBlockInfo(measurer.getCourseInfo(ETROBOC_COURSE_INFO_BLOCK_POS_RED1), 2,
               COLOR::RED);  //赤ブロック1を設置
  setBlockInfo(measurer.getCourseInfo(ETROBOC_COURSE_INFO_BLOCK_POS_RED2), 5,
               COLOR::RED);  //赤ブロック2を設置
  setBlockInfo(measurer.getCourseInfo(ETROBOC_COURSE_INFO_BLOCK_POS_YELLOW1), 0,
               COLOR::YELLOW);  //黄ブロック1を設置
  setBlockInfo(measurer.getCourseInfo(ETROBOC_COURSE_INFO_BLOCK_POS_YELLOW2), 4,
               COLOR::YELLOW);  //黄ブロック2を設置
  setBlockInfo(measurer.getCourseInfo(ETROBOC_COURSE_INFO_BLOCK_POS_BLUE1), 1,
               COLOR::BLUE);  //青ブロック1を設置
  setBlockInfo(measurer.getCourseInfo(ETROBOC_COURSE_INFO_BLOCK_POS_BLUE2), 7,
               COLOR::BLUE);  //青ブロック2を設置
  setBlockInfo(measurer.getCourseInfo(ETROBOC_COURSE_INFO_BLOCK_POS_GREEN1), 3,
               COLOR::GREEN);  //緑ブロック1を設置
  setBlockInfo(measurer.getCourseInfo(ETROBOC_COURSE_INFO_BLOCK_POS_GREEN2), 6,
               COLOR::GREEN);  //緑ブロック2を設置
}

Node& BingoArea::getBlockInfo(int blockId)
{
  for(int i = 0; i < 16; i++) {
    if(IS_LEFT_COURSE) {
      if(leftCrossCircle[i].getBlock().blockId == blockId) {
        return leftCrossCircle[i];
      }
    } else {
      if(rightCrossCircle[i].getBlock().blockId == blockId) {
        return rightCrossCircle[i];
      }
    }
  }
  for(int i = 0; i < 8; i++) {
    if(IS_LEFT_COURSE) {
      if(leftBlockCircle[i].getBlock().blockId == blockId) {
        return leftBlockCircle[i];
      }
    } else {
      if(rightBlockCircle[i].getBlock().blockId == blockId) {
        return rightBlockCircle[i];
      }
    }
  }
}

// for Test
// x座標　y座標　ブロックの色　サークルの色 黒線の本数
void BingoArea::printinfo()
{
  for(int i = 0; i < 8; i++) {
    printf("%d %d %d %d\n", leftBlockCircle[i].getCoordinate().x,
           leftBlockCircle[i].getCoordinate().y, leftBlockCircle[i].getBlock().blockColor,
           leftBlockCircle[i].getCircleColor());
  }
}
