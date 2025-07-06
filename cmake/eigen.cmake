cmake_minimum_required(VERSION 3.20)

include(ExternalProject)


set(Eigen_SRC_DIR       ${CMAKE_SOURCE_DIR}/3rd_party_libraries/eigen-src)
set(Eigen_BUILD_DIR     ${CMAKE_BINARY_DIR}/eigen-build)
set(Eigen_INSTALL_DIR   ${CMAKE_BINARY_DIR}/eigen-install)
set(Eigen_DOWNLOAD_DIR  ${CMAKE_BINARY_DIR}/eigen-download)


ExternalProject_Add(Eigen
    GIT_REPOSITORY          https://gitlab.com/libeigen/eigen.git
    GIT_TAG                 3.4.0
    GIT_SHALLOW             TRUE
    GIT_PROGRESS            TRUE
    SOURCE_DIR              ${Eigen_SRC_DIR}
    BINARY_DIR              ${Eigen_BUILD_DIR}
    DOWNLOAD_DIR            ${Eigen_DOWNLOAD_DIR}
    UPDATE_DISCONNECTED     TRUE
    CMAKE_ARGS
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        -DBUILD_SHARED_LIBS=ON
        -DCMAKE_INSTALL_PREFIX=${Eigen_INSTALL_DIR}
    BUILD_ALWAYS            FALSE
    STEP_TARGETS            install
)