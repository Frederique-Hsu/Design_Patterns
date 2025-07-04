cmake_minimum_required(VERSION 3.20)


set(GTEST_SRC_DIR       ${CMAKE_BINARY_DIR}/googletest-src)

# set(GTest_GIT_TAG   v1.17.0)
set(GTest_GIT_TAG   main)

if (USE_ExternalProject)

    include(ExternalProject)

    set(GTEST_BUILD_DIR     ${CMAKE_BINARY_DIR}/googletest-build)
    set(GTEST_INSTALL_DIR   ${CMAKE_BINARY_DIR}/googletest-install)


    ExternalProject_Add(googletest
        GIT_REPOSITORY      https://github.com/google/googletest.git
        GIT_TAG             ${GTest_GIT_TAG}
        GIT_SHALLOW         TRUE
        GIT_PROGRESS        TRUE
        SOURCE_DIR          ${GTEST_SRC_DIR}
        BINARY_DIR          ${GTEST_BUILD_DIR}
        UPDATE_DISCONNECTED TRUE
        CMAKE_ARGS
            -DCMAKE_CXX_STANDARD=17
            -DCMAKE_CXX_STANDARD_REQUIRED=ON
            -DCMAKE_CXX_EXTENSIONS=OFF
            -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
            -DBUILD_SHARED_LIBS=ON
            -DCMAKE_INSTALL_PREFIX=${GTEST_INSTALL_DIR}
        BUILD_ALWAYS        TRUE
        STEP_TARGETS        install
    )

elseif (USE_FetchContent)

    include(FetchContent)
    set(FETCHCONTENT_UPDATES_DISCONNECTED   TRUE)

    FetchContent_Declare(googletest
        GIT_REPOSITORY      https://github.com/google/googletest.git
        GIT_TAG             ${GTest_GIT_TAG}
        GIT_SHALLOW         TRUE
        GIT_PROGRESS        TRUE
        SOURCE_DIR          ${GTEST_SRC_DIR}
    )
    FetchContent_MakeAvailable(googletest)

endif()
