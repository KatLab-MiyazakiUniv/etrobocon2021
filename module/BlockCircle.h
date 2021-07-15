/**
 * @file BlockCircle.h
 * @brief ブロックサークル情報を保持するクラス(基底クラス:Nodeクラス)
 * @author Hisataka-Hagiyama,uchyam
 */

#ifndef BLOCKCIRCLE_H
#define BLOCKCIRCLE_H

#include "Node.h"
class BlockCircle : public Node {
 public:
  //コンストラクタ
  BlockCircle();
  
  /**
   *@fn void setCircleId(CIRCLE_ID id);
   *@brief サークルIDをセットする
   *@param id サークルID
   */
  void setCircleId(CIRCLE_ID id);
  
   /**
   *@fn CIRCLE_ID getCircleId();
   *@brief サークルIDを取得する
   */
  CIRCLE_ID getCircleId();

 private:
  CIRCLE_ID circleId;  //サークルID
};
#endif
