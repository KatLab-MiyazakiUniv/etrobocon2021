/**
 * @file InCrossLeft.h
 * @brief 交点内移動（左折）のクラス
 * @author kodama0720, yutotanaka24
 */

#ifndef IN_CROSS_LEFT_H
#define IN_CROSS_LEFT_H

#include "Rotation.h"
#include "StraightRunner.h"
#include "LineTracer.h"
#include "BingoMotion.h"

class InCrossLeft : public BingoMotion {
 public:
  InCrossLeft(LineTracer& _lineTracer);

  /**
   * @brief 交点サークル上を左に進む
   */
  void runLeft(void);

 private:
  Rotation rotation;
  StraightRunner straightRunner;
  LineTracer& lineTracer;
};

#endif