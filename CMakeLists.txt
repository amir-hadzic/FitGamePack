cmake_minimum_required(VERSION 2.6)
project(FitGamePack)

find_package(SDL)
find_package(SDL_ttf)

add_definitions(-Wall -Wextra -pedantic -Wno-write-strings -std=c++0x)

set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(Fitgy)
add_subdirectory(TicTacToe)
