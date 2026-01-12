cmake_minimum_required(VERSION 3.20)

project(Facade)

file(GLOB_RECURSE sources "cpp/*.c*")
file(GLOB_RECURSE headers "cpp/*.h*")

message(STATUS "${PROJECT_NAME} project's code files list:")
foreach(source ${sources})
    message(STATUS "\t\t ${source}")
endforeach()
foreach(header ${headers})
    message(STATUS "\t\t ${header}")
endforeach()
message(STATUS "\n")


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
    "-Werror"
    "-Wno-gnu-conditional-omitted-operand")