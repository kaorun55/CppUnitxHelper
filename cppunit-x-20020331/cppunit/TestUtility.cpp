/*
 * TestUtility.cpp
 */

#include "cuconfig.h"
#include "cudebug.h"
#include "TestUtility.h"

cu_NAMESPACE_BEGIN(cppunit)

const char* TestUtility::trimFileName(const char* fileName)
{
	for (const char* p = fileName; *p != 0; ++p) {
		if (*p == '/' || *p == '\\' || *p == ':') {
			fileName = p + 1;
		}
	}
	return fileName;
}

cu_NAMESPACE_END
