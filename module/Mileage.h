/**
 *  @file Mileage.h
 *  @brief 走行距離を計算するクラス
 *  @author Hisataka-Hagiyama,uchiyam
 */

#ifndef DISTANCE_H
#define DISTANCE_H
#include "cmath"

class Mileage {
 public:
  /** コンストラクタ
   */
  Mileage();

  /**
   * @fn double calculateWheelMileage(int angle);
   * @brief タイヤの累計走行距離を計算する
   * @param angle タイヤの回転角度[deg]
   * @return タイヤの累計走行距離[mm]
   */
  double calculateWheelMileage(int angle);

  /**
   * @fn　double calculateMileage(int rightAngle, int leftAngle);
   * @brief 走行体全体の累計走行距離を計算する
   * @param rightAngle 右タイヤの回転角度[deg]
   * @param leftAngle 左タイヤの回転角度[deg]
   * @return 走行体全体の累計走行距離[mm]
   */
  double calculateMileage(int rightAngle, int leftAngle);

 private:
  double radius;  //タイヤの半径[mm]
};
#endif