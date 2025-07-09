cmake_minimum_required(VERSION 3.20)

set(GTest_SOURCE_DIR	${CMAKE_SOURCE_DIR}/3rd_party_libraries/googletest-src)

if (Retrieve_Dependencies_By_ExternalProject)

	include(ExternalProject)

	set(GTest_BUILD_DIR		${CMAKE_BINARY_DIR}/googletest-build)
	set(GTest_INSTALL_DIR	${CMAKE_BINARY_DIR}/googletest-install)
	set(GTest_DOWNLOAD_DIR	${CMAKE_BINARY_DIR}/googletest-download)

	ExternalProject_Add(googletest
		GIT_REPOSITORY			https://github.com/google/googletest.git
		GIT_TAG					main
		GIT_SHALLOW				TRUE
		GIT_PROGRESS			TRUE
		SOURCE_DIR				${GTest_SOURCE_DIR}
		BINARY_DIR				${GTest_BUILD_DIR}
		DOWNLOAD_DIR			${GTest_DOWNLOAD_DIR}
		# 设定为FALSE时，则每次编译时都去拉取更新代码，网络不通时就会报错。
		# 若设定为TRUE时，就不会去拉取更新代码，即使网络不通也会成功编译。
		UPDATE_DISCONNECTED		TRUE	
		CMAKE_ARGS
			-DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
			-DBUILD_SHARED_LIBS=ON
			-DCMAKE_INSTALL_PREFIX=${GTest_INSTALL_DIR}
		# 设定为TRUE, 若当前项目代码有任何修改，就重新编译。 设定为FALSE则不重新编译。
		BUILD_ALWAYS			TRUE	
		STEP_TARGETS			install
	)

else()

	include(FetchContent)

	set(FETCHCONTENT_UPDATES_DISCONNECTED	TRUE)	# 设置为TRUE，使得不必每次编译时拉取更新代码

	FetchContent_Declare(googletest
		GIT_REPOSITORY			https://github.com/google/googletest.git
		GIT_TAG					main
		GIT_SHALLOW				TRUE
		GIT_PROGRESS			TRUE
		SOURCE_DIR				${GTest_SOURCE_DIR}
	)
	FetchContent_MakeAvailable(googletest)

endif()