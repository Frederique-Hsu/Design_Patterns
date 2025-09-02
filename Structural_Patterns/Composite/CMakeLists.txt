cmake_minimum_required(VERSION  3.20)

project(Composite)


file(GLOB_RECURSE sources "*.c*")
file(GLOB_RECURSE headers "*.c*")

add_executable(${PROJECT_NAME}
    ../main.cpp
    ${sources}
    ${headers})

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD        17
    CXX_EXTENSIONS      NO
    CXX_STANDARD_REQUIRED   YES)

target_compile_options(${PROJECT_NAME} PRIVATE
    "-Wall"
    "-Wextra"
    "-Wpedantic"
    "-Werror")