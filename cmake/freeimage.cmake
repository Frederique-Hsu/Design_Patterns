cmake_minimum_required(VERSION 3.20)


include(ExternalProject)

set(FreeImage_SRC_DIR           ${CMAKE_SOURCE_DIR}/3rd_party_libraries/freeimage-src)
set(FreeImage_BUILD_DIR         ${CMAKE_BINARY_DIR}/freeimage-build)
set(FreeImage_INSTALL_DIR       ${CMAKE_BINARY_DIR}/freeimage-install)
set(FreeImage_DOWNLOAD_DIR      ${CMAKE_BINARY_DIR}/freeimage-download)


ExternalProject_Add(FreeImage
    GIT_REPOSITORY              https://github.com/danoli3/FreeImage.git
    GIT_TAG                     3.19.10
    GIT_SHALLOW                 TRUE
    GIT_PROGRESS                TRUE
    SOURCE_DIR                  ${FreeImage_SRC_DIR}
    BINARY_DIR                  ${FreeImage_BUILD_DIR}
    DOWNLOAD_DIR                ${FreeImage_INSTALL_DIR}
    UPDATE_DISCONNECTED         TRUE
    CMAKE_ARGS
        -DCMAKE_BUILD_TYPE=Release
        -DBUILD_SHARED_LIBS=OFF
        -DCMAKE_INSTALL_PREFIX=${FreeImage_INSTALL_DIR}
    BUILD_ALWAYS                FALSE
    STEP_TARGETS                install
)