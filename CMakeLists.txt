cmake_minimum_required(VERSION 4.2)
project(taller)

set(CMAKE_CXX_STANDARD 20)

add_executable(taller main.cpp
        classes/Cancion.cpp
        classes/Cancion.h
        data_structures/Nodo.cpp
        data_structures/Nodo.h
        data_structures/Lista.cpp
        data_structures/Lista.h
        core/lectura.cpp
        core/lectura.h
        classes/reproductor.cpp
        classes/reproductor.h)
