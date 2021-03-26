cmake_minimum_required(VERSION 3.15)
project(coding_IDE)

set(CMAKE_CXX_STANDARD 14)

set(PROJECT_HEADERS
        heap.h
        grid.h
        d_matrix.h
        dictionary.h
        findMatches.h
        )
set(PROJECT_SOURCES
        main.cpp
        heap.cpp
        grid.cpp
        dictionary.cpp
        findMatches.cpp
        )

add_executable(untitled1 ${PROJECT_SOURCES} ${PROJECT_HEADERS})
