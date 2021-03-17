cmake_minimum_required(VERSION 3.15)
project(coding_IDE)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES grid.h grid.cpp dictionary.h dictionary.cpp findMatches.h findMatches.cpp main.cpp)

add_executable(ClionProject ${SOURCE_FILES})
