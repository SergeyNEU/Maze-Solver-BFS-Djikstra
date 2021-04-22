cmake_minimum_required(VERSION 3.15)
project(coding_IDE)

set(CMAKE_CXX_STANDARD 14)

set(PROJECT_HEADERS
        maze.h
        d_matrix.h
        board.h
        )
set(PROJECT_SOURCES
        main.cpp
        maze.cpp
        board.cpp
)

add_executable(untitled1 ${PROJECT_SOURCES} ${PROJECT_HEADERS})
