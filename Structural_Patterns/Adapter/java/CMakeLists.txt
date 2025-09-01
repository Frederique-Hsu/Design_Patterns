cmake_minimum_required(VERSION  3.20)

project(JavaAdapterPattern  Java)

find_package(Java REQUIRED)
include(UseJava)

file(GLOB_RECURSE sources "*.java")

add_jar(${PROJECT_NAME}
    SOURCES         ${sources}
    ENTRY_POINT     AdapterPatternDemo)

set_target_properties(${PROJECT_NAME} PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY    ${CMAKE_BINARY_DIR})
