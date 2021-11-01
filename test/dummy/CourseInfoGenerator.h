/**
 * @file CourseInfoGenerator.h
 * @brief GoogleTestにおいて、全てのブロック配置パターンを網羅するためのシングルトンクラス
 * @author Takahiro55555
 * @ref
 */

#ifndef COURSE_INFO_GENERATOR_H
#define COURSE_INFO_GENERATOR_H

#include <vector>
#include <algorithm>
#include "etroboc_ext.h"

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
   * ビット演算用マスク
   */
  const uint8_t READ_RED1_MASK = 0b00000001;
  const uint8_t READ_RED2_MASK = 0b00000010;
  const uint8_t READ_YELLOW1_MASK = 0b00000100;
  const uint8_t READ_YELLOW2_MASK = 0b00001000;
  const uint8_t READ_BLUE1_MASK = 0b00010000;
  const uint8_t READ_BLUE2_MASK = 0b00100000;
  const uint8_t READ_GREEN1_MASK = 0b01000000;
  const uint8_t READ_GREEN2_MASK = 0b10000000;
  const uint8_t READ_ALL_MASK = 0b11111111;
  const uint8_t NOT_READ_MASK = 0b00000000;

  /**
   * シミュレータ用APIにおける交点サークルの座標ID(L)
   */
  const std::vector<int> CROSS_CIRCLE_ID_LISTS_L;

  /**
   * シミュレータ用APIにおける交点サークルの座標ID(R)
   */
  const std::vector<int> CROSS_CIRCLE_ID_LISTS_R;

  /**
   * 全パターンのブロック配置を持つ
   */
  std::vector<std::vector<int>> allBlockPatterns;

  /**
   * allBlockPatterns における現在返すべき情報の添え字(L)
   */
  int currentBlockPatternindexL = 0;

  /**
   * allBlockPatterns における現在返すべき情報の添え字(R)
   */
  int currentBlockPatternindexR = 0;

  /**
   * 配置情報取得済みブロックの情報を保持する(L)
   */
  uint8_t readBlockInfoL = NOT_READ_MASK;

  /**
   * 配置情報取得済みブロックの情報を保持する(R)
   */
  uint8_t readBlockInfoR = NOT_READ_MASK;

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