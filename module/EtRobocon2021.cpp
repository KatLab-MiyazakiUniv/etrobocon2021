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
  LineTracer trace(true);

  //タッチセンサが押されるまで待機
  while(!measurer.isPressed()) {
    controller.sleep();
  }

  //ライントレースエリア攻略開始
  // LineTraceArea::runLineTraceArea();
  trace.run(350, 12, 60, PidGain(0.1, 0.8, 0.1));
  bingoArea.initBingoArea();
  RouteCalculator route(bingoArea);
  std::vector<std::pair<Coordinate, Direction>> minroute = route.calculateRoute({ 2, 4 }, { 1, 1 });
  for(auto i : minroute) {
    printf("%d %d %d\n", i.first.x, i.first.y, i.second);
  }
  //シミュレータへ競技の終了を通知する
  controller.notifyCompletedToSimulator();
}
