cmake_minimum_required(VERSION 3.20)

set(CURRENT_PROJECT_NAME    test_misc)
project(${CURRENT_PROJECT_NAME})


include(${CMAKE_SOURCE_DIR}/cmake/googletest.cmake)

file(GLOB_RECURSE sources "*.c*")
file(GLOB_RECURSE headers "*.h*")
list(FILTER sources EXCLUDE REGEX "build/*")
list(FILTER headers EXCLUDE REGEX "build/*")


add_executable(${CURRENT_PROJECT_NAME}
    ${sources}
    ${headers})

set_target_properties(${CURRENT_PROJECT_NAME} PROPERTIES
    CXX_STANDARD        17
    CXX_EXTENSIONS      NO
    CXX_STANDARD_REQUIRED   YES)

message(STATUS "The CPPFLAGS = ${CPPFLAGS}")
target_compile_options(${CURRENT_PROJECT_NAME} PRIVATE
    ${CPPFLAGS}
)

if (USE_ExternalProject)
    add_dependencies(${CURRENT_PROJECT_NAME} googletest)

    target_include_directories(${CURRENT_PROJECT_NAME} PRIVATE
        ${GTEST_INSTALL_DIR}/include)

    target_link_directories(${CURRENT_PROJECT_NAME} PRIVATE
        ${GTEST_INSTALL_DIR}/lib)
elseif(USE_FetchContent)
endif()

target_link_libraries(${CURRENT_PROJECT_NAME} PRIVATE
    gtest)

#================================================================================

enable_testing()

add_test(NAME UTest_${CURRENT_PROJECT_NAME}
    COMMAND $<TARGET_FILE:${CURRENT_PROJECT_NAME}>)
