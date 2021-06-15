/**
 * @file LineTraceArea.cpp
 * @brief ライントレースエリアを攻略するクラス
 * @author Hisataka-Hagiyama,uchyam
 */

#include "LineTraceArea.h"

// Lコースの情報を初期化する
const std::array<SectionParam, LineTraceArea::LEFT_SECTION_SIZE> LineTraceArea::LEFT_COURSE_INFO
    = { SectionParam{ 1625.340, 50, 100, PidGain(0, 0, 0) },
        SectionParam{ 594.506, 50, 100, PidGain(0, 0, 0) },
        SectionParam{ 690.288, 50, 100, PidGain(0, 0, 0) },
        SectionParam{ 511.724, 50, 100, PidGain(0, 0, 0) },
        SectionParam{ 1709.700, 50, 100, PidGain(0, 0, 0) },
        SectionParam{ 309.562, 50, 100, PidGain(0, 0, 0) },
        SectionParam{ 807.404, 50, 100, PidGain(0, 0, 0) } };

// Rコースの情報を初期化する
const std::array<SectionParam, LineTraceArea::RIGHT_SECTION_SIZE> LineTraceArea::RIGHT_COURSE_INFO
    = { SectionParam{ 1625.340, 50, 100, PidGain(0, 0, 0) },
        SectionParam{ 594.506, 50, 100, PidGain(0, 0, 0) },
        SectionParam{ 690.288, 50, 100, PidGain(0, 0, 0) },
        SectionParam{ 511.724, 50, 100, PidGain(0, 0, 0) },
        SectionParam{ 1709.700, 50, 100, PidGain(0, 0, 0) },
        SectionParam{ 309.562, 50, 100, PidGain(0, 0, 0) },
        SectionParam{ 807.404, 50, 100, PidGain(0, 0, 0) } };

void LineTraceArea::runLineTraceArea()
{
  const SectionParam* param;
  bool isLeftEdge;  // true:左エッジ,false:右エッジ

  if(IS_LEFT_COURSE) {
    // Lコースの場合
    param = LEFT_COURSE_INFO.begin();
    isLeftEdge = false;
  } else {
    // Rコースの場合
    param = RIGHT_COURSE_INFO.begin();
    isLeftEdge = true;
  }

  // LineTracerにエッジを与えてインスタンス化する
  LineTracer lineTracer(isLeftEdge);

  // LRに応じて各区間を順番に走らせる
  for(int section = 0; section < (IS_LEFT ? LEFT_SECTION_SIZE : RIGHT_SECTION_SIZE); section++) {
    // Linetracerクラスのrun関数に区間の情報を渡して走行させる
    lineTracer.run(param[section].sectionDistance, param[section].sectionTargetBrightness,
                   param[section].sectionPWM, param[section].sectionPidGain);
  }
}
