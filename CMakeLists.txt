cmake_minimum_required(VERSION 3.10)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 11)

add_executable(TicTacToe "main.cpp" "game.h" "game.cpp" "AI.h" "AI.cpp" "GameManager.h" "GameManager.cpp")