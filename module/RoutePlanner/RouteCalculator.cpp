/**
 * @file  RouteCalculator.cpp
 * @brief 経路計算クラス
 * @author  Hisataka-Hagiyama,uchyam
 */

#include "RouteCalculator.h"

RouteCalculator::RouteCalculator(CourseInfo& courseInfo, Robot& robot, const bool IS_LEFT_COURSE)
  : courseInfo(courseInfo), goalNode(0, 0), robot(robot), isLeftCourse(IS_LEFT_COURSE)
{
}

std::vector<std::pair<Coordinate, Direction>> RouteCalculator::calculateRoute(
    Coordinate start, Coordinate goal, Coordinate destination)
{
  LineTracer lineTracer(isLeftCourse);
  MotionPerformer motionPerformer(lineTracer);
  MoveCostCalculator moveCostCalculator(motionPerformer);

  std::vector<AstarInfo> open;   //これから探索するノードを格納
  std::vector<AstarInfo> close;  //探索済みのノードを格納
  std::vector<std::pair<Coordinate, Direction>> routeCoordinate;  //最短経路の座標を格納
  struct AstarInfo elem({ 0, 0 }, 0);  //現在探索しているノード(座標(0,0),コスト0で初期化)
  double actualCost = 0;
  Route route[BINGO_SIZE][BINGO_SIZE];  //経路復元のための配列
  goalNode = goal;                      // ゴールノードをセット
  route[start.x][start.y].setInfo(start, 0, robot.getDirection(), true);
  //(ブロックサークルの座標-ゴールの座標)の符号を計算する
  int dx = (destination.x > goal.x) - (destination.x < goal.x);  // ブロックサークルへの方向
  int dy = (destination.y > goal.y) - (destination.y < goal.y);  // ブロックサークルへの方向
  // 方向の変換テーブル（向きコストの算出に使う）
  std::array<std::array<int, 2>, 8> robotVectorLeft = { {
      { 0, -1 },  // N
      { 1, -1 },  // NE
      { 1, 0 },   // E
      { 1, 1 },   // SE
      { 0, 1 },   // S
      { -1, 1 },  // SW
      { -1, 0 },  // W
      { -1, -1 }  // NW
  } };
  std::array<std::array<int, 2>, 8> robotVectorRight = { {
      { 0, -1 },   // N
      { -1, -1 },  // NE
      { -1, 0 },   // E
      { -1, 1 },   // SE
      { 0, 1 },    // S
      { 1, 1 },    // SW
      { 1, 0 },    // W
      { 1, -1 }    // NW
  } };
  open.push_back(AstarInfo(start, route[start.x][start.y].cost + calculateManhattan(start)));
  while(!open.empty()) {
    //予測コストの小さい順にソートする
    sort(open.begin(), open.end(), std::greater<AstarInfo>());
    //探索するノードをopenから取り出す
    elem = open.back();
    open.pop_back();
    Direction preDirection
        = route[elem.coordinate.x][elem.coordinate.y].direction;  //現時点での走行体の向き

    std::vector<AstarInfo> next
        = checkNeighborhood(elem.coordinate, route);  //隣接しているノードを格納
    for(const auto& m : next) {
      Direction currentDirection
          = calculateDirection(m.coordinate, elem.coordinate);  //移動した後の向きを計算する
      if((m.coordinate == route[elem.coordinate.x][elem.coordinate.y].parent)) {
        // 親ノードの場合はopenに追加しない
      } else if(m.coordinate.x % 2 == 1 && m.coordinate.y % 2 == 1 && m.coordinate != goalNode) {
        //ゴールでないブロックサークルはopenに追加しない
      } else if((elem.coordinate.x % 2 == 1 || elem.coordinate.y % 2 == 1)
                && (m.coordinate.x % 2 == 1 || m.coordinate.y % 2 == 1)) {
        //中点->中点に移動する場合はopenに追加しない
      } else if(checkBlock(m.coordinate)) {
        // ブロックがある場合はopenに追加しない
      } else if(route[m.coordinate.x][m.coordinate.y].checked == true) {
        //すでにチェックしている場合はopenに追加しない
      } else if(courseInfo.existBlock(start)
                && abs(MotionConverter::calculateAngle(
                       route[elem.coordinate.x][elem.coordinate.y].direction, currentDirection))
                       == 180) {
        //経路の始点にブロックが置かれており(すなわちこの経路ではブロックを持って移動する)、180度方向転換するような場合はopenに追加しない
      } else {
        // openにより大きいコストの同じ座標がある場合はopenから削除する
        if(checkList(m, open)) route[m.coordinate.x][m.coordinate.y].checked = true;
        // closeにより大きいコストの同じ座標がある場合はcloseから削除する
        if(checkList(m, close)) route[m.coordinate.x][m.coordinate.y].checked = true;
        if(m.coordinate == goal && goal != destination) {
          //ゴールと設置先が違い(すなわち取得経路)、かつゴールに到達した際は向きコストを考慮する
          int rdx = isLeftCourse ? robotVectorLeft[static_cast<int>(currentDirection)][0]
                                 : robotVectorRight[static_cast<int>(currentDirection)][0];
          int rdy = isLeftCourse ? robotVectorLeft[static_cast<int>(currentDirection)][1]
                                 : robotVectorRight[static_cast<int>(currentDirection)][1];

          int directionCost = 4;  //方向コスト
          if(dx * rdx > 0) directionCost--;  // xについて進行方向が合致していれば、コストを下げる
          if(dy * rdy > 0) directionCost--;  // yについて進行方向が合致していれば、コストを下げる

          //実コスト＝そのノードまでの距離＋向きコスト＋移動コスト＋推定コスト（マンハッタン距離）
          actualCost = route[elem.coordinate.x][elem.coordinate.y].cost + directionCost
                       + moveCostCalculator.calculateMoveCost(
                           std::make_pair(elem.coordinate, preDirection),
                           std::make_pair(m.coordinate, currentDirection), isLeftCourse)
                       + calculateManhattan(m.coordinate);
          open.push_back(AstarInfo(m.coordinate, actualCost));
          //ゴールを未探索、もしくはこれまでに発見したゴールまでの経路よりコストが小さい場合はゴールまでの経路を更新する
          if(route[m.coordinate.x][m.coordinate.y].cost > actualCost
             || route[m.coordinate.x][m.coordinate.y].cost == 0) {
            route[m.coordinate.x][m.coordinate.y].setInfo(elem.coordinate, actualCost,
                                                          currentDirection, false);
          }
        } else {
          //ゴール以外は向きコストを考慮せず探索する
          //実コスト＝そのノードまでの距離＋移動コスト＋推定コスト（マンハッタン距離）
          actualCost = route[elem.coordinate.x][elem.coordinate.y].cost
                       + moveCostCalculator.calculateMoveCost(
                           std::make_pair(elem.coordinate, preDirection),
                           std::make_pair(m.coordinate, currentDirection), isLeftCourse)
                       + calculateManhattan(m.coordinate);
          open.push_back(AstarInfo(m.coordinate, actualCost));
          route[m.coordinate.x][m.coordinate.y].setInfo(elem.coordinate, actualCost,
                                                        currentDirection, true);
        }
      }
    }
    close.push_back(elem);
  }
  //経路復元処理
  setRoute(routeCoordinate, route);  //探索が終了したノードはcloseに移動
  return routeCoordinate;
}

