/**
 * @file InCrossRight.h
 * @brief 交点内移動（右折）のクラス
 * @author kodama0720, yutotanaka24
 */

#ifndef IN_CROSS_RIGHT_H
#define IN_CROSS_RIGHT_H

#include "Rotation.h"
#include "StraightRunner.h"
#include "LineTracer.h"
#include "BingoMotion.h"

class InCrossRight : public BingoMotion {
 public:
  InCrossRight(LineTracer& _lineTracer);

  /**
   * @brief 交点サークル上を右に進む
   */
  void runRight(void);

 private:
  Rotation rotation;
  StraightRunner straightRunner;
  LineTracer& lineTracer;
};

#endif