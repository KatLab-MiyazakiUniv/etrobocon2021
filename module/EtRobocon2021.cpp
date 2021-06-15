#include "EtRobocon2021.h"
#include "stdio.h"
#include "Controller.h"
#include "Measurer.h"
#include "LineTracer.h"

/*
 * タッチセンサーを押すと直進する
 * エンターボタンを押すと止まる
 * 下ボタンを押すとカラーセンサーのRGBをターミナルに表示する
 */
void EtRobocon2021::start()
{
  Controller controller;
  Measurer measurer;
  LineTracer lineTracer(true);
  // PidGain gain(0.6, 0.01, 0.01);

  while(!measurer.isPressed()) {
    controller.sleep();
  }

  lineTracer.run(1625.34, 20, 30, PidGain(0.8, 0.01, 0.01));
  controller.sleep(2000);
  lineTracer.run(594.506, 20, 30, PidGain(0.8, 0.01, 0.01));
  controller.sleep(2000);
  lineTracer.run(690.288, 20, 30, PidGain(0.8, 0.01, 0.01));
  controller.sleep(2000);
  lineTracer.run(511.724, 20, 30, PidGain(0.8, 0.01, 0.01));
  controller.sleep(2000);
  lineTracer.run(1709.7, 20, 30, PidGain(0.8, 0.01, 0.01));
  controller.sleep(2000);
  lineTracer.run(309.562, 20, 30, PidGain(0.8, 0.01, 0.01));
  controller.sleep(2000);
  lineTracer.run(807.404, 20, 30, PidGain(0.8, 0.01, 0.01));
}
