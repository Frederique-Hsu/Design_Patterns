cmake_minimum_required(VERSION 3.20)

set(BOOST_SRC_DIR			${CMAKE_SOURCE_DIR}/3rd_party_libraries/boost-src)
set(BOOST_STATE_DIR			${CMAKE_BINARY_DIR}/boost-state)
set(BOOST_INSTALL_DIR		${CMAKE_BINARY_DIR}/boost-install)


if (NOT EXISTS "${BOOST_SRC_DIR}/.git")
	message(STATUS "Initial the boost repo downloading...")

	file(MAKE_DIRECTORY ${BOOST_SRC_DIR})

	if (${CMAKE_SYSTEM_NAME} STREQUAL "Windows" AND MSVC)
		set(GIT_EXECUTABLE "C:/Program Files/Git/cmd/git.exe")
		# find_program(GIT_EXECUTABLE NAMES git git.exe REQUIRED)
	elseif (${CMAKE_SYSTEM_NAMME} STREQUAL "Linux")
		find_program(GIT_EXECUTABLE git REQUIRED)
	endif()

	message(STATUS "GIT_EXECUTABLE = ${GIT_EXECUTABLE}")

	set(GIT_TAG		boost-1.86.0)

	execute_process(
		COMMAND ${GIT_EXECUTABLE} clone --recurse-submodules --depth 10 --branch ${GIT_TAG} https://github.com/boostorg/boost.git ${BOOST_SRC_DIR}
		WORKING_DIRECTORY		${CMAKE_CURRENT_BINARY_DIR}
		RESULT_VARIABLE			GIT_CLONE_RESULT
	)

	if (NOT GIT_CLONE_RESULT EQUAL 0)
		message(FATAL_ERROR "Failed to git clone boost repository.")
	endif()
endif()


include(ExternalProject)

ExternalProject_Add(Boost
	PREFIX					${BOOST_STATE_DIR}
	SOURCE_DIR				${BOOST_SRC_DIR}
	DOWNLOAD_COMMAND		""
	GIT_CONFIG				"core.worktree=${BOOST_SRC_DIR}"
	UPDATE_DISCONNECTED		ON
	CMAKE_ARGS
		-DCMAKE_BUILD_TYPE=Debug
		-DBUILD_SHARED_LIBS=OFF
		-DCMAKE_INSTALL_PREFIX=${BOOST_INSTALL_DIR}
	BUILD_ALWAYS			ON
	LOG_BUILD				ON
	STEP_TARGETS			install
)

set(BOOST_INCLUDE_DIR		${BOOST_INSTALL_DIR}/include)
set(BOOST_LIB_DIR			${BOOST_INSTALL_DIR}/lib)