/*
 * cudebug.h
 */

#ifndef cppunit_cudebug_h
#define cppunit_cudebug_h

#include "cuconfig.h"
#include "TestUtility.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#ifdef cu_NO_FILE_OPERATIONS
#  include "custdio.h"
#endif

cu_NAMESPACE_BEGIN(cppunit)

#ifdef NDEBUG
#  define cu_ASSERT(e) (void)0
#else
#  define cu_ASSERT(e) \
	((e) ? (void)0 : CPPUNIT::cu_assert(__FILE__, __LINE__, #e))

inline void cu_assert(const char* file, int line, const char* message)
{
	fprintf(stderr, "\n%s(%d): assertion failed: %s\n",
			TestUtility::trimFileName(file), line, message);
	abort();
}

#endif /* !NDEBUG */

#ifndef DEBUG
#  define cu_IFTRACE(e) (void)0
#else
#  define cu_IFTRACE(e) (e)

inline void cu_trace(const char* file, int line, const char* format, ...)
{
	va_list ap;
	va_start(ap, format);
	fprintf(stdout, "%s(%d): ", TestUtility::trimFileName(file), line);
	vfprintf(stdout, format, ap);
	va_end(ap);
}

#endif /* DEBUG */

#define cu_TRACE(s) \
	cu_IFTRACE(CPPUNIT::cu_trace(__FILE__, __LINE__, s))
#define cu_TRACE1(fmt, p1) \
	cu_IFTRACE(CPPUNIT::cu_trace(__FILE__, __LINE__, fmt, p1))
#define cu_TRACE2(fmt, p1, p2) \
	cu_IFTRACE(CPPUNIT::cu_trace(__FILE__, __LINE__, fmt, p1, p2))
#define cu_TRACE3(fmt, p1, p2, p3) \
	cu_IFTRACE(CPPUNIT::cu_trace(__FILE__, __LINE__, fmt, p1, p2, p3))
#define cu_TRACE4(fmt, p1, p2, p3, p4) \
	cu_IFTRACE(CPPUNIT::cu_trace(__FILE__, __LINE__, fmt, p1, p2, p3, p4))
#define cu_TRACE5(fmt, p1, p2, p3, p4, p5) \
	cu_IFTRACE(CPPUNIT::cu_trace(__FILE__, __LINE__, fmt, p1, p2, p3, p4, p5))

cu_NAMESPACE_END

#ifdef ENABLE_LEAK_CHECKER
#  include <debug/LeakChecker.h>
#  define USE_DEBUGTOOLS
#endif

#endif /* !cppunit_cudebug_h */
