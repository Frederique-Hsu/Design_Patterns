cmake_minimum_required(VERSION 3.20)

set(CPPUTEST_SRC_DIR        ${CMAKE_BINARY_DIR}/cpputest-src)

set(CppUTest_GIT_TAG    master)

if (USE_ExternalProject)

    include(ExternalProject)

    set(CPPUTEST_BUILD_DIR      ${CMAKE_BINARY_DIR}/cpputest-build)
    set(CPPUTEST_INSTALL_DIR    ${CMAKE_BINARY_DIR}/cpputest-install)


    ExternalProject_Add(cpputest
        GIT_REPOSITORY      https://github.com/cpputest/cpputest.git
        GIT_TAG             ${CppUTest_GIT_TAG}
        GIT_SHALLOW         TRUE
        GIT_PROGRESS        TRUE
        SOURCE_DIR          ${CPPUTEST_SRC_DIR}
        BINARY_DIR          ${CPPUTEST_BUILD_DIR}
        UPDATE_DISCONNECTED TRUE
        CMAKE_ARGS
            -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
            -DBUILD_SHARED_LIBS=ON
            -DCMAKE_INSTALL_PREFIX=${CPPUTEST_INSTALL_DIR}
        BUILD_ALWAYS        TRUE
        STEP_TARGETS        install
    )

elseif (USE_FetchContent)

    include(FetchContent)
    set(FETCHCONTENT_UPDATES_DISCONNECTED   TRUE)

    FetchContent_Declare(cpputest
        GIT_REPOSITORY      https://github.com/cpputest/cpputest.git
        GIT_TAG             ${CppUTest_GIT_TAG}
        GIT_SHALLOW         TRUE
        GIT_PROGRESS        TRUE
        SOURCE_DIR          ${CPPUTEST_SRC_DIR}
    )
    FetchContent_MakeAvailable(cpputest)

endif()
