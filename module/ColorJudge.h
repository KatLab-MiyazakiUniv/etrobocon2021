/**
 * @file ColorJudge.cpp
 * @brief 色識別クラス
 * @author hiroto0927, miyashita64
 */

#ifndef COLOR_JUDGE_H
#define COLOR_JUDGE_H

#include "Measurer.h"

class ColorJudge {
 public:
  static bool isBlackWhite(COLOR_NUMBER colorNumber);

 private:
  ColorJudge();
};

#endif