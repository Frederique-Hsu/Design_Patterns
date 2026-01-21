cmake_minimum_required(VERSION  3.20)

project(OOP_Design_Patterns)


add_subdirectory(Structural_Patterns)
add_subdirectory(Creational_Patterns)
add_subdirectory(Behavioral_Patterns)

# add_subdirectory(references/Design-Patterns-GoF)

enable_testing()
add_subdirectory(testing)

# if (${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
#     find_package(OpenMP QUIET)

#     if (OpenMP_FOUND)
#         message(STATUS "Found OpenMP via find_package")
#     else()
#         set(OPENMP_INCLUDE_DIR  "/opt/homebrew/opt/libomp/include")
#         set(OPENMP_LIB_DIR      "/opt/homebrew/opt/libomp/lib")

#         if (NOT EXISTS "${OPENMP_INCLUDE_DIR}}")
#             include_directories(${OPENMP_INCLUDE_DIR})
#             link_directories(${OPENMP_LIB_DIR})
#             message(STATUS "Using OpenMP via ${OPENMP_INCLUDE_DIR}")
#         else()
#             message(WARNING "OpenMP not found")
#         endif()
#     endif()

#     add_compile_options(-Wno-unused-private-field)
#     add_subdirectory(references/LexI)
# endif()

if (${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    add_subdirectory(references/LexI)
endif()