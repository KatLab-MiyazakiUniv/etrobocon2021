/**
 * @file SetColorBlockMotion.h
 * @brief カラーブロック設置クラス
 * @author kodama0720, yutotanaka24
 */

#ifndef BINGO_MOTION_H
#define BINGO_MOTION_H

#include "StraightRunner.h"
#include "Rotation.h"
#include "Controller.h"

class SetColorBlockMotion : public BingoMotion {
 public:
  SetColorBlockMoion();

  /**
   * @brief 投げ入れ設置する
   * @param isLeft 投げ入れる向き true: 左向き
   */
  void throwBlock(bool isLeft);

  /**
   * @brief ピボットターン設置する
   * @param isLeft ピボットターンする向き true: 左向き
   */
  void setBlockPivotTurn(book isLeft);

  private:
  StraightRunner straightRunner;
  Rotation rotation;
  Controller controller;
};

#endif
