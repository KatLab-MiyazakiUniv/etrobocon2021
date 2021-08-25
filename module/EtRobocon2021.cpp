/**
 * @file EtRobocon2021.cpp
 * @brief 全体を制御するクラス
 * @author Hisataka-Hagiyama,uchyam
 */

#include "EtRobocon2021.h"
#include "Rotation.h"

void EtRobocon2021::start()
{
  Controller controller;
  Measurer measurer;

  //タッチセンサが押されるまで待機
  while(!measurer.isPressed()) {
    controller.sleep();
  }

  printf("!!!!! START !!!!!\n");

  Rotation rotation;
  int angle = 180;
  int pwm = 100;
  int angleKey = 1;
  while(true) {
    if(measurer.isPressed()) {
      angleKey = angleKey % 2 + 1;
      angle = angleKey * 90;
      rotation.rotateLeft(angle, pwm);
    }
    controller.sleep();
  }

  //ライントレースエリア攻略開始
  LineTraceArea::runLineTraceArea();

  //シミュレータへ競技の終了を通知する
  controller.notifyCompletedToSimulator();
}
