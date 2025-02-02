cmake_minimum_required(VERSION 3.31.5)

project("project-the-project")

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_EXTENSIONS ON)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_COMPILE_WARNING_AS_ERROR ON)

add_compile_options(-Wall -Wextra -Wpedantic -Wfatal-errors)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(PkgConfig)

pkg_check_modules(SDL3 REQUIRED IMPORTED_TARGET sdl3=3.2.0)

add_subdirectory("game-the-game")