/**
 * @file ColorJudge.cpp
 * @brief 色識別クラス
 * @author hiroto0927, miyashita64
 */

#include "ColorJudge.h"

ColorJudge::ColorJudge() {}

// 与えられたRGB値が、白黒かを判定する
bool ColorJudge::isBlackWhite(rgb_raw_t& rgb)
{
  rgb_raw_t& rgbRef = rgb;
  COLOR_NUMBER colorNumber = getColorNumber(rgbRef);
  return (colorNumber == COLOR_NUMBER ::COLOR_BLACK || colorNumber == COLOR_NUMBER ::COLOR_WHITE);
}

COLOR_NUMBER ColorJudge::getColorNumber(rgb_raw_t& rgb)
{
  int hue = 0;         // 色相(0-360)
  int saturation = 0;  // 彩度(0-100)
  int value = 0;       // 明度(0-255)

  int max = (rgb.r > rgb.g && rgb.r > rgb.b) ? rgb.r : (rgb.g > rgb.b) ? rgb.g : rgb.b;
  int min = (rgb.r < rgb.g && rgb.r < rgb.b) ? rgb.r : (rgb.g < rgb.b) ? rgb.g : rgb.b;

  if(max == 0) {
    return COLOR_NUMBER::COLOR_BLACK;
  }
  saturation = 100 * (max - min) / max;
  value = max;

  // 白黒(彩度が低い)の場合
  if(saturation < SATURATION_BORDER) {
    // 明度が低ければ、黒を返す
    if(value < VALUE_BORDER) return COLOR_NUMBER::COLOR_BLACK;
    // 明度が低くなければ、白を返す
    return COLOR_NUMBER::COLOR_WHITE;
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
  if(hue < RED_BORDER) return COLOR_NUMBER::COLOR_RED;
  if(hue < YELLOW_BORDER) return COLOR_NUMBER::COLOR_YELLOW;
  if(hue < GREEN_BORDER) return COLOR_NUMBER::COLOR_GREEN;
  if(hue < BLUE_BORDER) return COLOR_NUMBER::COLOR_BLUE;
  return COLOR_NUMBER::COLOR_RED;
}