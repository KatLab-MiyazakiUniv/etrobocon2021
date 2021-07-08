/**
 * @file Node.h
 * @brief ノードを保持するクラス
 * @author Hisataka-Hagiyama,uchyam
 */

#ifndef NODE_H
#define NODE_H
#include "ColorJudge.h"

//ブロックの色とブロックの番号を保持する構造体
struct Block {
  COLOR blockColor;  //ブロックの色
  int blockId;       //ブロックの番号
  //コンストラクタ
  Block(COLOR blockColor = COLOR::NONE, int blockId = -1);
};

//ブロックの座標を保持する構造体
struct Coordinate {
  int x;  // x座標
  int y;  // y座標
  //コンストラクタ
  Coordinate(int x = 0, int y = 0);
};

class Node {
 public:
  //コンストラクタ
  //座標、サークルの色、ブロックの色、ブロック番号を初期化する
  Node(int x = 0, int y = 0, COLOR circleColor = COLOR::NONE, int blockId = -1,
       COLOR blockColor = COLOR::NONE);

  /**
   *@fn void setCoordinate(int x, int y);
   *@brief　ノードに座標をセットする
   *@param x座標[int]
   *@pamram y座標[int]
   */
  void setCoordinate(int x, int y);

  /**
   *@fn void setNodeInfo(int blockId, COLOR circleColor, COLOR blockColor);
   *@brief　ノードにブロック情報をセットする
   *@param _blockId ブロック番号
   *@pamram _blockColor ブロックの色
   */
  void setBlock(int _blockId, COLOR _blockColor);

  /**
   *@fn void setNodeInfo(int blockId, COLOR circleColor, COLOR blockColor);
   *@brief　ノードにサークルの色をセットする
   *@param  サークルの色[COLOR]
   */
  void setCicleColor(COLOR color);

  Coordinate& getCoordinate();
  Block& getBlock();
  COLOR& getCircleColor();

 private:
  Coordinate blockCoordinate;  //座標
  Block block;                 //ブロックの色、番号
  COLOR circleColor;           //サークルの色
};
#endif
