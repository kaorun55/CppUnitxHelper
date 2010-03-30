## Process this file with automake to produce Makefile.in.

SUBDIRS = . tests

lib_LIBRARIES = libcppunit.a

libcppunit_a_SOURCES = \
  SimpleString.cpp \
  SimpleList.cpp \
  TestUtility.cpp \
  TestFailure.cpp \
  TestResult.cpp \
  TestCase.cpp \
  TestSuite.cpp \
  TestRegistry.cpp \
  TestRunner.cpp \
  TestDecorator.cpp \
  RepeatedTest.cpp \
  TestSetup.cpp \
  cudebug.h \
  custdio.h

cppunit_includedir = $(includedir)/cppunit

cppunit_include_HEADERS = \
  cuconfig.h \
  SimpleString.h \
  SimpleList.h \
  SimpleAutoPtr.h \
  TestUtility.h \
  TestFailure.h \
  TestListener.h \
  TestResult.h \
  Test.h \
  TestCase.h \
  TestCaller.h \
  TestSuite.h \
  TestRegistry.h \
  TestRunner.h \
  TestDecorator.h \
  RepeatedTest.h \
  TestSetup.h
