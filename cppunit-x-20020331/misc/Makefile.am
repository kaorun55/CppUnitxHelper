## Process this file with automake to produce Makefile.in.

INCLUDES = -I$(top_srcdir)

noinst_PROGRAMS = AllTests_lc SampleTest_lc

AllTests_lc_SOURCES   = AllTests_lc.cpp
SampleTest_lc_SOURCES = SampleTest_lc.cpp

EXTRA_DIST = \
  cppunit_all.cpp \
  cppunit_tests.cpp \
  make4bcc.bat

DISTCLEANFILES = *.exe *.tds *.obj
