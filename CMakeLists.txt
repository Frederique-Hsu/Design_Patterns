cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(Design_Patterns)

set(PROJECT_ROOT_PATH   ${CMAKE_CURRENT_SOURCE_DIR})
set(PROJECT_BUILD_PATH  ${PROJECT_ROOT_PATH}/build)

list(APPEND CPPFLAGS
    "-Wall"
    "-Wextra"
    "-pedantic"
    "-Werror")

include(FetchContent)
set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)

option(BUILD_UTEST_FROM_SOURCE
    "Git clone the repository of unit test framework from GitHub, and build it from source"
    ON)

enable_testing()

add_subdirectory(Behavioral_Patterns)
add_subdirectory(Creational_Patterns)
add_subdirectory(Structural_Patterns)
add_subdirectory(SOLID)
add_subdirectory(references/LexI)
add_subdirectory(references/Design-Patterns-GoF)
add_subdirectory(references/DesignPattern)