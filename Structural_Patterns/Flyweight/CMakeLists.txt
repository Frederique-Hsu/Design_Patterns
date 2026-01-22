cmake_minimum_required(VERSION 3.20)

project(Flyweight)

file(GLOB_RECURSE cpp_sources "cpp/*.c*")
file(GLOB_RECURSE cpp_headers "cpp/*.h*")

message(STATUS "${PROJECT_NAME} project's code files list: ")
foreach(source ${cpp_sources})
    message(STATUS "\t\t ${source}")
endforeach()
foreach(header ${cpp_headers})
    message(STATUS "\t\t ${header}")
endforeach()
message(STATUS "\n")


add_executable(${PROJECT_NAME}
    ../main.cpp
    ${cpp_sources}
    ${cpp_headers})

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD        17
    CXX_EXTENSIONS      NO
    CXX_STANDARD_REQUIRED   YES)

target_compile_options(${PROJECT_NAME} PRIVATE
    "-Wall"
    "-Wextra"
    "-Wpedantic"
    "-Werror")


add_executable(Flyweight_Pattern
    Flyweight_Pattern.cpp
    Flyweight_Pattern.hpp)

enable_testing()
add_test(NAME Flyweight_Pattern
    COMMAND $<TARGET_FILE:Flyweight_Pattern> -s)

add_subdirectory(python)