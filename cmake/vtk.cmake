cmake_minimum_required(VERSION 3.20)


include(ExternalProject)

set(VTK_SRC_DIR             ${CMAKE_SOURCE_DIR}/3rd_party_libraries/vtk-src)
set(VTK_BUILD_DIR           ${CMAKE_BINARY_DIR}/vtk-build)
set(VTK_INSTALL_DIR         ${CMAKE_BINARY_DIR}/vtk-install)
set(VTK_DOWNLOAD_DIR        ${CMAKE_BINARY_DIR}/vtk-download)

ExternalProject_Add(VTK
    GIT_REPOSITORY          https://gitlab.kitware.com/vtk/vtk.git
    GIT_TAG                 v9.4.1
    GIT_SHALLOW             TRUE
    GIT_PROGRESS            TRUE
    SOURCE_DIR              ${VTK_SRC_DIR}
    BINARY_DIR              ${VTK_BUILD_DIR}
    DOWNLOAD_DIR            ${VTK_DOWNLOAD_DIR}
    UPDATE_DISCONNECTED     TRUE
    CMAKE_ARGS
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        -DBUILD_SHARED_LIBS=ON
        -DCMAKE_INSTALL_PREFIX=${VTK_INSTALL_DIR}
    BUILD_ALWAYS            FALSE
    STEP_TARGETS            install
)