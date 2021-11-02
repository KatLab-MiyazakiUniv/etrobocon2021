/**
 * @file	MotionPerformer.h
 * @brief	動作実行クラス
 * @author	Hisataka-Hagiyama,uchyam
 */
#ifndef MOTION_PERFORMER_H
#define MOTION_PERFORMER_H

#include "InCrossStraight.h"
#include "InCrossRight.h"
#include "InCrossLeft.h"
#include "ToCrossMotion.h"
#include "DirectionChanger.h"
#include "BlockPivotTurn.h"
#include "BlockThrower.h"
#include <vector>

enum class MOTION {
  RF = 0,    //(直進:Run Forward)
  RR = 1,    //(右折:Run Right)
  RL = 2,    //(左折:Run Left)
  RTC = 3,   //(交点間:Run To Cross)
  SBPR = 4,  //(右回転ピボットターン設置:Set Block Pivot turn Right)
  SBPL = 5,  //(左回転ピボットターン設置:Set Block Pivot turn Left)
  SBTR = 6,  //(右回転投げ入れ設置:Set Block Throw Right)
  SBTL = 7,  //(左回転投げ入れ設置:Set Block Throw Left)
  CDC = 8,   //(時計回りに45度方向転換:Change Direction Clockwise)
  CDRC = 9,  //(反時計回りに45度方向転換:Change Direction Reverse Clockwise)
};

class MotionPerformer {
 public:
  //コンストラクタ
  MotionPerformer(LineTracer& _lineTracer);

  /**
   * @fn void runForward(void);
   * @brief 交点内移動（直進）を実行する
   */
  void runForward(void);

  /**
   * @fn void runRight(void);
   * @brief 交点内移動（右折）を実行する
   */
  void runRight(void);

  /**
   * @fn void runLeft(void);
   * @brief 交点内移動（左折）を実行する
   */
  void runLeft(void);

  /**
   * @fn void runToCross(void);
   * @brief 交点間移動を実行する
   */
  void runToCross(void);

  /**
   * @fn void changeDirection(int rotateAngle, int changeAngle);
   * @brief 方向転換を実行する
   * @param rotateAngle 回転角度（deg） -180 < angle <= 180 45度刻み
   * @param changeAngle 設置動作の直前方向から見て回頭する角度
   */
  void changeDirection(int rotateAngle, int changeAngle);

  /**
   * @fn void setBlockPivotTurn(bool isClockwise);
   * @brief ピボットターン設置を実行する
   * @param isClockwise ピボットターンする向き true: 右回転
   */
  void setBlockPivotTurn(bool isClockwise);

  /**
   * @fn void setBlockThrow(bool isClockwise);
   * @brief 投げ入れ設置を実行する
   * @param isClockwise 投げ入れる向き true: 右回転
   */
  void setBlockThrow(bool isClockwise);

  /**
   * @fn void getMotionTimeRunForward(void);
   * @brief 交点移動（直進）の時間コストを取得
   * @return 動作時間
   */
  double getMotionTimeRunForward(void);

  /**
   * @fn int getMotionTimeRunRight(void);
   * @brief 交点移動（右折）の時間コストを取得
   * @return 動作時間
   */
  double getMotionTimeRunRight(void);

  /**
   * @fn int getMotionTimeRunLeft(void);
   * @brief 交点移動（左折）の時間コストを取得
   * @return 動作時間
   */
  double getMotionTimeRunLeft(void);

  /**
   * @fn int getMotionTimeRunToCross(void);
   * @brief 交点間移動の時間コストを取得
   * @return 動作時間
   */
  double getMotionTimeRunToCross(void);

  /**
   * @fn int getMotionTimechangeDirection(void);
   * @brief 方向転換の時間コストを取得
   * @return 動作時間
   */
  double getMotionTimeChangeDirection(int angle);

  /**
   * @fn int getMotionTimePivotTurn(void);
   * @brief ピボットターンの時間コストを取得
   * @return 動作時間
   */
  double getMotionTimePivotTurn(void);

  /**
   * @fn int getMotionTimeThrowBlock(void);
   * @brief 投げ入れ設置の時間コストを取得
   * @return 動作時間
   */
  double getMotionTimeThrowBlock(void);

  /**
   * @fn int getFailureRiskRunForward(void);
   * @brief 交点移動（直進）の誤差コストを取得
   * @return 失敗リスク
   */
  double getFailureRiskRunForward(void);

  /**
   * @fn int getFailureRiskRunRight(void);
   * @brief 交点移動（右折）の誤差コストを取得
   * @return 失敗リスク
   */
  double getFailureRiskRunRight(void);

  /**
   * @fn int getFailureRiskRunLeft(void);
   * @brief 交点移動（左折）の誤差コストを取得
   * @return 失敗リスク
   */
  double getFailureRiskRunLeft(void);

  /**
   * @fn int getFailureRiskRunToCross(void);
   * @brief 交点間移動の誤差コストを取得
   * @return 失敗リスク
   */
  double getFailureRiskRunToCross(void);

  /**
   * @fn int getFailureRiskchangeDirection(int angle);
   * @brief 方向転換の誤差コストを取得
   * @return 失敗リスク
   */
  double getFailureRiskChangeDirection(int angle);

  /**
   * @fn int getFailureRiskPivotTurn(void);
   * @brief ピボットターンの誤差コストを取得
   * @return 失敗リスク
   */
  double getFailureRiskPivotTurn(void);

  /**
   * @fn int getFailureRiskThrowBlock(void);
   * @brief 投げ入れ設置の誤差コストを取得
   * @return 失敗リスク
   */
  double getFailureRiskThrowBlock(void);

  /**
   * 動作を記録する動的配列
   */
  static std::vector<MOTION> motionLog;

 private:
  LineTracer& lineTracer;
  InCrossStraight inCrossStraight;
  InCrossRight inCrossRight;
  InCrossLeft inCrossLeft;
  ToCrossMotion toCrossMotion;
  DirectionChanger directionChanger;
  BlockPivotTurn blockPivotTurn;
  BlockThrower blockThrower;
};

#endif
