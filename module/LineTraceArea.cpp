/**
 * @file LineTraceArea.cpp
 * @brief ライントレースエリアを攻略するクラス
 * @author Hisataka-Hagiyama,uchyam
 */

#include "LineTraceArea.h"
#include <stdio.h>

//左コースの情報を初期化する
const std::array<SectionParam, ARRAYSIZE> LineTraceArea::leftCourseInfo
    = { SectionParam{ 1629.980, 50, 100, PidGain(0, 0, 0) },
        SectionParam{ 594.506, 50, 100, PidGain(0, 0, 0) },
        SectionParam{ 690.288, 50, 100, PidGain(0, 0, 0) },
        SectionParam{ 511.724, 50, 100, PidGain(0, 0, 0) },
        SectionParam{ 1709.7, 50, 100, PidGain(0, 0, 0) },
        SectionParam{ 309.562, 50, 100, PidGain(0, 0, 0) },
        SectionParam{ 802.254, 50, 100, PidGain(0, 0, 0) } };

//右コースの情報を初期化する
const std::array<SectionParam, ARRAYSIZE> LineTraceArea::rightCourseInfo
    = { SectionParam{ 1629.980, 50, 100, PidGain(0, 0, 0) },
        SectionParam{ 594.506, 50, 100, PidGain(0, 0, 0) },
        SectionParam{ 690.288, 50, 100, PidGain(0, 0, 0) },
        SectionParam{ 511.724, 50, 100, PidGain(0, 0, 0) },
        SectionParam{ 1709.7, 50, 100, PidGain(0, 0, 0) },
        SectionParam{ 309.562, 50, 100, PidGain(0, 0, 0) },
        SectionParam{ 802.254, 50, 100, PidGain(0, 0, 0) } };

void LineTraceArea::runLineTraceArea()
{
  const SectionParam* param;

  // LineTracerクラスにエッジを与えインスタンス化する
  // LineTracer _linetracer(_EDGE);
  printf("%d\n", _EDGE);

  if(_EDGE == 1) {
    //左コースの場合
    param = leftCourseInfo.begin();
  } else {
    //右コースの場合
    param = rightCourseInfo.begin();
  }

  //各区間を順番に走らせる
  for(int section = 0; section < ARRAYSIZE; section++) {
    printf("%lf %d  %d %lf %lf %lf\n", param[section].sectionDistance,
           param[section].sectionTargetBrightness, param[section].sectionPWM,
           param[section].sectionPidGain.kp, param[section].sectionPidGain.ki,
           param[section].sectionPidGain.kd);
    // Linetracerクラスのrun関数に区間の情報を渡して走行させる
    // _linetracer.run(param[section].sectionDistance,
    // param[section].sectionTragetBrightness,param[section].sectionPWM,
    // param[section].sectionPidGain)
  }
}
