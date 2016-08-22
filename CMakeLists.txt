cmake_minimum_required(VERSION 3.5)
project(cstat_project)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(cstat_project ${SOURCE_FILES})