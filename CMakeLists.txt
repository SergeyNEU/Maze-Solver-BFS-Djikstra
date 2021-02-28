cmake_minimum_required(VERSION 3.15)
project(coding_IDE)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES card.h card.cpp deck.h deck.cpp main.cpp)

add_executable(ClionProject ${SOURCE_FILES})
