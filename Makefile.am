AM_CXXFLAGS = @OPENMP_CXXFLAGS@

cstat_headers = \
	src/mvrnorm.hpp

noinst_LIBRARIES = libcstat.a
libcstat_a_SOURCES = $(cstat_headers) 
libcstat_a_LDLIBS = @cstat_LDLIBS@
libcstat_a_CPPFLAGS = @cstat_CPPFLAGS@

TESTS = cstat_tests
check_PROGRAMS = cstat_tests

cstat_tests_SOURCES = $(cstat_headers) \
	tests/test.cpp
cstat_tests_LDLIBS = @cstat_LDLIBS@
cstat_tests_CPPFLAGS = @cstat_CPPFLAGS@
cstat_tests_LDADD = libcstat.a
