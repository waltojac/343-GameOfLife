cmake_minimum_required(VERSION 3.8)
project(gameOfLife)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c file_utilities.c file_utilities.h)
add_executable(gameOfLife ${SOURCE_FILES} file_utilities.c file_utilities.h)