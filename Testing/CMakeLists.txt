cmake_minimum_required(VERSION 3.20)

set(CURRENT_PROJECT_NAME	Testing)
project(${CURRENT_PROJECT_NAME})

option(Retrieve_Dependencies_By_ExternalProject
	"Retrieve the dependencies for your project by \"ExternalProject_Add\" method or \"FetchContent_Declare\" method?"
	OFF)

include(${CMAKE_SOURCE_DIR}/cmake/googletest.cmake)

file(GLOB_RECURSE sources "*.cpp")
file(GLOB_RECURSE headers "*.hpp")
list(FILTER sources EXCLUDE REGEX "build/*")
list(FILTER headers EXCLUDE REGEX "build/*")

message(STATUS "source files = ")
foreach(source ${sources})
	message(STATUS "\t\t ${source}")
endforeach()

message(STATUS "header files = ")
foreach(header ${headers})
	message(STATUS "\t\t ${header}")
endforeach()

add_executable(${CURRENT_PROJECT_NAME}
	${sources}
	${headers})

set_target_properties(${CURRENT_PROJECT_NAME} PROPERTIES
	CXX_STANDARD			17
	CXX_EXTENSIONS			NO
	CXX_STANDARD_REQUIRED	YES)

message(STATUS "CMAKE_SYSTEM_NAME = ${CMAKE_SYSTEM_NAME}")

if (${CMAKE_SYSTEM_NAME} STREQUAL "Windows" AND MSVC)
	target_compile_options(${CURRENT_PROJECT_NAME} PRIVATE
		"/Zc:__cplusplus")
endif()

if (Retrieve_Dependencies_By_ExternalProject)

	message(STATUS "\t\t Retrieve the dependencies by \"ExternalProject_Add\" method.")
	add_dependencies(${CURRENT_PROJECT_NAME} googletest)

	target_include_directories(${CURRENT_PROJECT_NAME} PRIVATE
		${GTest_INSTALL_DIR}/include)

	target_link_directories(${CURRENT_PROJECT_NAME} PRIVATE
		${GTest_INSTALL_DIR}/lib)
	
else()
	message(STATUS "\t\t Retrieve the dependencies by \"FetchContent_Declare\" method.")
endif()

target_link_libraries(${CURRENT_PROJECT_NAME} PRIVATE
	gtest)


#===================================================================================================

enable_testing()

add_test(NAME UTest_${CURRENT_PROJECT_NAME}
	COMMAND $<TARGET_FILE:${CURRENT_PROJECT_NAME}>)


# 注意： 只有使用FetchContent来加载GoogleTest单元测试依赖项时，以下的单元测试项发现才有效。
include(GoogleTest)
gtest_discover_tests(${CURRENT_PROJECT_NAME})