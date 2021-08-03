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
  Robot robot(true);
  LineTracer trace(true);
  BingoArea bingoArea;
  MotionConverter motion;
  //タッチセンサが押されるまで待機
  while(!measurer.isPressed()) {
    controller.sleep();
  }
  trace.run(350, 12, 60, PidGain(0.1, 0.8, 0.1));
  bingoArea.initBingoArea();
  robot.setDirection(Direction::N);
  RouteCalculator route(bingoArea, robot);
  std::vector<std::pair<Coordinate, Direction>> minroute = route.calculateRoute({ 4, 2 }, { 2, 0 });
  for(auto i : minroute) {
    printf("%d %d %d\n", i.first.x, i.first.y, i.second);
  }
  std::vector<MOTION> mlist = motion.convertMotion(minroute);
  for(auto i : mlist) {
    printf("%d\n", i);
  }
  // シミュレータへ競技の終了を通知する
  controller.notifyCompletedToSimulator();
}
