## Process this file with automake to produce Makefile.in.

EXTRA_DIST = \
  cppunit.dsw \
  cppunit/cppunit.dsp \
  cppunit_tests/cppunit_tests.dsp \
  SampleTest/SampleTest.dsp

CLEANFILES = cppunit.lib

DISTCLEANFILES = \
  cppunit.ncb \
  cppunit.opt \
  cppunit/cppunit.plg \
  cppunit_tests/cppunit_tests.plg \
  SampleTest/SampleTest.plg

CLEAN_SUBDIRS = \
  cppunit/Debug \
  cppunit/Release \
  cppunit_tests/Debug \
  cppunit_tests/Release \
  SampleTest/Debug \
  SampleTest/Release

clean-local:
	-rm -rf $(CLEAN_SUBDIRS)
