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

class DirectionChanger : public BingoMotion {
 public:
  DirectionChanger(LineTracer& _lineTracer);

  /**
   * @brief 方向転換する
   * @param ratateAngle 回転角度（deg） -180 < angle <= 180 45度刻み
   * @param changeAngle 設置動作の直前方向から見て回頭する角度
   */
  void changeDirection(int rotateAngle, int changeAngle);

 private:
  Rotation rotation;
  LineTracer& lineTracer;
  Controller controller;
  Measurer measurer;
};

#endif
