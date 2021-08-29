/**
 * @file ArmMotion.cpp
 * @brief アーム動作クラス
 * @author kodama0720, yutotanaka24, hiroto0927, miyashita64
 */

#ifndef ARM_MOTION_H
#define ARM_MOTION_H

#include "Measurer.h"
#include "Controller.h"

class ArmMotion {
 public:
  /**
   * アームを目標の角位置に保つ
   */
  static void keepArm();

  /**
   * @brief アームを動かして投げ入れる動作
   */
  static void throwMotion(void);

  /**
   * @brief フラグのセッター
   * @param _keepFlag アームを水平に調整するかのフラグ
   */
  static void setKeepFlag(bool _keepFlag);

 private:
  // アームが水平なときの角位置
  static constexpr int HORIZONTAL_ARM_COUNT = -45;
  // アームを水平に調整するかのフラグ(true:調整する/false:調整しない)
  static bool keepFlag;

  /**
   * コンストラクタ
   * インスタンス化を禁止するためにpriveteにし、処理については記述していない
   */
  ArmMotion();
};

#endif
