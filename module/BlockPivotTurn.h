/**
 * @file BlockPivotTurn.h
 * @brief ピボットターン設置クラス
 * @author kodama0720, yutotanaka24
 */

#ifndef BLOCK_PIVOT_TURN_H
#define BLOCK_PIVOT_TURN_H

#include "StraightRunner.h"
#include "Rotation.h"
#include "Controller.h"
#include "BingoMotion.h"

class BlockPivotTurn : public BingoMotion{
  public:
  /**
   * @brief ピボットターン設置する
   * @param isLeft ピボットターンする向き true: 左向き
   */
  void setBlockPivotTurn(bool isLeft);
  
  private:
  StraightRunner straightRunner;
  Rotation rotation;
  Controller controller;
  Measurer measurer;
};

#endif
