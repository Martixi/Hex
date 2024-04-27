cmake_minimum_required(VERSION 3.27)
project(Hex)

set(CMAKE_CXX_STANDARD 17)

add_executable(Hex main.cpp
        queries.h
        queries.cpp
        defines.h
        board.h
        board.cpp
        utility.h
        utility.cpp
        stack.h
        List.h
        List.cpp
        stack.cpp)
