/**
 * @file BingoArea.h
 * @brief ビンゴエリアを攻略するクラス
 * @author Hisataka-Hagiyama,uchyam
 */
#include "RoutePlanner.h"
#include "MotionConverter.h"
#include "CourseInfo.h"
#include "LineTraceArea.h"
#include "LineTracer.h"
#include "BlackBlockCarrier.h"
#ifndef BINGOAREA_H
#define BINGOAREA_H

class BingoArea {
 public:
  /**
   *@fn static void RunBingoArea();
   *@brief ビンゴエリアを走行する
   */
  static void runBingoArea();

 private:
  /**
   * コンストラクタ
   * インスタンス化を禁止するためにpriveteにし、処理については記述していない
   */
  BingoArea();
};

#endif
