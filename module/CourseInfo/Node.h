/**
 * @file Node.h
 * @brief ノードを保持するクラス
 * @author Hisataka-Hagiyama,uchyam
 */

#ifndef NODE_H
#define NODE_H
#include "ColorJudge.h"

//サークルID
// Lコースは左上から、Rコースは右上から順にブロックサークルにID(0~7)を振る
enum class CIRCLE_ID : int {
  NONE = -1,
  ID0 = 0,
  ID1 = 1,
  ID2 = 2,
  ID3 = 3,
  ID4 = 4,
  ID5 = 5,
  ID6 = 6,
  ID7 = 7,
};

//ブロックID
// Lコースは左上から、Rコースは右上から順にブロックにID(0~7)を振る
enum class BLOCK_ID : int {
  NONE = -1,
  ID0 = 0,
  ID1 = 1,
  ID2 = 2,
  ID3 = 3,
  ID4 = 4,
  ID5 = 5,
  ID6 = 6,
  ID7 = 7,
};

//ブロックの色とブロックの番号を保持する構造体
struct Block {
  COLOR blockColor;  //ブロックの色
  BLOCK_ID blockId;  //ブロックの番号
  //コンストラクタ
  Block(COLOR blockColor = COLOR::NONE, BLOCK_ID blockId = BLOCK_ID::NONE);
};

//ブロックの座標を保持する構造体
struct Coordinate {
  int x;  // x座標
  int y;  // y座標
  //コンストラクタ
  Coordinate(int x = 0, int y = 0);

  //Coordinate型同士の比較ができるよう比較演算子をオーバーロード
  bool operator==(const Coordinate& another) const
  {
    return ((x == another.x) && (y == another.y));
  }
  bool operator!=(const Coordinate& another) const
  {
    return ((x != another.x) || (y != another.y));
  }
};

class Node {
 public:
  //コンストラクタ
  //座標、サークルの色、ブロックの色、ブロック番号を初期化する
  Node(int x = 0, int y = 0, COLOR circleColor = COLOR::NONE, BLOCK_ID blockId = BLOCK_ID::NONE,
       COLOR blockColor = COLOR::NONE);

  /**
   *@fn void setCoordinate(int x, int y);
   *@brief　ノードに座標をセットする
   *@param x x座標
   *@param y y座標
   */
  void setCoordinate(int x, int y);

  /**
   *@fn setBlock(BLOCK_ID _blockId, COLOR _blockColor);
   *@brief　ノードにブロック情報をセットする
   *@param _blockId ブロック番号
   *@param _blockColor ブロックの色
   */
  void setBlock(BLOCK_ID _blockId, COLOR _blockColor);

  /**
   *@fn void setCircleColor(COLOR color);
   *@brief ノードにサークルの色をセットする
   *@param color サークルの色
   */
  void setCircleColor(COLOR color);

  /**
   *@fn Coordinate& getCoordinate();
   *@brief 座標を取得する
   *@return Coordinate型の参照
   */
  Coordinate& getCoordinate();

  /**
   *@fn Block& getBlock();
   *@brief ブロック情報を取得する
   *@return Block型の参照
   */
  Block& getBlock();

  /**
   *@fn COLOR& getCircleColor();
   *@brief サークルの色を取得する
   *@return COLOR型の参照
   */
  COLOR& getCircleColor();

 private:
  Coordinate blockCoordinate;  //座標
  Block block;                 //ブロックの色、番号
  COLOR circleColor;           //サークルの色
};
#endif
