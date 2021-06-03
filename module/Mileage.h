/**
 **  @file Mileage.h
 **  @brief 走行距離を計算するクラス
 **  @author Hisataka-Hagiyama,uchyam
 **/

#ifndef MILEAGE_H
#define MILEAGE_H
#include "cmath"

class Mileage {
 public:
  // インスタンスを生成する関数
  static Mileage& getInstance();

  /**
   ** @fn　double calculateMileage(int rightAngle, int leftAngle);
   ** @brief 走行体全体の累計走行距離を計算する
   ** @param rightAngle 右タイヤの回転角度[deg]
   ** @param leftAngle 左タイヤの回転角度[deg]
   ** @return 走行体全体の累計走行距離[mm]
   **/
  double calculateMileage(int rightAngle, int leftAngle);

 private:
  // コンストラクタ
  Mileage();
  // コピーコンストラクタ
  Mileage(const Mileage& other);
  // 代入演算子
  Mileage& operator=(const Mileage& other);

  /**
   ** @fn double calculateWheelMileage(int angle);
   ** @brief タイヤの累計走行距離を計算する
   ** @param angle タイヤの回転角度[deg]
   ** @return タイヤの累計走行距離[mm]
   **/
  double calculateWheelMileage(int angle);

  const double radius;  //タイヤの半径[mm]

};
#endif