std::vector<AstarInfo> RouteCalculator::checkNeighborhood(Coordinate coordinate,
                                                          Route route[BINGO_SIZE][BINGO_SIZE])
{
  std::vector<AstarInfo> nodeList;
  int nx, ny;
  //上下左右、斜めに隣接するノードについて確認を行う
  for(int i = -1; i < 2; i++) {
    for(int j = -1; j < 2; j++) {
      if(i != 0 || j != 0) {
        nx = coordinate.x + i;
        ny = coordinate.y + j;
        Coordinate newCoordinate(nx, ny);
        //ビンゴエリアの座標内((0,0)~(6,6))にある座標はリストに追加する
        if((nx >= 0) && (nx < BINGO_SIZE) && (ny >= 0) && (ny < BINGO_SIZE)) {
          nodeList.push_back(AstarInfo({ nx, ny }, route[coordinate.x][coordinate.y].cost));
        }
      }
    }
  }
  return nodeList;
}

bool RouteCalculator::checkBlock(Coordinate coordinate)
{
  if(coordinate == goalNode) {
    return false;  // ゴールノードの場合はブロックがあっても避けない
  } else if(courseInfo.existBlock(coordinate)) {
    return true;  // ブロックがあるので処理を終える
  } else {
    return false;  // ブロックがないので次の処理に移る
  }
}

bool RouteCalculator::checkList(AstarInfo node, std::vector<AstarInfo>& list)
{
  for(int i = 0; i < static_cast<int>(list.size()); i++) {
    // listに既に同じノードがあるか調べる
    if(node.coordinate == list[i].coordinate && node < list[i]) {
      //既に同じノードがあり、コストがより大きい場合削除する
      list.erase(list.begin() + i);
      return true;
    }
  }
  return false;
}

int RouteCalculator::calculateManhattan(Coordinate coordinate)
{
  int distX = abs(goalNode.x - coordinate.x);  // x方向の距離
  int distY = abs(goalNode.y - coordinate.y);  // y方向の距離
  return distX + distY;  //マンハッタン距離=x方向の距離 + y方向の距離
}

void RouteCalculator::setRoute(std::vector<std::pair<Coordinate, Direction>>& list,
                               Route route[BINGO_SIZE][BINGO_SIZE])
{
  Coordinate last = route[goalNode.x][goalNode.y]
                        .parent;  //最後に確認したノードの親ノード(ゴールノードの親で初期化)
  //スタートノードでなく、このノードを通っている間チェックしていく(ゴールノードから辿っていく)
  for(Coordinate c = goalNode;
      c != route[c.x][c.y].parent && route[c.x][c.y].parent != Coordinate{ -1, -1 };
      c = route[c.x][c.y].parent) {
    Coordinate p = route[c.x][c.y].parent;
    Direction direction = route[c.x][c.y].direction;
    list.push_back(std::make_pair(c, direction));
    last = p;
  }
  list.push_back(std::make_pair(last, robot.getDirection()));  //スタートノードをリストに追加する
  std::reverse(list.begin(), list.end());  //リストを逆順にする(ゴールから順に格納されていくため)
}

Direction RouteCalculator::calculateDirection(Coordinate next, Coordinate current)
{
  int gx = next.x - current.x;
  int gy = next.y - current.y;
  if(gx == 0) {
    if(gy == 0)
      return robot.getDirection();  //移動していない場合は走行体の向きを戻り値とする
    else if(gy > 0) {
      return Direction::S;
    } else {
      return Direction::N;
    }
  } else if(gy == 0) {
    if(gx > 0) {
      return isLeftCourse ? Direction::E : Direction::W;
    } else {
      return isLeftCourse ? Direction::W : Direction::E;
    }
  } else {
    if(gx > 0) {
      if(gy > 0) {
        return isLeftCourse ? Direction::SE : Direction::SW;
      } else {
        return isLeftCourse ? Direction::NE : Direction::NW;
      }
    } else {
      if(gy > 0) {
        return isLeftCourse ? Direction::SW : Direction::SE;
      } else {
        return isLeftCourse ? Direction::NW : Direction::NE;
      }
    }
  }
}
