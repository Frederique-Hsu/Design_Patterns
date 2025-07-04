cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(SOLID)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(${CMAKE_SOURCE_DIR}/cmake/boost.cmake)


add_executable(SRP SRP.cpp SRP.hpp)
target_include_directories(SRP PRIVATE ${BOOST_INSTALL_DIR}/include)
add_dependencies(SRP boost)

add_executable(OCP OCP.cpp OCP.hpp)

add_executable(LSP LSP.cpp LSP.hpp)

add_executable(ISP ISP.cpp ISP.hpp)

add_executable(DIP DIP.cpp DIP.hpp)

enable_testing()

add_test(NAME Test_SRP
    COMMAND $<TARGET_FILE:SRP>)

add_test(NAME Test_OCP
    COMMAND $<TARGET_FILE:OCP>)

add_test(NAME Test_LSP
    COMMAND $<TARGET_FILE:LSP>)

add_test(NAME Test_ISP
    COMMAND $<TARGET_FILE:ISP>)

add_test(NAME Test_DIP
    COMMAND $<TARGET_FILE:DIP>)
