AC_PREREQ(2.61)

AC_INIT([libfyaml-examples],
        m4_esyscmd([build-aux/git-version-gen .tarball-version]),
	[pantelis.antoniou@konsulko.com])

AC_CONFIG_SRCDIR([src/version/version.c])
AC_CONFIG_HEADER([config.h])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE([foreign 1.8.5 -Wall subdir-objects ])

AX_CHECK_ENABLE_DEBUG()

AC_PROG_MKDIR_P
AC_PROG_CC
AC_PROG_CC_C99
AM_PROG_CC_C_O
AC_PROG_GCC_TRADITIONAL
AC_USE_SYSTEM_EXTENSIONS
AM_PROG_AR
AC_PROG_CXX
AC_PROG_AWK
AC_PROG_LN_S

AX_PTHREAD

AC_PATH_PROG([M4], [m4 gm4], [no])
if test "x$M4" = xno ; then
   AC_MSG_ERROR([m4 missing])
fi

AC_SUBST(ACLOCAL_AMFLAGS, "-I m4")

# pkg-config
PKG_PROG_PKG_CONFIG

AC_LTDL_ENABLE_INSTALL
AC_LIBLTDL_INSTALLABLE
AC_LIBTOOL_DLOPEN
AC_LIBTOOL_WIN32_DLL
AC_PROG_LIBTOOL
AC_SUBST(LTDLINCL)
AC_SUBST(LIBLTDL)
AC_CONFIG_SUBDIRS(libltdl)

AC_HEADER_STDC
AC_C_CONST
AC_C_BIGENDIAN
AC_TYPE_PID_T
AC_TYPE_SIZE_T
AC_CHECK_TYPES(ssize_t, , [AC_DEFINE([ssize_t], [signed long],
    [Define ssize_t if it is not done by the standard libs.])])
AC_TYPE_OFF_T
AC_TYPE_SIGNAL
AC_TYPE_UID_T
AC_CHECK_DECLS(environ)

AX_APPEND_COMPILE_FLAGS(
    [-Wall -Wsign-compare],
    [], [-pedantic -Werror])

if test "x$ax_enable_debug" != "xyes" ; then
	AX_APPEND_COMPILE_FLAGS(
		[-O2],
		[], [])
fi

PKG_CHECK_MODULES(LIBFYAML, [ libfyaml ], HAVE_LIBFYAML=1, HAVE_LIBFYAML=0)

if test "x$HAVE_LIBFYAML" != "x1" ; then
	AC_MSG_ERROR([failed to find libfyaml])
fi

AC_SUBST(HAVE_LIBFYAML)
AC_SUBST(LIBFYAML_CFLAGS)
AC_SUBST(LIBFYAML_LIBS)
AC_DEFINE_UNQUOTED([HAVE_LIBFYAML], [$HAVE_LIBFYAML], [Define to 1 if you have libfyaml available])
AM_CONDITIONAL([HAVE_LIBFYAML], [ test x$HAVE_LIBFYAML = x1 ])

# check for docker
AC_PATH_PROG([DOCKER], [docker])
if test "x$DOCKER"  != "x" ; then
	HAVE_DOCKER=1
else
	HAVE_DOCKER=0
fi
AM_CONDITIONAL([HAVE_DOCKER], [ test x$HAVE_DOCKER = x1 ])

# Shave by default
SHAVE_INIT([build-aux], [enable])

AC_CONFIG_FILES([
        build-aux/shave
        build-aux/shave-libtool
	Makefile
	src/Makefile
])

AC_OUTPUT

echo "
 ---{ $PACKAGE_NAME $VERSION }---

    VERSION:              ${VERSION}
    prefix:               ${prefix}
    DOCKER:               $DOCKER

"
