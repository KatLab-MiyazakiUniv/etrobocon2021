/**
 * @file DestinationList.cpp
 * @brief 運搬先決定クラス
 * @author hiroto0927, miyashita64
 */

#include "DestinationList.h"

// コンストラクタ 全ブロックの運搬先を決定する
DestinationList::DestinationList(CourseInfo& courseInfo)
{
  // 赤、青、黄、緑のブロックサークルID
  const std::array<COLOR, 4> COLORS = { COLOR::RED, COLOR::BLUE, COLOR::YELLOW, COLOR::GREEN };
  std::array<std::array<CIRCLE_ID, 2>, 4> CIRCLE_IDS{ {
      { CIRCLE_ID::ID2, CIRCLE_ID::ID6 },  // RED
      { CIRCLE_ID::ID3, CIRCLE_ID::ID7 },  // BLUE
      { CIRCLE_ID::ID0, CIRCLE_ID::ID4 },  // YELLOW
      { CIRCLE_ID::ID1, CIRCLE_ID::ID5 },  // GREEN
  } };

  const int B_ZERO = static_cast<int>(BLOCK_ID::ID0);
  const int B_SIZE = static_cast<int>(BLOCK_ID::ID7) + 1;

  // 全ブロックを取得
  std::array<Node, B_SIZE> blockNodes;
  for(int i = B_ZERO; i < B_SIZE; i++) {
    blockNodes[i] = courseInfo.getNode(static_cast<BLOCK_ID>(i));
  }

  // 各色について合計距離が短い組み合わせを探索する
  for(int color = 0; color < 4; color++) {
    BLOCK_ID firstBlockId = BLOCK_ID::NONE;
    BLOCK_ID secondBlockId = BLOCK_ID::NONE;

    // 色がcolorな、2つのブロックを探索
    for(int i = B_ZERO; i < B_SIZE; i++) {
      // 色がcolorなブロックを発見した場合
      if(blockNodes[i].getBlock().blockColor == COLORS[color]) {
        if(firstBlockId == BLOCK_ID::NONE) {  // 1つめ
          firstBlockId = static_cast<BLOCK_ID>(i);
        } else {  // 2つめ
          secondBlockId = static_cast<BLOCK_ID>(i);
          break;
        }
      }
    }

    // 色がcolorなブロックの座標
    Coordinate blockCoord1 = courseInfo.getNode(firstBlockId).getCoordinate();
    Coordinate blockCoord2 = courseInfo.getNode(secondBlockId).getCoordinate();
    // 色がcolorなブロックサークルの座標
    Coordinate circleCoord1 = courseInfo.getBlockCircle(CIRCLE_IDS[color][0]).getCoordinate();
    Coordinate circleCoord2 = courseInfo.getBlockCircle(CIRCLE_IDS[color][1]).getCoordinate();

    // 各パターンの、運搬距離(マンハッタン)の合計を算出
    int pattern1 = calculateDistance(blockCoord1, circleCoord1)
                   + calculateDistance(blockCoord2, circleCoord2);
    int pattern2 = calculateDistance(blockCoord1, circleCoord2)
                   + calculateDistance(blockCoord2, circleCoord1);

    // ブロックIDをint化
    int firstBlockNumber = static_cast<int>(firstBlockId);
    int secondBlockNumber = static_cast<int>(secondBlockId);
    // 運搬距離の合計を比較し、短い方を採用するが、詰みパターン対処のためにもう片方の運搬先も保持しておく
    if(pattern1 < pattern2) {
      destinations[firstBlockNumber][0] = CIRCLE_IDS[color][0];
      destinations[secondBlockNumber][0] = CIRCLE_IDS[color][1];
      destinations[firstBlockNumber][1] = CIRCLE_IDS[color][1];
      destinations[secondBlockNumber][1] = CIRCLE_IDS[color][0];
    } else {
      destinations[firstBlockNumber][0] = CIRCLE_IDS[color][1];
      destinations[secondBlockNumber][0] = CIRCLE_IDS[color][0];
      destinations[firstBlockNumber][1] = CIRCLE_IDS[color][0];
      destinations[secondBlockNumber][1] = CIRCLE_IDS[color][1];
    }
  }
}

// 指定されたブロックの運搬先サークルIDを返す
CIRCLE_ID DestinationList::getDestination(BLOCK_ID blockId)
{
  return destinations[static_cast<int>(blockId)][0];
}

// 指定されたブロックのもう1つの運搬先サークルIDを返す
CIRCLE_ID DestinationList::getDestinationAlt(BLOCK_ID blockId)
{
  return destinations[static_cast<int>(blockId)][1];
}

// 座標間のマンハッタン距離を計算する
int DestinationList::calculateDistance(Coordinate& blockCoord, Coordinate& circleCoord)
{
  int dx = std::abs(blockCoord.x - circleCoord.x);
  int dy = std::abs(blockCoord.y - circleCoord.y);
  return dx + dy;
}

void DestinationList::swapDestination(BLOCK_ID blockId)
{
  int id = static_cast<int>(blockId);
  for(int i = 0; i <= static_cast<int>(BLOCK_ID::ID7); i++) {
    if(destinations[i][1] == destinations[static_cast<int>(id)][0]) {
      CIRCLE_ID tmp = destinations[id][0];
      CIRCLE_ID tmp1 = destinations[id][1];
      destinations[id][0] = destinations[i][0];
      destinations[id][1] = destinations[i][1];
      destinations[i][0] = tmp;
      destinations[i][1] = tmp1;
    }
  }
}
