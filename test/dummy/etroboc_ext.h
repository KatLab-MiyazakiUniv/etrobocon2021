/**
 * @file etroboc_ext.h.h
 * @brief EV3拡張API（ダミー）
 * @author Takahiro55555,Hisataka-Hagiyama,uchyam
 */

#ifndef ETROBOC_EXT_H
#define ETROBOC_EXT_H

#include <vector>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <chrono>
#include <sys/time.h>
#include <ctime>

inline static void ETRoboc_notifyCompletedToSimulator(void) {}
void setIsLeft(bool _isLeft);

//ブロックの配置パターンを列挙したファイルの名前
//カレントディレクトリは GoogleTest を実行する際に生成される `build` ディレクトリ
static std::string COURSE_INFO_ALL_PATTERN_L = "../course-info-l.csv";
static std::string COURSE_INFO_ALL_PATTERN_R = "../course-info-r.csv";

//想定するCSVのヘッダー行
static std::string EXPECTED_CSV_HEADER_LR
    = "course_info,access_counter,first_access_time_milli_sec,last_access_time_milli_sec";

//ブロック配置情報の格納に利用する配列の長さ
#define BLOCK_INFO_ARRAY_LEN 8

//コース情報取得関数用ID定義
enum ETROBOC_COURSE_INFO_ID {
  ETROBOC_COURSE_INFO_BLOCK_POS_BLACK1,
  ETROBOC_COURSE_INFO_BLOCK_POS_RED1,
  ETROBOC_COURSE_INFO_BLOCK_POS_RED2,
  ETROBOC_COURSE_INFO_BLOCK_POS_YELLOW1,
  ETROBOC_COURSE_INFO_BLOCK_POS_YELLOW2,
  ETROBOC_COURSE_INFO_BLOCK_POS_BLUE1,
  ETROBOC_COURSE_INFO_BLOCK_POS_BLUE2,
  ETROBOC_COURSE_INFO_BLOCK_POS_GREEN1,
  ETROBOC_COURSE_INFO_BLOCK_POS_GREEN2
};

//ブロックの配置パターンを列挙したファイル1行分のデータを格納する構造体
typedef struct {
  char pattern[BLOCK_INFO_ARRAY_LEN];  //ブロック配置情報
  uint accessCounter
      [BLOCK_INFO_ARRAY_LEN];  //テスト実行時に当該情報にアクセスした回数を各ブロックごとに数える(0~9)
  double firstAccessTimeMilliSec;  //最初に当該情報にアクセスした時間
  double lastAccessTimeMilliSec;   //最後に当該情報にアクセスした時間
} SingleCourseInfo;

//全てのブロック配置パターンを列挙したデータを格納する構造体
typedef struct AllCourseInfo {
  std::vector<SingleCourseInfo> allInfo;  //コース情報
  std::string fname;                      //ファイル名
  int currentIndex;  //次に読み込むべきコース情報へのインデックス
};

/**
 * コース情報の取得
 * @param id
 * @return 位置情報(ASCIIコード)
 */
int ETRoboc_getCourseInfo(ETROBOC_COURSE_INFO_ID id);

/**
 * Unix のエポックからの経過時間を取得する
 * @return Unix のエポックからの経過時間 (ミリ秒)
 */
time_t getMillisecondsSinceEpoch();

int getDefaultCourseInfo(ETROBOC_COURSE_INFO_ID id);
int getCurrentCourseInfo(ETROBOC_COURSE_INFO_ID id, AllCourseInfo& info);
AllCourseInfo& readAllCourseInfo(std::string fname);
SingleCourseInfo& stringToSingleCourseInfo(std::string line);
int writeAllCourseInfo(AllCourseInfo& allInfo);
std::string singleCourseInfoToString(SingleCourseInfo& singleCourseInfo);

#endif
