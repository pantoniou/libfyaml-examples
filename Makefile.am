BUILT_SOURCES = $(top_srcdir)/.version
$(top_srcdir)/.version:
	echo $(VERSION) > $@-t && mv $@-t $@
dist-hook:
	echo $(VERSION) > $(distdir)/.tarball-version

# files to keep in the distribution (in case you want to boostrap)
EXTRA_DIST=bootstrap.sh \
	   build-aux/shave.in build-aux/shave-libtool.in \
	   build-aux/git-version-gen \
	   README.md

MAINTAINERCLEANFILES = \
        Makefile.in src/Makefile.in config.h.in configure \
        install-sh ltmain.sh missing mkinstalldirs \
        config.log config.status config.guess config.sub config.h \
        build-stamp compile depcomp acinclude.m4 aclocal.m4 \
	stamp-h1 \
	ar-lib m4/libtool.m4 m4/ltoptions.m4 m4/ltsugar.m4 m4/ltversion.m4 \
	m4/lt~obsolete.m4 src/mock/.dirstamp src/mock/Makefile.in \
	config.h.in~ \
	test-driver test/Makefile.in \
	build-aux/ar-lib build-aux/compile build-aux/config.guess \
	build-aux/config.sub build-aux/depcomp build-aux/install-sh \
	build-aux/ltmain.sh build-aux/missing build-aux/tap-driver.sh \
	.version .tarball-version

clean-local:

SUBDIRS = src

if HAVE_DOCKER
docker: Dockerfile
	@DOCKER@ build -t libfyaml-examples:$(VERSION) $(top_srcdir)
endif
