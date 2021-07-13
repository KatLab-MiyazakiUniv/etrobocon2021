/**
 * @file etroboc_ext.cpp
 * @brief EV3拡張API（ダミー）
 * @author Takahiro55555,Hisataka-Hagiyama,uchyam
 */

#include "etroboc_ext.h"

int ETRoboc_getCourseInfo(ETROBOC_COURSE_INFO_ID id)
{
  if(id == ETROBOC_COURSE_INFO_BLOCK_POS_BLACK1) {
    return 48;
  } else if(id == ETROBOC_COURSE_INFO_BLOCK_POS_RED1) {
    return 69;
  } else if(id == ETROBOC_COURSE_INFO_BLOCK_POS_RED2) {
    return 77;
  } else if(id == ETROBOC_COURSE_INFO_BLOCK_POS_YELLOW1) {
    return 66;
  } else if(id == ETROBOC_COURSE_INFO_BLOCK_POS_YELLOW2) {
    return 75;
  } else if(id == ETROBOC_COURSE_INFO_BLOCK_POS_BLUE1) {
    return 68;
  } else if(id == ETROBOC_COURSE_INFO_BLOCK_POS_BLUE2) {
    return 82;
  } else if(id == ETROBOC_COURSE_INFO_BLOCK_POS_GREEN1) {
    return 71;
  } else if(id == ETROBOC_COURSE_INFO_BLOCK_POS_GREEN2) {
    return 80;
  } else {
    return -1;
  }
}