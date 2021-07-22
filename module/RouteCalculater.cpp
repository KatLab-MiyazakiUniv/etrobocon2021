/**
 *  @file	RouteCalculater.cpp
 *  @brief	経路計算をする
 *  @author	Hisataka-Hagiyama,uchyam
 */
#include "RouteCalculater.h"

using namespace std;

RouteCalculater::RouteCalculater(BingoArea& bingoArea) : bingoArea(bingoArea), goal(0, 0) {}

void RouteCalculater::calculateRoute(vector<Coordinate>& list, Coordinate startCoordinate,
                                     Coordinate goalCoordinate)
{
  vector<AstarInfo> open;
  vector<AstarInfo> close;
  struct AstarInfo elem({ 0, 0 }, 0);
  int actualCost;
  Route route[BINGO_SIZE][BINGO_SIZE];

  list.clear();
  goal = goalCoordinate;  // ゴールノードをセット

  route[startCoordinate.y][startCoordinate.x].set(startCoordinate, 0);
  open.push_back(AstarInfo(startCoordinate, route[startCoordinate.y][startCoordinate.x].currentCost
                                                + calculateManhattan(startCoordinate)));
  while(!open.empty()) {
    sort(open.begin(), open.end(), std::greater<AstarInfo>());
    elem = open.back();
    open.pop_back();
    if(elem.coordinate == goal) {
      break;
    }
    vector<AstarInfo> next = nextNode(elem.coordinate, route);
    for(const auto& m : next) {
      if((m.coordinate == route[elem.coordinate.y][elem.coordinate.x].parent)) {
        // 親ノードの場合はopenに追加しない
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

  setRoute(list, route, goal);
}

vector<AstarInfo> RouteCalculater::nextNode(Coordinate coordinate,
                                            Route route[BINGO_SIZE][BINGO_SIZE])
{
  vector<AstarInfo> nodeList;
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
  if(coordinate == goal) {
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

bool RouteCalculater::checkList(AstarInfo node, vector<AstarInfo>& list)
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
  int diffX = abs(goal.x - coordinate.x);
  int diffY = abs(goal.y - coordinate.y);
  return diffX + diffY;
}

void RouteCalculater::setRoute(vector<Coordinate>& list, Route route[BINGO_SIZE][BINGO_SIZE],
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