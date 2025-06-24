cmake_minimum_required(VERSION 3.20)


set(TINYXML2_SRC_DIR            ${CMAKE_SOURCE_DIR}/3rd_party_libraries/tinyxml2-src)
set(TINYXML2_BUILD_DIR          ${CMAKE_BINARY_DIR}/tinyxml2-build)
set(TINYXML2_INSTALL_DIR        ${CMAKE_BINARY_DIR}/tinyxml2-install)
set(TINYXML2_DOWNLOAD_DIR       ${CMAKE_BINARY_DIR}/tinyxml2-download)

if (FALSE)
    include (FetchContent)
    set(FETCHCONTENT_UPDATES_DISCONNECTED   TRUE)

    FetchContent_Declare(TinyXml2
        GIT_REPOSITORY      https://github.com/leethomason/tinyxml2.git
        GIT_TAG             10.0.0
        GIT_SHALLOW         TRUE
        GIT_PROGRESS        TRUE
        SOURCE_DIR          ${TINYXML2_SRC_DIR}
        # BINARY_DIR        ${TINYXML2_BUILD_DIR}
    )
    FetchContent_MakeAvailable(TinyXml2)
else()
    include(ExternalProject)

    ExternalProject_Add(TinyXml2
        GIT_REPOSITORY      https://github.com/leethomason/tinyxml2.git
        GIT_TAG             10.0.0
        GIT_SHALLOW         TRUE
        GIT_PROGRESS        TRUE
        SOURCE_DIR          ${TINYXML2_SRC_DIR}
        BINARY_DIR          ${TINYXML2_BUILD_DIR}
        DOWNLOAD_DIR        ${TINYXML2_DOWNLOAD_DIR}
        UPDATE_DISCONNECTED TRUE
        CMAKE_ARGS
            -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
            -DCMAKE_INSTALL_PREFIX=${TINYXML2_INSTALL_DIR}
            -DBUILD_SHARED_LIBS=ON
        BUILD_ALWAYS        TRUE
        STEP_TARGETS        install
    )
endif()