cmake_minimum_required(VERSION 2.6)
project(pocman)

add_executable(pocman tablero.cpp pacman.cpp fantasma.cpp main.cpp)

install(TARGETS pocman RUNTIME DESTINATION bin)
