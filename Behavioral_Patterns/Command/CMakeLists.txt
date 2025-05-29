cmake_minimum_required(VERSION 3.10)

set(CURRENT_PROJECT_NAME Command)
project(${CURRENT_PROJECT_NAME})

file(GLOB_RECURSE sources *.c*)
file(GLOB_RECURSE headers *.h*)

add_executable(${CURRENT_PROJECT_NAME} 
    ../main.cpp 
    ${sources} 
    ${headers})
set_target_properties(${CURRENT_PROJECT_NAME} PROPERTIES
    CXX_STANDARD            17
    CXX_EXTENSIONS          NO
    CXX_STANDARD_REQUIRED   YES)
target_compile_options(${CURRENT_PROJECT_NAME} PUBLIC ${CPPFLAGS})
target_link_libraries(${CURRENT_PROJECT_NAME} PUBLIC gtest)


enable_testing()
add_test(NAME UTest_${CURRENT_PROJECT_NAME}
    COMMAND $<TARGET_FILE:${CURRENT_PROJECT_NAME}>)