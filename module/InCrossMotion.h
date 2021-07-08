/**
 * @file InCrossMotion.h
 * @brief 交点内移動のクラス
 * @author kodama0720, yutotanaka24
 */

#ifndef IN_CROSS_MOTION_H
#define IN_CROSS_MOTION_H

#include "Rotation.h"
#include "StraightRunner.h"
#include "LineTracer.h"
#include "BingoMotion.h"

class InCrossMotion : public BingoMotion {
 public:
  InCrossMotion(bool _isLeftEdge);

  /**
   * @brief 交点サークル上を前に進む
   */
  void runForward(void);

  /**
   * @brief 交点サークル上を後ろに進む
   */
  void runBack(void);

  /**
   * @brief 交点サークル上を右に進む
   */
  void runRight(void);

  /**
   * @brief 交点サークル上を左に進む
   */
  void runLeft(void);

 private:
  Rotation rotation;
  StraightRunner straightRunner;
  LineTracer lineTracer;
};

#endif
