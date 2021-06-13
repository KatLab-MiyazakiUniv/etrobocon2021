/**
 * @file LineTraceArea.cpp
 * @brief ライントレースエリアを攻略するクラス
 * @author Hisataka-Hagiyama,uchyam
 */

#include "LineTraceArea.h"

//左コースの情報を初期化する
const std::array<SectionParam, LineTraceArea::RIGHTSECTIONSIZE> LineTraceArea::LEFTCOURSEINFO
    = { SectionParam{ 1629.980, 50, 100, PidGain(0, 0, 0) },
        SectionParam{ 594.506, 50, 100, PidGain(0, 0, 0) },
        SectionParam{ 690.288, 50, 100, PidGain(0, 0, 0) },
        SectionParam{ 511.724, 50, 100, PidGain(0, 0, 0) },
        SectionParam{ 1709.7, 50, 100, PidGain(0, 0, 0) },
        SectionParam{ 309.562, 50, 100, PidGain(0, 0, 0) },
        SectionParam{ 802.254, 50, 100, PidGain(0, 0, 0) } };

//右コースの情報を初期化する
const std::array<SectionParam, LineTraceArea::LEFTSECTIONSIZE> LineTraceArea::RIGHTCOURSEINFO
    = { SectionParam{ 1629.980, 50, 100, PidGain(0, 0, 0) },
        SectionParam{ 594.506, 50, 100, PidGain(0, 0, 0) },
        SectionParam{ 690.288, 50, 100, PidGain(0, 0, 0) },
        SectionParam{ 511.724, 50, 100, PidGain(0, 0, 0) },
        SectionParam{ 1709.7, 50, 100, PidGain(0, 0, 0) },
        SectionParam{ 309.562, 50, 100, PidGain(0, 0, 0) },
        SectionParam{ 802.254, 50, 100, PidGain(0, 0, 0) } };

void LineTraceArea::runLineTraceArea()
{
  LineTracer linetracer(IS_LEFT);
  const SectionParam* param;

  if(IS_LEFT) {
    //左コースの場合
    param = LEFTCOURSEINFO.begin();
  } else {
    //右コースの場合
    param = RIGHTCOURSEINFO.begin();
  }

  //左右に応じて各区間を順番に走らせる
  for(int section = 0; section < (IS_LEFT ? LEFTSECTIONSIZE : RIGHTSECTIONSIZE); section++) {
    // Linetracerクラスのrun関数に区間の情報を渡して走行させる
    linetracer.run(param[section].sectionDistance, param[section].sectionTargetBrightness,
                   param[section].sectionPWM, param[section].sectionPidGain);
  }
}