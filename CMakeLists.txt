cmake_minimum_required(VERSION 3.16)
project(badjson C)

set(CMAKE_C_STANDARD 90)

add_executable(playground main.c parser.h tiled.c tiled.h parser.c filereader.c filereader.h)