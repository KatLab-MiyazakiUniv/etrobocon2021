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
        SectionParam{ 670, 12, 55, PidGain(1, 0.8, 1) },
        SectionParam{ 600, 12, 100, PidGain(3, 2.7, 1.2) },
        SectionParam{ 580, 12, 60, PidGain(0.9, 0.3, 0.6) },
        SectionParam{ 1450, 12, 100, PidGain(2, 0.9, 0.9) },
        SectionParam{ 400, 12, 50, PidGain(5, 0.8, 0.9) },
        SectionParam{ 1000, 12, 100, PidGain(3, 1, 0.8) } };

// Rコースの情報を初期化する
const std::array<SectionParam, LineTraceArea::RIGHT_SECTION_SIZE> LineTraceArea::RIGHT_COURSE_INFO
    = { SectionParam{ 150, 12, 60, PidGain(0.1, 0.8, 0.1) },
        SectionParam{ 1445, 12, 100, PidGain(3.5, 1, 1) },
        SectionParam{ 670, 12, 55, PidGain(1, 0.8, 1) },
        SectionParam{ 600, 12, 100, PidGain(3, 2.7, 1.2) },
        SectionParam{ 580, 12, 60, PidGain(0.9, 0.3, 0.6) },
        SectionParam{ 1450, 12, 100, PidGain(2, 0.9, 0.9) },
        SectionParam{ 400, 12, 50, PidGain(5, 0.8, 0.9) },
        SectionParam{ 1000, 12, 100, PidGain(3, 1, 0.8) } };

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
