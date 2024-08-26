set(CURRENT_PROJECT_NAME Mediator)

project(${CURRENT_PROJECT_NAME} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS NO)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

file(GLOB_RECURSE sources *.c*)
file(GLOB_RECURSE headers *.h*)

find_package(GTest REQUIRED CONFIG)

add_executable(${CURRENT_PROJECT_NAME} ../main.cpp ${sources} ${headers})

target_compile_options(${CURRENT_PROJECT_NAME} PUBLIC ${COMMON_COMPILE_OPTIONS})

target_link_libraries(${CURRENT_PROJECT_NAME} PUBLIC GTest::gtest)

add_test(NAME UTest_${CURRENT_PROJECT_NAME}
    COMMAND $<TARGET_FILE:${CURRENT_PROJECT_NAME}>)