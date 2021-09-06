/**
 * @file BingoArea.cpp
 * @brief ビンゴエリアを攻略するクラス
 * @author Hisataka-Hagiyama,uchyam
 */

#include "BingoArea.h"

void BingoArea::runBingoArea()
{
  CourseInfo courseInfo(IS_LEFT_COURSE);
  LineTracer lineTracer(IS_LEFT_COURSE);
  MotionPerformer motionPerformer(lineTracer);
  MotionConverter motionConverter(motionPerformer, IS_LEFT_COURSE);
  //コース情報を初期化する
  courseInfo.initCourseInfo();
  //黒ブロックを運搬する
  BlackBlockCarrier::carryBlackBlock();
  RoutePlanner routePlanner(courseInfo, IS_LEFT_COURSE);
  //経路計画クラスで運搬経路リストを求める
  std::vector<std::vector<std::pair<Coordinate, Direction>>> carryRoute
      = routePlanner.planBingoRoute();
  //運搬経路リストを動作に変換していく
  for(const auto& i : carryRoute) {
    motionConverter.convertToMotion(i);
  }
}
