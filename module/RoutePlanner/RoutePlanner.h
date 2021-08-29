/**
 * @file RoutePlanner.h
 * @brief 経路計画クラス
 * @author hiroto0927, miyashita64, Hisataka-Hagiyama, uchyam
 */

#include "CourseInfo.h"
#include "DestinationList.h"
#include "BlockSelector.h"
#include "RouteCalculator.h"
#include <vector>
#include <utility>

class RoutePlanner {
 public:
  /**
   * コンストラクタ
   */
  RoutePlanner(CourseInfo& _courseInfo, const bool IS_LEFT_COURSE);

  /**
   * 1つのブロックを運搬するまでの経路を計画し、取得経路、設置経路のリストを渡す
   */
  std::vector<std::vector<std::pair<Coordinate, Direction>>> planBingoRoute();

 private:
  CourseInfo& courseInfo;
  bool isLeftCourse;
};
