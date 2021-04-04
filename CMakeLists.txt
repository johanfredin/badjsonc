cmake_minimum_required(VERSION 3.16)
project(badjson)

set(CMAKE_C_STANDARD 90)

add_executable(badjson main.c parser.h tiled.c tiled.h parser.c filereader.c filereader.h utils.h)