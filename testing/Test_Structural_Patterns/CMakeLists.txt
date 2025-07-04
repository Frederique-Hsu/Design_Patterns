cmake_minimum_required(VERSION 3.20)

set(CURRENT_PROJECT_NAME    Test_Structural_Patterns)
project(${CURRENT_PROJECT_NAME})


include(${CMAKE_SOURCE_DIR}/cmake/catch2.cmake)

file(GLOB_RECURSE sources "*.c*")
file(GLOB_RECURSE headers "*.h*")
list(FILTER sources EXCLUDE REGEX "build/*")
list(FILTER headers EXCLUDE REGEX "build/*")


add_executable(${CURRENT_PROJECT_NAME}
    ${sources}
    ${headers})


if (USE_ExternalProject)
    add_dependencies(${CURRENT_PROJECT_NAME} catch2)

    target_include_directories(${CURRENT_PROJECT_NAME} PRIVATE
        ${CATCH2_INSTALL_DIR}/include)

    target_link_directories(${CURRENT_PROJECT_NAME} PRIVATE
        ${CATCH2_INSTALL_DIR}/lib)
elseif(USE_FetchContent)
    # no need to add the include/ and lib/ directories of Catch2
endif()

if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    target_link_libraries(${CURRENT_PROJECT_NAME} PRIVATE
        Catch2d)
else()
    target_link_libraries(${CURRENT_PROJECT_NAME} PRIVATE
        Catch2)
endif()

set_target_properties(${CURRENT_PROJECT_NAME} PROPERTIES
    CXX_STANDARD        17
    CXX_EXTENSIONS      NO
    CXX_STANDARD_REQUIRED   YES)

target_compile_options(${CURRENT_PROJECT_NAME} PRIVATE
    ${CPPFLAGS})

#===============================================================================

enable_testing()

add_test(NAME UTest_${CURRENT_PROJECT_NAME}
    COMMAND $<TARGET_FILE:${CURRENT_PROJECT_NAME}>)
