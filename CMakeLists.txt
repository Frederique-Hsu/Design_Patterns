cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(Design_Patterns)


# add_subdirectory(Behavioral_Patterns)
# add_subdirectory(Creational_Patterns)
add_subdirectory(Structural_Patterns)
# add_subdirectory(SOLID)

enable_testing()

if (false)
    add_subdirectory(references/LexI)
    add_subdirectory(references/Design-Patterns-GoF)
    add_subdirectory(references/DesignPattern)
endif()

add_subdirectory(testing)