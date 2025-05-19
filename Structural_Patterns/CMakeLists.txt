cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(Structural_Patterns)

set(STRUCTURAL_PATTERNS_PATH ${CMAKE_CURRENT_SOURCE_DIR})


if (${BUILD_UTEST_FROM_SOURCE})
    FetchContent_Declare(Catch2
        GIT_REPOSITORY      https://github.com/catchorg/Catch2.git
        GIT_TAG             v3.7.1)
    FetchContent_MakeAvailable(Catch2)
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