cmake_minimum_required(VERSION 3.10)
project(SoloTest)

set(CMAKE_CXX_STANDARD 17)

add_executable(game
        src/main.cpp
        src/Game.cpp
        src/Game.h
)

target_include_directories(game PRIVATE src)