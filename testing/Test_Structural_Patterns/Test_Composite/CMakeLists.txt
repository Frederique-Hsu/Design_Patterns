cmake_minimum_required(VERSION 3.20)

project(Test_Composite)

#===============================================================================

file(GLOB_RECURSE sources
    "*.c*"
    "${CMAKE_SOURCE_DIR}/Structural_Patterns/Composite/cpp/*.c*")

file(GLOB_RECURSE headers
    "*.h*"
    "${CMAKE_SOURCE_DIR}/Structural_Patterns/Composite/cpp/*.h*")

message(STATUS "${PROJECT_NAME} project's code files list: ")
foreach(source ${sources})
    message(STATUS "\t\t ${source}")
endforeach()

foreach(header ${headers})
    message(STATUS "\t\t ${header}")
endforeach()
message(STATUS "\n")

#===============================================================================

add_executable(${PROJECT_NAME}
    ../main.cpp
    ${sources}
    ${headers})

add_dependencies(${PROJECT_NAME}    catch2)

#===============================================================================

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD        17
    CXX_EXTENSIONS      NO
    CXX_STANDARD_REQUIRED   YES)

target_compile_options(${PROJECT_NAME} PRIVATE
    "-Wall"
    "-Wextra"
    "-Wpedantic"
    "-Werror"
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}
    ${CATCH2_INCLUDE_DIR})

target_link_directories(${PROJECT_NAME} PRIVATE
    ${CATCH2_LIB_DIR})

target_link_libraries(${PROJECT_NAME} PRIVATE
    $<$<CONFIG:Debug>:Catch2d>
    $<$<NOT:$<CONFIG:Debug>>:Catch2>)

#===============================================================================

enable_testing()

add_test(NAME ${PROJECT_NAME}
    COMMAND $<TARGET_FILE:${PROJECT_NAME}> -s)