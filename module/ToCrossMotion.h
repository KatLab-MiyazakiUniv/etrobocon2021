/**
 * @file ToCrossMotion.h
 * @brief 交点間移動のクラス
 * @author kodama0720, yutotanaka24
 */

#ifndef TO_CROSS_MOTION_H
#define TO_CROSS_MOTION_H

#include "LineTracer.h"

class ToCrossMotion : public BingoMotion {
 public:
  /**
   * @brief 交点間を移動する
   */
  static void runToCross(void);

  private:
   ToCrossMotion();
};

#endif
