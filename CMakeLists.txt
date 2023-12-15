cmake_minimum_required(VERSION 3.27)
project(Mantis)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(classes)
include_directories(classes/mantises)

add_executable(Mantis
        Mantis.cpp
        Mantis.h
        ingore_this/test_run_class.cpp
        ingore_this/test_run_class.h
        Terrarium.cpp
        Terrarium.h
)
