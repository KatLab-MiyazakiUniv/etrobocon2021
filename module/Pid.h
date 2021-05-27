/**
 *  @file Pid.h
 *  @brief PIDを計算するクラス
 *  @author Hisataka-Hagiyama,uchiyam
 */

#ifndef PID_H
#define PID_H

static const double DELTA = 0.01;  //周期[10ミリ秒]

// PIDゲインを保持する構造体
struct PidGain {
 public:
  double kp;  // Pゲイン
  double ki;  // Iゲイン
  double kd;  // Dゲイン

  /** コンストラクタ
   *  @param _kp Pゲイン
   *  @param _ki Iゲイン
   *  @param _kd Dゲイン
   */
  PidGain(double _kp, double _ki, double _kd);
};

class Pid {
 public:
  /** コンストラクタ
   *  @param _kp Pゲイン
   *  @param _ki Iゲイン
   *  @param _kd Dゲイン
   */
  Pid(double _kp, double _ki, double _kd);

  /**
   * @fn void setPidParam(double _kp, double _ki, double _kd);
   * @brief PIDゲインを設定する
   * @param _kp Pゲイン
   * @param _ki Iゲイン
   * @param _kd Dゲイン
   */
  void setPidGain(double _kp, double _ki, double _kd);

  /**
   * @fn double calculatePid(double targetValue, double presentValue);
   * @brief PIDを計算する
   * @param targetValue 目標値
   * @param presentValue 現在値
   * @return PIDの計算結果(操作量)
   */
  double calculatePid(double targetValue, double presentValue);

 private:
  PidGain gain;
  double preDeviation;  //前回の偏差
  double integral;      //偏差の累積
};

#endif