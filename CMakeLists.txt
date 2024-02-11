cmake_minimum_required(VERSION 3.10)
project(MyProject)

include_directories(functions)

file(GLOB SOURCES "main.c" "essai.c")

add_executable(MyProject ${SOURCES}
        functions/UI.c
        functions/UI.h
        functions/library.h
        functions/library.c)