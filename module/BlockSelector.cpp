/**
 * @file BlockSelector.h
 * @brief 運搬ブロック決定クラス
 * @author hiroto0927, miyashita64
 */

#include "BlockSelector.h"

BlockSelector::BlockSelector(BingoArea& bingoArea)
  : bingoArea(bingoArea),
    arrivableBlocks{ T, F, T, T, T, F, F, F },
    arrivableCircles{
      T, T, F, T, T, F, F, F, F,
    }
{
}

BlockId BlockSelector::selectBlockId()
{
  int i;
  BlockId bestBlockId;
  int minDist = 100;
  int maxCrossLine = 0;
  int maxDirectPoint = -1;
  Robot robot;

  for(i = 0; i < BLOCK_LENGTH; i++) {
    BlockId blockNumber = static_cast<BlockId>(i);

    // 運搬済みだった場合
    if(isCarriedBlock(blockNumber)) continue;

    // 取得可能ブロックの判定
    if(!arrivableBlocks[i]) continue;

    // 運搬可能ブロックの判定
    // blockNumberが指すブロックの、運搬先サークル番号を取得
    int targetCircle = static_cast<int>(destinationList.getDestination(blockNumber));
    // 現在いけるブロックサークル
    // または　対象ブロックを動かしたときに行けるようになるブロックサークル
    if(!(arrivableCircles[targetCircle] || OPEN_CIRCLE[i][targetCircle])) continue;

    // ブロックを取りに行く距離(ここで計算)+ブロックを運ぶ距離(DestinationListから取得)　の和を計算
    &Node targetBlock = bingoArea.getBlockInfo();
    Coordinate robotCoord = robot.getCoordinate();
    int distance = std::abs(robotCoord.x - targetBlock.coordinate.x)
                   - std::abs(robotCoord.y - targetBlock.coordinate.y);
    if(distance > minDist) continue;
    minDist = distance;

    // 運ぶブロックがある場所に交わっている黒線の数を取得(BingoAreaから取得)
    CrossCircle crossCircle = bingoArea.getEdgeNumber();
    if(crossCircle.crossLine < maxCrossLine) continue;
    maxCrossLine = crossCircle.crossLine;

    // 走行体の向きの進路を優先する(RunningInfoから取得)
    // 走行体の進行方向
    Direction robotDirection = robot.getDirection();
    int rdx = static_cast<int>(robotDirection) % 3 - 1;  // dx 1,0,-1
    int rdy = static_cast<int>(robotDirection) / 3 - 1;  // dy 1,0,-1
    // 目標ブロックへの方向
    int dx = robotCoord.x - targetBlock.coordinate.x;
    int dy = robotCoord.y - targetBlock.coordinate.y;
    int directPoint = 0;
    if(dy * rdy > 0) directPoint++;  // yの進行方向が合致していれば、評価を上げる
    if(dx * rdx > 0) directPoint++;  // xの進行方向が合致していれば、評価を上げる
    if(directPoint < maxDirectPoint) continue;
    maxDirectPoint = directPoint;

    // ここまで、同じであれば、処理順
    bestBlockId = blockNumber;
  }

  return bestBlockId;
}

// 指定されたブロックが運搬済みかを判定する
bool BlockSelector::isCarriedBlock(BlockNumber blockNumber)
{
  Block block = bingoArea.getBlockInfo(blockNumber);
  Coordinate coord = block.getCoorinate();
  return (coord.x % 2 == 1 && coord.y % 2 == 1);
}