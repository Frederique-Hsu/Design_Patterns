cmake_minimum_required(VERSION 3.20)


set(BOOST_SRC_DIR       ${CMAKE_BINARY_DIR}/boost-src)

set(BOOST_GIT_TAG   master)


if (USE_ExternalProject)

    include(ExternalProject)


    set(BOOST_BUILD_DIR     ${CMAKE_BINARY_DIR}/boost-build)
    set(BOOST_INSTALL_DIR   ${CMAKE_BINARY_DIR}/boost-install)


    ExternalProject_Add(boost
        GIT_REPOSITORY      https://github.com/boostorg/boost.git
        GIT_TAG             ${BOOST_GIT_TAG}
        GIT_SHALLOW         TRUE
        GIT_PROGRESS        TRUE
        SOURCE_DIR          ${BOOST_SRC_DIR}
        BINARY_DIR          ${BOOST_BUILD_DIR}
        UPDATE_DISCONNECTED FALSE
        CMAKE_ARGS
            -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
            -DBUILD_SHARED_LIBS=ON
            -DCMAKE_INSTALL_PREFIX=${BOOST_INSTALL_DIR}
        BUILD_ALWAYS        FALSE
        # STEP_TARGETS        install
    )

elseif (USE_FetchContent)

    include(FetchContent)
    set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)

    FetchContent_Declare(boost
        GIT_REPOSITORY      https://github.com/boostorg/boost.git
        GIT_TAG             ${BOOST_GIT_TAG}
        GIT_SHALLOW         TRUE
        GIT_PROGRESS        TRUE
        SOURCE_DIR          ${BOOST_SRC_DIR}
    )
    FetchContent_MakeAvailable(boost)

endif()
