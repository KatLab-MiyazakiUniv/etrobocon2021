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
  return courseInfoGenerator->getCourseInfo(id, isLeft);
}

void setIsLeft(bool _isLeft)
{
  isLeft = _isLeft;
}
