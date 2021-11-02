/**
 * @file etroboc_ext.cpp
 * @brief EV3拡張API（ダミー）
 * @author Takahiro55555,Hisataka-Hagiyama,uchyam
 */

#include "etroboc_ext.h"

bool isLeft = true;

int ETRoboc_getCourseInfo(ETROBOC_COURSE_INFO_ID id)
{
  CourseInfoGenerator* courseInfoGenerator = CourseInfoGenerator::getInstance();
  if(isLeft) {
    return courseInfoGenerator->getCourseInfoL(id);
  }
  return courseInfoGenerator->getCourseInfoR(id);
}

void setIsLeft(bool _isLeft)
{
  isLeft = _isLeft;
}
