cmake_minimum_required(VERSION 3.16)

project(test)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "-g -O0 -Wall -Wno-unused -Werror -Wpedantic -fprofile-arcs -ftest-coverage")
set(CMAKE_C_FLAGS "-g -O0 -Wall -Wno-unused -Werror -Wpedantic -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_FLAGS "-fprofile-arcs -ftest-coverage -pthread -std=c++11 -O0 ${CMAKE_CXX_FLAGS}")

set(LIB_SOURCE_FILES func.c)
add_library(func STATIC ${LIB_SOURCE_FILES})

add_executable(main main.c)
target_link_libraries(main func)


enable_testing()
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
add_executable(test_iz1 test_iz1.cpp)
target_link_libraries(test_iz1 ${GTEST_LIBRARIES} pthread func)
