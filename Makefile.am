cstat_headers = \
	src/mvrnorm.hpp

TESTS = cstat_tests
check_PROGRAMS = cstat_tests

cstat_tests_SOURCES = $(cstat_headers) \
	tests/test.cpp
cstat_tests_CPPFLAGS = @eigen_CFLAGS@ 
