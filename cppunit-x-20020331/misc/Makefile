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
top_srcdir = ..
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

top_builddir = ..

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

INCLUDES = -I$(top_srcdir)

noinst_PROGRAMS = AllTests_lc SampleTest_lc

AllTests_lc_SOURCES = AllTests_lc.cpp
SampleTest_lc_SOURCES = SampleTest_lc.cpp

EXTRA_DIST =    cppunit_all.cpp   cppunit_tests.cpp   make4bcc.bat


DISTCLEANFILES = *.exe *.tds *.obj
mkinstalldirs = $(SHELL) $(top_srcdir)/config/mkinstalldirs
CONFIG_HEADER = ../config.h
CONFIG_CLEAN_FILES = 
noinst_PROGRAMS =  AllTests_lc$(EXEEXT) SampleTest_lc$(EXEEXT)
PROGRAMS =  $(noinst_PROGRAMS)


DEFS = -DHAVE_CONFIG_H -I. -I$(srcdir) -I..
CPPFLAGS = 
LDFLAGS = 
LIBS = 
AllTests_lc_OBJECTS =  AllTests_lc.o
AllTests_lc_LDADD = $(LDADD)
AllTests_lc_DEPENDENCIES = 
AllTests_lc_LDFLAGS = 
SampleTest_lc_OBJECTS =  SampleTest_lc.o
SampleTest_lc_LDADD = $(LDADD)
SampleTest_lc_DEPENDENCIES = 
SampleTest_lc_LDFLAGS = 
CXXCOMPILE = $(CXX) $(DEFS) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(AM_CXXFLAGS) $(CXXFLAGS)
CXXLD = $(CXX)
CXXLINK = $(CXXLD) $(AM_CXXFLAGS) $(CXXFLAGS) $(LDFLAGS) -o $@
DIST_COMMON =  Makefile.am Makefile.in


DISTFILES = $(DIST_COMMON) $(SOURCES) $(HEADERS) $(TEXINFOS) $(EXTRA_DIST)

TAR = tar
GZIP_ENV = --best
SOURCES = $(AllTests_lc_SOURCES) $(SampleTest_lc_SOURCES)
OBJECTS = $(AllTests_lc_OBJECTS) $(SampleTest_lc_OBJECTS)

all: all-redirect
.SUFFIXES:
.SUFFIXES: .S .c .cpp .o .s
$(srcdir)/Makefile.in: # Makefile.am $(top_srcdir)/configure.in $(ACLOCAL_M4) 
	cd $(top_srcdir) && $(AUTOMAKE) --gnu --include-deps misc/Makefile

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

AllTests_lc$(EXEEXT): $(AllTests_lc_OBJECTS) $(AllTests_lc_DEPENDENCIES)
	@rm -f AllTests_lc$(EXEEXT)
	$(CXXLINK) $(AllTests_lc_LDFLAGS) $(AllTests_lc_OBJECTS) $(AllTests_lc_LDADD) $(LIBS)

SampleTest_lc$(EXEEXT): $(SampleTest_lc_OBJECTS) $(SampleTest_lc_DEPENDENCIES)
	@rm -f SampleTest_lc$(EXEEXT)
	$(CXXLINK) $(SampleTest_lc_LDFLAGS) $(SampleTest_lc_OBJECTS) $(SampleTest_lc_LDADD) $(LIBS)
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

