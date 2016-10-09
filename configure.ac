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
AC_CONFIG_SRCDIR([src/cut.c])


dnl ***********************************************************************
dnl * Libraries requirements                                              *
dnl ***********************************************************************
PKG_PROG_PKG_CONFIG([0.23])
GLIB_VERSION=2.30.0
GIO_VERSION=2.30.0

AC_SUBST(GLIB_VERSION)
AC_SUBST(GIO_VERSION)


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


dnl ***********************************************************************
dnl * exporting variables                                                 *
dnl ***********************************************************************
AC_SUBST(LDFLAGS)
AC_SUBST(CFLAGS)
AC_SUBST(GLIB_CFLAGS)
AC_SUBST(GLIB_LIBS)
AC_SUBST(GIO_CFLAGS)
AC_SUBST(GIO_LIBS)


AC_CONFIG_FILES([
Makefile
src/Makefile
])
