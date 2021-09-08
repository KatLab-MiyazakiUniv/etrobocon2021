/**
 * @file LineTracer.h
 * @brief ライントレースする
 * @author yutotanaka24,kodama0720
 */

#ifndef LINE_TRACER_H
#define LINE_TRACER_H

#include "Pid.h"
#include "Measurer.h"
#include "Mileage.h"
#include "Controller.h"
#include "ColorJudge.h"

/**
 * ライントレースをするクラス
 */
class LineTracer {
 public:
  /**
   * コンストラクタ
   * @param _isLeftEdge コースのLR判定
   */
  LineTracer(bool _isLeftEdge);

  /**
   * 指定された距離の間ライントレースをする関数
   * @param targetDistance 目標距離
   * @param targetBrightness 目標輝度
   * @param pwm PWM値
   * @param gain PIDを保持する構造体
   */
  void run(double targetDistance, int targetBrightness, int pwm, const PidGain& gain);

  /**
   * 白黒を判定している間ライントレースをする関数
   * @param targetBrightness 目標輝度
   * @param pwm PWM値
   * @param gain PIDを保持する構造体
   */
  void runToColor(int targetBrightness, int pwm, const PidGain& gain);

  /**
   * エッジのゲッター
   * @return true: 左エッジ, false: 右エッジ
   */
  bool getIsLeftEdge();

  /**
   * エッジのセッター
   * @param _isLeftEdge true: 左エッジ, false: 右エッジ
   */
  void setIsLeftEdge(bool _isLeftEdge);

  /**
   * エッジを切り替える
   */
  void toggleEdge();

 private:
  bool isLeftEdge;
  Measurer measurer;
  Controller controller;
};

#endif
