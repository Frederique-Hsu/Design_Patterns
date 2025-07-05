cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(Design_Patterns)


list(APPEND CPPFLAGS
    "-Wall"
    "-Wextra"
    "-pedantic"
    # "-Werror"
)

option(USE_FetchContent
    "Utilize the FetchContent approach to retrieve unit test framework repositories."
    OFF)
option(USE_ExternalProject
    "Utilize the ExternalProject approach to retrieve unit test framework repositories."
    ON)


enable_testing()

# add_subdirectory(Behavioral_Patterns)
# add_subdirectory(Creational_Patterns)
# add_subdirectory(Structural_Patterns)
add_subdirectory(SOLID)
# add_subdirectory(references/LexI)
# add_subdirectory(references/Design-Patterns-GoF)
# add_subdirectory(references/DesignPattern)

add_subdirectory(testing)

add_subdirectory(OOC)
add_subdirectory(object_oriented_c)
