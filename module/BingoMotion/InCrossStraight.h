/**
 * @file InCrossStraight.h
 * @brief 交点内移動（直進）のクラス
 * @author kodama0720, yutotanaka24
 */

#ifndef IN_CROSS_STRAIGHT_H
#define IN_CROSS_STRAIGHT_H

#include "Rotation.h"
#include "StraightRunner.h"
#include "LineTracer.h"
#include "BingoMotion.h"

class InCrossStraight : public BingoMotion {
 public:
 //コンストラクタ
  InCrossStraight();

  /**
   * @brief 交点サークル上を前に進む
   */
  void runForward(void);

 private:
  StraightRunner straightRunner;
};

#endif
