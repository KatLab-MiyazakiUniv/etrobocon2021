/**
 * @file LineTraceArea.cpp
 * @brief ライントレースエリアを攻略するクラス
 * @author Hisataka-Hagiyama,uchyam
 */

#include "LineTraceArea.h"

// Lコースの情報を初期化する
const std::array<SectionParam, LineTraceArea::LEFT_SECTION_SIZE> LineTraceArea::LEFT_COURSE_INFO
    = { SectionParam{ 1625.340, 20, 30, PidGain(0.8, 0.01, 0.01) },
        SectionParam{ 594.506, 20, 30, PidGain(0.8, 0.01, 0.01) },
        SectionParam{ 690.288, 20, 30, PidGain(0.8, 0.01, 0.01) },
        SectionParam{ 511.724, 20, 30, PidGain(0.8, 0.01, 0.01) },
        SectionParam{ 1709.700, 20, 30, PidGain(0.8, 0.01, 0.01) },
        SectionParam{ 309.562, 20, 30, PidGain(0.8, 0.01, 0.01) },
        SectionParam{ 807.404, 20, 30, PidGain(0.8, 0.01, 0.01) } };

// Rコースの情報を初期化する
const std::array<SectionParam, LineTraceArea::RIGHT_SECTION_SIZE> LineTraceArea::RIGHT_COURSE_INFO
    = { SectionParam{ 1625.340, 20, 30, PidGain(0.8, 0.01, 0.01) },
        SectionParam{ 594.506, 20, 30, PidGain(0.8, 0.01, 0.01) },
        SectionParam{ 690.288, 20, 30, PidGain(0.8, 0.01, 0.01) },
        SectionParam{ 511.724, 20, 30, PidGain(0.8, 0.01, 0.01) },
        SectionParam{ 1709.700, 20, 30, PidGain(0.8, 0.01, 0.01) },
        SectionParam{ 309.562, 20, 30, PidGain(0.8, 0.01, 0.01) },
        SectionParam{ 807.404, 20, 30, PidGain(0.8, 0.01, 0.01) } };

void LineTraceArea::runLineTraceArea()
{
  const SectionParam* param;
  bool isLeftEdge;  // true:左エッジ,false:右エッジ

  if(IS_LEFT_COURSE) {
    // Lコースの場合
    param = LEFT_COURSE_INFO.begin();
  } else {
    // Rコースの場合
    param = RIGHT_COURSE_INFO.begin();
  }
  //エッジの設定
  isLeftEdge = !IS_LEFT_COURSE;

  // LineTracerにエッジを与えてインスタンス化する
  LineTracer lineTracer(isLeftEdge);

  // LRに応じて各区間を順番に走らせる
  for(int section = 0; section < (IS_LEFT_COURSE ? LEFT_SECTION_SIZE : RIGHT_SECTION_SIZE);
      section++) {
    // Linetracerクラスのrun関数に区間の情報を渡して走行させる
    lineTracer.run(param[section].sectionDistance, param[section].sectionTargetBrightness,
                   param[section].sectionPwm, param[section].sectionPidGain);
  }
}
