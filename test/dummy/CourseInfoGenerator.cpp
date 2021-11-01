/**
 * @file CourseInfoGenerator.cpp
 * @brief GoogleTestにおいて、全てのブロック配置パターンを網羅するためのシングルトンクラス
 * @author Takahiro55555
 * 参考文献: C++におけるオブジェクトの取り扱い方[シングルトン]
 *   URL: https://www.haljion.net/index.php/2019-11-13-03-27-18/119-2019-11-13-03-22-16/rx-62n/222-c
 */

#include "CourseInfoGenerator.h"

CourseInfoGenerator* CourseInfoGenerator::_singleton = NULL;

CourseInfoGenerator::~CourseInfoGenerator()
{
  /* ToDo: 終了処理を書く */
  delete _singleton;
}

CourseInfoGenerator* CourseInfoGenerator::getInstance()
{
  /* 初めて呼び出すとき */
  if(_singleton == NULL) {
    /* メモリの確保 */
    _singleton = new CourseInfoGenerator();
    /* 初期化 */
    _singleton->_initialize();
  }
}

int CourseInfoGenerator::getCourseInfoL(ETROBOC_COURSE_INFO_ID id)
{
  int circleIdIndex = 0;
  if(readBlockInfoL == READ_ALL_MASK) {
    readBlockInfoL = NOT_READ_MASK;
    currentBlockPatternindexL = (currentBlockPatternindexL + 1) % allBlockPatterns.size();
  }
  if(id == ETROBOC_COURSE_INFO_BLOCK_POS_BLACK1) {
    return 48;
  } else if(id == ETROBOC_COURSE_INFO_BLOCK_POS_RED1) {
    circleIdIndex = allBlockPatterns[currentBlockPatternindexL][0];
    readBlockInfoL |= READ_RED1_MASK;
  } else if(id == ETROBOC_COURSE_INFO_BLOCK_POS_RED2) {
    circleIdIndex = allBlockPatterns[currentBlockPatternindexL][1];
    readBlockInfoL |= READ_RED2_MASK;
  } else if(id == ETROBOC_COURSE_INFO_BLOCK_POS_YELLOW1) {
    circleIdIndex = allBlockPatterns[currentBlockPatternindexL][2];
    readBlockInfoL |= READ_YELLOW1_MASK;
  } else if(id == ETROBOC_COURSE_INFO_BLOCK_POS_YELLOW2) {
    circleIdIndex = allBlockPatterns[currentBlockPatternindexL][3];
    readBlockInfoL |= READ_YELLOW2_MASK;
  } else if(id == ETROBOC_COURSE_INFO_BLOCK_POS_BLUE1) {
    circleIdIndex = allBlockPatterns[currentBlockPatternindexL][4];
    readBlockInfoL |= READ_BLUE1_MASK;
  } else if(id == ETROBOC_COURSE_INFO_BLOCK_POS_BLUE2) {
    circleIdIndex = allBlockPatterns[currentBlockPatternindexL][5];
    readBlockInfoL |= READ_BLUE2_MASK;
  } else if(id == ETROBOC_COURSE_INFO_BLOCK_POS_GREEN1) {
    circleIdIndex = allBlockPatterns[currentBlockPatternindexL][6];
    readBlockInfoL |= READ_GREEN1_MASK;
  } else if(id == ETROBOC_COURSE_INFO_BLOCK_POS_GREEN2) {
    circleIdIndex = allBlockPatterns[currentBlockPatternindexL][7];
    readBlockInfoL |= READ_GREEN2_MASK;
  } else {
    return -1;
  }
  return CROSS_CIRCLE_ID_LISTS_L[circleIdIndex];
}

int CourseInfoGenerator::getCourseInfoR(ETROBOC_COURSE_INFO_ID id)
{
  int circleIdIndex = 0;
  if(readBlockInfoR == READ_ALL_MASK) {
    readBlockInfoR = NOT_READ_MASK;
    currentBlockPatternindexR = (currentBlockPatternindexR + 1) % allBlockPatterns.size();
  }
  if(id == ETROBOC_COURSE_INFO_BLOCK_POS_BLACK1) {
    return 48;
  } else if(id == ETROBOC_COURSE_INFO_BLOCK_POS_RED1) {
    circleIdIndex = allBlockPatterns[currentBlockPatternindexR][0];
    readBlockInfoR |= READ_RED1_MASK;
  } else if(id == ETROBOC_COURSE_INFO_BLOCK_POS_RED2) {
    circleIdIndex = allBlockPatterns[currentBlockPatternindexR][1];
    readBlockInfoR |= READ_RED2_MASK;
  } else if(id == ETROBOC_COURSE_INFO_BLOCK_POS_YELLOW1) {
    circleIdIndex = allBlockPatterns[currentBlockPatternindexR][2];
    readBlockInfoR |= READ_YELLOW1_MASK;
  } else if(id == ETROBOC_COURSE_INFO_BLOCK_POS_YELLOW2) {
    circleIdIndex = allBlockPatterns[currentBlockPatternindexR][3];
    readBlockInfoR |= READ_YELLOW2_MASK;
  } else if(id == ETROBOC_COURSE_INFO_BLOCK_POS_BLUE1) {
    circleIdIndex = allBlockPatterns[currentBlockPatternindexR][4];
    readBlockInfoR |= READ_BLUE1_MASK;
  } else if(id == ETROBOC_COURSE_INFO_BLOCK_POS_BLUE2) {
    circleIdIndex = allBlockPatterns[currentBlockPatternindexR][5];
    readBlockInfoR |= READ_BLUE2_MASK;
  } else if(id == ETROBOC_COURSE_INFO_BLOCK_POS_GREEN1) {
    circleIdIndex = allBlockPatterns[currentBlockPatternindexR][6];
    readBlockInfoR |= READ_GREEN1_MASK;
  } else if(id == ETROBOC_COURSE_INFO_BLOCK_POS_GREEN2) {
    circleIdIndex = allBlockPatterns[currentBlockPatternindexR][7];
    readBlockInfoR |= READ_GREEN2_MASK;
  } else {
    return -1;
  }
  return CROSS_CIRCLE_ID_LISTS_R[circleIdIndex];
}

CourseInfoGenerator::CourseInfoGenerator()
  : CROSS_CIRCLE_ID_LISTS_L((69, 77, 66, 75, 68, 82, 71, 80)),
    CROSS_CIRCLE_ID_LISTS_R((72, 74, 67, 76, 65, 81, 70, 83))
{
  /* 何もしない */
}

CourseInfoGenerator::CourseInfoGenerator(const CourseInfoGenerator& src)
{
  /* シングルトンをコピーしておく */
  _singleton = src._singleton;
}

CourseInfoGenerator& CourseInfoGenerator::operator=(const CourseInfoGenerator& src)
{
  /* シングルトンをコピーしておく */
  _singleton = src._singleton;
  return *this;
}

void CourseInfoGenerator::_initialize()
{
  /* ToDo: 初期化処理を実装する */
  std::vector<int> baseCase = { 0, 1, 2, 3, 4, 5, 6, 7 };
  do {
    for(auto num : baseCase) {
      allBlockPatterns.push_back(baseCase);
    }
  } while(std::next_permutation(baseCase.begin(), baseCase.end()));
}
