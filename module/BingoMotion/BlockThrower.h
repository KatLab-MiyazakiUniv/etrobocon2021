/**
 * @file BlockThrower.h
 * @brief 投げ入れ設置クラス
 * @author kodama0720, yutotanaka24
 */

#ifndef BLOCK_THROWER_H
#define BLOCK_THROWER_H

#include "StraightRunner.h"
#include "Controller.h"
#include "BingoMotion.h"
#include "ArmMotion.h"

class BlockThrower : public BingoMotion {
 public:
  // コンストラクタ
  BlockThrower();

  /**
   * @brief 投げ入れ設置する
   * @param isClockwise 投げ入れる向き true: 右回転
   */
  void setBlockThrow(bool isClockwise);

 private:
  StraightRunner straightRunner;
  Controller controller;
  Measurer measurer;
  const double TREAD = 140;  // 走行体のトレッド幅（両輪の間の距離）[mm]
  const int MIN_PWM = 10;    // モーターパワーの最小値
};

#endif
