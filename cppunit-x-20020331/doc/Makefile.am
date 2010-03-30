## Process this file with automake to produce Makefile.in.

EXTRA_DIST = \
  Doxyfile \
  header.html

all-local:
	-rm -rf $(srcdir)/html
	cd $(srcdir) && doxygen

clean-local:
	-rm -rf $(srcdir)/html
