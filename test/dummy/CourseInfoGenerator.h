/**
 * @file CourseInfoGenerator.h
 * @brief GoogleTestにおいて、全てのブロック配置パターンを網羅するためのシングルトンクラス
 * @author Takahiro55555
 * @ref
 */

#ifndef COURSE_INFO_GENERATOR_H
#define COURSE_INFO_GENERATOR_H
#include "etroboc_ext.h"
#include <array>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>


/**
 * ビット演算用マスク
 */
constexpr char READ_RED1_MASK = 0b00000001;
constexpr char READ_RED2_MASK = 0b00000010;
constexpr char READ_YELLOW1_MASK = 0b00000100;
constexpr char READ_YELLOW2_MASK = 0b00001000;
constexpr char READ_BLUE1_MASK = 0b00010000;
constexpr char READ_BLUE2_MASK = 0b00100000;
constexpr char READ_GREEN1_MASK = 0b01000000;
constexpr char READ_GREEN2_MASK = 0b10000000;
constexpr char READ_ALL_MASK = 0b11111111;
constexpr char NOT_READ_MASK = 0b00000000;

/**
 * 順列の要素数
 */
constexpr int PERMUTATION_N = 8;

/**
 * シミュレータ用APIにおける交点サークルの座標ID(L)
 */
constexpr std::array<char, PERMUTATION_N> CROSS_CIRCLE_ID_LIST_L = {69, 77, 66, 75, 68, 82, 71, 80};

/**
 * シミュレータ用APIにおける交点サークルの座標ID(R)
 */
constexpr std::array<char, PERMUTATION_N> CROSS_CIRCLE_ID_LIST_R = {72, 74, 67, 76, 65, 81, 70, 83};



class CourseInfoGenerator {
 public:
  /**
   * デストラクタ
   */
  virtual ~CourseInfoGenerator();

  /**
   * インスタンスを取得する
   * Singletonのための関数
   * @return Singleton化されたインスタンス
   */
  static CourseInfoGenerator* getInstance();

  /**
   * コース情報の取得(L)
   * @param id
   * @return 位置情報(ASCIIコード)
   */
  int getCourseInfo(ETROBOC_COURSE_INFO_ID id, bool isLeft);

  /**
   * ログ用CSVファイルに追記を行う
   * @param msg
   */
  void writeLogWithCurrentCourseInfo(std::string msg, bool isLeft);

 private:
  /**
   * シングルトン用インスタンス
   */
  static CourseInfoGenerator* _singleton;

  /**
   * 全パターンのブロック配置を持つ
   */
  static std::vector<std::array<int, PERMUTATION_N>> allBlockPatterns;

  /**
   * allBlockPatterns における現在返すべき情報の添え字(L)
   */
  static int currentBlockPatternindexL;

  /**
   * allBlockPatterns における現在返すべき情報の添え字(R)
   */
  static int currentBlockPatternindexR;

  /**
   * 配置情報取得済みブロックの情報を保持する(L)
   */
  static char readBlockInfoL;

  /**
   * 配置情報取得済みブロックの情報を保持する(R)
   */
  static char readBlockInfoR;

  /**
   * 配置情報取得済みブロックの情報を保持する(L)
   */
  static std::string logCsvFileNameL;

  /**
   * 配置情報取得済みブロックの情報を保持する(R)
   */
  static std::string logCsvFileNameR;

  /**
   * コピーコンストラクタ
   * @param src コピー元
   */
  CourseInfoGenerator(const CourseInfoGenerator& src);

  /**
   * 代入演算子
   * @param src コピー元
   */
  CourseInfoGenerator& operator=(const CourseInfoGenerator& src);

  /**
   * 初期化処理用関数
   */
  void _initialize();

  CourseInfoGenerator();

    /**
   * コース情報の取得(L)
   * @param id
   * @return 位置情報(ASCIIコード)
   */
  int getCourseInfoL(ETROBOC_COURSE_INFO_ID id);

  /**
   * コース情報の取得(R)
   * @param id
   * @return 位置情報(ASCIIコード)
   */
  int getCourseInfoR(ETROBOC_COURSE_INFO_ID id);

/**
 * 現在の日時をで返す
 * @return 「YYYY-MMDD-hhmm-ss」の形式
 * 参考: 【コピペでOK】C++で日時文字列を取得する方法！ - lisz-works
 *   URL: https://www.lisz-works.com/entry/cpp-datetime-string
 */
std::string getDatetimeStr();

};

#endif