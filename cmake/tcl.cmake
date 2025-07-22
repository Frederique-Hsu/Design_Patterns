cmake_minimum_required(VERSION 3.20)


set(TCL_SRC_DIR             ${CMAKE_SOURCE_DIR}/3rd_party_libraries/tcl-src)
set(TCL_STATE_DIR           ${CMAKE_BINARY_DIR}/tcl-state)
set(TCL_INSTALL_DIR         ${3RD_PARTY_DIR}/tcl-install)


set(GIT_REPO_NAME           Tcl)
set(GIT_REPO_URL            https://github.com/tcltk/tcl.git)
set(GIT_TAG_OR_BRANCH       core-8-6-16)
set(GIT_CLONE_DEPTH         10)

#===================================================================================================

find_program(GIT_EXECUTABLE git REQUIRED)
if (NOT EXISTS ${TCL_SRC_DIR}/.git)
    message(STATUS "It is now git-cloning (shallow) the ${GIT_REPO_NAME} repository...")

    execute_process(
        COMMAND ${GIT_EXECUTABLE} clone --recurse-submodules --depth=${GIT_CLONE_DEPTH} --branch=${GIT_TAG_OR_BRANCH} ${GIT_REPO_URL} ${TCL_SRC_DIR}
        WORKING_DIRECTORY       ${CMAKE_CURRENT_BINARY_DIR}
        RESULT_VARIABLE         git_clone_result
    )

    if (NOT git_clone_result EQUAL 0)
        message(FATAL_ERROR "Failed to git clone the ${GIT_REPO_NAME} repository!")
    endif()
else()
    execute_process(
        COMMAND ${GIT_EXECUTABLE} -C ${TCL_SRC_DIR} describe --tags --exact-match HEAD
        OUTPUT_VARIABLE     current_version_tag
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    if (NOT ${current_version_tag} STREQUAL ${GIT_TAG_OR_BRANCH})
        message(STATUS "Switching ${GIT_REPO_NAME} to ${GIT_TAG_OR_BRANCH}...")

        execute_process(
            COMMAND ${GIT_EXECUTABLE} -C ${TCL_SRC_DIR} fetch --depth=${GIT_CLONE_DEPTH} origin ${GIT_TAG_OR_BRANCH}:${GIT_TAG_OR_BRANCH}
            COMMAND ${GIT_EXECUTABLE} -C ${TCL_SRC_DIR} checkout ${GIT_TAG_OR_BRANCH}
            RESULT_VARIABLE result
        )
        if (NOT result EQUAL 0)
            message(STATUS "Failed to switch to your expected ${GIT_TAG_OR_BRANCH}")
        endif()
    endif()
endif()

#===================================================================================================

include(ExternalProject)

ExternalProject_Add(Tcl
    PREFIX                  ${TCL_STATE_DIR}
    SOURCE_DIR              ${TCL_SRC_DIR}
    DOWNLOAD_COMMAND        ""
    GIT_CONFIG              "core.worktree=${TCL_SRC_DIR}"
    UPDATE_DISCONNECTED     TRUE

    # 以下一些命令，不需要用""给引用起来。 引用起来反而会出错。
    CONFIGURE_COMMAND       ${TCL_SRC_DIR}/unix/configure --enable-shared --enable-64bit --prefix=${TCL_INSTALL_DIR}
    BUILD_COMMAND           make -j 8
    INSTALL_COMMAND         make install

    BUILD_ALWAYS            TRUE
    STEP_TARGETS            install
)


set(TCL_INCLUDE_DIR     ${TCL_INSTALL_DIR}/include)
set(TCL_LIB_DIR         ${TCL_INSTALL_DIR}/lib)