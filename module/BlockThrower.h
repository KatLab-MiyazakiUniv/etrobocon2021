/**
 * @file BlockThrower.h
 * @brief 投げ入れ設置クラス
 * @author kodama0720, yutotanaka24
 */

#ifndef BLOCK_THROWER_H
#define BLOCK_THROWER_H

#include "StraightRunner.h"
#include "Rotation.h"
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
  void throwBlock(bool isClockwise);

 private:
  StraightRunner straightRunner;
  Rotation rotation;
  Controller controller;
  Measurer measurer;
};

#endif
