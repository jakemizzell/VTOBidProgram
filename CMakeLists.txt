cmake_minimum_required(VERSION 3.7)
project(VTOBidProgram)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES scanner.c main.c)
add_executable(bid ${SOURCE_FILES})