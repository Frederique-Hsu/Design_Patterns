cmake_minimum_required(VERSION 3.10)

set(CURRENT_PROJECT_NAME Adapter)
project(${CURRENT_PROJECT_NAME})


file(GLOB_RECURSE cppsources "*.c*")
file(GLOB_RECURSE cppheaders "*.h*")

add_executable(${CURRENT_PROJECT_NAME}
    ../main.cpp
    ${cppsources}
    ${cppheaders})

set_target_properties(${CURRENT_PROJECT_NAME} PROPERTIES
    CXX_STANDARD            17
    CXX_EXTENSIONS          NO
    CXX_STANDARD_REQUIRED   YES)

target_compile_options(${CURRENT_PROJECT_NAME} PUBLIC
    "-Wall"
    "-Wextra"
    "-pedantic"
    "-Werror")

