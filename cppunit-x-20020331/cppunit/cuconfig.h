/*
 * cuconfig.h
 */

#ifndef cppunit_cuconfig_h
#define cppunit_cuconfig_h

/*
 * �J�������Ƃ̐ݒ�B
 */
// << Compilers >>
// _MSC_VER     : Microsoft Visual C++
// __BORLANDC__ : Borland C++
// __GNUC__     : GNU C/C++

// << Platforms >>
// _WIN32       : Win32
// __unix__     : Unix
// __linux__    : Linux
// __CYGWIN__   : Cygwin
// __MINGW32__  : Mingw32
// __Lynx__     : LynxOS
// VxWorks      : VxWorks

// cu_ �Ŏn�܂�}�N���͓����I�Ɏg�p������̂Ȃ̂ŁA
// ���[�U�̎g�p�͏��サ�Ȃ��B

#include <stddef.h>
#if defined(__INCvxANSIh) && !defined(VxWorks)
#  define VxWorks
#endif

#if 0
#  define cu_OLD_FOR_SCOPE
#  define cu_NO_EXPLICIT
#endif

// for Debug
#ifdef MINIMUM_SET
#  define cu_NO_TEMPLATES
#  define cu_NO_MEMBER_TEMPLATES
#  define cu_NO_MEMBER_TEMPLATE_CLASSES
#  define cu_NO_NAMESPACES
#  define cu_NO_NAMESPACE_STD
#  define cu_NO_EXCEPTIONS
#  define cu_NO_RTTI
#  define cu_NO_STD_STRING
#  define cu_NO_STD_LIST
#  define cu_NO_STD_AUTO_PTR
#  define cu_NO_TIME_H
#  define cu_NO_FILE_OPERATIONS
#endif

#ifdef _MSC_VER
  // �u�f�o�b�O���Ŏ��ʎq�� 255 �����ɐ؂�̂Ă��܂����v�� OFF�B
#  pragma warning(disable:4786)
#  define cu_OLD_FOR_SCOPE
  // MSVC++ 6.0 �� auto_ptr �� ISO/ANSI ��݊��B
#  define cu_NO_STD_AUTO_PTR
#endif

#ifdef __BORLANDC__
  // �u��������ɐ^/�U�v�� OFF�B
#  pragma warn -ccc
  // �u���s����Ȃ��R�[�h�v�� OFF�B
#  pragma warn -rch
  // �u�p�����[�^�`�͈�x���g�p����Ȃ��v�� OFF�B
#  pragma warn -par
  // �u�`�̓C�����C���W�J�ł��Ȃ��v�� OFF�B
#  pragma warn -inl
#endif

#ifdef __GNUC__
#  if __GNUC__ < 2 || (__GNUC__ == 2 && __GNUC_MINOR__ < 8)
#    define cu_NO_EXPLICIT
#    define cu_NO_MEMBER_TEMPLATES
#    define cu_NO_MEMBER_TEMPLATE_CLASSES
#    define cu_NO_NAMESPACES
#    define cu_NO_NAMESPACE_STD
#    define cu_NO_EXCEPTIONS
#    define cu_NO_RTTI
#    define cu_NO_STD_STRING
#    define cu_NO_STD_LIST
#    define cu_HAS_INNER_CLASS_BUG
#  endif
#  if __GNUC__ < 2 || (__GNUC__ == 2 && __GNUC_MINOR__ < 95)
#    define cu_NO_STD_AUTO_PTR
#  endif
#  if __GNUC__ < 3
#    define char_traits string_char_traits
#    define ios_base ios
#  endif
#endif

#ifdef VxWorks
#  define cu_NO_NAMESPACES
#  define cu_NO_NAMESPACE_STD
#endif

#ifdef cu_NO_TEMPLATES
#  define cu_NO_MEMBER_TEMPLATES
#  define cu_NO_MEMBER_TEMPLATE_CLASSES
#  define cu_NO_STD_LIST
#  define cu_NO_STD_AUTO_PTR
#endif

