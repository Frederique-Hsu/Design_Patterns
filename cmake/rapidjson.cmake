cmake_minimum_required(VERSION 3.20)

include(ExternalProject)


set(RapidJSON_SRC_DIR           ${CMAKE_SOURCE_DIR}/3rd_party_libraries/rapidjson-src)
set(RapidJSON_BUILD_DIR         ${CMAKE_BINARY_DIR}/rapidjson-build)
set(RapidJSON_INSTALL_DIR       ${CMAKE_BINARY_DIR}/rapidjson-install)
set(RapidJSON_DOWNLOAD_DIR      ${CMAKE_BINARY_DIR}/rapidjson-download)


ExternalProject_Add(RapidJSON
    GIT_REPOSITORY              https://github.com/Tencent/rapidjson.git
    GIT_TAG                     v1.1.1.0
    GIT_SHALLOW                 TRUE
    GIT_PROGRESS                TRUE
    UPDATE_DISCONNECTED         TRUE
    SOURCE_DIR                  ${RapidJSON_SRC_DIR}
    BINARY_DIR                  ${RapidJSON_BUILD_DIR}
    DOWNLOAD_DIR                ${RapidJSON_DOWNLOAD_DIR}
    CMAKE_ARGS
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        -DBUILD_SHARED_LIBS=ON
        -DCMAKE_INSTALL_PREFIX=${RapidJSON_INSTALL_DIR}
    BUILD_ALWAYS                TRUE
    STEP_TARGETS                install
)