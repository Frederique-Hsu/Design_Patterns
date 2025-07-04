cmake_minimum_required(VERSION 3.20)

project(testing)

add_subdirectory(test_misc)

if (NOT ${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
    add_subdirectory(Test_Creational_Patterns)
endif()

add_subdirectory(Test_Structural_Patterns)
