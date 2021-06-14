/**
 * @file LineTraceArea.h
 * @brief ライントレースエリアを攻略するクラス
 * @author Hisataka-Hagiyama,uchyam
 */

#ifndef LINETRACEAREA_H
#define LINETRACEAREA_H
#include "array"
#include "LineTracer.h"
#include "Pid.h"

/**
 * Lコース/Rコース向けの設定を定義
 * デフォルトはLコース
 */
#if defined(MAKE_RIGHT)
static const bool IS_LEFT = false;  // Rコース
#else
static const bool IS_LEFT = true;  // Lコース
#endif

//区間の情報を保持する構造体
struct SectionParam {
  double sectionDistance;       //区間の走行距離
  int sectionTargetBrightness;  //区間の目標輝度
  int sectionPWM;               //区間のPWM値
  PidGain sectionPidGain;       //区間のPIDゲイン
};

class LineTraceArea {
 public:
  /**
   *@fn static void RunLineTraceArea();
   *@brief ライントレースエリアを走行する
   */
  static void runLineTraceArea();

 private:
  static const int LEFTSECTIONSIZE = 7;   // Lコースの区間の数
  static const int RIGHTSECTIONSIZE = 7;  // Rコースの区間の数
  static const std::array<SectionParam, LEFTSECTIONSIZE> LEFTCOURSEINFO;    // Lコースの情報
  static const std::array<SectionParam, RIGHTSECTIONSIZE> RIGHTCOURSEINFO;  // Rコースの情報

  /**
   * コンストラクタ
   * インスタンス化を禁止するためにpriveteにし、処理については記述していない
   */
  LineTraceArea();
};

#endif
