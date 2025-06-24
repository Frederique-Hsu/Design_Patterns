cmake_minimum_required(VERSION 3.20)

message(STATUS "current path is ${CMAKE_CURRENT_LIST_DIR}")
include(${CMAKE_CURRENT_LIST_DIR}/tcl.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/tk.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/freetype.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/tbb.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/freeimage.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/vtk.cmake)

set(OCCT_SRC_DIR            ${CMAKE_SOURCE_DIR}/3rd_party_libraries/occt-src)
set(OCCT_BUILD_DIR          ${CMAKE_BINARY_DIR}/occt-build)
set(OCCT_INSTALL_DIR        ${CMAKE_BINARY_DIR}/occt-install)
set(OCCT_DOWNLOAD_DIR       ${CMAKE_BINARY_DIR}/occt-download)

include(ExternalProject)

ExternalProject_Add(OCCT
    GIT_REPOSITORY          https://git.dev.opencascade.org/repos/occt.git
    GIT_TAG                 V7_6_0
    GIT_SHALLOW             TRUE
    GIT_PROGRESS            TRUE
    SOURCE_DIR              ${OCCT_SRC_DIR}
    BINARY_DIR              ${OCCT_BUILD_DIR}
    DOWNLOAD_DIR            ${OCCT_DOWNLOAD_DIR}
    UPDATE_DISCONNECTED     TRUE
    CMAKE_ARGS
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        -DBUILD_SHARED_LIBS=ON
        -DCMAKE_INSTALL_PREFIX=${OCCT_INSTALL_DIR}
    BUILD_ALWAYS            TRUE
    STEP_TARGETS            install
)

add_dependencies(OCCT 
    Tcl 
    Tk
    FreeType
    TBB
    FreeImage
    VTK)