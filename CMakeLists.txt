cmake_minimum_required(VERSION 3.22)
project(Lab3QuickSort)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab3QuickSort main.cpp QuickSort.h ./matplotlib-cpp-master/matplotlibcpp.h )
add_subdirectory(GoogleTests)