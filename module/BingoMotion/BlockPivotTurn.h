/**
 * @file BlockPivotTurn.h
 * @brief ピボットターン設置クラス
 * @author kodama0720, yutotanaka24
 */

#ifndef BLOCK_PIVOT_TURN_H
#define BLOCK_PIVOT_TURN_H

#include "StraightRunner.h"
#include "Rotation.h"
#include "BingoMotion.h"
#include "ArmMotion.h"
#include "BlockThrower.h"
#include "InCrossLeft.h"
#include "InCrossRight.h"
#include "Measurer.h"
#include "Controller.h"

class BlockPivotTurn : public BingoMotion {
 public:
  //コンストラクタ
  BlockPivotTurn();

  /**
   * @brief ピボットターン設置する
   * @param isClockwise ピボットターンする向き true: 右回転
   */
  void setBlockPivotTurn(bool isClockwise);

 private:
  StraightRunner straightRunner;
  Rotation rotation;
  BlockThrower blockThrower;
  Measurer measurer;
  Controller controller;

  const double TREAD = 140;  // 走行体のトレッド幅（両輪の間の距離）[mm]
  const int MIN_PWM = 10;    // モーターパワーの最小値
};

#endif
