cmake_minimum_required(VERSION 3.2)
project(SudokuSolver)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(SOURCE_FILES main.cpp)
add_executable(SudokuSolver ${SOURCE_FILES} SudokuBoard.cpp SudokuBoard.h SudokuSolver.cpp SudokuSolver.h)