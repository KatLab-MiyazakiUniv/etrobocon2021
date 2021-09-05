/**
 * @file CourseInfo.h
 * @brief ビンゴエリアの情報を保持するクラス
 * @author Hisataka-Hagiyama,uchyam
 */

#ifndef COURSEINFO_H
#define COURSEINFO_H

#include "array"
#include "BlockCircle.h"
#include "CrossCircle.h"
#include "CenterMark.h"
#include "LineTraceArea.h"
#include "Measurer.h"

class CourseInfo {
 public:
  //コンストラクタ
  //交点サークル、ブロックサークルについて座標、サークルの色を設定、交点サークルの黒線の本数を設定
  CourseInfo(const bool IS_LEFT_COURSE);

  /**
   *@fn Node& getNode(int blockId);
   *@brief　ブロック番号を指定し、ノードの情報を取得する
   *@param blockId ブロック番号
   *@return Nodeの参照
   */
  Node& getNode(BLOCK_ID blockId);

  /**
   *@fn BlockCircle& getBlockCircle(CIRCLE_ID circleId);
   *@brief　ブロックサークルIDを指定し、ブロックサークルの情報を取得する
   *@param circleId ブロックサークルID
   *@return BlockCircleの参照
   */
  BlockCircle& getBlockCircle(CIRCLE_ID circleId);

  /**
   *@fn CrossCircle& getCrossCircle(int index);
   *@brief 添え字を指定し、交点サークルの情報を取得する
   *@param index 添え字
   *@return CrossCircleの参照
   */
  CrossCircle& getCrossCircle(int index);

  /**
   *@fn CenterMark& getCenterMark();
   *@brief センタマークの情報を取得する
   *@return CenterMarkの参照
   */
  CenterMark& getCenterMark();

  /**
   *@fn void setCourseInfo();
   *@brief APIから取得した情報を基にビンゴエリア情報を初期化する
   */
  void initCourseInfo();

  /**
   *@fn void moveCourseInfo();
   *@brief ブロックを移動する
   *@param circleid 移動先のサークル番号
   *@param blockid　移動させるブロック番号
   */
  void moveBlock(CIRCLE_ID circleid, BLOCK_ID blockid);

  /**
   * @fn bool existBlock(Coordinate& coordinate);
   * @brief 指定された座標のブロックの有無を確認
   * @param coordinate　座標
   * @return 判定結果(true:ブロックあり false:ブロックなし)
   */
  bool existBlock(Coordinate& coordinate);

 private:
  std::array<CrossCircle, 16> crossCircle;  // 交点サークル情報
  std::array<BlockCircle, 8> blockCircle;   // ブロックサークル情報
  CenterMark centerMark;                    //センターマーク情報
  Measurer measurer;
  const bool isLeftCourse;

  /**
   *@fn void setBlockInfo(int, COLOR);
   *@brief　ブロックの情報をセットする
   *@param info ブロックの位置を表す数字
   *@param color ブロックの色
   */
  void setBlockInfo(int info, COLOR color);
};

#endif
