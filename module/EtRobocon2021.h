/**
 * @file EtRobocon2021.h
 * @brief 全体を制御するクラス
 * @author Hisataka-Hagiyama,uchyam
 */

#ifndef ETROBOCON2021_H
#define ETROBOCON2021_H

#include "Controller.h"
#include "LineTraceArea.h"
#include "Measurer.h"
#include "BingoArea.h"
#include "LineTracer.h"
#include "RouteCalculator.h"
#include "MotionConverter.h"
class EtRobocon2021 {
 public:
  static void start();
};

#endif
