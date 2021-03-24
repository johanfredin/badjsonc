cmake_minimum_required(VERSION 3.17)
project(psx_spike C)

set(CMAKE_C_STANDARD 90)

add_executable(playground main.c parser.h parser.c tiled.c tiled.h)