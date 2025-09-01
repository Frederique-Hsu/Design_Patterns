cmake_minimum_required(VERSION  3.20)

project(Test_Structural_Patterns)


enable_testing()

include(${CMAKE_SOURCE_DIR}/cmakes/catch2.cmake)

add_subdirectory(Test_Adapter)
add_subdirectory(Test_Bridge)