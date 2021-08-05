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
#include "MotionConverter.h"
#include "vector"

class MotionPerformer {
 public:
  //コンストラクタ
  MotionPerformer(LineTracer& _lineTracer);

  /**
   * @fn void moveStraight(void);
   * @brief 交点内移動（直進）を実行する
   */
  void moveStraight(void);

  /**
   * @fn void turnRight(void);
   * @brief 交点内移動（右折）を実行する
   */
  void turnRight(void);

  /**
   * @fn void turnLeft(void);
   * @brief 交点内移動（左折）を実行する
   */
  void turnLeft(void);

  /**
   * @fn void moveBetweenCross(void);
   * @brief 交点間移動を実行する
   */
  void moveBetweenCross(void);

  /**
   * @fn void turnAround(void);
   * @brief 180度方向転換を実行する
   */
  void turnAround(void);

  /**
   * @fn void pibotTurn(bool isClockwise);
   * @brief ピボットターン設置を実行する
   * @param isClockwise ピボットターンする向き true: 右回転
   */
  void pibotTurn(bool isClockwise);

  /**
   * @fn void throwBlock(bool isClockwise);
   * @brief 投げ入れ設置を実行する
   * @param isClockwise 投げ入れる向き true: 右回転
   */
  void throwBlock(bool isClockwise);

  /**
   * @fn void getMotionTimeInCrossStraight(void);
   * @brief 交点移動（直進）の時間コストを取得
   * @return 動作時間
   */
  int getMotionTimeStraight(void);

  /**
   * @fn int getMotionTimeTurnRight(void);
   * @brief 交点移動（右折）の時間コストを取得
   * @return 動作時間
   */
  int getMotionTimeTurnRight(void);

  /**
   * @fn int getMotionTimeTurnLeft(void);
   * @brief 交点移動（左折）の時間コストを取得
   * @return 動作時間
   */
  int getMotionTimeTurnLeft(void);

  /**
   * @fn int getMotionTimeBetweenCross(void);
   * @brief 交点間移動の時間コストを取得
   * @return 動作時間
   */
  int getMotionTimeBetweenCross(void);

  /**
   * @fn int getMotionTimeTurnAround(void);
   * @brief 180度方向転換の時間コストを取得
   * @return 動作時間
   */
  int getMotionTimeTurnAround(void);

  /**
   * @fn int getMotionTimePibotTurn(void);
   * @brief ピボットターンの時間コストを取得
   * @return 動作時間
   */
  int getMotionTimePibotTurn(void);

  /**
   * @fn int getMotionTimeThrowBlock(void);
   * @brief 投げ入れ設置の時間コストを取得
   * @return 動作時間
   */
  int getMotionTimeThrowBlock(void);

  /**
   * @fn int getFailureRiskStraight(void);
   * @brief 交点移動（直進）の誤差コストを取得
   * @return 失敗リスク
   */
  int getFailureRiskStraight(void);

  /**
   * @fn int getFailureRiskTurnRight(void);
   * @brief 交点移動（右折）の誤差コストを取得
   * @return 失敗リスク
   */
  int getFailureRiskTurnRight(void);

  /**
   * @fn int getFailureRiskTurnLeft(void);
   * @brief 交点移動（左折）の誤差コストを取得
   * @return 失敗リスク
   */
  int getFailureRiskTurnLeft(void);

  /**
   * @fn int getFailureRiskBetweenCross(void);
   * @brief 交点間移動の誤差コストを取得
   * @return 失敗リスク
   */
  int getFailureRiskBetweenCross(void);

  /**
   * @fn int getFailureRiskTurnAround(void);
   * @brief 180度方向転換の誤差コストを取得
   * @return 失敗リスク
   */
  int getFailureRiskTurnAround(void);

  /**
   * @fn int getFailureRiskPibotTurn(void);
   * @brief ピボットターンの誤差コストを取得
   * @return 失敗リスク
   */
  int getFailureRiskPibotTurn(void);

  /**
   * @fn int getFailureRiskThrowBlock(void);
   * @brief 投げ入れ設置の誤差コストを取得
   * @return 失敗リスク
   */
  int getFailureRiskThrowBlock(void);

  /**
   * 動作を記録する動的配列
   */
  std::vector<MOTION> motionLog;

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