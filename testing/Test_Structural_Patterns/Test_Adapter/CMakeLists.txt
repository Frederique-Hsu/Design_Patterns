cmake_minimum_required(VERSION     3.20)

project(Test_Adapter)

#===============================================================================

file(GLOB_RECURSE sources
    "*.c*"
    "${CMAKE_SOURCE_DIR}/Structural_Patterns/Adapter/cpp/*.c*")
file(GLOB_RECURSE headers
    "*.h*"
    "${CMAKE_SOURCE_DIR}/Structural_Patterns/Adapter/cpp/*.h*")

message(STATUS "${PROJECT_NAME} project's source files list: ")
foreach(source ${sources})
    message(STATUS "\t\t ${source}")
endforeach()

message(STATUS "${PROJECT_NAME} project's header files list: ")
foreach(header ${headers})
    message(STATUS "\t\t ${header}")
endforeach()

#===============================================================================

add_executable(${PROJECT_NAME}
    ../main.cpp
    ../finalize.hpp
    ../finalize.cpp
    ${sources}
    ${headers})

#===============================================================================

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR})

if (USE_ExternalProject)
    add_dependencies(${PROJECT_NAME} catch2)

    target_include_directories(${PROJECT_NAME} PRIVATE ${CATCH2_INCLUDE_DIR})
    target_link_directories(${PROJECT_NAME} PRIVATE ${CATCH2_LIB_DIR})
else()
endif()

if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    target_link_libraries(${PROJECT_NAME} PRIVATE Catch2d)
else()
    target_link_libraries(${PROJECT_NAME} PRIVATE Catch2)
endif()

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD            17
    CXX_EXTENSIONS          NO
    CXX_STANDARD_REQUIRED   YES)

#===============================================================================

enable_testing()

add_test(NAME ${PROJECT_NAME}
    COMMAND $<TARGET_FILE:${PROJECT_NAME}> -s)
