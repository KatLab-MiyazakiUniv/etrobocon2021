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

class BlockPivotTurn : public BingoMotion{
  public:
  /**
   * @brief ピボットターン設置する
   * @param isClockwise ピボットターンする向き true: 右向き
   */
  void setBlockPivotTurn(bool isClockwise);
  
  private:
  StraightRunner straightRunner;
  Rotation rotation;
};

#endif
