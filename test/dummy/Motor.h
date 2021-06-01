/**
 * @file Measure.cpp
 * @brief モータクラス（ダミー）
 * @author kodama0720, yutotanaka24
 */

#ifndef MOTOR_H
#define MOTOR_H

#include "Port.h"
#include "ev3api.h"

namespace ev3api {

//モータクラス
class Motor {
 public:
  double count = 0.0;

  /**
   * コンストラクタ
   * @param port  モータポート番号
   * @param brake true:ブレーキモード/false:フロートモード
   * @param type  モータタイプ 
   * @return -
   */
  explicit Motor(ePortM port, bool brake = true, motor_type_t type = LARGE_MOTOR);
  
  /**
   * モータ角位置取得
   * @return モータ角位置[deg]
   */
  int getCount();
};
}  // namespace ev3api

#endif
