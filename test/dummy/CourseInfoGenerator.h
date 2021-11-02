/**
 * @file CourseInfoGenerator.h
 * @brief GoogleTestにおいて、全てのブロック配置パターンを網羅するためのシングルトンクラス
 * @author Takahiro55555
 * @ref
 */

#ifndef COURSE_INFO_GENERATOR_H
#define COURSE_INFO_GENERATOR_H
#include "etroboc_ext.h"
#include <vector>
#include <algorithm>

/**
 * ビット演算用マスク
 */
constexpr int READ_RED1_MASK = 0b00000001;
constexpr int READ_RED2_MASK = 0b00000010;
constexpr int READ_YELLOW1_MASK = 0b00000100;
constexpr int READ_YELLOW2_MASK = 0b00001000;
constexpr int READ_BLUE1_MASK = 0b00010000;
constexpr int READ_BLUE2_MASK = 0b00100000;
constexpr int READ_GREEN1_MASK = 0b01000000;
constexpr int READ_GREEN2_MASK = 0b10000000;
constexpr int READ_ALL_MASK = 0b11111111;
constexpr int NOT_READ_MASK = 0b00000000;

/**
 * シミュレータ用APIにおける交点サークルの座標ID(L)
 */
constexpr int CROSS_CIRCLE_ID_LISTS_L[] = {69, 77, 66, 75, 68, 82, 71, 80};

/**
 * シミュレータ用APIにおける交点サークルの座標ID(R)
 */
constexpr int CROSS_CIRCLE_ID_LISTS_R[] = {72, 74, 67, 76, 65, 81, 70, 83};

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
  int getCourseInfoL(ETROBOC_COURSE_INFO_ID id);

  /**
   * コース情報の取得(R)
   * @param id
   * @return 位置情報(ASCIIコード)
   */
  int getCourseInfoR(ETROBOC_COURSE_INFO_ID id);

 private:
  /**
   * シングルトン用インスタンス
   */
  static CourseInfoGenerator* _singleton;

  /**
   * 全パターンのブロック配置を持つ
   */
  static std::vector<std::vector<int>> allBlockPatterns;

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
  static uint8_t readBlockInfoL;

  /**
   * 配置情報取得済みブロックの情報を保持する(R)
   */
  static uint8_t readBlockInfoR;

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
   * 初期化する
   */
  void _initialize();

  CourseInfoGenerator();

//   ~CourseInfoGenerator();
};

#endif