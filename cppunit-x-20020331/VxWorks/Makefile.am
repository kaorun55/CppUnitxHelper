## Process this file with automake to produce Makefile.in.

EXTRA_DIST = \
  cppunit.wsp \
  cppunit/cppunit.wpj \
  cppunit_tests/cppunit_tests.wpj \
  SampleTest/SampleTest.wpj

DISTCLEANFILES = \
  cppunit/Makefile \
  cppunit/prjObjs.lst \
  cppunit_tests/Makefile \
  cppunit_tests/prjObjs.lst \
  SampleTest/Makefile \
  SampleTest/prjObjs.lst

CLEAN_SUBDIRS = \
  cppunit/SIMNTgnu \
  cppunit_tests/SIMNTgnu \
  SampleTest/SIMNTgnu

clean-local:
	-rm -rf $(CLEAN_SUBDIRS)
