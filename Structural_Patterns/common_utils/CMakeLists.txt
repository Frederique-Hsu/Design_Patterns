cmake_minimum_required(VERSION 3.10)

set(CURRENT_PROJECT_NAME common_utils)
project(${CURRENT_PROJECT_NAME})

file(GLOB_RECURSE sources *.c*)
file(GLOB_RECURSE headers *.h*)

add_library(${CURRENT_PROJECT_NAME} OBJECT
    ${sources}
    ${headers})
set_target_properties(${CURRENT_PROJECT_NAME} PROPERTIES
    POSITION_INDEPENDENT_CODE   ON
    CXX_STANDARD                17
    CXX_EXTENSIONS              NO
    CXX_STANDARD_REQUIRED       YES)

add_library(${CURRENT_PROJECT_NAME}-shared SHARED $<TARGET_OBJECTS:${CURRENT_PROJECT_NAME}>)
add_library(${CURRENT_PROJECT_NAME}-static STATIC $<TARGET_OBJECTS:${CURRENT_PROJECT_NAME}>)