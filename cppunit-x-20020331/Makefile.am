## Process this file with automake to produce Makefile.in.

MAKE_SUBDIRS = cppunit samples
DIST_SUBDIRS = cppunit samples misc msvc VxWorks doc
SUBDIRS      = $(MAKE_SUBDIRS)

AUTOMAKE_OPTIONS = dist-zip

EXTRA_DIST = \
  README_ja \
  COPYING_ja \
  bootstrap \
  config/install-sh \
  config/mkinstalldirs \
  config/missing

distdir = $(PACKAGE)-$(CONFIGURE_DATE)

doc:
	$(MAKE) -C doc

dist-doc:
	-rm -f $(distdir)-doc.zip
	here=`cd $(top_builddir) && pwd`; \
	cd $(top_srcdir)/doc && zip -rq $$here/$(distdir)-doc.zip html

release:
	rm -rf .deps */.deps
	$(MAKE) MAKE_SUBDIRS="$(DIST_SUBDIRS)" clean all
	$(MAKE) distcheck
	$(MAKE) dist-all
	$(MAKE) dist-doc

clean-all:
	$(MAKE) MAKE_SUBDIRS="$(DIST_SUBDIRS)" clean

distclean-all:
	$(MAKE) MAKE_SUBDIRS="$(DIST_SUBDIRS)" distclean

maintainer-clean-all:
	$(MAKE) MAKE_SUBDIRS="$(DIST_SUBDIRS)" maintainer-clean

.PHONY: doc dist-doc release clean-all distclean-all maintainer-clean-all
