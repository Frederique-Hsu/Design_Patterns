cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(Behavioral_Patterns)

if (BUILD_UTEST_FROM_SOURCE)
    set(GTest_SRC_PATH      ${PROJECT_BUILD_PATH}/_deps/gtest-src)
    set(GTest_BUILD_PATH    ${PROJECT_BUILD_PATH}/_deps/gtest-build)

    FetchContent_Declare(GTest
        GIT_REPOSITORY      https://github.com/google/googletest.git
        GIT_TAG             main)
    
    FetchContent_GetProperties(GTest)
    if (NOT GTest_POPULATED)
        FetchContent_Populate(GTest)
        add_subdirectory(${GTest_SRC_PATH} ${GTest_BUILD_PATH})
    endif()
endif()


enable_testing()

add_subdirectory(Chain_of_Responsibility)
add_subdirectory(Command)
add_subdirectory(Interpreter)
add_subdirectory(Iterator)
add_subdirectory(Mediator)
add_subdirectory(Memento)
add_subdirectory(Observer)
add_subdirectory(State)
add_subdirectory(Strategy)
add_subdirectory(Template_Method)
add_subdirectory(Visitor)