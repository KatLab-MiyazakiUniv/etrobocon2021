/**
 *  @file Pid.cpp
 *  @brief PIDを計算するクラス
 *  @author Hisataka-Hagiyama,uchiyam
 */

#include "Pid.h"

PidGain::PidGain(double _kp, double _ki, double _kd) : kp(_kp), ki(_ki), kd(_kd) {}

Pid::Pid(double _kp, double _ki, double _kd) : gain(_kp, _ki, _kd), integral(0), preDeviation(0) {}

void Pid::setPidGain(double _kp, double _ki, double _kd)
{
  gain.kp = _kp;
  gain.ki = _ki;
  gain.kd = _kd;
}

double Pid::calculatePid(double targetValue, double presentValue)
{
  //現在の偏差を求める
  double presentDeviation = targetValue - presentValue;
  //積分の処理を行う
  integral += presentDeviation * DELTA;
  //微分の処理を行う
  double difference = (presentDeviation - preDeviation) / DELTA;
  //前回の偏差を更新する
  preDeviation = presentDeviation;

  // P制御の計算を行う
  double p = gain.kp * presentDeviation;
  // I制御の計算を行う
  double i = gain.ki * integral;
  // D制御の計算を行う
  double d = gain.kd * difference;

  //操作量 = P制御 + I制御 + D制御
  return (p + i + d);
}
