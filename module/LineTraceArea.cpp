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
        SectionParam{ 670, 12, 80, PidGain(1.6, 0.83, 1.3) },
        SectionParam{ 600, 12, 100, PidGain(2, 1, 1) },
        SectionParam{ 580, 12, 80, PidGain(1.6, 0.67, 0.66) },
        SectionParam{ 1450, 12, 100, PidGain(3, 0.3, 0.3) },
        SectionParam{ 400, 12, 60, PidGain(5, 1.2, 0.1) },
        SectionParam{ 700, 12, 100, PidGain(3, 1, 1.8) } };

// Rコースの情報を初期化する
const std::array<SectionParam, LineTraceArea::RIGHT_SECTION_SIZE> LineTraceArea::RIGHT_COURSE_INFO
    = { SectionParam{ 150, 12, 60, PidGain(0.2, 0.1, 0.1) },
        SectionParam{ 1445, 12, 100, PidGain(3.5, 1, 1) },
        SectionParam{ 670, 12, 80, PidGain(1.7, 0.8, 0.8) },
        SectionParam{ 600, 12, 100, PidGain(3.3, 1, 1) },
        SectionParam{ 580, 12, 80, PidGain(1.6, 0.67, 0.6) },
        SectionParam{ 1450, 12, 100, PidGain(4, 0.3, 0.3) },
        SectionParam{ 400, 12, 60, PidGain(6, 2, 0.5) },
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

void LineTraceArea::runLineTraceAreaShortcut()
{
  const SectionParam* param;
  bool isLeftEdge;  // true:左エッジ,false:右エッジ

  //エッジの設定
  isLeftEdge = !IS_LEFT_COURSE;

  // LineTracerにエッジを与えてインスタンス化する
  LineTracer lineTracer(isLeftEdge);
  StraightRunner straightRunner;
  Measurer measurer;
  Controller controller;

  int targetBrightness = 12;
  int initialDistance = 0;
  int currentDistance = 0;

  int curveDistance1 = 777;
  int straightDistance1 = 435;
  int curveDistance2 = 777;
  int straightDistance2 = 1120;
  int curveDistance3 = 700;
  int straightDistance3 = 500;

  lineTracer.run(150, targetBrightness, 60, PidGain(0.1, 0.8, 0.1));
  lineTracer.run(1385, targetBrightness, 100, PidGain(3.5, 1, 1));

  //第一カーブ
  initialDistance = Mileage::calculateMileage(measurer.getRightCount(), measurer.getLeftCount());
  while(true) {
    currentDistance = Mileage::calculateMileage(measurer.getRightCount(), measurer.getLeftCount());
    if(currentDistance - initialDistance >= curveDistance1) {
      break;
    }
    controller.setRightMotorPwm(100);
    controller.setLeftMotorPwm(65);
    controller.sleep();
  }

  straightRunner.runStraightToDistance(straightDistance1, 100);

  //第二カーブ
  initialDistance = Mileage::calculateMileage(measurer.getRightCount(), measurer.getLeftCount());
  while(true) {
    currentDistance = Mileage::calculateMileage(measurer.getRightCount(), measurer.getLeftCount());
    if(currentDistance - initialDistance >= curveDistance2) {
      break;
    }
    controller.setRightMotorPwm(100);
    controller.setLeftMotorPwm(66);
    controller.sleep();
  }

  lineTracer.run(straightDistance2, targetBrightness, 100, PidGain(3.5, 1, 1));

  //第三カーブ
  initialDistance = Mileage::calculateMileage(measurer.getRightCount(), measurer.getLeftCount());
  while(true) {
    currentDistance = Mileage::calculateMileage(measurer.getRightCount(), measurer.getLeftCount());
    if(currentDistance - initialDistance >= curveDistance3) {
      break;
    }
    controller.setRightMotorPwm(64);
    controller.setLeftMotorPwm(100);
    controller.sleep();
  }

  lineTracer.run(straightDistance3, targetBrightness, 100, PidGain(3, 1, 1.8));
}
