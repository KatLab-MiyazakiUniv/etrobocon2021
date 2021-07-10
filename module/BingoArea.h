/**
 * @file BingoArea.h
 * @brief ビンゴエリアの情報を保持するクラス
 * @author Hisataka-Hagiyama,uchyam
 */

#ifndef BINGOAREA_H
#define BINGOAREA_H
#include "array"
#include "BlockCircle.h"
#include "CrossCircle.h"
#include "CenterMark.h"
#include "LineTraceArea.h"
#include "Measurer.h"

class BingoArea {
 public:
  //コンストラクタ
  //交点サークル、ブロックサークルについて座標、サークルの色を設定、交点サークルの黒線の本数を設定
  BingoArea();

  /**
   *@fn void setBlockInfo(int, COLOR);
   *@brief　ブロックの情報をセットする
   *@param info ブロックの位置を表す数字
   *@pamram color ブロックの色
   */
  void setBlockInfo(int info, COLOR color);

  /**
   *@fn Node& getBlockInfo(int blockId);
   *@brief　ブロック番号を指定し、ノードの情報を取得する
   *@param　 blockId ブロック番号
   *@return Nodeの参照
   */
  Node& getBlockInfo(BLOCK_ID blockId);

  BlockCircle& getBlockCircleInfo(CIRCLE_ID circleId);
  CrossCircle& getCrossCircleInfo(int index);
  /**
   *@fn void setBingoArea();
   *@brief APIから取得した情報を基にビンゴエリア情報を初期化する
   */
  void initBingoArea();

  // for Test
  //セットできているか表示するために設けた
  void printinfo();

 private:
  std::array<CrossCircle, 16> crossCircle;  // 交点サークル情報
  std::array<BlockCircle, 8> blockCircle;   // ブロックサークル情報
  CenterMark centerMark;                    //センターマーク情報
  Measurer measurer;
};
#endif
