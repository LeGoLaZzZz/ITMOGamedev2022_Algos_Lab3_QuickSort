# 'Google_test' is the subproject name
project(GoogleTests)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'Google_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests
add_executable(GoogleTests_run Lab3QuickSortTests.cpp ../QuickSort.h)
target_link_libraries(GoogleTests_run gtest gtest_main)