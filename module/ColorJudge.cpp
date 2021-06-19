/**
 * @file ColorJudge.cpp
 * @brief 色識別クラス
 * @author hiroto0927, miyashita64
 */

#include "ColorJudge.h"

ColorJudge::ColorJudge() {}

bool ColorJudge::isBlackWhite(colorid_t colorId)
{
  COLOR_NUMBER colorNumber = static_cast<COLOR_NUMBER>(colorId);
  return (colorNumber == COLOR_NUMBER::COLOR_BLACK || colorNumber == COLOR_NUMBER::COLOR_WHITE);
}