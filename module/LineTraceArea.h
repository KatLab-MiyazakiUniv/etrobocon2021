/**
 * @file LineTraceArea.h
 * @brief ライントレースエリアを攻略するクラス
 * @author Hisataka-Hagiyama,uchyam
 */

#ifndef LINETRACEAREA_H
#define LINETRACEAREA_H
#include "Pid.h"
#include "array"
//ライントレースエリアの情報を持つ配列のサイズ（ライントレースエリアにおける区間の数）
static const int ARRAYSIZE = 7;

/**
 * 左コース/右コース向けの設定を定義
 * デフォルトは左コース
 */
#if defined(MAKE_RIGHT)
const int _EDGE = -1;  //右コースの走行で使う値
#else
const int _EDGE = 1;  //左コースの走行で使う値(makeコマンドで引数を指定しなければこちらの値となる)
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
  static const std::array<SectionParam, ARRAYSIZE> rightCourseInfo;  //右コースの情報
  static const std::array<SectionParam, ARRAYSIZE> leftCourseInfo;   //左コースの情報

  /**
   * コンストラクタ
   * インスタンス化を禁止するためにpriveteにし、処理については記述していない
   */
  LineTraceArea();
};

#endif
