/**
 * @file ColorJudge.h
 * @brief 色識別クラス
 * @author hiroto0927, miyashita64
 */

#ifndef COLOR_JUDGE_H
#define COLOR_JUDGE_H

#include "Measurer.h"

enum class COLOR : int {
  NONE = 0,
  BLACK = 1,
  BLUE = 2,
  GREEN = 3,
  YELLOW = 4,
  RED = 5,
  WHITE = 6,
};

class ColorJudge {
 public:
  /**
   * 与えられたRGB値から、何色かを返す
   * @param rgb RGB値の参照
   * @return 色
   */
  static COLOR getColor(rgb_raw_t const& rgb);

 private:
  static constexpr int SATURATION_BORDER = 50;  // 無彩色かの彩度の境界

  static constexpr int BLACK_LIMIT_BORDER = 50;  // 黒の明度の境界
  static constexpr int WHITE_LIMIT_BORDER = 90;  // 白の明度の境界
  static constexpr int BLACK_BORDER = 100;       // 無彩色の黒の明度の境界

  static constexpr int RED_BORDER = 30;                    // 赤の色相の境界
  static constexpr int YELLOW_BORDER = 75;                 // 黄の色相の境界
  static constexpr int GREEN_BORDER = 165;                 // 緑の色相の境界
  static constexpr int BLUE_BORDER = 300;                  // 青の色相の境界
  static constexpr rgb_raw_t MAX_RGB = { 112, 107, 152 };  //コースが白の時（最大）のRGB値
  ColorJudge();
};

#endif