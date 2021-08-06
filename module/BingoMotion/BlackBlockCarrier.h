/**
 * @file BlackBlockCarrier.h
 * @brief 黒ブロックを取得してセンターマークまで運搬する
 * @author kodama0720, yutotanaka24
 */

#ifndef BLACK_BLOCK_CARRIER_H
#define BLACK_BLOCK_CARRIER_H

#include "Rotation.h"
#include "LineTracer.h"
#include "StraightRunner.h"

class BlackBlockCarrier {
 public:
  static void carryBlackBlock();
};
#endif