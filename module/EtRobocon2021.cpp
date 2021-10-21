/**
 * @file EtRobocon2021.cpp
 * @brief 全体を制御するクラス
 * @author Hisataka-Hagiyama,uchyam
 */

#include "EtRobocon2021.h"
//
#include "Clock.h"
#include "ToCrossMotion.h"
#include "LineTracer.h"
#include "InCrossLeft.h"
#include "InCrossRight.h"
//

void EtRobocon2021::start()
{
  Controller controller;
  Measurer measurer;

  //タッチセンサが押されるまで待機
  while(!measurer.isPressed()) {
    controller.sleep();
  }


  /*
  ev3api::Clock clock;
  bool isLeft = true;
  bool isEdge = true;
  int key = 0;
  clock_t start, end;

  LineTracer lt(isLeft);
  ToCrossMotion tcm(lt);
  InCrossLeft icl(lt);
  InCrossRight icr(lt);

  while(true){
    if(measurer.isPressed()){
      lt.setIsLeftEdge(isLeft==isEdge);
      tcm.runToCross();
      start = clock.now();
      if(isLeft){
        icl.runLeft();
      }else{
        icr.runRight();
      }
      end = clock.now();
      printf("%s (%s): %f[s]\n", (isLeft ? "LEFT" : "RIGHT"), (isEdge? "on" : "re"), (float)(end - start) / 1000000.0);

      isLeft = !isLeft;
      isEdge = (bool)(key/2);
      key = (key+1)%4;
    }
    controller.sleep();
  }
  /*/
  //ライントレースエリア攻略開始
  LineTraceArea::runLineTraceArea();
  //ビンゴエリア攻略開始
  BingoArea::runBingoArea();
  //*/
  //シミュレータへ競技の終了を通知する
  controller.notifyCompletedToSimulator();
}
