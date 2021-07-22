/**
 * @file ChangeDirection.cpp
 * @brief 方向転換クラス
 * @author kodama0720, yutotanaka24
 */

#include "ChangeDirection.h"

ChangeDirection::ChangeDirection(LineTracer& _lineTracer) : lineTracer(_lineTracer) {}

void ChangeDirection::turnAround(int angle){
  int pwm = 30;

  //回転方向を判定
  if(angle >= 0){
    rotation.rotateLeft(angle, pwm);
  }else{
    rotation.rotateRight(angle, pwm);
  }

  //エッジ切り替え

  //色サークルに乗るまで直進

  //白黒を判定するまで進む

}
