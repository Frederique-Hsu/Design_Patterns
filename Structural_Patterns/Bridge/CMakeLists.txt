cmake_minimum_required(VERSION  3.20)

project(Bridge)


file(GLOB_RECURSE sources "*.c*")
file(GLOB_RECURSE headers "*.h*")


add_executable(${PROJECT_NAME}
    ../main.cpp
    ${sources}
    ${headers})

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD        17
    CXX_EXTENSIONS      NO
    CXX_STANDARD_REQUIRED   YES)

target_compile_options(${PROJECT_NAME} PUBLIC
    "-Wall"
    "-Wextra"
    "-Wpedantic"
    "-Werror"
)