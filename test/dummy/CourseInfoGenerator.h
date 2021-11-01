/**
 * @file CourseInfoGenerator.h
 * @brief GoogleTestにおいて、全てのブロック配置パターンを網羅するためのシングルトンクラス
 * @author Takahiro55555
 * @ref 
 */

#ifndef COURSE_INFO_GENERATOR_H
#define COURSE_INFO_GENERATOR_H

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


 private:
  /**
   * シングルトン用インスタンス
   */
  static CourseInfoGenerator* _singleton;

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
};

CourseInfoGenerator::CourseInfoGenerator(/* args */) {}

CourseInfoGenerator::~CourseInfoGenerator() {}

#endif