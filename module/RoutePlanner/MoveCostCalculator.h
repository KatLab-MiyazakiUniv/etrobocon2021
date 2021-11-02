/**
 * @file  MoveCostCalculator.h
 * @brief 移動コスト計算クラス
 * @author  Hisataka-Hagiyama
 */

#ifndef MOVECOST_CALCULATOR_H
#define MOVECOST_CALCULATOR_H

#include "MotionConverter.h"

class MoveCostCalculator {
 public:
  //コンストラクタ
  MoveCostCalculator(MotionPerformer& _motionPerformer);

  /**
   * @fn static int calculateMoveCost(std::pair<Coordinate, Direction> current,std::pair<Coordinate,
   * Direction> next,bool isLeftCourse);
   * @brief 動作に応じた移動コストを計算する
   * @param current 現在の座標と向き
   * @param next 移動後の座標と向き
   * @return 移動コスト
   */
  double calculateMoveCost(std::pair<Coordinate, Direction> current,
                           std::pair<Coordinate, Direction> next, bool isLeftCourse);

 private:
  MotionPerformer& motionPerformer;
};

#endif
