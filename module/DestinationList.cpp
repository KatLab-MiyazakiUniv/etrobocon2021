/**
 * @file DestinationList.cpp
 * @brief 運搬先決定クラス
 * @author hiroto0927, miyashita64
 */

#include "DestinationList.h"

// コンストラクタ 全ブロックの運搬先を決定する
DestinationList::DestinationList()
{
  // 赤、青、黄、緑のブロックサークル番号
  const std::array<COLOR, 4> COLORS = { COLOR::RED, COLOR::BLUE, COLOR::YELLOW, COLOR::GREEN };
  std::array<std::array<CircleNumber, 2>, 4> CIRCLES{ {
      { CircleNumber::C_2, CircleNumber::C_7 },  // RED
      { CircleNumber::C_3, CircleNumber::C_8 },  // BLUE
      { CircleNumber::C_0, CircleNumber::C_5 },  // YELLOW
      { CircleNumber::C_1, CircleNumber::C_6 },  // GREEN
  } };

  // 全ブロックを取得
  std::array<Block, BLOCK_LENGTH> blocks;
  for(int i = 0; i < BLOCK_LENGTH; i++) {
    blocks[i] = bingoArea.getBlockInfo(static_cast<BlockNumber>(i));
  }

  // 各色について合計距離が短い組み合わせを探索する
  for(int color = 0; color < 4; color++) {
    // 色がcolorな、2つのブロックを探索
    int first = -1;
    for(int i = 0; i < BLOCK_LENGTH; i++) {
      if(blocks[i].color != COLORS[color]) continue;
      if(first == -1) {  // 1つめ
        first = i;
      } else {  // 2つめ
        // 各パターンの、マンハッタン距離の合計を算出
        int pattern1 = calculateDistance(static_cast<BlockNumber>(first), CIRCLES[color][0])
                       + calculateDistance(static_cast<BlockNumber>(i), CIRCLES[color][1]);
        int pattern2 = calculateDistance(static_cast<BlockNumber>(first), CIRCLES[color][1])
                       + calculateDistance(static_cast<BlockNumber>(i), CIRCLES[color][0]);
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

// 指定されたブロックの運搬先サークル番号を返す
CircleNumber DestinationList::getDestination(BlockNumber blockNumber)
{
  return destinations[static_cast<int>(blockNumber)];
}

// ブロックとサークル間のマンハッタン距離を計算する
int DestinationList::calculateDistance(BlockNumber blockNumber, CircleNumber circleNumber)
{
  Coordinate blockCoord = convertBlockCoordinate(blockNumber);
  Coordinate circleCoord = convertCircleCoordinate(circleNumber);
  int dx = std::abs(blockCoord.x - circleCoord.x);
  int dy = std::abs(blockCoord.y - circleCoord.y);
  return dx + dy;
}

// BingoAreaから取得できる？
// ブロック番号に対応する座標を返す
Coordinate DestinationList::convertBlockCoordinate(BlockNumber blockNumber)
{
  Coordinate coordinate = { 0, 0 };
  int number = static_cast<int>(blockNumber);
  int tmp = number % 4;
  coordinate.x = (tmp == 0) ? 2 : (tmp == 1) ? 6 : (tmp == 2) ? 0 : 4;
  coordinate.y = (number / 2) * 2;
  return coordinate;
}

// サークル番号に対応する座標を返す
Coordinate DestinationList::convertCircleCoordinate(CircleNumber circleNumber)
{
  Coordinate coordinate = { 0, 0 };
  int number = static_cast<int>(circleNumber);
  coordinate.x = (number % 3) * 2 + 1;
  coordinate.y = (number / 3) * 2 + 1;
  return coordinate;
}