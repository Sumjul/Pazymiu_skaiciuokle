cmake_minimum_required(VERSION 3.25)
project(Pazymiu_Skaiciuokle)
include_directories(include)
file(GLOB SOURCES "src/student.cpp" "src/functions.cpp")

option(BUILD_TESTS "Build with Catch2 tests" OFF)

if (BUILD_TESTS)
    message(STATUS "Building Catch2 tests...")
    add_executable(Tests ${COMMON_SOURCES} src/tests.cpp)
else()
    message(STATUS "Building main program...")
    add_executable(Pazymiu_Skaiciuokle ${COMMON_SOURCES} src/main.cpp)
endif()

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -funroll-loops")