/**
 * @file	RouteCalculator.cpp
 * @brief	経路計算クラス
 * @author	Hisataka-Hagiyama,uchyam
 */

#include "RouteCalculator.h"

RouteCalculator::RouteCalculator(BingoArea& bingoArea, Robot& robot)
  : bingoArea(bingoArea), goalNode(0, 0), robot(robot)
{
}

std::vector<std::pair<Coordinate, Direction>> RouteCalculator::calculateRoute(Coordinate start,
                                                                              Coordinate goal)
{
  std::vector<AstarInfo> open;   //これから探索するノードを格納
  std::vector<AstarInfo> close;  //探索済みのノードを格納
  std::vector<std::pair<Coordinate, Direction>> routeCoordinate;  //最短経路の座標を格納
  struct AstarInfo elem({ 0, 0 }, 0);  //現在探索しているノード(座標(0,0),コスト0で初期化)
  int actualCost = 0;
  Route route[BINGO_SIZE][BINGO_SIZE];  //経路復元のための配列

  goalNode = goal;  // ゴールノードをセット
  route[start.x][start.y].setInfo(start, 0);
  open.push_back(AstarInfo(start, route[start.x][start.y].cost + calculateManhattan(start)));
  while(!open.empty()) {
    //予測コストの小さい順にソートする
    sort(open.begin(), open.end(), std::greater<AstarInfo>());
    //探索するノードをopenから取り出す
    elem = open.back();
    open.pop_back();
    //現在探索しているノードがゴールノードであれば探索を終了する
    if(elem.coordinate == goalNode) {
      break;
    }
    std::vector<AstarInfo> next
        = checkNeighborhood(elem.coordinate, route);  //隣接しているノードを格納
    for(const auto& m : next) {
      if((m.coordinate == route[elem.coordinate.x][elem.coordinate.y].parent)) {
        // 親ノードの場合はopenに追加しない
      } else if(m.coordinate.x % 2 == 1 && m.coordinate.y % 2 == 1 && m.coordinate != goalNode) {
        //ゴールでないブロックサークルはopenに追加しない
      } else if((elem.coordinate.x % 2 == 1 || elem.coordinate.y % 2 == 1)
                && (m.coordinate.x % 2 == 1 || m.coordinate.y % 2 == 1)) {
        //中点->中点に移動する場合はopenに追加しない
      } else if(checkBlock(m.coordinate)) {
        // ブロックがある場合はopenに追加しない
      } else {
        checkList(m, open);  // openにより大きいコストの同じ座標がある場合はopenから削除する
        checkList(m, close);  // closeにより大きいコストの同じ座標がある場合はcloseから削除する
        actualCost = route[elem.coordinate.x][elem.coordinate.y].cost;
        open.push_back(AstarInfo(m.coordinate, actualCost + calculateManhattan(m.coordinate)));
        route[m.coordinate.x][m.coordinate.y].setInfo(elem.coordinate, actualCost);
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
        //ビンゴエリアの座標内((0,0)~(6,6))にある座標はリストに追加する
        if((nx >= 0) && (nx < BINGO_SIZE) && (ny >= 0) && (ny < BINGO_SIZE)) {
          nodeList.push_back(AstarInfo({ nx, ny }, route[coordinate.x][coordinate.y].cost
                                                       + calculateManhattan({ nx, ny })));
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
  } else if(bingoArea.existBlock(coordinate)) {
    return true;  // ブロックがあるので処理を終える
  } else {
    return false;  // ブロックがないので次の処理に移る
  }
}

void RouteCalculator::checkList(AstarInfo node, std::vector<AstarInfo>& list)
{
  for(int i = 0; i < static_cast<int>(list.size()); i++) {
    // listに既に同じノードがあるか調べる
    if(node.coordinate == list[i].coordinate && node < list[i]) {
      list.erase(list.begin() + i);  //既に同じノードがあり、コストがより大きい場合削除する
    }
  }
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
    //まだ最短経路としてチェックしていないorゴールである場合は最短経路リストに追加していく
    if(route[c.x][c.y].checked == false || c == goalNode) {
      Direction direction = calculateDirection(c, p);
      list.push_back(std::make_pair(c, direction));
    }
    route[c.x][c.y].checked = true;  //このノードはチェック済みとする
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
      return Direction::E;
    } else {
      return Direction::W;
    }
  } else {
    if(gx > 0) {
      if(gy > 0) {
        return Direction::SE;
      } else {
        return Direction::NE;
      }
    } else {
      if(gy > 0) {
        return Direction::SW;
      } else {
        return Direction::NW;
      }
    }
  }
}
