/**
 * @file ColorJudge.cpp
 * @brief 色識別クラス
 * @author hiroto0927, miyashita64
 */

#ifndef COLOR_JUDGE_H
#define COLOR_JUDGE_H

#include "Measurer.h"

// 色識別番号
enum class COLOR_NUMBER : int {
  COLOR_NONE = 0,
  COLOR_BLACK = 1,
  COLOR_BLUE = 2,
  COLOR_GREEN = 3,
  COLOR_YELLOW = 4,
  COLOR_RED = 5,
  COLOR_WHITE = 6,
  COLOR_BROWN = 7,
  TNUM_COLOR  // サイズ
};

class ColorJudge {
 public:
  static bool isBlackWhite(colorid_t colorId);

 private:
  ColorJudge();
};

#endif