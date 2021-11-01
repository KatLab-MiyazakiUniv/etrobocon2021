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
}
