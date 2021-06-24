/**
 * @file ColorJudge.cpp
 * @brief 色識別クラス
 * @author hiroto0927, miyashita64
 */

//* 消す
#include <stdio.h>
#include <string>
#include <iostream>
//*/
#include "ColorJudge.h"

ColorJudge::ColorJudge() {}

// RGBをHSVに変形し、色を判別する
COLOR ColorJudge::getColor(rgb_raw_t const& rgb)
{
  int hue = 0;         // 色相(0-360)
  int saturation = 0;  // 彩度(0-100)
  int value = 0;       // 明度(0-255)

  int max = (rgb.r > rgb.g && rgb.r > rgb.b) ? rgb.r : (rgb.g > rgb.b) ? rgb.g : rgb.b;
  int min = (rgb.r < rgb.g && rgb.r < rgb.b) ? rgb.r : (rgb.g < rgb.b) ? rgb.g : rgb.b;

  if(max == 0) {
    return COLOR::BLACK;
  }
  saturation = 100 * (max - min) / max;
  value = max;

  // 明度が低ければ、黒を返す
  if(value < BLACK_BORDER) return COLOR::BLACK;
  // 彩度が低い場合
  if(saturation < SATURATION_BORDER) {
    // 明度が高ければ、白を返す
    if(value > WHITE_BORDER) return COLOR::WHITE;
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