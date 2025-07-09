cmake_minimum_required(VERSION 3.20)


set(TINYXML2_SRC_DIR		${CMAKE_SOURCE_DIR}/3rd_party_libraries/tinyxml2-src)
set(TINYXML2_STATE_DIR		${CMAKE_BINARY_DIR}/tinyxml2-state)
set(TINYXML2_INSTALL_DIR	${CMAKE_BINARY_DIR}/tinyxml2-install)


if (NOT EXISTS "${TINYXML2_SRC_DIR}/.git")
	message(STATUS "Initialize the tinyxml2 repository downloading...")

	file(MAKE_DIRECTORY ${TINYXML2_SRC_DIR})

	if (${CMAKE_SYSTEM_NAME} STREQUAL "Windows" AND MSVC)
		set(GIT_EXECUTABLE "C:/Program Files/Git/cmd/git.exe")
		# find_program(GIT_EXECUTABLE NAMES git git.exe REQUIRED)
	elseif (${CMAKE_SYSTEM_NAMME} STREQUAL "Linux")
		find_program(GIT_EXECUTABLE git REQUIRED)
	endif()

	message(STATUS "GIT_EXECUTABLE = ${GIT_EXECUTABLE}")

	set(GIT_TAG		10.0.0)

	execute_process(
		COMMAND ${GIT_EXECUTABLE} clone --depth 10 --branch ${GIT_TAG} https://github.com/leethomason/tinyxml2.git ${TINYXML2_SRC_DIR}
		WORKING_DIRECTORY		${CMAKE_CURRENT_BINARY_DIR}
		RESULT_VARIABLE			GIT_CLONE_RESULT
	)

	if (NOT GIT_CLONE_RESULT EQUAL 0)
		message(FATAL_ERROR "Failed to git clone the tinyxml2 repository.")
	endif()
endif()


include(ExternalProject)

ExternalProject_Add(TinyXml2
	PREFIX					${TINYXML2_STATE_DIR}
	SOURCE_DIR				${TINYXML2_SRC_DIR}
	DOWNLOAD_COMMAND		""
	GIT_CONFIG				"core.worktree=${TINYXML2_SRC_DIR}"
	UPDATE_DISCONNECTED		ON
	CMAKE_ARGS
		-DCMAKE_BUILD_TYPE=Release
		-DBUILD_SHARED_LIBS=ON
		-DCMAKE_INSTALL_PREFIX=${TINYXML2_INSTALL_DIR}
	BUILD_ALWAYS			ON
	STEP_TARGETS			install
)

set(TINYXML2_INCLUDE_DIR		${TINYXML2_INSTALL_DIR}/include)
set(TINYXML2_LIB_DIR			${TINYXML2_INSTALL_DIR}/lib)