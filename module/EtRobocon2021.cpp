/**
 * @file EtRobocon2021.cpp
 * @brief 全体を制御するクラス
 * @author Hisataka-Hagiyama,uchyam
 */

#include "EtRobocon2021.h"

/*
 * タッチセンサーを押すと直進する
 * エンターボタンを押すと止まる
 * 下ボタンを押すとカラーセンサーのRGBをターミナルに表示する
 */
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
}