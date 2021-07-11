/**
 * @file DestinationList.cpp
 * @brief 運搬先決定クラス
 * @author hiroto0927, miyashita64
 */

#include "DestinationList.h"
//*
// コンストラクタ 全ブロックの運搬先を決定する
DestinationList::DestinationList(BingoArea& bingoArea)
{
  // 赤、青、黄、緑のブロックサークルID
  const std::array<COLOR, 4> COLORS = { COLOR::RED, COLOR::BLUE, COLOR::YELLOW, COLOR::GREEN };
  std::array<std::array<CIRCLE_ID, 2>, 4> CIRCLE_IDS{ {
      { CIRCLE_ID::ID2, CIRCLE_ID::ID6 },  // RED
      { CIRCLE_ID::ID3, CIRCLE_ID::ID7 },  // BLUE
      { CIRCLE_ID::ID0, CIRCLE_ID::ID4 },  // YELLOW
      { CIRCLE_ID::ID1, CIRCLE_ID::ID5 },  // GREEN
  } };

  const int NUMZERO = static_cast<int>(BLOCK_ID::ID0);
  const int NUMSIZE = static_cast<int>(BLOCK_ID::SIZE);

  // 全ブロックを取得
  std::array<Node, NUMSIZE> blockNodes;
  for(int i = NUMZERO; i < NUMSIZE; i++) {
    blockNodes[i] = bingoArea.getBlockInfo(static_cast<BLOCK_ID>(i));
  }

  // 各色について合計距離が短い組み合わせを探索する
  for(int color = 0; color < 4; color++) {
    // 色がcolorな、2つのブロックを探索
    int first = -1;
    for(int i = NUMZERO; i < NUMSIZE; i++) {
      // 色がcolorでなければ、次のブロックへ
      if(blockNodes[i].getBlock().blockColor != COLORS[color]) continue;
      if(first == -1) {  // 1つめ
        first = i;
      } else {  // 2つめ
        // 色がcolorなブロック１の座標
        Coordinate blockCoord1
            = bingoArea.getBlockInfo(static_cast<BLOCK_ID>(first)).getCoordinate();
        // 色がcolorなブロック２の座標
        Coordinate blockCoord2 = bingoArea.getBlockInfo(static_cast<BLOCK_ID>(i)).getCoordinate();
        // 色がcolorなブロックサークル１の座標
        Coordinate circleCoord1
            = bingoArea.getBlockCircleInfo(CIRCLE_IDS[color][0]).getCoordinate();
        // 色がcolorなブロックサークル２の座標
        Coordinate circleCoord2
            = bingoArea.getBlockCircleInfo(CIRCLE_IDS[color][1]).getCoordinate();

        // 各パターンの、マンハッタン距離の合計を算出
        int pattern1 = calculateDistance(blockCoord1, circleCoord1)
                       + calculateDistance(blockCoord2, circleCoord2);
        int pattern2 = calculateDistance(blockCoord1, circleCoord2)
                       + calculateDistance(blockCoord2, circleCoord1);
        // 運送距離の合計を比較し、短い方を採用する
        if(pattern1 < pattern2) {
          destinations[first] = CIRCLE_IDS[color][0];
          destinations[i] = CIRCLE_IDS[color][1];
        } else {
          destinations[first] = CIRCLE_IDS[color][1];
          destinations[i] = CIRCLE_IDS[color][0];
        }
        // 探索を次の色に移す
        break;
      }
    }
  }
}

// 指定されたブロックの運搬先サークルIDを返す
CIRCLE_ID DestinationList::getDestination(BLOCK_ID blockId)
{
  return destinations[static_cast<int>(blockId)];
}

// 座標間のマンハッタン距離を計算する
int DestinationList::calculateDistance(Coordinate& blockCoord, Coordinate& circleCoord)
{
  int dx = std::abs(blockCoord.x - circleCoord.x);
  int dy = std::abs(blockCoord.y - circleCoord.y);
  return dx + dy;
}