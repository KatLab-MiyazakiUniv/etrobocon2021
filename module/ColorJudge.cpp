/**
 * @file ColorJudge.cpp
 * @brief 色識別クラス
 * @author hiroto0927, miyashita64
 */

#include "ColorJudge.h"

ColorJudge::ColorJudge() {}

bool ColorJudge::isBlackWhite(COLOR_NUMBER colorNumber)
{
  return (colorNumber == COLOR_NUMBER::COLOR_BLACK || colorNumber == COLOR_NUMBER::COLOR_WHITE);
}