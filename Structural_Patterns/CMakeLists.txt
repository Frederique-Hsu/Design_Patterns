cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(Structural_Patterns)

set(STRUCTURAL_PATTERNS_PATH ${CMAKE_CURRENT_SOURCE_DIR})


if (${BUILD_UTEST_FROM_SOURCE})
    set(Catch2_SRC_PATH     ${PROJECT_BUILD_PATH}/_deps/catch2-src)
    set(Catch2_BUILD_PATH   ${PROJECT_BUILD_PATH}/_deps/catch2-build)

    FetchContent_Declare(Catch2
        GIT_REPOSITORY      https://github.com/catchorg/Catch2.git
        GIT_TAG             v3.7.1)
    
    FetchContent_GetProperties(Catch2)
    if (NOT Catch2_POPULATED)
        FetchContent_Populate(Catch2)
        add_subdirectory(${Catch2_SRC_PATH} ${Catch2_BUILD_PATH})
    endif()
endif()

enable_testing()

add_subdirectory(Adapter)
add_subdirectory(Bridge)
add_subdirectory(Composite)
add_subdirectory(Decorator)
add_subdirectory(Facade)
add_subdirectory(Flyweight)
add_subdirectory(Proxy)
add_subdirectory(common_utils)