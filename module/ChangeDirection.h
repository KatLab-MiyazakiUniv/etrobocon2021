/**
 * @file ChangeDirection.h
 * @brief 方向転換クラス
 * @author kodama0720, yutotanaka24
 */

#ifndef CHANGE_DIRECTION_H
#define CHANGE_DIRECTION_H

#include "Controller.h"
#include "Rotation.h"
#include "StraightRunner.h"
#include "LineTracer.h"
#include "BingoMotion.h"

class ChangeDirection : public BingoMotion{
  public:
  ChangeDirection(LineTracer& _lineTracer);

  /**
   * @brief 方向転換する
   * @param angle 回転角度（deg）
   */
  void turnAround(int angle);
  
  private:
  Rotation rotation;
  LineTracer lineTracer;
  Controller controller;
  Measurer measurer;
};

#endif
