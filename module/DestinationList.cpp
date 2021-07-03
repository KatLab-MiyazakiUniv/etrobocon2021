/**
 * @file DestinationList.cpp
 * @brief 運搬先決定クラス
 * @author hiroto0927, miyashita64
 */

#include "DestinationList.h"

// コンストラクタ
DestinationList::DestinationList()
{
  std::array<Block, BLOCK_SIZE> blocks;
  const std::array<COLOR, 4> COLORS = { COLOR::RED, COLOR::BLUE, COLOR::YELLOW, COLOR::GREEN };
  // 赤、青、黄、緑のブロックサークル番号
  std::array<std::array<int, 2>, 4> CIRCLES{ { { 2, 7 }, { 3, 8 }, { 0, 5 }, { 1, 6 } } };

  // 全ブロックを取得
  for(int i = 0; i < BLOCK_SIZE; i++) {
    blocks[i] = BingoArea::getBlockInfo(convertBlockCoordinate(i));
  }

  // 各色について合計距離が短い組み合わせを探索する
  for(int color = 0; color < 4; color++) {
    int tmp = -1;
    // 色がcolorな、2つのブロックを探索
    for(int i = 0; i < BLOCK_SIZE; i++) {
      if(blocks[i].color == COLORS[color]) {
        if(tmp < 0) {  // 1つめ
          tmp = i;
          destinations[tmp] = CIRCLES[color][0];
        } else {  // 2つめ
          destinations[i] = CIRCLES[color][1];
          // 各パターンの、マンハッタン距離の合計を算出
          int pattern1
              = calculateDistance(tmp, CIRCLES[color][0]) + calculateDistance(i, CIRCLES[color][1]);
          int pattern2
              = calculateDistance(tmp, CIRCLES[color][1]) + calculateDistance(i, CIRCLES[color][0]);
          // 運送距離の合計を比較し、短い方を採用する
          if(pattern1 < pattern2) {
            destinations[tmp] = CIRCLES[color][0];
            destinations[i] = CIRCLES[color][1];
          } else {
            destinations[tmp] = CIRCLES[color][1];
            destinations[i] = CIRCLES[color][0];
          }
          break;
        }
      }
    }
  }
}

int DestinationList::getDestination(int blockNumber)
{
  return destinations[blockNumber];
}

// ブロックとサークル間のマンハッタン距離を計算する
int DestinationList::calculateDistance(int blockNumber, int circleNumber)
{
  Coordinate blockCoord = convertBlockCoordinate(blockNumber);
  Coordinate circleCoord = convertCircleCoordinate(circleNumber);
  int dx = std::abs(blockCoord.x - circleCoord.x);
  int dy = std::abs(blockCoord.y - circleCoord.y);
  return dx + dy;
}

// ブロック番号に対応する座標を返す
Coordinate DestinationList::convertBlockCoordinate(int blockNumber)
{
  Coordinate coordinate = { 0, 0 };
  int tmp = blockNumber % 4;
  coordinate.x = (tmp == 0) ? 2 : (tmp == 1) ? 6 : (tmp == 2) ? 0 : 4;
  coordinate.y = (blockNumber / 2) * 2;
  return coordinate;
}

// サークル番号に対応する座標を返す
Coordinate DestinationList::convertCircleCoordinate(int circleNumber)
{
  Coordinate coordinate = { 0, 0 };
  coordinate.x = (circleNumber % 3) * 2 + 1;
  coordinate.y = (circleNumber / 3) * 2 + 1;
  return coordinate;
}