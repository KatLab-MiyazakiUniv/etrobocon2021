/**
 * @file DestinationList.cpp
 * @brief 運搬先決定クラス
 * @author hiroto0927, miyashita64
 */

#include "DestinationList.h"

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

  const int B_ZERO = static_cast<int>(BLOCK_ID::ID0);
  const int B_SIZE = static_cast<int>(BLOCK_ID::SIZE);

  // 全ブロックを取得
  std::array<Node, B_SIZE> blockNodes;
  for(int i = B_ZERO; i < B_SIZE; i++) {
    blockNodes[i] = bingoArea.getBlockInfo(static_cast<BLOCK_ID>(i));
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
    Coordinate blockCoord1 = bingoArea.getBlockInfo(firstBlockId).getCoordinate();
    Coordinate blockCoord2 = bingoArea.getBlockInfo(secondBlockId).getCoordinate();
    // 色がcolorなブロックサークルの座標
    Coordinate circleCoord1 = bingoArea.getBlockCircleInfo(CIRCLE_IDS[color][0]).getCoordinate();
    Coordinate circleCoord2 = bingoArea.getBlockCircleInfo(CIRCLE_IDS[color][1]).getCoordinate();

    // 各パターンの、運搬距離(マンハッタン)の合計を算出
    int pattern1 = calculateDistance(blockCoord1, circleCoord1)
                   + calculateDistance(blockCoord2, circleCoord2);
    int pattern2 = calculateDistance(blockCoord1, circleCoord2)
                   + calculateDistance(blockCoord2, circleCoord1);

    // ブロックIDをint化
    int firstBlockNumber = static_cast<int>(firstBlockId);
    int secondBlockNumber = static_cast<int>(secondBlockId);
    // 運搬距離の合計を比較し、短い方を採用する
    if(pattern1 < pattern2) {
      destinations[firstBlockNumber] = CIRCLE_IDS[color][0];
      destinations[secondBlockNumber] = CIRCLE_IDS[color][1];
    } else {
      destinations[firstBlockNumber] = CIRCLE_IDS[color][1];
      destinations[secondBlockNumber] = CIRCLE_IDS[color][0];
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