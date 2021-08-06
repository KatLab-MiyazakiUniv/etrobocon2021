/**
 * @file BlockSelector.cpp
 * @brief 運搬ブロック決定クラス
 * @author hiroto0927, miyashita64
 */

#include "BlockSelector.h"

// コンストラクタ
BlockSelector::BlockSelector(BingoArea& _bingoArea, DestinationList& _destination, Robot& _robot)
  : bingoArea(_bingoArea),
    destinationList(_destination),
    robot(_robot),
    arrivableBlocks{ T, F, T, T, T, F, F, F },
    arrivableCircles{ T, T, F, T, F, F, F, F },
    OPEN_CIRCLE_ID{ {
        { T, T, T, T, F, F, F, F },
        { F, T, T, F, T, F, F, F },
        { T, T, F, T, F, T, F, F },
        { T, T, T, T, T, F, T, T },
        { T, T, F, T, T, T, T, T },
        { F, F, T, F, T, F, T, T },
        { F, F, F, T, F, T, T, F },
        { F, F, F, F, T, T, T, T },
    } },
    OPEN_BLOCK_ID{ {
        { T, T, T, T, T, F, F, F },
        { T, T, F, T, F, T, F, F },
        { T, F, T, T, T, F, T, F },
        { T, T, T, T, T, T, F, T },
        { T, F, T, T, T, T, T, T },
        { F, T, F, T, T, T, F, T },
        { F, F, T, F, T, F, T, T },
        { F, F, F, T, T, T, T, T },
    } }

{
}

// 運搬するブロックを決定する
BLOCK_ID BlockSelector::selectBlock()
{
  int i;
  BLOCK_ID bestBlockId = BLOCK_ID::NONE;  // 最善と思われる運搬ブロック候補
  int minDist = 100;                      // 候補の運搬距離
  int maxCrossLine = 0;                   // 候補の交線数
  int maxDirectPoint = -1;  // 候補と走行体の進行方向についての評価点
  bool updateFg = false;

  const int B_ZERO = static_cast<int>(BLOCK_ID::ID0);
  const int B_SIZE = static_cast<int>(BLOCK_ID::ID7) + 1;

  // 最善と思われる運搬ブロックを探索する
  for(i = B_ZERO; i < B_SIZE; i++) {
    BLOCK_ID blockId = static_cast<BLOCK_ID>(i);
    updateFg = false;

    // 運搬先サークル番号
    int targetCircleNumber = static_cast<int>(destinationList.getDestination(blockId));

    // 運搬済みだった場合
    if(isCarriedBlock(blockId)) continue;

    // ブロックに到着できない場合
    if(!arrivableBlocks[i]) continue;

    // ブロックの運搬先に到着できない場合
    // 現在ブロックサークルに到着できない and 対象のブロックを運搬してもサークルが開放されない
    if(!arrivableCircles[targetCircleNumber] && !OPEN_CIRCLE_ID[i][targetCircleNumber]) continue;

    // ブロックを取りに行く距離(ここで計算)+ブロックを運ぶ距離(DestinationListから取得)　の和を計算
    Node& targetBlock = bingoArea.getNode(blockId);
    Coordinate targetBlockCoord = targetBlock.getCoordinate();
    Coordinate targetCircleCoord
        = bingoArea.getBlockCircle(static_cast<CIRCLE_ID>(targetCircleNumber)).getCoordinate();
    Coordinate robotCoord = robot.getCoordinate();
    // ブロックを取得するまでの距離
    int toBlockDistance
        = std::abs(robotCoord.x - targetBlockCoord.x) + std::abs(robotCoord.y - targetBlockCoord.y);
    // ブロックから運搬先サークルまでの距離
    int toCircleDistance = std::abs(targetCircleCoord.x - targetBlockCoord.x)
                           + std::abs(targetCircleCoord.y - targetBlockCoord.y);
    // 距離の和
    int distance = toBlockDistance + toCircleDistance;

    // 暫定の運搬距離より短い場合
    if(distance < minDist) {
      updateFg = true;     // これ以降の要素を更新するフラグを立てる
      minDist = distance;  // 運搬距離の記録を更新
    } else if(distance > minDist) {
      // 暫定の運搬ブロックより、運搬距離が長い場合
      continue;
    }

    // 運ぶブロックがある交点サークルに交わっている黒線の数を取得
    int crossCircleId = targetBlockCoord.x / 2 + targetBlockCoord.y / 2 * 4;
    int crossLine = bingoArea.getCrossCircle(crossCircleId).getEdgeNumber();
    // 上位の項目で優れている、もしくは交線の数が多い場合
    if(updateFg || crossLine > maxCrossLine) {
      updateFg = true;           // これ以降の要素を更新するフラグを立てる
      maxCrossLine = crossLine;  // 交線数の記録を更新
    } else if(crossLine < maxCrossLine) {
      // 暫定の運搬ブロックより、交点サークルの交線が少ない場合
      continue;
    }

    // 走行体の向きの進路を優先する
    // 走行体の進行方向
    Direction robotDirection = robot.getDirection();
    int rdx = static_cast<int>(robotDirection) % 3 - 1;  // dx 1,0,-1
    int rdy = static_cast<int>(robotDirection) / 3 - 1;  // dy 1,0,-1
    // 目標ブロックへの方向
    int dx = targetBlock.getCoordinate().x - robotCoord.x;
    int dy = targetBlock.getCoordinate().y - robotCoord.y;
    // x,yの方向について、符号が同じであれば、加点する
    int directPoint = 0;
    if(dx * rdx > 0) directPoint++;  // xについて進行方向が合致していれば、評価を上げる
    if(dy * rdy > 0) directPoint++;  // yについて進行方向が合致していれば、評価を上げる
    // 上位の項目で優れている、もしくは方向について有利な場合
    if(updateFg || directPoint > maxDirectPoint) {
      maxDirectPoint = directPoint;  // 方向の評価点の記録を更新
      bestBlockId = blockId;         // 運搬ブロックの候補を更新
    }
    // ここまでの項目が等しい場合は、既存(idが若い)のブロックを採用する
  }

  // ブロックが運搬されたとして、運搬可能範囲を開放
  for(int i = B_ZERO; i < B_SIZE; i++) {
    int bestBlockNumber = static_cast<int>(bestBlockId);
    arrivableBlocks[i] = arrivableBlocks[i] || OPEN_BLOCK_ID[bestBlockNumber][i];
    arrivableCircles[i] = arrivableCircles[i] || OPEN_CIRCLE_ID[bestBlockNumber][i];
  }

  // 最良と思われる候補を返す
  return bestBlockId;
}

// 指定されたブロックが運搬済みかを判定する
bool BlockSelector::isCarriedBlock(BLOCK_ID blockId)
{
  Coordinate coord = bingoArea.getNode(blockId).getCoordinate();
  // x,y座標がどちらも奇数にある場合、「ブロックサークル上にある==運搬済み」と判断する
  return (coord.x % 2 == 1 && coord.y % 2 == 1);
}
