cmake_minimum_required(VERSION 3.20)

set(CURRENT_PROJECT_NAME	Test_GeometryDynamic)
project(${CURRENT_PROJECT_NAME})


include(${CMAKE_SOURCE_DIR}/cmake/catch2.cmake)

file(GLOB_RECURSE sources "*.cpp")
file(GLOB_RECURSE headers "*.hpp")
list(FILTER sources EXCLUDE REGEX "build/*")
list(FILTER headers EXCLUDE REGEX "build/*")


add_executable(${CURRENT_PROJECT_NAME}
	${sources}
	${headers})

set_target_properties(${CURRENT_PROJECT_NAME} PROPERTIES
	CXX_STANDARD		17
	CXX_EXTENSIONS		NO
	CXX_STANDARD_REQUIRED	YES)

if (${CMAKE_SYSTEM_NAME} STREQUAL "Windows" AND MSVC)
	target_compile_options(${CURRENT_PROJECT_NAME} PRIVATE
		"/Zc:__cplusplus")
endif()


set(GeometryDynamic_INCLUDE_DIR		${CMAKE_SOURCE_DIR})
set(OpenCASCADE_INCLUDE_DIR			${ExternalLirary_INCLUDE_DIR}/opencascade)
set(Eigen3_INCLUDE_DIR				${ExternalLirary_INCLUDE_DIR}/eigen3)

target_include_directories(${CURRENT_PROJECT_NAME} PRIVATE
	${GeometryDynamic_INCLUDE_DIR}
	${OpenCASCADE_INCLUDE_DIR}
	${Eigen3_INCLUDE_DIR}
)

set(GeometryDynamic_LIB_DIR		${CMAKE_BINARY_DIR}/GeometryDynamic)
target_link_directories(${CURRENT_PROJECT_NAME} PRIVATE
	${GeometryDynamic_LIB_DIR}
)

if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
	set(Boost_Debug_LIB_DIR				${ExternalLibrary_Debug_LIB_DIR})
	set(OpenCASCADE_Debug_LIB_DIR		${ExternalLibrary_Debug_LIB_DIR}/opencascade)
	set(AnalysisSitus_Debug_LIB_DIR		${ExternalLibrary_Debug_LIB_DIR}/asi)

	target_link_directories(${CURRENT_PROJECT_NAME} PRIVATE
		${Boost_Debug_LIB_DIR}
		${OpenCASCADE_Debug_LIB_DIR}
		${AnalysisSitus_Debug_LIB_DIR}
	)
else()
	set(Boost_Release_LIB_DIR			${ExternalLibrary_Release_LIB_DIR})
	set(OpenCASCADE_Release_LIB_DIR		${ExternalLibrary_Release_LIB_DIR}/opencascade)
	set(AnalysisSitus_Release_LIB_DIR	${ExternalLibrary_Release_LIB_DIR}/asi)

	target_link_directories(${CURRENT_PROJECT_NAME} PRIVATE
		${Boost_Release_LIB_DIR}
		${OpenCASCADE_Release_LIB_DIR}
		${AnalysisSitus_Release_LIB_DIR}
	)
endif()

target_link_libraries(${CURRENT_PROJECT_NAME} PRIVATE
	Catch2
	GeometryDynamic

	TKernel		
	TKMath
	TKBRep
	TKTopAlgo
	TKGeomAlgo
	TKV3d
	TKG3d
	TKMesh
	TKSTEP
	TKIGES
	TKSTL
	TKXSBase
	TKGeomBase
	TKG2d
	TKShHealing
	TKService
	TKHLR
	TKSTEPAttr
	TKSTEP209
	TKSTEPBase
	TKBool
	TKPrim
	TKBO
	
    # asiAlgo
)

