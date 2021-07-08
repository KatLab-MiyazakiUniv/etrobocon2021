/**
 * @file BlackBlockCarrier.h
 * @brief 黒ブロックを取得してセンターマークまで運搬する
 * @author kodama0720, yutotanaka24
 */

#ifndef BlackBlockCarrier_H
#define BlackBlockCarrier_H

#include <cmath>
#include "Controller.h"
#include "Measurer.h"
#include "Mileage.h"
#include "Rotation.h"
#include "LineTracer.h"

class BlackBlockCarrier {
    public:

    void carryBlackBlock(void);

    private:
    bool isLeftEdge;
    Mileage mileage;
    Measurer measurer;
    Controller controller;
    Rotation rotation;
    LineTracer linetracer;

};
#endif