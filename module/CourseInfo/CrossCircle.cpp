/**
 * @file CrossCircle.cpp
 * @brief 交点サークル情報を保持するクラス
 * @author Hisataka-Hagiyama,uchyam
 */
#include "CrossCircle.h"
CrossCircle::CrossCircle() : Node(){};

void CrossCircle::setEdgeNumber(int num)
{
  edgeNumber = num;
}

int CrossCircle::getEdgeNumber()
{
  return edgeNumber;
}
