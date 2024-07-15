cmake_minimum_required(VERSION 3.28)
project(libq C)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES
        src/libq.c
        src/libq.h
        src/linked_list.c
        src/linked_list.h
)

add_executable(main ${SOURCE_FILES})

