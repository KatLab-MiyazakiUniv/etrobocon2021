/**
 *  @file	RouteCalculater.h
 *  @brief	経路計算をする
 *  @author	Hisataka-Hagiyama,uchyam
 */
#ifndef ROUTE_CALCULATER_H
#define ROUTE_CALCULATER_H

#include "BingoArea.h"
#include "array"
#include "math.h"
#include "vector"
#include "algorithm"

struct AstarInfo {
  // ノードの座標
  Coordinate coordinate;
  int estimateCost;

  AstarInfo(Coordinate _coordinate, int _estimateCost)
    : coordinate(_coordinate), estimateCost(_estimateCost)
  {
  }

  bool operator<(const AstarInfo& another) const { return estimateCost < another.estimateCost; }
  bool operator>(const AstarInfo& another) const { return estimateCost > another.estimateCost; }
};

struct Route {
  //親ノード
  Coordinate parent;
  int currentCost;  //このノードに到達するまでのコスト

  Route() : parent(-1, -1), currentCost(0) {}

  void set(Coordinate _parent, int _currentCost)
  {
    parent = _parent;
    currentCost = _currentCost;
  }
};

class RouteCalculater {
 public:
  /** コンストラクタ
   *  @param bingoArea
   */
  RouteCalculater(BingoArea& bingoArea);

  /**
   *  @brief 経路計算をする
   *  @param list 経路座標を格納するリスト
   *  @param startCoordinate [スタートノードの座標]
   *  @param goalCoordinate [ゴールノードの座標]
   */
  void calculateRoute(std::vector<Coordinate>& list, Coordinate startCoordinate,
                      Coordinate goalCoordinate);

 private:
  BingoArea& bingoArea;
  Coordinate goal;  //クラス内でゴールノードを共有しておく
  static constexpr int BINGO_SIZE = 7;

  /**
   *  @brief 指定ノードの隣接ノードをすべて求める
   *  @param coordinate [指定ノードの座標]
   *  @param route [経路情報]
   *  @return 隣接ノードそれぞれの情報(エリア外のノードは除外する)
   */
  std::vector<AstarInfo> nextNode(Coordinate coordinate, Route route[BINGO_SIZE][BINGO_SIZE]);

  /**
   *  @brief 指定ノードのブロックの有無を判定する(7×7座標)
   *  @param coordinate [指定ノードの座標]
   *  @return 判定結果 [trueがブロックあり]
   */
  bool checkBlock(Coordinate coordinate);

  /**
   *  @brief リストに隣接ノードと同じノードがあるか調べて，ある場合は削除する
   *  @param node [隣接ノードの情報]
   *  @param list [オープンorクローズリスト]
   *  @return 判定結果 [この隣接ノードを探索する必要がない場合true]
   */
  bool checkList(AstarInfo node, std::vector<AstarInfo>& list);

  /**
   *  @brief ヒューリスティック関数としてマンハッタン距離を取る
   *  @param coordinate [指定ノードの座標]
   *  @return 指定ノードとゴールノードのマンハッタン距離 [int]
   */
  int calculateManhattan(Coordinate coordinate);

  /**
   *  @brief 指定ノードまでの経路をセットする
   *  @param list [経路座標を保持するリスト]
   *  @param route [経路情報]
   *  @param coordinate [指定ノードの座標]
   */
  void setRoute(std::vector<Coordinate>& list, Route route[BINGO_SIZE][BINGO_SIZE],
                Coordinate coordinate);
};

#endif