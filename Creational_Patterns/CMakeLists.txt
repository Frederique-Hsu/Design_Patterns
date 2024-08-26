cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(Creational_Patterns)

list(APPEND COMMON_COMPILE_OPTIONS
    "-Wall"
    "-Werror")

enable_testing()

add_subdirectory(Abstract_Factory)
add_subdirectory(Builder)
add_subdirectory(Factory_Method)
add_subdirectory(Prototype)
add_subdirectory(Singleton)