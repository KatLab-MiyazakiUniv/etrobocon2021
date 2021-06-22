/**
 * @file ColorJudge.h
 * @brief 色識別クラス
 * @author hiroto0927, miyashita64
 */

#ifndef COLOR_JUDGE_H
#define COLOR_JUDGE_H

#include "Measurer.h"

enum class COLOR_NUMBER : int {
  COLOR_NONE = 0,
  COLOR_BLACK = 1,
  COLOR_BLUE = 2,
  COLOR_GREEN = 3,
  COLOR_YELLOW = 4,
  COLOR_RED = 5,
  COLOR_WHITE = 6,
};

class ColorJudge {
 public:
  /**
   * 与えられたRGB値が、無彩色(白黒)かを判定する
   * @param rgb RGB値の参照
   * @return true: 黒白, false: それ以外
   */
  static bool isBlackWhite(rgb_raw_t& rgb);

  /**
   * 与えられたRGB値から、何色かを返す
   * @param rgb RGB値の参照
   * @return 色
   */
  static COLOR_NUMBER getColorNumber(rgb_raw_t& rgb);

 private:
  static const int SATURATION_BORDER = 70;  // 無彩色かの彩度の境界
  static const int RED_BORDER = 30;         // 赤の色相の境界
  static const int YELLOW_BORDER = 75;      // 黄の色相の境界
  static const int GREEN_BORDER = 165;      // 緑の色相の境界
  static const int BLUE_BORDER = 300;       // 青の色相の境界
  static const int VALUE_BORDER = 128;      // 白か黒かの明度の境界
  ColorJudge();
};

#endif