subdir = misc

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
AllTests_lc.o: AllTests_lc.cpp cppunit_tests.cpp \
	../cppunit/tests/SimpleStringTest.cpp ../cppunit/cudebug.h \
	../cppunit/cuconfig.h ../cppunit/TestUtility.h \
	../cppunit/tests/SimpleStringTest.h ../cppunit/TestCase.h \
	../cppunit/Test.h ../cppunit/SimpleString.h \
	../cppunit/TestSuite.h ../cppunit/TestCaller.h \
	../cppunit/tests/SimpleListTest.cpp \
	../cppunit/tests/SimpleListTest.h ../cppunit/SimpleList.h \
	../cppunit/tests/SimpleAutoPtrTest.cpp \
	../cppunit/tests/SimpleAutoPtrTest.h ../cppunit/SimpleAutoPtr.h \
	../cppunit/tests/TestUtilityTest.cpp \
	../cppunit/tests/TestUtilityTest.h \
	../cppunit/tests/TestResultTest.cpp \
	../cppunit/tests/TestResultTest.h ../cppunit/TestResult.h \
	../cppunit/TestListener.h ../cppunit/TestFailure.h \
	../cppunit/tests/TestCaseTest.cpp \
	../cppunit/tests/TestCaseTest.h \
	../cppunit/tests/TestCallerTest.cpp \
	../cppunit/tests/TestCallerTest.h \
	../cppunit/tests/TestSuiteTest.cpp \
	../cppunit/tests/TestSuiteTest.h \
	../cppunit/tests/TestRegistryTest.cpp \
	../cppunit/tests/TestRegistryTest.h ../cppunit/TestRegistry.h \
	../cppunit/tests/TestDecoratorTest.cpp \
	../cppunit/tests/TestDecoratorTest.h ../cppunit/TestDecorator.h \
	../cppunit/tests/RepeatedTestTest.cpp \
	../cppunit/tests/RepeatedTestTest.h ../cppunit/RepeatedTest.h \
	../cppunit/tests/TestSetupTest.cpp \
	../cppunit/tests/TestSetupTest.h ../cppunit/TestSetup.h \
	../cppunit/tests/CppUnitTest.cpp ../cppunit/tests/CppUnitTest.h \
	../cppunit/tests/AllTests.cpp ../cppunit/TestRunner.h \
	cppunit_all.cpp ../cppunit/SimpleString.cpp \
	../cppunit/SimpleList.cpp ../cppunit/TestUtility.cpp \
	../cppunit/TestFailure.cpp ../cppunit/TestResult.cpp \
	../cppunit/TestCase.cpp ../cppunit/TestSuite.cpp \
	../cppunit/TestRegistry.cpp ../cppunit/TestRunner.cpp \
	../cppunit/TestDecorator.cpp ../cppunit/RepeatedTest.cpp \
	../cppunit/TestSetup.cpp
SampleTest_lc.o: SampleTest_lc.cpp ../samples/SampleTest.cpp \
	../cppunit/cudebug.h ../cppunit/cuconfig.h \
	../cppunit/TestUtility.h ../cppunit/TestCase.h \
	../cppunit/Test.h ../cppunit/TestSuite.h \
	../cppunit/TestCaller.h ../cppunit/TestRunner.h \
	../cppunit/TestRegistry.h cppunit_all.cpp \
	../cppunit/SimpleString.cpp ../cppunit/SimpleString.h \
	../cppunit/SimpleList.cpp ../cppunit/SimpleList.h \
	../cppunit/TestUtility.cpp ../cppunit/TestFailure.cpp \
	../cppunit/TestFailure.h ../cppunit/TestResult.cpp \
	../cppunit/TestResult.h ../cppunit/TestListener.h \
	../cppunit/TestCase.cpp ../cppunit/TestSuite.cpp \
	../cppunit/TestRegistry.cpp ../cppunit/TestRunner.cpp \
	../cppunit/TestDecorator.cpp ../cppunit/TestDecorator.h \
	../cppunit/RepeatedTest.cpp ../cppunit/RepeatedTest.h \
	../cppunit/TestSetup.cpp ../cppunit/TestSetup.h

info-am:
info: info-am
dvi-am:
dvi: dvi-am
check-am: all-am
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
	-test -z "$(DISTCLEANFILES)" || rm -f $(DISTCLEANFILES)

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
clean-tags maintainer-clean-tags distdir info-am info dvi-am dvi check \
check-am installcheck-am installcheck install-exec-am install-exec \
install-data-am install-data install-am install uninstall-am uninstall \
all-redirect all-am all installdirs mostlyclean-generic \
distclean-generic clean-generic maintainer-clean-generic clean \
mostlyclean distclean maintainer-clean


# Tell versions [3.59,3.63) of GNU make to not export all variables.
# Otherwise a system limit (for SysV at least) may be exceeded.
.NOEXPORT:
