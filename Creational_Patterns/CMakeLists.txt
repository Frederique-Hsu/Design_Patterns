cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(Creational_Patterns)

list(APPEND COMMON_COMPILE_OPTIONS
    "-Wall"
    "-Werror")
    
set(ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
SET(BUILDER_SUBPROJECT_PATH ${ROOT_PATH}/Builder)

set(MAZE_LIB_NAME maze_components)
add_library(${MAZE_LIB_NAME} SHARED "")
target_sources(${MAZE_LIB_NAME} PUBLIC
    ${BUILDER_SUBPROJECT_PATH}/map_site.hpp
    ${BUILDER_SUBPROJECT_PATH}/maze.cpp
    ${BUILDER_SUBPROJECT_PATH}/maze.hpp
    ${BUILDER_SUBPROJECT_PATH}/room.cpp
    ${BUILDER_SUBPROJECT_PATH}/room.hpp
    ${BUILDER_SUBPROJECT_PATH}/wall.cpp
    ${BUILDER_SUBPROJECT_PATH}/wall.hpp
    ${BUILDER_SUBPROJECT_PATH}/door.cpp
    ${BUILDER_SUBPROJECT_PATH}/door.hpp
    ${BUILDER_SUBPROJECT_PATH}/user_exception.cpp
    ${BUILDER_SUBPROJECT_PATH}/user_exception.hpp
    ${BUILDER_SUBPROJECT_PATH}/spell.hpp)

enable_testing()

add_subdirectory(Abstract_Factory)
add_subdirectory(Builder)
add_subdirectory(Factory_Method)
add_subdirectory(Prototype)
add_subdirectory(Singleton)