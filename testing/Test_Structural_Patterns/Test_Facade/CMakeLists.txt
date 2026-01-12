cmake_minimum_required(VERSION 3.20)

project(Test_Facade)

#===============================================================================

file(GLOB_RECURSE cppsources 
    "*.c*"
    "${CMAKE_SOURCE_DIR}/Structural_Patterns/Facade/cpp/*.c*")
file(GLOB_RECURSE cppheaders
    "*.h*"
    "${CMAKE_SOURCE_DIR}/Structural_Patterns/Facade/cpp/*.h*")

message(STATUS "${PROJECT_NAME} project's code files list: ")
foreach(cppsource ${cppsources})
    message(STATUS "\t\t ${cppsource}")
endforeach()
foreach(cppheader ${cppheaders})
    message(STATUS "\t\t ${cppheader}")
endforeach()
message(STATUS "\n")

#===============================================================================

add_executable(${PROJECT_NAME}
    ../main.cpp
    ${cppsources}
    ${cppheaders})

add_dependencies(${PROJECT_NAME} catch2)

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
    "-Wno-gnu-conditional-omitted-operand")

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