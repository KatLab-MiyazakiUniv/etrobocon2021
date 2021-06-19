/**
 * @file Rotation.h
 * @brief 回頭・ピボットターンするクラス
 * @author kodama0720, yutotanaka24
 */

#ifndef ROTATION_H
#define ROTATION_H

#include "Controller.h"
#include "Measurer.h"

class Rotation{
  public:
  /**
  * @param angle 回転角度(deg)
  * @param pwm PWM値
  */
  void rotate(int angle, int pwm);

  private:
  Controller controller;
  Measurer measurer;
};

#endif
