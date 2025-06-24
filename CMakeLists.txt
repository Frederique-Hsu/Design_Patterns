cmake_minimum_required(VERSION 3.20)

project(DynamicCore)


include(cmake/boost.cmake)
include(cmake/tinyxml2.cmake)
include(cmake/opencascade.cmake)

add_subdirectory(Common)
add_subdirectory(GeometryDynamic)