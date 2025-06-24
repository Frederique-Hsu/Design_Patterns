cmake_minimum_required(VERSION 3.20)

project(DynamicCore)

set(BOOST_INSTALL_DIR       ${CMAKE_BINARY_DIR}/boost-install)
include(cmake/boost.cmake)
set(TINYXML2_INSTALL_DIR    ${CMAKE_BINARY_DIR}/tinyxml2-install)
include(cmake/tinyxml2.cmake)
set(OCCT_INSTALL_DIR        ${CMAKE_BINARY_DIR}/occt-install)
include(cmake/opencascade.cmake)

add_subdirectory(Common)
add_subdirectory(GeometryDynamic)