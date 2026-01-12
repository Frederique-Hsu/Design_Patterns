cmake_minimum_required(VERSION 3.20)

project(PyAdapter)

find_package(Python3 COMPONENTS Interpreter REQUIRED)


enable_testing()
add_test(NAME Test_PyClassAdapter
    COMMAND ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/class_adapter.py -v)

add_test(NAME Test_PyObjectAdapter
    COMMAND ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/object_adapter.py -v)