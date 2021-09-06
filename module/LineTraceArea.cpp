/**
 * @file LineTraceArea.cpp
 * @brief ライントレースエリアを攻略するクラス
 * @author Hisataka-Hagiyama,uchyam
 */

#include "LineTraceArea.h"

// Lコースの情報を初期化する
const std::array<SectionParam, LineTraceArea::LEFT_SECTION_SIZE> LineTraceArea::LEFT_COURSE_INFO
    = { SectionParam{ 150, 12, 60, PidGain(0.1, 0.8, 0.1) },
        SectionParam{ 1445, 12, 100, PidGain(3.5, 1, 1) },
        SectionParam{ 670, 12, 80, PidGain(1.5, 0.83, 1.3) },
        SectionParam{ 600, 12, 100, PidGain(3.3, 1, 1) },
        SectionParam{ 580, 12, 80, PidGain(1.5, 0.67, 0.66) },
        SectionParam{ 1450, 12, 100, PidGain(3, 0.3, 0.3) },
        SectionParam{ 400, 12, 60, PidGain(4.1, 1.2, 0.1) },
        SectionParam{ 700, 12, 100, PidGain(3, 1, 1.8) } };

// Rコースの情報を初期化する
const std::array<SectionParam, LineTraceArea::RIGHT_SECTION_SIZE> LineTraceArea::RIGHT_COURSE_INFO
    = { SectionParam{ 150, 12, 60, PidGain(0.2, 0.1, 0.1) },
        SectionParam{ 1445, 12, 100, PidGain(3.5, 1, 1) },
        SectionParam{ 670, 12, 80, PidGain(1.25, 1.05, 1.3) },
        SectionParam{ 600, 12, 100, PidGain(3.3, 1, 1) },
        SectionParam{ 580, 12, 80, PidGain(0.95, 0.675, 0.65) },
        SectionParam{ 1450, 12, 100, PidGain(4, 0.3, 0.3) },
        SectionParam{ 400, 12, 60, PidGain(4.2, 1.3, 0.15) },
        SectionParam{ 700, 12, 100, PidGain(3, 1, 1.8) } };

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
