/**
 * @file BingoMotion.h
 * @brief ビンゴ動作の親クラス
 * @author kodama0720, yutotanaka24
 */

#ifndef BINGO_MOTION_H
#define BINGO_MOTION_H

class BingoMotion {
 public:
  // コンストラクタ
  BingoMotion(double time = 0, double risk = 0);

  /**
   * @brief 動作時間を取得する
   * @return 動作時間
   */
  double getMotionTime(void);

  /**
   * @brief 失敗リスクを取得する
   * @return 失敗リスク
   */
  double getFailureRisk(void);

 private:
  double MOTION_TIME;
  double FAILURE_RISK;
};

#endif
