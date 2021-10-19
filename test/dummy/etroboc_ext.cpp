/**
 * @file etroboc_ext.cpp
 * @brief EV3拡張API（ダミー）
 * @author Takahiro55555,Hisataka-Hagiyama,uchyam
 */

#include "etroboc_ext.h"

bool isLeft = true;

int ETRoboc_getCourseInfo(ETROBOC_COURSE_INFO_ID id)
{
  std::string fname = isLeft ? COURSE_INFO_ALL_PATTERN_L : COURSE_INFO_ALL_PATTERN_R;
  AllCourseInfo info = readAllCourseInfo(fname);

  if(info.allInfo.size() == 0 || info.currentIndex < 0) {
    return getDefaultCourseInfo(id);
  }
  return getCurrentCourseInfo(id, info);
}

void setIsLeft(bool _isLeft)
{
  isLeft = _isLeft;
}

int getDefaultCourseInfo(ETROBOC_COURSE_INFO_ID id)
{
  if(id == ETROBOC_COURSE_INFO_BLOCK_POS_BLACK1) {
    return 48;
  } else if(id == ETROBOC_COURSE_INFO_BLOCK_POS_RED1) {
    return (isLeft ? 69 : 72);
  } else if(id == ETROBOC_COURSE_INFO_BLOCK_POS_RED2) {
    return (isLeft ? 77 : 74);
  } else if(id == ETROBOC_COURSE_INFO_BLOCK_POS_YELLOW1) {
    return (isLeft ? 66 : 67);
  } else if(id == ETROBOC_COURSE_INFO_BLOCK_POS_YELLOW2) {
    return (isLeft ? 75 : 76);
  } else if(id == ETROBOC_COURSE_INFO_BLOCK_POS_BLUE1) {
    return (isLeft ? 68 : 65);
  } else if(id == ETROBOC_COURSE_INFO_BLOCK_POS_BLUE2) {
    return (isLeft ? 82 : 81);
  } else if(id == ETROBOC_COURSE_INFO_BLOCK_POS_GREEN1) {
    return (isLeft ? 71 : 70);
  } else if(id == ETROBOC_COURSE_INFO_BLOCK_POS_GREEN2) {
    return (isLeft ? 80 : 83);
  } else {
    return -1;
  }
}

//ToDo: initialAccesTime, lastAccessTime 等の設定処理
int getCurrentCourseInfo(ETROBOC_COURSE_INFO_ID id, AllCourseInfo& info)
{
  int blockPos = -1;
  if(id == ETROBOC_COURSE_INFO_BLOCK_POS_BLACK1) {
    blockPos = 48;
  } else if(id == ETROBOC_COURSE_INFO_BLOCK_POS_RED1) {
    blockPos = (int)info.allInfo[info.currentIndex].pattern[0];
    info.allInfo[info.currentIndex].accessCounter[0]++;
  } else if(id == ETROBOC_COURSE_INFO_BLOCK_POS_RED2) {
    blockPos = (int)info.allInfo[info.currentIndex].pattern[1];
    info.allInfo[info.currentIndex].accessCounter[1]++;
  } else if(id == ETROBOC_COURSE_INFO_BLOCK_POS_YELLOW1) {
    blockPos = (int)info.allInfo[info.currentIndex].pattern[2];
    info.allInfo[info.currentIndex].accessCounter[2]++;
  } else if(id == ETROBOC_COURSE_INFO_BLOCK_POS_YELLOW2) {
    blockPos = (int)info.allInfo[info.currentIndex].pattern[3];
    info.allInfo[info.currentIndex].accessCounter[3]++;
  } else if(id == ETROBOC_COURSE_INFO_BLOCK_POS_BLUE1) {
    blockPos = (int)info.allInfo[info.currentIndex].pattern[4];
    info.allInfo[info.currentIndex].accessCounter[4]++;
  } else if(id == ETROBOC_COURSE_INFO_BLOCK_POS_BLUE2) {
    blockPos = (int)info.allInfo[info.currentIndex].pattern[5];
    info.allInfo[info.currentIndex].accessCounter[5]++;
  } else if(id == ETROBOC_COURSE_INFO_BLOCK_POS_GREEN1) {
    blockPos = (int)info.allInfo[info.currentIndex].pattern[6];
    info.allInfo[info.currentIndex].accessCounter[6]++;
  } else if(id == ETROBOC_COURSE_INFO_BLOCK_POS_GREEN2) {
    blockPos = (int)info.allInfo[info.currentIndex].pattern[7];
    info.allInfo[info.currentIndex].accessCounter[7]++;
  }
  return blockPos;
}

