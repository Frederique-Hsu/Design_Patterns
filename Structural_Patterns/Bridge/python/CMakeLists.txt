cmake_minimum_required(VERSION 3.20)

project(PyBridge)

find_package(Python3 COMPONENTS Interpreter REQUIRED)

enable_testing()
add_test(NAME Test_${PROJECT_NAME}
    COMMAND ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/main.py -v)