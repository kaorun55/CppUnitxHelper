# Generated automatically from Makefile.in by configure.
# Makefile.in generated automatically by automake 1.4 from Makefile.am

# Copyright (C) 1994, 1995-8, 1999 Free Software Foundation, Inc.
# This Makefile.in is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY, to the extent permitted by law; without
# even the implied warranty of MERCHANTABILITY or FITNESS FOR A
# PARTICULAR PURPOSE.


SHELL = /bin/sh

srcdir = .
top_srcdir = ../..
prefix = /usr/local
exec_prefix = ${prefix}

bindir = ${exec_prefix}/bin
sbindir = ${exec_prefix}/sbin
libexecdir = ${exec_prefix}/libexec
datadir = ${prefix}/share
sysconfdir = ${prefix}/etc
sharedstatedir = ${prefix}/com
localstatedir = ${prefix}/var
libdir = ${exec_prefix}/lib
infodir = ${prefix}/info
mandir = ${prefix}/man
includedir = ${prefix}/include
oldincludedir = /usr/include

DESTDIR =

pkgdatadir = $(datadir)/cppunit-x
pkglibdir = $(libdir)/cppunit-x
pkgincludedir = $(includedir)/cppunit-x

top_builddir = ../..

ACLOCAL = aclocal
AUTOCONF = autoconf
AUTOMAKE = automake
AUTOHEADER = autoheader

INSTALL = /usr/bin/install -c
INSTALL_PROGRAM = ${INSTALL} $(AM_INSTALL_PROGRAM_FLAGS)
INSTALL_DATA = ${INSTALL} -m 644
INSTALL_SCRIPT = ${INSTALL_PROGRAM}
transform = s,x,x,

NORMAL_INSTALL = :
PRE_INSTALL = :
POST_INSTALL = :
NORMAL_UNINSTALL = :
PRE_UNINSTALL = :
POST_UNINSTALL = :
CC = gcc
CONFIGURE_DATE = 20100330
CXX = c++
CXXFLAGS = -g -O2 -Wall
EXEEXT = .dSYM
MAINT = #
MAKEINFO = makeinfo
PACKAGE = cppunit-x
RANLIB = ranlib
VERSION = 0.2

TESTS = AllTests

INCLUDES = -I$(top_srcdir)

noinst_PROGRAMS = AllTests

AllTests_SOURCES =    SimpleStringTest.cpp   SimpleListTest.cpp   SimpleAutoPtrTest.cpp   TestUtilityTest.cpp   TestResultTest.cpp   TestCaseTest.cpp   TestCallerTest.cpp   TestSuiteTest.cpp   TestRegistryTest.cpp   TestDecoratorTest.cpp   RepeatedTestTest.cpp   TestSetupTest.cpp   CppUnitTest.cpp   AllTests.cpp   SimpleStringTest.h   SimpleListTest.h   SimpleAutoPtrTest.h   TestUtilityTest.h   TestResultTest.h   TestCaseTest.h   TestCallerTest.h   TestSuiteTest.h   TestRegistryTest.h   TestDecoratorTest.h   RepeatedTestTest.h   TestSetupTest.h   CppUnitTest.h


AllTests_LDADD = $(top_builddir)/cppunit/libcppunit.a
mkinstalldirs = $(SHELL) $(top_srcdir)/config/mkinstalldirs
CONFIG_HEADER = ../../config.h
CONFIG_CLEAN_FILES = 
noinst_PROGRAMS =  AllTests$(EXEEXT)
PROGRAMS =  $(noinst_PROGRAMS)


DEFS = -DHAVE_CONFIG_H -I. -I$(srcdir) -I../..
CPPFLAGS = 
LDFLAGS = 
LIBS = 
AllTests_OBJECTS =  SimpleStringTest.o SimpleListTest.o \
SimpleAutoPtrTest.o TestUtilityTest.o TestResultTest.o TestCaseTest.o \
TestCallerTest.o TestSuiteTest.o TestRegistryTest.o TestDecoratorTest.o \
RepeatedTestTest.o TestSetupTest.o CppUnitTest.o AllTests.o
AllTests_DEPENDENCIES =  $(top_builddir)/cppunit/libcppunit.a
AllTests_LDFLAGS = 
CXXCOMPILE = $(CXX) $(DEFS) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(AM_CXXFLAGS) $(CXXFLAGS)
CXXLD = $(CXX)
CXXLINK = $(CXXLD) $(AM_CXXFLAGS) $(CXXFLAGS) $(LDFLAGS) -o $@
CFLAGS = -g -O2
COMPILE = $(CC) $(DEFS) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(AM_CFLAGS) $(CFLAGS)
CCLD = $(CC)
LINK = $(CCLD) $(AM_CFLAGS) $(CFLAGS) $(LDFLAGS) -o $@
DIST_COMMON =  Makefile.am Makefile.in


