/**
 * @file BingoMotion.h
 * @brief ビンゴ動作の親クラス
 * @author kodama0720, yutotanaka24
 */

#ifndef BINGO_MOTION_H
#define BINGO_MOTION_H

class BingoMotion {
 public:
  BingoMotion();

  /**
   * @brief 動作時間を取得する
   * @return 動作時間
   */
  int getMotionTime(void);

  /**
   * @brief 失敗リスクを取得する
   * @return 失敗リスク
   */
  int getFailureRisk(void);//ゲッター

  private:
  int MOTION_TIME;
  int FAILURE_RISK;
};

#endif
