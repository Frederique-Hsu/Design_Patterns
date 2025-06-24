cmake_minimum_required(VERSION 3.20)

include(ExternalProject)

set(FreeType_SRC_DIR        ${CMAKE_SOURCE_DIR}/3rd_party_libraries/freetype-src)
set(FreeType_BUILD_DIR      ${CMAKE_BINARY_DIR}/freetype-build)
set(FreeType_INSTALL_DIR    ${CMAKE_BINARY_DIR}/freetype-install)
set(FreeType_DOWNLOAD_DIR   ${CMAKE_BINARY_DIR}/freetype-download)


ExternalProject_Add(FreeType
    GIT_REPOSITORY          https://gitlab.freedesktop.org/freetype/freetype.git
    GIT_TAG                 VER-2-13-3
    GIT_SHALLOW             TRUE
    GIT_PROGRESS            TRUE
    SOURCE_DIR              ${FreeType_SRC_DIR}
    BINARY_DIR              ${FreeType_BUILD_DIR}
    DOWNLOAD_DIR            ${FreeType_DOWNLOAD_DIR}
    UPDATE_DISCONNECTED     TRUE
    CMAKE_ARGS
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        -DBUILD_SHARED_LIBS=ON
        -DCMAKE_INSTALL_PREFIX=${FreeType_INSTALL_DIR}
    BUILD_ALWAYS            FALSE
    STEP_TARGETS            install
)