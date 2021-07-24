/**
 * @file DirectionChanger.h
 * @brief 方向転換クラス
 * @author kodama0720, yutotanaka24
 */

#ifndef DIRECTION_CHANGER_H
#define DIRECTION_CHANGER_H

#include "Controller.h"
#include "Rotation.h"
#include "StraightRunner.h"
#include "LineTracer.h"
#include "BingoMotion.h"

class DirectionChanger : public BingoMotion{
  public:
  DirectionChanger(LineTracer& _lineTracer);

  /**
   * @brief 方向転換する
   * @param angle 回転角度（deg） -180 < angle <= 180 45度刻み
   * @param isLeft 直前に投げ入れた方向
   */
  void changeDirection(int angle, bool isLeft=true);
  
  private:
  Rotation rotation;
  LineTracer& lineTracer;
  Controller controller;
  Measurer measurer;
};

#endif
