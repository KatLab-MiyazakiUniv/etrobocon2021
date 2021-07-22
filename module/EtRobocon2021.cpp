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
  BingoArea bingoArea;
  std::vector<Coordinate> minroute;

  //タッチセンサが押されるまで待機
  while(!measurer.isPressed()) {
    controller.sleep();
  }

  //ライントレースエリア攻略開始
  LineTraceArea::runLineTraceArea();
  bingoArea.initBingoArea();
  RouteCalculater route(bingoArea);
  route.calculateRoute(minroute, { 2, 4 }, { 5, 3 });
  for(auto i : minroute) {
    printf("%d %d\n", i.x, i.y);
  }
  //シミュレータへ競技の終了を通知する
  controller.notifyCompletedToSimulator();
}
