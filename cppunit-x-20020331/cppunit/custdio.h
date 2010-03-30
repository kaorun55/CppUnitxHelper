/*
 * custdio.h
 */

#ifndef cppunit_custdio_h
#define cppunit_custdio_h

#include "cuconfig.h"
#include <stdio.h>
#include <stdarg.h>

#ifdef cu_NO_FILE_OPERATIONS

cu_NAMESPACE_BEGIN(cppunit)

inline int cu_fflush(void*) { return 0; }
inline int cu_fputc(char c, void*) { return putchar(c); }

inline int cu_fputs(const char* s, void*)
{
	// puts() ‚¾‚Æ‰üs‚ª’Ç‰Á‚³‚ê‚Ä‚µ‚Ü‚¤B
	int result = printf("%s", s);
	return (result >= 0) ? result : EOF;
}

inline int cu_fprintf(void*, const char* format, ...)
{
	va_list ap;
	va_start(ap, format);
	int result = vprintf(format, ap);
	va_end(ap);
	return result;
}

inline int cu_vfprintf(void*, const char* format, va_list ap)
{
	return vprintf(format, ap);
}

cu_NAMESPACE_END

#undef  FILE
#undef  stdin
#undef  stdout
#undef  stderr
#undef  fflush
#undef  putc
#undef  fputc
#undef  fputs
#undef  fprintf
#undef  vfprintf

#define FILE                  void
#define stdin                 0
#define stdout                0
#define stderr                0
#define fflush(fp)            CPPUNIT::cu_fflush(fp)
#define putc(c, fp)           CPPUNIT::cu_fputc(c, fp)
#define fputc(c, fp)          CPPUNIT::cu_fputc(c, fp)
#define fputs(s, fp)          CPPUNIT::cu_fputs(s, fp)
#define fprintf               CPPUNIT::cu_fprintf
#define vfprintf(fp, fmt, ap) CPPUNIT::cu_vfprintf(fp, fmt, ap)

#endif /* cu_NO_FILE_OPERATIONS */

#endif /* !cppunit_custdio_h */
