/**
 * @file CrossCircle.h
 * @brief 交点サークル情報を保持するクラス(基底クラス:Nodeクラス)
 * @author Hisataka-Hagiyama,uchyam
 */

#ifndef CROSSCIRCLE_H
#define CROSSCIRCLE_H

#include "Node.h"
class CrossCircle : public Node {
 public:
  //コンストラクタ
  CrossCircle();

  /**
   *@fn int setEdgeNumber(int num);
   *@brief　黒線の数をセットする
   *@param num 黒線の本数
   */
  void setEdgeNumber(int num);

  /**
   *@fn int getEdgeNumber(Coordinate info);
   *@brief　黒線の数を取得する
   *@return 黒線の本数
   */
  int getEdgeNumber();

 private:
  int edgeNumber;  //接する黒線の本数
};
#endif
