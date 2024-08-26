set(CURRENT_PROJECT_NAME Flyweight)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS NO)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

find_package(Catch2 REQUIRED CONFIG)

file(GLOB_RECURSE sources *.c*)
file(GLOB_RECURSE headers *.h*)

add_executable(${CURRENT_PROJECT_NAME} "")
target_sources(${CURRENT_PROJECT_NAME} PRIVATE
    ../main.cpp
    ${sources}
    ${headers})

target_compile_options(${CURRENT_PROJECT_NAME} PUBLIC ${COMMON_COMPILE_OPTIONS})
target_link_libraries(${CURRENT_PROJECT_NAME} PRIVATE Catch2::Catch2)

add_test(NAME UTest_${CURRENT_PROJECT_NAME}
    COMMAND $<TARGET_FILE:${CURRENT_PROJECT_NAME}>)