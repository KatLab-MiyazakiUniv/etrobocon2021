/**
 * @file	RouteCalculator.h
 * @brief	経路計算クラス
 * @author	Hisataka-Hagiyama,uchyam
 */

#ifndef ROUTE_CALCULATOR_H
#define ROUTE_CALCULATOR_H

#include "BingoArea.h"
#include "cmath"
#include "Robot.h"
#include "utility"
#include "vector"

//A*アルゴリズムで使う座標と予測コストをまとめた構造体
struct AstarInfo {
  // ノードの座標
  Coordinate coordinate;//座標
  int estimateCost;//予測コスト

  //コンストラクタ
  AstarInfo(Coordinate _coordinate, int _estimateCost)
    : coordinate(_coordinate), estimateCost(_estimateCost)
  {
  }
  //予測コストでソートできるように比較演算子をオーバーロード
  bool operator<(const AstarInfo& another) const { return estimateCost < another.estimateCost; }
  bool operator>(const AstarInfo& another) const { return estimateCost > another.estimateCost; }
};

//経路復元で使う親ノードとコストをまとめた構造体
struct Route {
  Coordinate parent;  //親ノード
  int cost;           //このノードに到達するまでのコスト
  bool checked
      = false;  //経路復元の際にこのノードをチェックしたかどうか

  //コンストラクタ
  Route() : parent(-1, -1), cost(0) {}
  /**
   * @fn void set(Coordinate _parent, int _currentCost)
   * @brief 各ノードの親ノード、現在のコスト、現在の走行体の向きをセットする
   * @param _parent 親ノード
   * @param _currentCost　現在のコスト
   */
  void setInfo(Coordinate _parent, int _currentCost)
  {
    parent = _parent;
    cost = _currentCost;
  }
};

class RouteCalculator {
 public:
  //コンストラクタ
  RouteCalculator(BingoArea& bingoArea,Robot &robot);

  /**
   * @fn std::vector<std::pair<Coordinate, Direction>> calculateRoute(Coordinate start, Coordinate goal)
   * @brief 経路計算をする
   * @param start スタートノードの座標
   * @param goal ゴールノードの座標
   * @return 最短経路の座標と走行体の向きのペアを格納した動的配列
   */
  std::vector<std::pair<Coordinate, Direction>> calculateRoute(Coordinate start, Coordinate goal);

 private:
  BingoArea& bingoArea;
  Coordinate goalNode;  //クラス内でゴールノードを共有しておく
  static constexpr int BINGO_SIZE = 7;
  Robot &robot;

  /**
   * @fn std::vector<AstarInfo> checkNeighborhood(Coordinate coordinate, Route, route[BINGO_SIZE][BINGO_SIZE]);
   * @brief 指定ノードの隣接ノードをすべて求める
   * @param coordinate 指定ノードの座標
   * @param route 経路情報
   * @return 隣接ノードそれぞれの情報(エリア外のノードは除外する)
   */
  std::vector<AstarInfo> checkNeighborhood(Coordinate coordinate,
                                           Route route[BINGO_SIZE][BINGO_SIZE]);

  /**
   * @fn bool checkBlock(Coordinate coordinate);
   * @brief 指定ノードのブロックの有無を判定する(7×7座標)
   * @param coordinate 指定ノードの座標
   * @return 判定結果(trueがブロックあり)
   */
  bool checkBlock(Coordinate coordinate);

  /**
   * @fn void checkList(AstarInfo node, std::vector<AstarInfo>& list);
   * @brief リストに隣接ノードと同じノードがあるか調べて，ある場合は削除する
   * @param node 隣接ノードの情報
   * @param list オープンorクローズリスト
   */
  void checkList(AstarInfo node, std::vector<AstarInfo>& list);

  /**
   * @fn int calculateManhattan(Coordinate coordinate);
   * @brief ヒューリスティック関数としてマンハッタン距離を計算する
   * @param coordinate ノードの座標
   * @return 指定ノードとゴールノードとのマンハッタン距離
   */
  int calculateManhattan(Coordinate coordinate);

  /**
   * @fn void setRoute(std::vector<std::pair<Coordinate, Direction>>& list, Route route[BINGO_SIZE][BINGO_SIZE], Coordinate coordinate);
   * @brief 指定ノードまでの経路をセットする
   * @param list 最短経路の座標と走行体の向きのペアを保持する動的配列
   * @param route 経路情報
   * @param coordinate ノードの座標
   */
  void setRoute(std::vector<std::pair<Coordinate, Direction>>& list, Route route[BINGO_SIZE][BINGO_SIZE], Coordinate coordinate);

  /**
   * @fn   Direction calculateDirection(Coordinate next, Coordinate current);
   * @brief 走行体の位置の変化から走行体の向きを計算する
   * @param next 移動後の座標
   * @param current 現在の座標
   * @return 移動後の走行体の向き
   */
  Direction calculateDirection(Coordinate next, Coordinate current);
};

#endif