if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
	add_custom_command(TARGET ${CURRENT_PROJECT_NAME} POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Debug_BIN_DIR}/boost_locale-vc143-mt-gd-x64-1_86.dll			$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Debug_BIN_DIR}/boost_filesystem-vc143-mt-gd-x64-1_86.dll		$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>

		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Debug_BIN_DIR}/tinyxml2.dll						$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Debug_BIN_DIR}/opencascade/TKernel.dll			$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Debug_BIN_DIR}/opencascade/TKMath.dll			$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Debug_BIN_DIR}/opencascade/TKBRep.dll			$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Debug_BIN_DIR}/opencascade/TKTopAlgo.dll		$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Debug_BIN_DIR}/opencascade/TKGeomAlgo.dll		$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Debug_BIN_DIR}/opencascade/TKV3d.dll			$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Debug_BIN_DIR}/opencascade/TKG3d.dll			$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Debug_BIN_DIR}/opencascade/TKMesh.dll			$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Debug_BIN_DIR}/opencascade/TKSTEP.dll			$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Debug_BIN_DIR}/opencascade/TKIGES.dll			$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Debug_BIN_DIR}/opencascade/TKSTL.dll			$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Debug_BIN_DIR}/opencascade/TKXSBase.dll			$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Debug_BIN_DIR}/opencascade/TKGeomBase.dll		$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Debug_BIN_DIR}/opencascade/TKG2d.dll			$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Debug_BIN_DIR}/opencascade/TKShHealing.dll		$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Debug_BIN_DIR}/opencascade/TKService.dll		$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Debug_BIN_DIR}/opencascade/TKHLR.dll			$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Debug_BIN_DIR}/opencascade/TKSTEPAttr.dll		$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Debug_BIN_DIR}/opencascade/TKSTEP209.dll		$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Debug_BIN_DIR}/opencascade/TKSTEPBase.dll		$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Debug_BIN_DIR}/opencascade/TKBool.dll			$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Debug_BIN_DIR}/opencascade/TKPrim.dll			$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Debug_BIN_DIR}/opencascade/TKBO.dll				$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>

		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Debug_BIN_DIR}/opencascadeRely/freetype.dll		$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
	)
else()
	add_custom_command(TARGET ${CURRENT_PROJECT_NAME} POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Release_BIN_DIR}/boost_locale-vc143-mt-x64-1_86.dll				$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Release_BIN_DIR}/boost_filesystem-vc143-mt-x64-1_86.dll			$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>

		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Release_BIN_DIR}/tinyxml2.dll					$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Release_BIN_DIR}/opencascade/TKernel.dll		$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Release_BIN_DIR}/opencascade/TKMath.dll			$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Release_BIN_DIR}/opencascade/TKBRep.dll			$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Release_BIN_DIR}/opencascade/TKTopAlgo.dll		$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Release_BIN_DIR}/opencascade/TKGeomAlgo.dll		$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Release_BIN_DIR}/opencascade/TKV3d.dll			$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Release_BIN_DIR}/opencascade/TKG3d.dll			$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Release_BIN_DIR}/opencascade/TKMesh.dll			$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Release_BIN_DIR}/opencascade/TKSTEP.dll			$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Release_BIN_DIR}/opencascade/TKIGES.dll			$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Release_BIN_DIR}/opencascade/TKSTL.dll			$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Release_BIN_DIR}/opencascade/TKXSBase.dll		$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Release_BIN_DIR}/opencascade/TKGeomBase.dll		$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Release_BIN_DIR}/opencascade/TKG2d.dll			$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Release_BIN_DIR}/opencascade/TKShHealing.dll	$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Release_BIN_DIR}/opencascade/TKService.dll		$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Release_BIN_DIR}/opencascade/TKHLR.dll			$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Release_BIN_DIR}/opencascade/TKSTEPAttr.dll		$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Release_BIN_DIR}/opencascade/TKSTEP209.dll		$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Release_BIN_DIR}/opencascade/TKSTEPBase.dll		$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Release_BIN_DIR}/opencascade/TKBool.dll			$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Release_BIN_DIR}/opencascade/TKPrim.dll			$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Release_BIN_DIR}/opencascade/TKBO.dll			$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>

		COMMAND ${CMAKE_COMMAND} -E copy ${ExternalLibrary_Release_BIN_DIR}/opencascadeRely/freetype.dll	$<TARGET_FILE_DIR:${CURRENT_PROJECT_NAME}>
	)
endif()


#===============================================================================

enable_testing()

add_test(NAME UTest_${CURRENT_PROJECT_NAME}
	COMMAND $<TARGET_FILE:${CURRENT_PROJECT_NAME}> -s)

include(Catch)
catch_discover_tests(${CURRENT_PROJECT_NAME})