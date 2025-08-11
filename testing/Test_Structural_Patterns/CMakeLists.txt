cmake_minimum_required(VERSION 3.20)

project(Test_Structural_Patterns)


include(${CMAKE_SOURCE_DIR}/cmake/catch2.cmake)

enable_testing()

add_subdirectory(Test_Adapter)
add_subdirectory(Test_Bridge)
