/**
 * @file CourseInfoGenerator.cpp
 * @brief GoogleTestにおいて、全てのブロック配置パターンを網羅するためのシングルトンクラス
 * @author Takahiro55555
 * 参考文献: C++におけるオブジェクトの取り扱い方[シングルトン]
 *   URL: https://www.haljion.net/index.php/2019-11-13-03-27-18/119-2019-11-13-03-22-16/rx-62n/222-c
 */

#include "CourseInfoGenerator.h"

CourseInfoGenerator* CourseInfoGenerator::_singleton = NULL;
int CourseInfoGenerator::currentBlockPatternindexL = 0;
int CourseInfoGenerator::currentBlockPatternindexR = 0;
char CourseInfoGenerator::readBlockInfoL = NOT_READ_MASK;
char CourseInfoGenerator::readBlockInfoR = NOT_READ_MASK;
std::vector<std::array<int, PERMUTATION_N>> CourseInfoGenerator::allBlockPatterns = {};
std::string CourseInfoGenerator::logCsvFileNameL = "";
std::string CourseInfoGenerator::logCsvFileNameR = "";

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

void CourseInfoGenerator::writeLogWithCurrentCourseInfo(std::string msg, bool isLeft){
  int currentIndex = currentBlockPatternindexR;
  std::string fname = logCsvFileNameR;
  std::array<char, PERMUTATION_N> circleIdList = CROSS_CIRCLE_ID_LIST_R;
  if(isLeft){
    currentIndex = currentBlockPatternindexL;
    fname = logCsvFileNameL;
    circleIdList = CROSS_CIRCLE_ID_LIST_L;
  }
  std::array<int, PERMUTATION_N> currentBlockPattern = allBlockPatterns[currentIndex];


  char blockId[9] = {'\0'};
  for(int i = 0; i < PERMUTATION_N; i++) {
    blockId[i] = circleIdList[currentBlockPattern[i]];
  }

  std::fstream logFile;
  logFile.open(fname, std::ios_base::app | std::ios_base::in);
  if (logFile.is_open()){
    logFile << currentIndex << "," << std::string(blockId) << "," << msg << std::endl;
  }
  logFile.close();
}

int CourseInfoGenerator::getCourseInfo(ETROBOC_COURSE_INFO_ID id, bool isLeft){
  if (isLeft){
    return getCourseInfoL(id);
  }
  return getCourseInfoR(id);
}

CourseInfoGenerator::CourseInfoGenerator()
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

  std::array<int, PERMUTATION_N> baseCase = { 0, 1, 2, 3, 4, 5, 6, 7 };
  do {
    for(auto num : baseCase) {
      allBlockPatterns.push_back(baseCase);
    }
  } while(std::next_permutation(baseCase.begin(), baseCase.end()));
  
  std::string datetime = getDatetimeStr();
  logCsvFileNameL = "../test-log-" + datetime + "-l.csv";
  logCsvFileNameR = "../test-log-" + datetime + "-r.csv";
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
  return (int)CROSS_CIRCLE_ID_LIST_L[circleIdIndex];
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
  return (int)CROSS_CIRCLE_ID_LIST_R[circleIdIndex];
}

std::string CourseInfoGenerator::getDatetimeStr() {
    time_t t = std::time(nullptr);
    const tm* localTime = std::localtime(&t);
    std::stringstream s;
    s << "20" << localTime->tm_year - 100 << "-";
    // setw(),setfill()で0詰め
    s << std::setw(2) << std::setfill('0') << localTime->tm_mon + 1;
    s << std::setw(2) << std::setfill('0') << localTime->tm_mday  << "-";
    s << std::setw(2) << std::setfill('0') << localTime->tm_hour;
    s << std::setw(2) << std::setfill('0') << localTime->tm_min  << "-";
    s << std::setw(2) << std::setfill('0') << localTime->tm_sec;
    // std::stringにして値を返す
    return s.str();
}