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
  //
  Rotation rotation;

  //タッチセンサが押されるまで待機
  while(!measurer.isPressed()) {
    controller.sleep();
  }

  int i;

  for(i = 0; i < 3; i++) {
    rotation.rotateLeft(90, 30);
    rotation.rotateRight(90, 30);
  }

  for(i = 0; i < 3; i++) {
    rotation.turnForwardRightPivot(90, 30);
    rotation.turnBackRightPivot(90, 30);
    rotation.turnForwardLeftPivot(90, 30);
    rotation.turnBackLeftPivot(90, 30);
  }

  //ライントレースエリア攻略開始
  // LineTraceArea::runLineTraceArea();
}
