cmake_minimum_required(VERSION 3.10)
project(MyProject)

include_directories(functions/)

file(GLOB SOURCES "main.c" "functions/*.c")

add_executable(MyProject ${SOURCES}
        functions/UI.c
        functions/UI.h
        functions/library.h
        functions/library.c)

file(GLOB GRAPH_FILES "graph/*")

foreach(file ${GRAPH_FILES})
    get_filename_component(FILE_NAME ${file} NAME)
    configure_file(${file} ${CMAKE_BINARY_DIR}/graph/${FILE_NAME} COPYONLY)
endforeach()