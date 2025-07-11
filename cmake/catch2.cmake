cmake_minimum_required(VERSION 3.20)


include(FetchContent)

set(FETCHCONTENT_UPDATES_DISCONNECTED	TRUE)

set(Catch2_SRC_DIR		${CMAKE_SOURCE_DIR}/3rd_party_libraries/catch2-src)

FetchContent_Declare(Catch2
	GIT_REPOSITORY		https://github.com/catchorg/Catch2.git
	GIT_TAG				v3.8.1
	GIT_SHALLOW			TRUE
	GIT_PROGRESS		TRUE
	SOURCE_DIR			${Catch2_SRC_DIR}
)
FetchContent_MakeAvailable(Catch2)