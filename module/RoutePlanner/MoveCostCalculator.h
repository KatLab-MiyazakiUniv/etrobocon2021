/**
 * @file  RouteCalculator.h
 * @brief 経路計算クラス
 * @author  Hisataka-Hagiyama,uchyam
 */

#ifndef MOVECOST_CALCULATOR_H
#define MOVECOST_CALCULATOR_H

#include "CourseInfo.h"
#include "cmath"
#include "Robot.h"
#include "utility"
#include "vector"
#include "MotionPerformer.h"
#include "MotionConverter.h"

class MoveCostCalculator {
public:
  /**
   * @fn   Direction calculateDirection(Coordinate next, Coordinate current);
   * @brief 走行体の位置の変化から走行体の向きを計算する
   * @param next 移動後の座標
   * @param current 現在の座標
   * @return 移動後の走行体の向き
   */
   static int calculateMoveCost(std::pair<Coordinate, Direction> current,std::pair<Coordinate, Direction> next,bool isLeftCourse);
};

#endif
