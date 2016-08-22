dnl Initialise Autoconf
AC_PREREQ([2.69])
AC_INIT(
	[cstat],
	[0.0.0],
	[simon.dirmeier@gmx.de],
	[cstat],
	[https://github.com/rafstraumur/cstat])
AC_CONFIG_HEADERS([src/config.h])
AC_CONFIG_SRCDIR([src/mvrnorm.hpp])

AC_LANG([C++])

AC_MSG_CHECKING([whether configure should try to set CXXFLAGS])
AS_IF(
	[test "x${CXXFLAGS+set}" = "xset"],
		[enable_cxxflags_setting=no],
		[enable_cxxflags_setting=yes]
)
AC_MSG_RESULT([$enable_cxxflags_setting])

AC_PROG_CXX
AC_PROG_SED
AC_PROG_RANLIB

AS_IF(
	[test "x${enable_cxxflags_setting}" = "xyes"],
	[	 
		AX_APPEND_COMPILE_FLAGS([-O3 -Wall], [CXXFLAGS])
		CXXFLAGS=$( echo $CXXFLAGS | $SED -e 's/^ *//' -e 's/ *$//' )
	]	
)

dnl Other dependencies
AX_CXX_COMPILE_STDCXX_11([noext], [mandatory])
AC_OPENMP
AC_CHECK_HEADERS(
	[Eigen/Dense], 
	[found Eigen],
	[AC_MSG_ERROR([could not find Eigen])]
)

AC_SUBST([cstat_LDLIBS])
AC_SUBST([cstat_CPPFLAGS])
AC_SUBST([OPENMP_CXXFLAGS])

AM_INIT_AUTOMAKE([1.14 foreign dist-bzip2 no-dist-gzip subdir-objects silent-rules])

AC_OUTPUT([Makefile])

AC_MSG_RESULT([
	Have fun sampling with: $PACKAGE_NAME

	CXX:        $CXX
	CXXFLAGS:   $CXXFLAGS
])
