cmake_minimum_required(VERSION  3.20)

project(Test_Behavioral_Patterns)

enable_testing()

include(${CMAKE_SOURCE_DIR}/cmakes/googletest.cmake)

add_subdirectory(Test_Chain_of_Responsibility)