DISTFILES = $(DIST_COMMON) $(SOURCES) $(HEADERS) $(TEXINFOS) $(EXTRA_DIST)

TAR = tar
GZIP_ENV = --best
SOURCES = $(AllTests_SOURCES)
OBJECTS = $(AllTests_OBJECTS)

all: all-redirect
.SUFFIXES:
.SUFFIXES: .S .c .cpp .o .s
$(srcdir)/Makefile.in: # Makefile.am $(top_srcdir)/configure.in $(ACLOCAL_M4) 
	cd $(top_srcdir) && $(AUTOMAKE) --gnu --include-deps cppunit/tests/Makefile

Makefile: $(srcdir)/Makefile.in  $(top_builddir)/config.status
	cd $(top_builddir) \
	  && CONFIG_FILES=$(subdir)/$@ CONFIG_HEADERS= $(SHELL) ./config.status


mostlyclean-noinstPROGRAMS:

clean-noinstPROGRAMS:
	-test -z "$(noinst_PROGRAMS)" || rm -f $(noinst_PROGRAMS)

distclean-noinstPROGRAMS:

maintainer-clean-noinstPROGRAMS:

.c.o:
	$(COMPILE) -c $<

.s.o:
	$(COMPILE) -c $<

.S.o:
	$(COMPILE) -c $<

mostlyclean-compile:
	-rm -f *.o core *.core

clean-compile:

distclean-compile:
	-rm -f *.tab.c

maintainer-clean-compile:

AllTests$(EXEEXT): $(AllTests_OBJECTS) $(AllTests_DEPENDENCIES)
	@rm -f AllTests$(EXEEXT)
	$(CXXLINK) $(AllTests_LDFLAGS) $(AllTests_OBJECTS) $(AllTests_LDADD) $(LIBS)
.cpp.o:
	$(CXXCOMPILE) -c $<

tags: TAGS

ID: $(HEADERS) $(SOURCES) $(LISP)
	list='$(SOURCES) $(HEADERS)'; \
	unique=`for i in $$list; do echo $$i; done | \
	  awk '    { files[$$0] = 1; } \
	       END { for (i in files) print i; }'`; \
	here=`pwd` && cd $(srcdir) \
	  && mkid -f$$here/ID $$unique $(LISP)

TAGS:  $(HEADERS) $(SOURCES)  $(TAGS_DEPENDENCIES) $(LISP)
	tags=; \
	here=`pwd`; \
	list='$(SOURCES) $(HEADERS)'; \
	unique=`for i in $$list; do echo $$i; done | \
	  awk '    { files[$$0] = 1; } \
	       END { for (i in files) print i; }'`; \
	test -z "$(ETAGS_ARGS)$$unique$(LISP)$$tags" \
	  || (cd $(srcdir) && etags $(ETAGS_ARGS) $$tags  $$unique $(LISP) -o $$here/TAGS)

mostlyclean-tags:

clean-tags:

distclean-tags:
	-rm -f TAGS ID

maintainer-clean-tags:

distdir = $(top_builddir)/$(PACKAGE)-$(VERSION)/$(subdir)

subdir = cppunit/tests

distdir: $(DISTFILES)
	@for file in $(DISTFILES); do \
	  d=$(srcdir); \
	  if test -d $$d/$$file; then \
	    cp -pr $$/$$file $(distdir)/$$file; \
	  else \
	    test -f $(distdir)/$$file \
	    || ln $$d/$$file $(distdir)/$$file 2> /dev/null \
	    || cp -p $$d/$$file $(distdir)/$$file || :; \
	  fi; \
	done
AllTests.o: AllTests.cpp ../../cppunit/cudebug.h \
	../../cppunit/cuconfig.h ../../cppunit/TestUtility.h \
	SimpleStringTest.h ../../cppunit/TestCase.h \
	../../cppunit/Test.h ../../cppunit/SimpleString.h \
	SimpleListTest.h ../../cppunit/SimpleList.h SimpleAutoPtrTest.h \
	../../cppunit/SimpleAutoPtr.h TestUtilityTest.h \
	TestResultTest.h ../../cppunit/TestResult.h \
	../../cppunit/TestListener.h TestCaseTest.h TestCallerTest.h \
	TestSuiteTest.h TestRegistryTest.h ../../cppunit/TestRegistry.h \
	TestDecoratorTest.h RepeatedTestTest.h TestSetupTest.h \
	../../cppunit/TestSetup.h ../../cppunit/TestDecorator.h \
	CppUnitTest.h ../../cppunit/TestRunner.h
