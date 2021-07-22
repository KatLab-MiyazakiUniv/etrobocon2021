/**
 * @file ToCrossMotion.h
 * @brief 交点間移動のクラス
 * @author kodama0720, yutotanaka24
 */

#ifndef TO_CROSS_MOTION_H
#define TO_CROSS_MOTION_H

#include "LineTracer.h"
#include "StraightRunner.h"
#include "BingoMotion.h"

class ToCrossMotion : public BingoMotion {
 public:
  ToCrossMotion(LineTracer& _lineTracer);

  /**
   * @brief 交点間を移動する
   */
  void runToCross(void);

 private:
  LineTracer& lineTracer;
};

#endif
