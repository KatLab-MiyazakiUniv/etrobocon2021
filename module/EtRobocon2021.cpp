/**
 * @file EtRobocon2021.cpp
 * @brief 全体を制御するクラス
 * @author Hisataka-Hagiyama,uchyam
 */

#include "EtRobocon2021.h"

void EtRobocon2021::start()
{
  Controller controller;
  Measurer measurer;

  //タッチセンサが押されるまで待機
  while(!measurer.isPressed()) {
    controller.sleep();
  }

  //ライントレースエリア攻略開始
  LineTraceArea::runLineTraceArea();
  //ビンゴエリア攻略開始
  BingoArea::runBingoArea();
  //シミュレータへ競技の終了を通知する
  controller.notifyCompletedToSimulator();
}
