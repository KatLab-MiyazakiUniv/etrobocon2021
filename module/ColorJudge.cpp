/**
 * @file ColorJudge.cpp
 * @brief 色識別クラス
 * @author hiroto0927, miyashita64
 */

#include "ColorJudge.h"

ColorJudge::ColorJudge() {}

// RGBをHSVに変形し、色を判別する
COLOR ColorJudge::getColor(rgb_raw_t const& _rgb)
{
  int hue = 0;         // 色相(0-360)
  int saturation = 0;  // 彩度(0-100)
  int value = 0;       // 明度(0-255)

  rgb_raw_t rgb;

  // 環境光を打ち消す
  rgb.r = (_rgb.r < MAX_RGB.r) ? _rgb.r * 256 / MAX_RGB.r : 256;
  rgb.g = (_rgb.g < MAX_RGB.g) ? _rgb.g * 256 / MAX_RGB.g : 256;
  rgb.b = (_rgb.b < MAX_RGB.b) ? _rgb.b * 256 / MAX_RGB.b : 256;

  // RGBの中の最大・最小値を求める
  int max = (rgb.r > rgb.g && rgb.r > rgb.b) ? rgb.r : (rgb.g > rgb.b) ? rgb.g : rgb.b;
  int min = (rgb.r < rgb.g && rgb.r < rgb.b) ? rgb.r : (rgb.g < rgb.b) ? rgb.g : rgb.b;

  if(max == 0) {
    return COLOR::BLACK;
  }
  saturation = 100 * (max - min) / max;
  value = max;

  // 明度が極端に低ければ、黒を返す
  if(value < BLACK_LIMIT_BORDER) return COLOR::BLACK;
  // 明度が極端に高ければ、白を返す
  if(min > WHITE_LIMIT_BORDER) return COLOR::WHITE;
  // 彩度が低い場合
  if(saturation < SATURATION_BORDER) {
    // 明度が低ければ、黒を返す
    if(value < BLACK_BORDER) return COLOR::BLACK;
  }

  // 色相を計算
  if(max == min) {
    hue = 0;
  } else if(rgb.r == max) {
    hue = 60 * (rgb.g - rgb.b) / (max - min);
  } else if(rgb.g == max) {
    hue = 60 * (rgb.b - rgb.r) / (max - min) + 120;
  } else if(rgb.b == max) {
    hue = 60 * (rgb.r - rgb.g) / (max - min) + 240;
  }

  // マイナスの場合の補完
  hue = (hue + 360) % 360;

  // 各境界によって、色を判別する
  if(hue < RED_BORDER) return COLOR::RED;
  if(hue < YELLOW_BORDER) return COLOR::YELLOW;
  if(hue < GREEN_BORDER) return COLOR::GREEN;
  if(hue < BLUE_BORDER) return COLOR::BLUE;
  return COLOR::RED;
}
