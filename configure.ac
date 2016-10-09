AC_PREREQ(2.59)

AC_INIT([content-define-cut], [0.0.1], [Olivier DELHOMME <olivier.delhomme@free.fr>])
AM_INIT_AUTOMAKE

AC_PROG_CC
AC_CONFIG_MACRO_DIR([m4])
AC_PROG_INTLTOOL([0.23])


dnl ***********************************************************************
dnl * Put the preprocessor macros in a header file                        *
dnl * instead of command line                                             *
dnl ***********************************************************************
AC_CONFIG_HEADER([config.h])
AC_CONFIG_SRCDIR([src/cdc.c])


dnl ***********************************************************************
dnl * Libraries requirements                                              *
dnl ***********************************************************************
PKG_PROG_PKG_CONFIG([0.23])
GLIB_VERSION=2.30.0
GIO_VERSION=2.30.0
CDPFGL_VERSION=0.0.9

AC_SUBST(GLIB_VERSION)
AC_SUBST(GIO_VERSION)
AC_SUBST(CDPFGL_VERSION)

AC_PROG_INSTALL

dnl ***********************************************************************
dnl * Build time sanity check                                             *
dnl ***********************************************************************
AM_SANITY_CHECK


dnl ***********************************************************************
dnl * Initialize maintainer mode                                          *
dnl ***********************************************************************
AM_MAINTAINER_MODE


dnl ***********************************************************************
dnl * checking for modules (glib, gio, sqlite, mhd, curl...)              *
dnl ***********************************************************************
PKG_CHECK_MODULES(GLIB, [glib-2.0 >= $GLIB_VERSION])
PKG_CHECK_MODULES(GIO, [gio-2.0 >= $GIO_VERSION])
PKG_CHECK_MODULES(CDPFGL, [libcdpfgl >= $CDPFGL_VERSION])


dnl ***********************************************************************
dnl * Checks dynamic libraries capabilities                               *
dnl ***********************************************************************
AC_DISABLE_STATIC
AC_PROG_LIBTOOL

dnl ***********************************************************************
dnl * triggers gettext                                                    *
dnl ***********************************************************************
GETTEXT_PACKAGE=cdc
AC_SUBST(GETTEXT_PACKAGE)
AC_DEFINE_UNQUOTED(GETTEXT_PACKAGE, "$GETTEXT_PACKAGE", [Gettext Package used])
AM_GLIB_GNU_GETTEXT


dnl ***********************************************************************
dnl * exporting variables                                                 *
dnl ***********************************************************************
AC_SUBST(LDFLAGS)
AC_SUBST(CFLAGS)
AC_SUBST(GLIB_CFLAGS)
AC_SUBST(GLIB_LIBS)
AC_SUBST(GIO_CFLAGS)
AC_SUBST(GIO_LIBS)
AC_SUBST(CDPFGL_CFLAGS)
AC_SUBST(CDPFGL_LIBS)


AC_CONFIG_FILES([
Makefile
src/Makefile
po/Makefile.in
])

AC_OUTPUT

AC_MSG_NOTICE([

 *** Flags that will be used to compile cdc project ***

 CFLAGS         : ${CFLAGS}
 LDFLAGS        : ${LDFLAGS}

 GLIB CFLAGS    : ${GLIB_CFLAGS}
 GLIB LIBS      : ${GLIB_LIBS}

 GIO CFLAGS     : ${GIO_CFLAGS}
 GIO LIBS       : ${GIO_LIBS}

 LIBCDPFGL CFLAGS     : ${CDPFGL_CFLAGS}
 LIBCDPFGL LIBS       : ${CDPFGL_LIBS}


 *** Dumping configuration ***

     - Build For OS             : $build_os
     - Compiler                 : ${CC}
     - Prefix                   : $prefix
     - Exec prefix              : ${exec_prefix}
     - Locale dir               : ${LOCALE_DIR}

You can now run 'make' to compile cdc project.

])
