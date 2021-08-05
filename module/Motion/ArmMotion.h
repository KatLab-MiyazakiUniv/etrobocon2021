/**
 * @file ArmMotion.cpp
 * @brief アーム動作クラス
 * @author kodama0720, yutotanaka24
 */

#ifndef ARM_MOTION_H
#define ARM_MOTION_H

#include "Measurer.h"
#include "Controller.h"

class ArmMotion {
 public:
  /**
   * @brief アームを動かして投げ入れる動作
   */
  static void throwMotion(void);

 private:
  ArmMotion();
};

#endif
