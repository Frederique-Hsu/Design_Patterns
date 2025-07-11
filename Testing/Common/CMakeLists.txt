cmake_minimum_required(VERSION 3.20)

set(CURRENT_PROJECT_NAME	Test_Common)
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
	${headers}
)

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

set(Common_INCLUDE_DIR		${CMAKE_SOURCE_DIR})
target_include_directories(${CURRENT_PROJECT_NAME} PUBLIC
	${Common_INCLUDE_DIR}
)

set(Common_LIB_DIR		${CMAKE_BINARY_DIR}/Common)
target_link_directories(${CURRENT_PROJECT_NAME} PRIVATE ${Common_LIB_DIR})

if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
	set(Boost_Debug_LIB_DIR         ${ExternalLibrary_Debug_LIB_DIR})

	target_link_directories(${CURRENT_PROJECT_NAME} PUBLIC
		${Boost_Debug_LIB_DIR}
	)

	target_link_libraries(${CURRENT_PROJECT_NAME} PUBLIC
		boost_locale-vc143-mt-gd-x64-1_86
		boost_filesystem-vc143-mt-gd-x64-1_86
	)
else()
	set(Boost_Release_LIB_DIR       ${ExternalLibrary_Release_LIB_DIR})

	target_link_directories(${CURRENT_PROJECT_NAME} PUBLIC
		${Boost_Release_LIB_DIR}
	)

	target_link_libraries(${CURRENT_PROJECT_NAME} PUBLIC
		boost_locale-vc143-mt-x64-1_86
		boost_filesystem-vc143-mt-x64-1_86
	)
endif()


target_link_libraries(${CURRENT_PROJECT_NAME} PUBLIC
	Common
	gtest
)

target_compile_definitions(${CURRENT_PROJECT_NAME} PRIVATE
	CONFIGURATION_XML_FILE="${CMAKE_CURRENT_BINARY_DIR}/config.xml")

if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
	add_custom_command(TARGET ${CURRENT_PROJECT_NAME} POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Debug_BIN_DIR}/boost_locale-vc143-mt-gd-x64-1_86.dll $<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Debug_BIN_DIR}/boost_filesystem-vc143-mt-gd-x64-1_86.dll $<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Debug_BIN_DIR}/tinyxml2.dll $<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/config.xml $<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
	)
else()
	add_custom_command(TARGET ${CURRENT_PROJECT_NAME} POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Release_BIN_DIR}/boost_locale-vc143-mt-x64-1_86.dll $<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Release_BIN_DIR}/boost_filesystem-vc143-mt-x64-1_86.dll $<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Release_BIN_DIR}/tinyxml2.dll $<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/config.xml $<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
	)
endif()


#===================================================================================================

enable_testing()

add_test(NAME UTest_${CURRENT_PROJECT_NAME}
	COMMAND $<TARGET_FILE:${CURRENT_PROJECT_NAME}>)


# 注意： 只有使用FetchContent来加载GoogleTest单元测试依赖项时，以下的单元测试项发现才有效。
include(GoogleTest)
gtest_discover_tests(${CURRENT_PROJECT_NAME})