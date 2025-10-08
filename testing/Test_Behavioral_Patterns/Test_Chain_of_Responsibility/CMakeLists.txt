cmake_minimum_required(VERSION  3.20)

project(Test_Chain_of_Responsibility)


file(GLOB_RECURSE code_files 
    "*.c*"
    "*.h*"
    "${CMAKE_SOURCE_DIR}/Behavioral_Patterns/Chain_of_Responsibility/cpp/*.c*"
    "${CMAKE_SOURCE_DIR}/Behavioral_Patterns/Chain_of_Responsibility/cpp/*.h*"
)

message(STATUS "${PROJECT_NAME} project's code files list: ")
foreach(code_file ${code_files})
    message(STATUS "\t\t ${code_file}")
endforeach()
message(STATUS "\n")


add_executable(${PROJECT_NAME} 
    ../main.cpp
    ${code_files})

add_dependencies(${PROJECT_NAME}    googletest)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD        17
    CXX_EXTENSIONS      NO
    CXX_STANDARD_REQUIRED   YES)

target_compile_options(${PROJECT_NAME} PRIVATE
    "-Wall"
    "-Wextra"
    "-Wpedantic"
    "-Werror")

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}
    ${GOOGLETEST_INCLUDE_DIR})

target_link_directories(${PROJECT_NAME} PRIVATE
    ${GOOGLETEST_LIB_DIR})

target_link_libraries(${PROJECT_NAME} PRIVATE
    gtest)


enable_testing()

add_test(NAME ${PROJECT_NAME}
    COMMAND $<TARGET_FILE:${PROJECT_NAME}>)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})

