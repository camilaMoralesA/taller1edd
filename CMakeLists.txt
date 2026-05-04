cmake_minimum_required(VERSION 4.2)
project(taller)

set(CMAKE_CXX_STANDARD 20)

add_executable(taller main.cpp
        clases/Cancion.cpp
        clases/Cancion.h)
