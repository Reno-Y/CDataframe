cmake_minimum_required(VERSION 3.27)
project(projetC C)

set(CMAKE_C_STANDARD 11)

add_executable(projetC
        main.c
        Dataframe.h
        Dataframe.c
        column.h
        column.c
)
