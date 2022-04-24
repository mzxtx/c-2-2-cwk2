cmake_minimum_required(VERSION 3.22)
project(c_2_2_cwk2 C)

set(CMAKE_C_STANDARD 11)

link_libraries(SDL2)

add_executable(c_2_2_cwk2 main.c game.c game.h sdl.c sdl.h)
