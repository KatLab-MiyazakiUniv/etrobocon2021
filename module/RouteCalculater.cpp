/**
 *  @file	RouteCalculater.cpp
 *  @brief	経路計算をする
 *  @author	Hisataka-Hagiyama,uchyam
 */
#include "RouteCalculater.h"

RouteCalculater::RouteCalculater(BingoArea& bingoArea) : bingoArea(bingoArea), goalNode(0, 0) {}

std::vector<Coordinate> RouteCalculater::calculateRoute(Coordinate start, Coordinate goal)
{
  std::vector<AstarInfo> open;              //これから探索するノードを格納
  std::vector<AstarInfo> close;             //探索済みのノードを格納
  std::vector<Coordinate> routeCoordinate;  //最短経路の座標を格納
  struct AstarInfo elem({ 0, 0 }, 0);  //現在探索しているノード(座標(0,0),コスト0で初期化)
  int actualCost;
  Route route[BINGO_SIZE][BINGO_SIZE];  //経路復元のための配列

  goalNode = goal;  // ゴールノードをセット

  route[start.y][start.x].set(start, 0);
  open.push_back(AstarInfo(start, route[start.y][start.x].currentCost + calculateManhattan(start)));
  while(!open.empty()) {
    //予測コストの小さい順にソートする
    sort(open.begin(), open.end(), std::greater<AstarInfo>());
    elem = open.back();  //現在探索しているノード
    open.pop_back();
    //現在探索しているノードがゴールノードであれば探索を終了する
    if(elem.coordinate == goalNode) {
      break;
    }
    std::vector<AstarInfo> next = nextNode(elem.coordinate, route);  //隣接しているノードを格納
    for(const auto& m : next) {
      if((m.coordinate == route[elem.coordinate.y][elem.coordinate.x].parent)) {
        // 親ノードの場合はopenに追加しない
      } else if((elem.coordinate.x % 2 == 1 || elem.coordinate.y % 2 == 1)
                && (m.coordinate.x % 2 == 1 || m.coordinate.y % 2 == 1)) {
        //中点->中点に移動する場合は追加しない
      } else if(checkBlock(m.coordinate)) {
        // ブロックがある場合はopenに追加しない
      } else if(checkList(m, open)) {
        // openにより大きいコストの同じ座標がある場合はopenから削除する
      } else if(checkList(m, close)) {
        // closeにより大きいコストの同じ座標がある場合はcloseから削除する
      } else {
        actualCost = route[elem.coordinate.y][elem.coordinate.x].currentCost;
        open.push_back(AstarInfo(m.coordinate, actualCost + calculateManhattan(m.coordinate)));
        route[m.coordinate.y][m.coordinate.x].set(elem.coordinate, actualCost);
      }
    }
    close.push_back(elem);
  }
  //経路復元処理
  setRoute(routeCoordinate, route, goalNode);
  return routeCoordinate;
}

std::vector<AstarInfo> RouteCalculater::nextNode(Coordinate coordinate,
                                                 Route route[BINGO_SIZE][BINGO_SIZE])
{
  std::vector<AstarInfo> nodeList;
  int nx, ny;

  for(int i = -1; i < 2; i++) {
    for(int j = -1; j < 2; j++) {
      if(i != 0 || j != 0) {
        nx = coordinate.x + i;
        ny = coordinate.y + j;
        if((nx >= 0) && (nx < BINGO_SIZE) && (ny >= 0) && (ny < BINGO_SIZE)) {
          nodeList.push_back(AstarInfo({ nx, ny }, route[coordinate.y][coordinate.x].currentCost
                                                       + calculateManhattan({ nx, ny })));
        }
      }
    }
  }
  return nodeList;
}

bool RouteCalculater::checkBlock(Coordinate coordinate)
{
  if(coordinate == goalNode) {
    return false;  // ゴールノードの場合はブロックがあっても避けない
  }
  // 交点サークルの場合
  if(bingoArea.existBlock(coordinate)) {
    return true;  // ブロックがあるのでこのノードの処理を終える
  } else if(coordinate.x % 2 == 1 && coordinate.y % 2 == 1) {
    return true;
  } else {
    return false;  // ブロックがないので次の処理に移る
  }
}

bool RouteCalculater::checkList(AstarInfo node, std::vector<AstarInfo>& list)
{
  for(int i = 0; i < static_cast<int>(list.size()); i++) {
    // listに既に同じノードがあるか調べる
    if(node.coordinate == list[i].coordinate) {
      if(node < list[i]) {
        list.erase(list.begin() + i);
        return false;  // listにすでにあるノードよりもコストが低いため、listから削除して次の処理に移る
      } else {
        return true;  // listにすでに同コストのノードがある場合はこのノードの処理を終える
      }
    }
  }
  return false;  // listにないノードなので次の処理に移る
}

int RouteCalculater::calculateManhattan(Coordinate coordinate)
{
  int distX = abs(goalNode.x - coordinate.x);
  int distY = abs(goalNode.y - coordinate.y);
  return distX + distY;
}

void RouteCalculater::setRoute(std::vector<Coordinate>& list, Route route[BINGO_SIZE][BINGO_SIZE],
                               Coordinate coordinate)
{
  // (x,y)を通っていないときのエラー処理
  if(route[coordinate.y][coordinate.x].parent == Coordinate{ -1, -1 }) {
    // printf("[ERROR] This coordinate does not pass.\n");
  } else if(route[coordinate.y][coordinate.x].parent == coordinate) {  // スタートノードの場合
    list.push_back(coordinate);
  } else {
    setRoute(list, route, route[coordinate.y][coordinate.x].parent);
    list.push_back(coordinate);
  }
}
