/**
 * @file MotionConverter.h
 * @brief 動作変換クラス
 * @author Hisataka-Hagiyama,uchyam
 */

#ifndef MOTION_CONVERTER_H
#define MOTION_CONVERTER_H

#include <cmath>
#include "MotionPerformer.h"
#include "RouteCalculator.h"
#include <utility>
#include <vector>

class MotionConverter {
 public:
  //コンストラクタ
  MotionConverter(MotionPerformer& motionPerformer);

  /**
   * @fn   MOTION decideMotion(std::pair<Coordinate, Direction> current, std::pair<Coordinate,
   * Direction> next);
   * @brief 2つの座標と向きのペアから動作を判定する
   * @param current 現在の座標と向き
   * @param next 次の座標と向き
   * @returm 動作を表す列挙子
   */
  MOTION decideMotion(std::pair<Coordinate, Direction> current,
                      std::pair<Coordinate, Direction> next);

  /**
   * @fn void convertToMotion(std::vector<std::pair<Coordinate, Direction>>& route);
   * @brief 経路を実際の動作に変換し、各動作を実行する
   * @param 経路の座標と走行体の向きを格納した動的配列
   */
  void convertToMotion(std::vector<std::pair<Coordinate, Direction>>& route);

 private:
  MotionPerformer& motionPerformer;

  /**
   * @fn int calculateAngle(Direction current, Direction next);
   * @brief 走行体の向きの変化から回転角を計算する
   * @param current 現在の向き
   * @param next 次の向き
   * @return 回転角[deg]
   */
  int calculateAngle(Direction current, Direction next);
};

#endif
