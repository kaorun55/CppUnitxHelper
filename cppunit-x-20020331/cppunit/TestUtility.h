/*
 * TestUtility.h
 */

#ifndef cppunit_TestUtility_h
#define cppunit_TestUtility_h

#include "cuconfig.h"

cu_NAMESPACE_BEGIN(cppunit)

/**
 * ユーティリティ。
 */
class TestUtility
{
  public:
	/** ファイル名からディレクトリ部分を取り除く。 */
	static const char* trimFileName(const char* fileName);
};

cu_NAMESPACE_END

#endif /* !cppunit_TestUtility_h */
