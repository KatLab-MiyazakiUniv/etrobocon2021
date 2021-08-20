/**
 * @file RoutePlanner.h
 * @brief 経路計画クラス
 * @author hiroto0927, miyashita64
 */

#include "CourseInfo.h"
#include "DestinationList.h"
#include "BlockSelector.h"
#include "RouteCalculator.h"

class RoutePlanner {
 public:
  /**
   * コンストラクタ
   */
  RoutePlanner(CourseInfo& _courseInfo, const bool IS_LEFT_COURSE);

  /**
   * 1つのブロックを運搬するまでの経路を計画する
   */
  void planBingoRoute();

 private:
  CourseInfo& courseInfo;
  bool isLeftCourse;
};
