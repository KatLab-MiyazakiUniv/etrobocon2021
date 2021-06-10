/**
 * @file EtRobocon2021.cpp
 * @brief 全体を制御するクラス
 * @author Hisataka-Hagiyama,uchyam
 **/

#include "EtRobocon2021.h"
#include "LineTraceArea.h"
/*
 * タッチセンサーを押すと直進する
 * エンターボタンを押すと止まる
 * 下ボタンを押すとカラーセンサーのRGBをターミナルに表示する
 */
void EtRobocon2021::start()
{
  Measurer measurer;
  //タッチセンサが押されるまで待機
  while(!measurer.isPressed()) {
    tslp_tsk(10);
  }

  //ライントレースエリア攻略
  LineTraceArea::runLineTraceArea();
}
