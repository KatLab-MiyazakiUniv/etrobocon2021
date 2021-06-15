/**
 * @file LineTraceArea.cpp
 * @brief ライントレースエリアを攻略するクラス
 * @author Hisataka-Hagiyama,uchyam
 */

#include "LineTraceArea.h"

// Lコースの情報を初期化する
const std::array<SectionParam, LineTraceArea::LEFTSECTIONSIZE> LineTraceArea::LEFTCOURSEINFO
    = { SectionParam{ 1625.340, 50, 100, PidGain(0, 0, 0) },
        SectionParam{ 594.506, 50, 100, PidGain(0, 0, 0) },
        SectionParam{ 690.288, 50, 100, PidGain(0, 0, 0) },
        SectionParam{ 511.724, 50, 100, PidGain(0, 0, 0) },
        SectionParam{ 1709.700, 50, 100, PidGain(0, 0, 0) },
        SectionParam{ 309.562, 50, 100, PidGain(0, 0, 0) },
        SectionParam{ 807.404, 50, 100, PidGain(0, 0, 0) } };

// Rコースの情報を初期化する
const std::array<SectionParam, LineTraceArea::RIGHTSECTIONSIZE> LineTraceArea::RIGHTCOURSEINFO
    = { SectionParam{ 1625.340, 50, 100, PidGain(0, 0, 0) },
        SectionParam{ 594.506, 50, 100, PidGain(0, 0, 0) },
        SectionParam{ 690.288, 50, 100, PidGain(0, 0, 0) },
        SectionParam{ 511.724, 50, 100, PidGain(0, 0, 0) },
        SectionParam{ 1709.700, 50, 100, PidGain(0, 0, 0) },
        SectionParam{ 309.562, 50, 100, PidGain(0, 0, 0) },
        SectionParam{ 807.404, 50, 100, PidGain(0, 0, 0) } };

void LineTraceArea::runLineTraceArea()
{
  LineTracer linetracer(IS_LEFT);
  const SectionParam* param;

  if(IS_LEFT) {
    // Lコースの場合
    param = LEFTCOURSEINFO.begin();
  } else {
    // Rコースの場合
    param = RIGHTCOURSEINFO.begin();
  }

  // LRに応じて各区間を順番に走らせる
  for(int section = 0; section < (IS_LEFT ? LEFTSECTIONSIZE : RIGHTSECTIONSIZE); section++) {
    // Linetracerクラスのrun関数に区間の情報を渡して走行させる
    linetracer.run(param[section].sectionDistance, param[section].sectionTargetBrightness,
                   param[section].sectionPWM, param[section].sectionPidGain);
  }
}
