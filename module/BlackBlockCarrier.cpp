/**
 * @file BlackBlockCarrier.cpp
 * @brief 黒ブロックを取得してセンターマークまで運搬する
 * @author kodama0720, yutotanaka24
 */
#include "BlackBlockCarrier.h"

LineTracer::LineTracer(bool _isLeftEdge) : isLeftEdge(_isLeftEdge) {}

void BlackBlockCarrier::carryBlackBlock(void)
{
    int runPwm = 100.0;
    int anglePwm = 60.0;
    int blackAngle = 90;
    double circleDistance = 50;
    PidGain gain(3, 1, 1);

    //黄色の円まで
    void LineTracer::runToColor(int targetBrightness, runPwm, PidGain gain);
    //黄色の円を通過
    void StraightRunner::runStraightToDistance(circleDistance, runPwm);
    //緑の円まで
    void LineTracer::runToColor(int targetBrightness, runPwm, PidGain gain);
    //緑の中心まで
    void StraightRunner::runStraightToDistance((circleDistance / 2), runPwm);
    //右に９０度回頭
    void Rotation::rotateRight(blackAngle, anglePwm);
    //黒のラインまで直進
    void StraightRunner::runStraightToDistance((circleDistance / 2), runPwm);
    //赤の円まで
    void LineTracer::runToColor(int targetBrightness, runPwm, PidGain gain);
    //赤の円を通過
    void StraightRunner::runStraightToDistance(circleDistance, runPwm);


}