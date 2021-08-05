/**
 * @file MotionConverter.h
 * @brief 動作変換クラス
 * @author Hisataka-Hagiyama,uchyam
 */

#ifndef MOTION_CONVERTER_H
#define MOTION_CONVERTER_H

#include "cmath"
#include "Node.h"
#include "Robot.h"
#include "utility"
#include "vector"

enum class MOTION {
  ST = 0,        //(直進:Straight)
  TR = 1,        //(右折::Turn Right)
  TL = 2,        //(左折:Turn Left)
  BC = 3,        //(交点間:Between Cross)
  PSET = 4,      //(ピボットターン設置:Pibot Turn Set)
  TSET = 5,      //(投げ入れ設置:Throw Set)
  TAC45 = 6,     //(時計回りに45度方向転換:Turn Around Clockwise)
  TAC90 = 7,     //(時計回りに90度方向転換:Turn Around Clockwise)
  TAC135 = 8,    //(時計回りに135度方向転換:Turn Around Clockwise)
  TARC45 = 9,    //(反時計回りに45度方向転換:Turn Around Reverse Clockwise)
  TARC90 = 10,   //(反時計回りに90度方向転換:Turn Around Reverse Clockwise)
  TARC135 = 11,  //(反時計回りに135度方向転換:Turn Around Reverse Clockwise)
  TA180 = 12,    //(180度方向転換Turn Around)
};

class MotionConverter {
 public:
  //コンストラクタ
  MotionConverter();

  /**
   * @fn MOTION decideMotion(std::pair<Coordinate, Direction> current, std::pair<Coordinate,
   * Direction> next);
   * @brief 2つの座標から動作を判定する
   * @param current 現在の座標と向き
   * @param next 次の座標と向き
   * @return 動作を表す列挙子
   */
  MOTION decideMotion(std::pair<Coordinate, Direction> current,
                      std::pair<Coordinate, Direction> next);

  /**
   * @fn std::vector<MOTION> convertToMotion(std::vector<std::pair<Coordinate, Direction>>& route);
   * @brief 動作に変換する
   * @param 経路の座標と走行体の向きを格納した動的配列
   * @return 動作に変換したものを格納した動的配列
   */
  std::vector<MOTION> convertToMotion(std::vector<std::pair<Coordinate, Direction>>& route);

 private:
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
