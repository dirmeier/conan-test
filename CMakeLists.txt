# cmake_minimum_required(VERSION <specify CMake version here>)
project(cstat)

include_directories(/opt/local/eigen/include/eigen3/)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp mvrnorm.hpp /opt/local/eigen/include/eigen3/Eigen/)
add_executable(cstat ${SOURCE_FILES})