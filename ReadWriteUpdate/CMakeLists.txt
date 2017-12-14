cmake_minimum_required(VERSION 3.8)
project(ProjetC)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES testrwu.c rwu.h rwu.c linkedList.h linkedList.c)
add_executable(ProjetC ${SOURCE_FILES})