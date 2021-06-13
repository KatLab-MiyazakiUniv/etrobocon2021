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
 * 左コース/右コース向けの設定を定義
 * デフォルトは左コース
 */
#if defined(MAKE_RIGHT)
static const bool IS_LEFT = false;  //右コース
#else
static const bool IS_LEFT = true;  //左コース
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
  static const int LEFTSECTIONSIZE = 7;   //左コースの区間の数
  static const int RIGHTSECTIONSIZE = 7;  //右コースの区間の数
  static const std::array<SectionParam, LEFTSECTIONSIZE> LEFTCOURSEINFO;    //左コースの情報
  static const std::array<SectionParam, RIGHTSECTIONSIZE> RIGHTCOURSEINFO;  //右コースの情報

  /**
   * コンストラクタ
   * インスタンス化を禁止するためにpriveteにし、処理については記述していない
   */
  LineTraceArea();
};

#endif
