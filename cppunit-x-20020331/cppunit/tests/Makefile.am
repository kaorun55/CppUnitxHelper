## Process this file with automake to produce Makefile.in.

TESTS = AllTests

INCLUDES = -I$(top_srcdir)

noinst_PROGRAMS = AllTests

AllTests_SOURCES = \
  SimpleStringTest.cpp \
  SimpleListTest.cpp \
  SimpleAutoPtrTest.cpp \
  TestUtilityTest.cpp \
  TestResultTest.cpp \
  TestCaseTest.cpp \
  TestCallerTest.cpp \
  TestSuiteTest.cpp \
  TestRegistryTest.cpp \
  TestDecoratorTest.cpp \
  RepeatedTestTest.cpp \
  TestSetupTest.cpp \
  CppUnitTest.cpp \
  AllTests.cpp \
  SimpleStringTest.h \
  SimpleListTest.h \
  SimpleAutoPtrTest.h \
  TestUtilityTest.h \
  TestResultTest.h \
  TestCaseTest.h \
  TestCallerTest.h \
  TestSuiteTest.h \
  TestRegistryTest.h \
  TestDecoratorTest.h \
  RepeatedTestTest.h \
  TestSetupTest.h \
  CppUnitTest.h

AllTests_LDADD = $(top_builddir)/cppunit/libcppunit.a
