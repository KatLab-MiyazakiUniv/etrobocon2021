/**
 * @file BlockCircle.cpp
 * @brief ブロックサークル情報を保持するクラス
 * @author Hisataka-Hagiyama,uchyam
 */

#include "BlockCircle.h"
BlockCircle::BlockCircle() : Node(){};

void BlockCircle::setCircleId(CIRCLE_ID id)
{
  circleId = id;
}

CIRCLE_ID BlockCircle::getCircleId()
{
  return circleId;
}
