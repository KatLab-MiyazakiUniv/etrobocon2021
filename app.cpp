#include "app.h"
#include "EtRobocon2021.h"
#include "ArmMotion.h"
#include "CourseInfo.h"
#include "RouteCalculator.h"
#include "Controller.h"
#include "Measurer.h"

void main_task(intptr_t unused)
{
  EtRobocon2021::start();
  ext_tsk();
}

void arm_task(intptr_t unused)
{
  while(true) {
    ArmMotion::keepArm();
  }
  ext_tsk();
}

void route_task(intptr_t unused)
{
  Controller controller;
  Measurer measurer;
  // BingoArea::runBingoArea()が呼び出されるまで待機
  //タッチセンサが押されるまで待機
  while(!measurer.isPressed()) {
    // while(RoutePlanner::plannerFlag == false) {
    controller.sleep();
  }
  controller.sleep(2000);
  // 経路計画開始
  RoutePlanner::planBingoRoute();
  ext_tsk();
}
