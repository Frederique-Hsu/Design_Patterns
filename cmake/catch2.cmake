cmake_minimum_required(VERSION 3.20)


set(CATCH2_SRC_DIR      ${CMAKE_BINARY_DIR}/catch2-src)

set(Catch2_GIT_TAG      devel)

if (USE_ExternalProject)

    include(ExternalProject)

    set(CATCH2_BUILD_DIR    ${CMAKE_BINARY_DIR}/catch2-build)
    set(CATCH2_INSTALL_DIR  ${CMAKE_BINARY_DIR}/catch2-install)


    ExternalProject_Add(catch2
        GIT_REPOSITORY      https://github.com/catchorg/Catch2.git
        GIT_TAG             ${Catch2_GIT_TAG}
        GIT_SHALLOW         TRUE
        GIT_PROGRESS        TRUE
        SOURCE_DIR          ${CATCH2_SRC_DIR}
        BINARY_DIR          ${CATCH2_BUILD_DIR}
        UPDATE_DISCONNECTED TRUE
        CMAKE_ARGS
            -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
            -DBUILD_SHARED_LIBS=ON
            -DCMAKE_INSTALL_PREFIX=${CATCH2_INSTALL_DIR}
        BUILD_ALWAYS        TRUE
        STEP_TARGETS        install
    )

elseif (USE_FetchContent)

    include(FetchContent)
    set(FETCHCONTENT_UPDATES_DISCONNECTED   TRUE)

    FetchContent_Declare(catch2
        GIT_REPOSITORY      https://github.com/catchorg/Catch2.git
        GIT_TAG             ${Catch2_GIT_TAG}
        GIT_SHALLOW         TRUE
        GIT_PROGRESS        TRUE
        SOURCE_DIR          ${CATCH2_SRC_DIR}
    )
    FetchContent_MakeAvailable(Catch2)

endif()