CppUnitTest.o: CppUnitTest.cpp ../../cppunit/cudebug.h \
	../../cppunit/cuconfig.h ../../cppunit/TestUtility.h \
	CppUnitTest.h ../../cppunit/TestCase.h ../../cppunit/Test.h \
	../../cppunit/TestSuite.h ../../cppunit/TestCaller.h
RepeatedTestTest.o: RepeatedTestTest.cpp ../../cppunit/cudebug.h \
	../../cppunit/cuconfig.h ../../cppunit/TestUtility.h \
	RepeatedTestTest.h ../../cppunit/TestCase.h \
	../../cppunit/Test.h TestCaseTest.h ../../cppunit/TestSuite.h \
	../../cppunit/TestResult.h ../../cppunit/RepeatedTest.h \
	../../cppunit/TestDecorator.h
SimpleAutoPtrTest.o: SimpleAutoPtrTest.cpp ../../cppunit/cudebug.h \
	../../cppunit/cuconfig.h ../../cppunit/TestUtility.h \
	SimpleAutoPtrTest.h ../../cppunit/TestCase.h \
	../../cppunit/Test.h ../../cppunit/SimpleAutoPtr.h \
	../../cppunit/TestSuite.h ../../cppunit/TestCaller.h
SimpleListTest.o: SimpleListTest.cpp ../../cppunit/cudebug.h \
	../../cppunit/cuconfig.h ../../cppunit/TestUtility.h \
	SimpleListTest.h ../../cppunit/TestCase.h ../../cppunit/Test.h \
	../../cppunit/SimpleList.h ../../cppunit/TestSuite.h \
	../../cppunit/TestCaller.h
SimpleStringTest.o: SimpleStringTest.cpp ../../cppunit/cudebug.h \
	../../cppunit/cuconfig.h ../../cppunit/TestUtility.h \
	SimpleStringTest.h ../../cppunit/TestCase.h \
	../../cppunit/Test.h ../../cppunit/SimpleString.h \
	../../cppunit/TestSuite.h ../../cppunit/TestCaller.h
TestCallerTest.o: TestCallerTest.cpp ../../cppunit/cudebug.h \
	../../cppunit/cuconfig.h ../../cppunit/TestUtility.h \
	TestCallerTest.h ../../cppunit/TestCase.h ../../cppunit/Test.h \
	../../cppunit/TestCaller.h ../../cppunit/TestResult.h
TestCaseTest.o: TestCaseTest.cpp ../../cppunit/cudebug.h \
	../../cppunit/cuconfig.h ../../cppunit/TestUtility.h \
	TestCaseTest.h ../../cppunit/TestCase.h ../../cppunit/Test.h \
	../../cppunit/TestSuite.h ../../cppunit/TestCaller.h \
	../../cppunit/TestResult.h ../../cppunit/TestFailure.h
TestDecoratorTest.o: TestDecoratorTest.cpp ../../cppunit/cudebug.h \
	../../cppunit/cuconfig.h ../../cppunit/TestUtility.h \
	TestDecoratorTest.h ../../cppunit/TestCase.h \
	../../cppunit/Test.h TestCaseTest.h ../../cppunit/TestSuite.h \
	../../cppunit/TestResult.h ../../cppunit/TestDecorator.h
TestRegistryTest.o: TestRegistryTest.cpp ../../cppunit/cudebug.h \
	../../cppunit/cuconfig.h ../../cppunit/TestUtility.h \
	TestRegistryTest.h ../../cppunit/TestCase.h \
	../../cppunit/Test.h ../../cppunit/TestRegistry.h \
	TestCaseTest.h ../../cppunit/TestSuite.h \
	../../cppunit/TestCaller.h ../../cppunit/TestResult.h
TestResultTest.o: TestResultTest.cpp ../../cppunit/cudebug.h \
	../../cppunit/cuconfig.h ../../cppunit/TestUtility.h \
	TestResultTest.h ../../cppunit/TestCase.h ../../cppunit/Test.h \
	../../cppunit/TestResult.h ../../cppunit/TestListener.h \
	../../cppunit/TestSuite.h ../../cppunit/TestCaller.h \
	../../cppunit/TestFailure.h
TestSetupTest.o: TestSetupTest.cpp ../../cppunit/cudebug.h \
	../../cppunit/cuconfig.h ../../cppunit/TestUtility.h \
	TestSetupTest.h ../../cppunit/TestCase.h ../../cppunit/Test.h \
	../../cppunit/TestSetup.h ../../cppunit/TestDecorator.h \
	TestCaseTest.h ../../cppunit/TestSuite.h \
	../../cppunit/TestCaller.h ../../cppunit/TestResult.h
