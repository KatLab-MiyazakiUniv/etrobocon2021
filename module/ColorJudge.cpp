/**
 * @file ColorJudge.cpp
 * @brief 色識別クラス
 * @author hiroto0927, miyashita64
 */

#include "ColorJudge.h"

ColorJudge::ColorJudge() {}

// RGBから色を判別する
COLOR ColorJudge::getColor(rgb_raw_t const& _rgb)
{
  rgb_raw_t rgb;
  hsv_raw_t hsv;
  int min;

  // 環境光による値の偏りを軽減する
  // 事前に測った白が(255,255,255)となるように、RGB値を変換する
  rgb.r = (_rgb.r < MAX_RGB.r) ? _rgb.r * 255 / MAX_RGB.r : 255;
  rgb.g = (_rgb.g < MAX_RGB.g) ? _rgb.g * 255 / MAX_RGB.g : 255;
  rgb.b = (_rgb.b < MAX_RGB.b) ? _rgb.b * 255 / MAX_RGB.b : 255;

  // HSV値に変換
  hsv = ColorJudge::getHsv(rgb);

  // RGBの中の最小値を求める
  min = std::min({ _rgb.r, _rgb.g, _rgb.b });

  // 明度が極端に低ければ、黒を返す
  if(hsv.value < BLACK_LIMIT_BORDER) return COLOR::BLACK;
  // 明度が極端に高ければ、白を返す
  if(min > WHITE_LIMIT_BORDER) return COLOR::WHITE;
  // 彩度が低い場合
  if(hsv.saturation < SATURATION_BORDER) {
    // 明度が低ければ、黒を返す
    if(hsv.value < BLACK_BORDER) return COLOR::BLACK;
  }

  // 各色相の境界によって、色を判別する
  if(hsv.hue < RED_BORDER) return COLOR::RED;
  if(hsv.hue < YELLOW_BORDER) return COLOR::YELLOW;
  if(hsv.hue < GREEN_BORDER) return COLOR::GREEN;
  if(hsv.hue < BLUE_BORDER) return COLOR::BLUE;
  return COLOR::RED;
}

// RGBをHSVに変換する
hsv_raw_t ColorJudge::getHsv(rgb_raw_t const& _rgb)
{
  hsv_raw_t hsv{ 0, 0, 0 };

  // RGBの中の最大・最小値を求める
  int max = std::max({ _rgb.r, _rgb.g, _rgb.b });
  int min = std::min({ _rgb.r, _rgb.g, _rgb.b });

  // maxが0の場合、黒を返す
  if(max == 0) {
    return hsv;
  }

  // 彩度
  hsv.saturation = 100 * (max - min) / max;
  // 輝度
  hsv.value = max;
  // 色相
  if(max == min) {
    hsv.hue = 0;
  } else if(_rgb.r == max) {
    hsv.hue = 60 * (_rgb.g - _rgb.b) / (max - min);
  } else if(_rgb.g == max) {
    hsv.hue = 60 * (_rgb.b - _rgb.r) / (max - min) + 120;
  } else if(_rgb.b == max) {
    hsv.hue = 60 * (_rgb.r - _rgb.g) / (max - min) + 240;
  }

  // マイナスの場合の補完
  hsv.hue = (hsv.hue + 360) % 360;

  return hsv;
}