AllCourseInfo& readAllCourseInfo(std::string fname)
{
  AllCourseInfo info;
  info.allInfo.reserve(40320);  // メモリの再確保を防止
  info.fname = fname;
  info.currentIndex = -1;

  std::ifstream ifs_csv_file(fname);
  std::string line;

  // ヘッダー行の確認
  std::getline(ifs_csv_file, line);
  if(line != EXPECTED_CSV_HEADER_LR) {
    return info;
  }

  // ファイルに記述されたコース情報を全て読み取る
  int index = 0;
  while(std::getline(ifs_csv_file, line)) {
    SingleCourseInfo singleInfo = stringToSingleCourseInfo(line);
    info.allInfo.push_back(singleInfo);

    // 次に読み込むべきコース情報か、そうでないかを判定
    if(info.currentIndex < 0) {
      bool isNotUsed = false;
      for(int i = 0; i < BLOCK_INFO_ARRAY_LEN; i++) {
        if(singleInfo.accessCounter[i] == 9) {
          isNotUsed = false;
          break;
        }
        if(singleInfo.accessCounter[i] == 0) {
          isNotUsed = true;
        }
      }
      if(isNotUsed) {
        info.currentIndex = index;
      }
    }
    index++;
  }

  return info;
}

SingleCourseInfo& stringToSingleCourseInfo(std::string line)
{
  SingleCourseInfo singleCourseInfo;
  sscanf(line.c_str(), "%s,%u%u%u%u%u%u%u%u,%lf,%lf", singleCourseInfo.pattern,
         &singleCourseInfo.accessCounter[0], &singleCourseInfo.accessCounter[1],
         &singleCourseInfo.accessCounter[2], &singleCourseInfo.accessCounter[3],
         &singleCourseInfo.accessCounter[4], &singleCourseInfo.accessCounter[5],
         &singleCourseInfo.accessCounter[6], &singleCourseInfo.accessCounter[7],
         &singleCourseInfo.firstAccessTimeMilliSec, &singleCourseInfo.lastAccessTimeMilliSec);
  return singleCourseInfo;
}

int writeAllCourseInfo(AllCourseInfo& allInfo)
{
  std::ofstream ofs_csv_file(allInfo.fname);
  ofs_csv_file << EXPECTED_CSV_HEADER_LR << std::endl;
  for(SingleCourseInfo singleInfo : allInfo.allInfo) {
    ofs_csv_file << singleCourseInfoToString(singleInfo) << std::endl;
  }
  return 0;
}

std::string singleCourseInfoToString(SingleCourseInfo& singleCourseInfo)
{
  std::string line;
  line += std::string(singleCourseInfo.pattern) + ",";
  line += std::to_string(singleCourseInfo.accessCounter[0]);
  line += std::to_string(singleCourseInfo.accessCounter[1]);
  line += std::to_string(singleCourseInfo.accessCounter[2]);
  line += std::to_string(singleCourseInfo.accessCounter[3]);
  line += std::to_string(singleCourseInfo.accessCounter[4]);
  line += std::to_string(singleCourseInfo.accessCounter[5]);
  line += std::to_string(singleCourseInfo.accessCounter[6]);
  line += std::to_string(singleCourseInfo.accessCounter[7]) + ",";
  line += std::to_string(singleCourseInfo.firstAccessTimeMilliSec) + ",";
  line += std::to_string(singleCourseInfo.lastAccessTimeMilliSec);
  return line;
}

time_t getMillisecondsSinceEpoch()
{
  struct timeval time_now {
  };
  gettimeofday(&time_now, nullptr);
  return (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
}
