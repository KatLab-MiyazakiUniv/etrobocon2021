/**
 * @file BlackBlockCarrier.cpp
 * @brief 黒ブロックを取得してセンターマークまで運搬する
 * @author kodama0720, yutotanaka24
 */
#include "BlackBlockCarrier.h"

LineTracer::LineTracer(bool _isLeftEdge) : isLeftEdge(_isLeftEdge) {}

void BlackBlockCarrier::carryBlackBlock(void)
{
    int straightPwm = 100.0;
    int anglePwm = 60.0;
    int blackAngle = 90;
    double circleDistance = 50;
    PidGain gain(3, 1, 1);

}