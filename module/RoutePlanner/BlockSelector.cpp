/**
 * @file BlockSelector.cpp
 * @brief 運搬ブロック決定クラス
 * @author hiroto0927, miyashita64
 */

#include "BlockSelector.h"

// コンストラクタ
BlockSelector::BlockSelector(DestinationList& _destination, const bool IS_LEFT_COURSE)
  : courseInfo(IS_LEFT_COURSE),
    destinationList(_destination),
    robot(IS_LEFT_COURSE),
    isLeftCourse(IS_LEFT_COURSE),
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
  courseInfo.initCourseInfo();
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
  RouteCalculator routeCalculator(courseInfo, robot, isLeftCourse);
  const int B_ZERO = static_cast<int>(BLOCK_ID::ID0);
  const int B_SIZE = static_cast<int>(BLOCK_ID::ID7) + 1;
  Coordinate currentCoordinate = robot.getCoordinate();  //現時点での走行体の座標
  Direction currentDirection = robot.getDirection();     //現時点での走行体の向き

  // 最善と思われる運搬ブロックを探索する
  for(i = B_ZERO; i < B_SIZE; i++) {
    BLOCK_ID blockId = static_cast<BLOCK_ID>(i);
    updateFg = false;

    //運搬するブロックの座標と運搬先の座標を求める
    int targetCircleNumber = static_cast<int>(destinationList.getDestination(blockId));
    Node& targetBlock = courseInfo.getNode(blockId);
    Coordinate targetCircleCoord
        = courseInfo.getBlockCircle(static_cast<CIRCLE_ID>(targetCircleNumber)).getCoordinate();
    Coordinate targetBlockCoord = targetBlock.getCoordinate();

    // 運搬済みだった場合
    if(isCarriedBlock(blockId)) continue;

    // ブロックに到着できない場合
    if(!arrivableBlocks[i]) continue;

    // ブロックの運搬先に到着できない場合
    robot.setDirection(currentDirection);
    robot.setDirection(
        routeCalculator.calculateRoute(robot.getCoordinate(), targetBlockCoord).back().second);
    if(routeCalculator.calculateRoute(targetBlockCoord, targetCircleCoord).front().first
           != targetBlockCoord
       || routeCalculator.calculateRoute(targetBlockCoord, targetCircleCoord).back().first
              != targetCircleCoord)
      continue;

    // 現在ブロックサークルに到着できない and 対象のブロックを運搬してもサークルが開放されない
    if(!arrivableCircles[targetCircleNumber] && !OPEN_CIRCLE_ID[i][targetCircleNumber]) continue;

    // ブロックを取りに行く距離(ここで計算)+ブロックを運ぶ距離(DestinationListから取得)　の和を計算
    Coordinate robotCoord = currentCoordinate;
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
    int crossLine = courseInfo.getCrossCircle(crossCircleId).getEdgeNumber();
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
    Direction robotDirection = currentDirection;
    // 方角の変換テーブル{dx,dy}
    std::array<std::array<int, 2>, 8> robotVector = { {
        { 0, -1 },  // N
        { 1, -1 },  // NE
        { 1, 0 },   // E
        { 1, 1 },   // SE
        { 0, 1 },   // S
        { -1, 1 },  // SW
        { -1, 0 },  // W
        { -1, -1 }  // S
    } };
    int rdx = robotVector[static_cast<int>(robotDirection)][0];
    int rdy = robotVector[static_cast<int>(robotDirection)][1];

    //*/
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
  //最善と思われるブロックの運搬先
  int bestCircleNumber = static_cast<int>(destinationList.getDestination(bestBlockId));
  Coordinate bestCircleCoord
      = courseInfo.getBlockCircle(static_cast<CIRCLE_ID>(bestCircleNumber)).getCoordinate();
  Node& bestBlock = courseInfo.getNode(bestBlockId);
  Coordinate bestBlockCoord = bestBlock.getCoordinate();

  //最善と思われるブロックまで走行体が移動したものとして座標と向きを更新
  robot.setCoordinate(bestBlockCoord);
  robot.setDirection(currentDirection);
  robot.setDirection(
      routeCalculator.calculateRoute(currentCoordinate, bestBlockCoord).back().second);

  //最善と思われるブロックを運搬したものとしてロボットの向きと座標を更新する
  std::vector<std::pair<Coordinate, Direction>> bestSetRoute
      = routeCalculator.calculateRoute(bestBlockCoord, bestCircleCoord);
  robot.setCoordinate(bestSetRoute[bestSetRoute.size() - 2].first);
  if(abs(MotionConverter::calculateAngle(bestSetRoute[bestSetRoute.size() - 2].second,
                                         bestSetRoute[bestSetRoute.size() - 1].second))
     == 45) {
    robot.setDirection(bestSetRoute[bestSetRoute.size() - 1].second);  //投げ入れ設置
  } else {
    robot.setDirection(bestSetRoute[bestSetRoute.size() - 2].second);  //ピボットターン設置
  }
  courseInfo.moveBlock(static_cast<CIRCLE_ID>(bestCircleNumber), bestBlockId);

  // 最良と思われる候補を返す
  return bestBlockId;
}

// 指定されたブロックが運搬済みかを判定する
bool BlockSelector::isCarriedBlock(BLOCK_ID blockId)
{
  Coordinate coord = courseInfo.getNode(blockId).getCoordinate();
  // x,y座標がどちらも奇数にある場合、「ブロックサークル上にある==運搬済み」と判断する
  return (coord.x % 2 == 1 && coord.y % 2 == 1);
}
