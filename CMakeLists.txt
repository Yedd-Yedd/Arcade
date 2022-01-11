cmake_minimum_required(VERSION 3.21)
project(Arcade C)

set(CMAKE_C_STANDARD 17)

set(SOURCES le_pendu.c pierre_feuille_ciseau.c mastermind.c main.c)
set(HEADER_FILES le_pendu.h pierre_feuille_ciseau.h mastermind.h)

add_executable(Arcade ${SOURCES} ${HEADER_FILES})

include_directories(./)
