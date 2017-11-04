#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([aresman], [0.1], [lorenzo1974@gmail.com], [], [https://www.linkedin.com/in/lorenzocipriani])
AC_CONFIG_SRCDIR([config.h.in])
AC_CONFIG_HEADERS([config.h])
AC_CANONICAL_SYSTEM
AM_INIT_AUTOMAKE()



# Checks for programs.
AC_PROG_CC

# Checks for libraries.
# FIXME: Replace `main' with a function in `-largp':
#AC_CHECK_LIB([argp], [main])

# Checks for header files.
AC_CHECK_HEADERS([fcntl.h stdlib.h string.h syslog.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_PID_T

# Checks for library functions.
AC_FUNC_FORK
AC_CHECK_FUNCS([strerror])

AC_CONFIG_FILES([Makefile
                 spike/Makefile
                 src/Makefile])
AC_OUTPUT
