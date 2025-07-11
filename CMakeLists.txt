cmake_minimum_required(VERSION 3.20)

project(DynamicCoreCollection)

#===============================================================================

set(ExternalLibrary_ROOT_DIR			${CMAKE_SOURCE_DIR}/ExternLibrary)
set(ExternalLirary_INCLUDE_DIR			${ExternalLibrary_ROOT_DIR}/include)
set(ExternalLibrary_Debug_LIB_DIR		${ExternalLibrary_ROOT_DIR}/libd)
set(ExternalLibrary_Release_LIB_DIR		${ExternalLibrary_ROOT_DIR}/lib)
set(ExternalLibrary_Debug_BIN_DIR		${ExternalLibrary_ROOT_DIR}/bind)
set(ExternalLibrary_Release_BIN_DIR		${ExternalLibrary_ROOT_DIR}/bin)

#===============================================================================

add_subdirectory(Common)
add_subdirectory(GeometryDynamic)

#===============================================================================

add_subdirectory(Testing)