cmake_minimum_required(VERSION 3.20)


include(ExternalProject)

set(TBB_SRC_DIR         ${CMAKE_SOURCE_DIR}/3rd_party_libraries/tbb-src)
set(TBB_BUILD_DIR       ${CMAKE_BINARY_DIR}/tbb-build)
set(TBB_INSTALL_DIR     ${CMAKE_BINARY_DIR}/tbb-install)
set(TBB_DOWNLOAD_DIR    ${CMAKE_BINARY_DIR}/tbb-download)


ExternalProject_Add(TBB
    GIT_REPOSITORY          https://github.com/uxlfoundation/oneTBB.git
    GIT_TAG                 v2022.1.0
    GIT_SHALLOW             TRUE
    GIT_PROGRESS            TRUE
    SOURCE_DIR              ${TBB_SRC_DIR}
    BINARY_DIR              ${TBB_BUILD_DIR}
    DOWNLOAD_DIR            ${TBB_DOWNLOAD_DIR}
    UPDATE_DISCONNECTED     TRUE
    CMAKE_ARGS
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        -DBUILD_SHARED_LIBS=ON
        -DCMAKE_INSTALL_PREFIX=${TBB_INSTALL_DIR}
    BUILD_ALWAYS            FALSE
    STEP_TARGETS            install
)