TestSuiteTest.o: TestSuiteTest.cpp ../../cppunit/cudebug.h \
	../../cppunit/cuconfig.h ../../cppunit/TestUtility.h \
	TestSuiteTest.h ../../cppunit/TestCase.h ../../cppunit/Test.h \
	TestCaseTest.h ../../cppunit/TestSuite.h \
	../../cppunit/TestResult.h
TestUtilityTest.o: TestUtilityTest.cpp ../../cppunit/cudebug.h \
	../../cppunit/cuconfig.h ../../cppunit/TestUtility.h \
	TestUtilityTest.h ../../cppunit/TestCase.h ../../cppunit/Test.h \
	../../cppunit/TestSuite.h ../../cppunit/TestCaller.h

check-TESTS: $(TESTS)
	@failed=0; all=0; \
	srcdir=$(srcdir); export srcdir; \
	for tst in $(TESTS); do \
	  if test -f $$tst; then dir=.; \
	  else dir="$(srcdir)"; fi; \
	  if $(TESTS_ENVIRONMENT) $$dir/$$tst; then \
	    all=`expr $$all + 1`; \
	    echo "PASS: $$tst"; \
	  elif test $$? -ne 77; then \
	    all=`expr $$all + 1`; \
	    failed=`expr $$failed + 1`; \
	    echo "FAIL: $$tst"; \
	  fi; \
	done; \
	if test "$$failed" -eq 0; then \
	  banner="All $$all tests passed"; \
	else \
	  banner="$$failed of $$all tests failed"; \
	fi; \
	dashes=`echo "$$banner" | sed s/./=/g`; \
	echo "$$dashes"; \
	echo "$$banner"; \
	echo "$$dashes"; \
	test "$$failed" -eq 0
info-am:
info: info-am
dvi-am:
dvi: dvi-am
check-am: all-am
	$(MAKE) $(AM_MAKEFLAGS) check-TESTS
check: check-am
installcheck-am:
installcheck: installcheck-am
install-exec-am:
install-exec: install-exec-am

install-data-am:
install-data: install-data-am

install-am: all-am
	@$(MAKE) $(AM_MAKEFLAGS) install-exec-am install-data-am
install: install-am
uninstall-am:
uninstall: uninstall-am
all-am: Makefile $(PROGRAMS)
all-redirect: all-am
install-strip:
	$(MAKE) $(AM_MAKEFLAGS) AM_INSTALL_PROGRAM_FLAGS=-s install
installdirs:


mostlyclean-generic:

clean-generic:

distclean-generic:
	-rm -f Makefile $(CONFIG_CLEAN_FILES)
	-rm -f config.cache config.log stamp-h stamp-h[0-9]*

maintainer-clean-generic:
mostlyclean-am:  mostlyclean-noinstPROGRAMS mostlyclean-compile \
		mostlyclean-tags mostlyclean-generic

mostlyclean: mostlyclean-am

clean-am:  clean-noinstPROGRAMS clean-compile clean-tags clean-generic \
		mostlyclean-am

clean: clean-am

distclean-am:  distclean-noinstPROGRAMS distclean-compile distclean-tags \
		distclean-generic clean-am

distclean: distclean-am

maintainer-clean-am:  maintainer-clean-noinstPROGRAMS \
		maintainer-clean-compile maintainer-clean-tags \
		maintainer-clean-generic distclean-am
	@echo "This command is intended for maintainers to use;"
	@echo "it deletes files that may require special tools to rebuild."

maintainer-clean: maintainer-clean-am

.PHONY: mostlyclean-noinstPROGRAMS distclean-noinstPROGRAMS \
clean-noinstPROGRAMS maintainer-clean-noinstPROGRAMS \
mostlyclean-compile distclean-compile clean-compile \
maintainer-clean-compile tags mostlyclean-tags distclean-tags \
clean-tags maintainer-clean-tags distdir check-TESTS info-am info \
dvi-am dvi check check-am installcheck-am installcheck install-exec-am \
install-exec install-data-am install-data install-am install \
uninstall-am uninstall all-redirect all-am all installdirs \
mostlyclean-generic distclean-generic clean-generic \
maintainer-clean-generic clean mostlyclean distclean maintainer-clean


# Tell versions [3.59,3.63) of GNU make to not export all variables.
# Otherwise a system limit (for SysV at least) may be exceeded.
.NOEXPORT:
