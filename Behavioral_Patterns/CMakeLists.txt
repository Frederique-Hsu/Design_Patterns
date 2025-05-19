cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(Behavioral_Patterns)

list(APPEND COMMON_COMPILE_OPTIONS
    "-Wall"
    "-Wpedantic"
    "-Werror")

if (BUILD_UTEST_FROM_SOURCE)
    FetchContent_Declare(GTest
        GIT_REPOSITORY  https://github.com/google/googletest.git
        GIT_TAG         main)
    FetchContent_MakeAvailable(GTest)
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