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

class BlockThrower : public BingoMotion{
  public:
  /**
   * @brief 投げ入れ設置する
   * @param isLeft 投げ入れる向き true: 左向き
   */
  void throwBlock(bool isLeft);
  
  private:
  StraightRunner straightRunner;
  Rotation rotation;
  Controller controller;
  Measurer measurer;
};

#endif