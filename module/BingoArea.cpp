/**
 * @file BingoArea.cpp
 * @brief ビンゴエリアを攻略するクラス
 * @author Hisataka-Hagiyama,uchyam
 */

#include "BingoArea.h"

void BingoArea::runBingoArea()
{
  CourseInfo courseInfo;
  LineTracer lineTracer(IS_LEFT_COURSE);
  MotionPerformer motionPerformer(lineTracer);
  MotionConverter motionConverter(motionPerformer);
  //コース情報を初期化する
  courseInfo.initCourseInfo();
  RoutePlanner routePlanner(courseInfo, IS_LEFT_COURSE);
  //経路計画クラスで求めた運搬経路リストを取得
  std::vector<std::vector<std::pair<Coordinate, Direction>>> carryRoute
      = routePlanner.planBingoRoute();
  //各運搬経路を動作に変換していく
  for(const auto& i : carryRoute) {
    motionConverter.convertToMotion(i);
  }
}
