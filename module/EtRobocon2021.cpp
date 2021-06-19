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
  /*
  for(i=0; i<3; i++){
    rotation.rotate(90, 30);
    rotation.rotate(-90, 30);
  }
  */
  for(i=0; i<3; i++){
    rotation.turnRightPivot(90, 30);
    rotation.turnRightPivot(-90, 30);
    rotation.turnLeftPivot(90, 30);
    rotation.turnLeftPivot(-90, 30);
  }

  //ライントレースエリア攻略開始
  //LineTraceArea::runLineTraceArea();
}
