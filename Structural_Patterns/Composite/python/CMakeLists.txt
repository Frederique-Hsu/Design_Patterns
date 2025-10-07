cmake_minimum_required(VERSION  3.20)

project(PyComposite)


find_package(Python3 COMPONENTS Interpreter REQUIRED)

enable_testing()

add_test(NAME Test_PyComposite
    COMMAND ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/main.py -v)