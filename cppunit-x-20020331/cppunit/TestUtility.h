/*
 * TestUtility.h
 */

#ifndef cppunit_TestUtility_h
#define cppunit_TestUtility_h

#include "cuconfig.h"

cu_NAMESPACE_BEGIN(cppunit)

/**
 * ���[�e�B���e�B�B
 */
class TestUtility
{
  public:
	/** �t�@�C��������f�B���N�g����������菜���B */
	static const char* trimFileName(const char* fileName);
};

cu_NAMESPACE_END

#endif /* !cppunit_TestUtility_h */
