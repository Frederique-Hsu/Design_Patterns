cmake_minimum_required(VERSION 3.20)

set(CURRENT_PROJECT_NAME    Probe_OpenCASCADE)
project(${CURRENT_PROJECT_NAME})


file(GLOB_RECURSE sources "*.c*")
file(GLOB_RECURSE headers "*.h*")
list(FILTER sources EXCLUDE REGEX "./build/*")
list(FILTER headers EXCLUDE REGEX "./build/*")

message(STATUS "source files list: ")
foreach(source ${sources})
    message(STATUS "\t\t ${source}")
endforeach()

message(STATUS "header files list: ")
foreach(header ${headers})
    message(STATUS "\t\t ${header}")
endforeach()



add_executable(${CURRENT_PROJECT_NAME}
    ${sources}
    ${headers})

add_dependencies(${CURRENT_PROJECT_NAME} OCCT)

set_target_properties(${CURRENT_PROJECT_NAME} PROPERTIES
    CXX_STANDARD            17
    CXX_EXTENSIONS          NO
    CXX_STANDARD_REQUIRED   YES)

target_compile_options(${CURRENT_PROJECT_NAME} PRIVATE
    "-Wall"
    "-Wextra"
    "-Werror"
)

target_include_directories(${CURRENT_PROJECT_NAME} PRIVATE
    ${OCCT_INCLUDE_DIR}
)

target_link_directories(${CURRENT_PROJECT_NAME} PRIVATE
    ${OCCT_LIB_DIR}
)

target_link_libraries(${CURRENT_PROJECT_NAME} PRIVATE
)