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
  std::array<std::array<CircleId, 2>, 4> CIRCLES{ {
      { CircleId::C_2, CircleId::C_7 },  // RED
      { CircleId::C_3, CircleId::C_8 },  // BLUE
      { CircleId::C_0, CircleId::C_5 },  // YELLOW
      { CircleId::C_1, CircleId::C_6 },  // GREEN
  } };

  const int B_ZERO = static_cast<int>(BlockId::B_0);
  const int B_SIZE = static_cast<int>(BlockId::SIZE);

  // 全ブロックを取得
  std::array<Node, B_SIZE> blockNodes;
  for(int i = B_ZERO; i < B_SIZE; i++) {
    blockNodes[i] = bingoArea.getBlockInfo(static_cast<BlockId>(i));
  }

  // 各色について合計距離が短い組み合わせを探索する
  for(int color = 0; color < 4; color++) {
    // 色がcolorな、2つのブロックを探索
    int first = -1;
    for(int i = B_ZERO; i < B_SIZE; i++) {
      // 色がcolorでなければ、次のブロックへ
      if(blockNodes[i].getBlock().blockColor != COLORS[color]) {
        printf("%d != %d\n", blockNodes[i].getBlock().blockColor, COLORS[color]);
        continue;
      }
      if(first == -1) {  // 1つめ
        first = i;
      } else {  // 2つめ
        // 色がcolorなブロック１の座標
        Coordinate blockCoord1
            = bingoArea.getBlockInfo(static_cast<BlockId>(first)).getCoordinate();
        // 色がcolorなブロック２の座標
        Coordinate blockCoord2 = bingoArea.getBlockInfo(static_cast<BlockId>(i)).getCoordinate();
        // 色がcolorなブロックサークル１の座標
        Coordinate circleCoord1 = convertCircleCoordinate(CIRCLES[color][0]);
        // 色がcolorなブロックサークル２の座標
        Coordinate circleCoord2 = convertCircleCoordinate(CIRCLES[color][1]);

        // 各パターンの、マンハッタン距離の合計を算出
        int pattern1 = calculateDistance(blockCoord1, circleCoord1)
                       + calculateDistance(blockCoord2, circleCoord2);
        int pattern2 = calculateDistance(blockCoord1, circleCoord2)
                       + calculateDistance(blockCoord2, circleCoord1);
        // 運送距離の合計を比較し、短い方を採用する
        if(pattern1 < pattern2) {
          destinations[first] = CIRCLES[color][0];
          destinations[i] = CIRCLES[color][1];
        } else {
          destinations[first] = CIRCLES[color][1];
          destinations[i] = CIRCLES[color][0];
        }
        // 探索を次の色に移す
        break;
      }
    }
  }
}

// 指定されたブロックの運搬先サークルIDを返す
CircleId DestinationList::getDestination(BlockId blockId)
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

// サークルIDに対応する座標を返す
Coordinate DestinationList::convertCircleCoordinate(CircleId _circleId)
{
  int circleId = static_cast<int>(_circleId);
  Coordinate coordinate = { 0, 0 };
  coordinate.x = (circleId % 3) * 2 + 1;
  coordinate.y = (circleId / 3) * 2 + 1;
  return coordinate;
}