/*
 * C++ ����T�|�[�g�֘A�̒�`�B
 */
#if 0
// ����ŗǂ��炵�����A�����Ȃ̂Ŗ����ɂ��Ă����B
#ifdef cu_OLD_FOR_SCOPE
#  define for if (0) ; else for
#endif
#endif

#ifdef cu_NO_EXPLICIT
#  define explicit
#endif

#ifndef cu_NO_NAMESPACES
#  define cu_NAMESPACE_BEGIN(ns) namespace ns {
#  define cu_NAMESPACE_END       }
#  define cu_USING_NAMESPACE(ns) using namespace ns;
#  define cu_USING(name)         using name;
#  define cu_NAMESPACE(ns)       ns
#else
#  define cu_NAMESPACE_BEGIN(ns)
#  define cu_NAMESPACE_END
#  define cu_USING_NAMESPACE(ns)
#  define cu_USING(name)
#  define cu_NAMESPACE(ns)
#endif

#ifndef cu_NO_NAMESPACE_STD
#  define cu_NAMESPACE_STD_BEGIN namespace std {
#  define cu_NAMESPACE_STD_END   }
#  define cu_USING_NAMESPACE_STD using namespace std;
#  define cu_USING_STD(name)     using std::name;
#  define cu_STD                 std
#else
#  define cu_NAMESPACE_STD_BEGIN
#  define cu_NAMESPACE_STD_END
#  define cu_USING_NAMESPACE_STD
#  define cu_USING_STD(name)
#  define cu_STD
#endif

#ifndef cu_NO_EXCEPTIONS
#  define cu_TRY       try
#  define cu_CATCH_ALL catch (...)
#  define cu_THROW(e)  throw (e)
#  define cu_RETHROW   throw
#  define cu_NOTHROW   throw()
#else
#  define cu_TRY
#  define cu_CATCH_ALL if (false)
#  define cu_THROW(e)
#  define cu_RETHROW
#  define cu_NOTHROW
#endif

/*
 * CppUnit �֌W�̒�`�B
 */
#define USING_NAMESPACE_CPPUNIT cu_USING_NAMESPACE(cppunit)
#define USING_CPPUNIT(name)     cu_USING(cppunit::name)
#define CPPUNIT                 cu_NAMESPACE(cppunit)

#ifndef cu_NO_STD_STRING
#  include <string>
  cu_NAMESPACE_BEGIN(cppunit)
  typedef cu_STD::string cu_String;
  cu_NAMESPACE_END
#else
  cu_NAMESPACE_BEGIN(cppunit)
  class SimpleString;
  typedef CPPUNIT::SimpleString cu_String;
  cu_NAMESPACE_END
#  include "SimpleString.h"
#endif

#ifndef cu_NO_STD_LIST
#  include <list>
  cu_NAMESPACE_BEGIN(cppunit)
  typedef cu_STD::list<void*> cu_List;
  cu_NAMESPACE_END
#else
  cu_NAMESPACE_BEGIN(cppunit)
  class SimpleList;
  typedef CPPUNIT::SimpleList cu_List;
  cu_NAMESPACE_END
#  include "SimpleList.h"
#endif

#ifndef cu_NO_STD_AUTO_PTR
#  include <memory>
#  define cu_AUTO_PTR(T) cu_STD::auto_ptr<T>
#else
#  include "SimpleAutoPtr.h"
#  define cu_AUTO_PTR(T) SIMPLE_AUTO_PTR(T)
#endif

#define cu_TEXT(e)            cu_TEXTX(e)
#define cu_TEXTX(e)           #e
#define cu_NAME2(a, b)        cu_NAME2X(a, b)
#define cu_NAME2X(a, b)       a ## b
#define cu_NAME3(a, b, c)     cu_NAME3X(a, b, c)
#define cu_NAME3X(a, b, c)    a ## b ## c
#define cu_NAME4(a, b, c, d)  cu_NAME4X(a, b, c, d)
#define cu_NAME4X(a, b, c, d) a ## b ## c ## d

#endif /* !cppunit_cuconfig_h */
