cmake_minimum_required(VERSION 3.20)


set(TBB_SRC_DIR         ${CMAKE_SOURCE_DIR}/3rd_party_libraries/tbb-src)
set(TBB_STATE_DIR       ${CMAKE_BINARY_DIR}/tbb-state)
set(TBB_INSTALL_DIR     ${3RD_PARTY_DIR}/tbb-install)


set(GIT_REPO_NAME           oneTBB)
set(GIT_REPO_URL            https://github.com/uxlfoundation/oneTBB.git)
set(GIT_TAG_OR_BRANCH       v2022.1.0)
set(GIT_CLONE_DEPTH         10)

#===================================================================================================

find_program(GIT_EXECUTABLE git REQUIRED)
if (NOT EXISTS ${TBB_SRC_DIR}/.git)
    message(STATUS "It is now git-cloning (shallow) the ${GIT_REPO_NAME} repository...")

    execute_process(
        COMMAND ${GIT_EXECUTABLE} clone --recurse-submodules --depth=${GIT_CLONE_DEPTH} --branch=${GIT_TAG_OR_BRANCH} ${GIT_REPO_URL} ${TBB_SRC_DIR}
        WORKING_DIRECTORY       ${CMAKE_CURRENT_BINARY_DIR}
        RESULT_VARIABLE         git_clone_result
    )

    if (NOT git_clone_result EQUAL 0)
        message(FATAL_ERROR "Failed to git clone the ${GIT_REPO_NAME} repository!")
    endif()
else()
    execute_process(
        COMMAND ${GIT_EXECUTABLE} -C ${TBB_SRC_DIR} describe --tags --exact-match HEAD
        OUTPUT_VARIABLE     current_version_tag
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    if (NOT ${current_version_tag} STREQUAL ${GIT_TAG_OR_BRANCH})
        message(STATUS "Switching ${GIT_REPO_NAME} to ${GIT_TAG_OR_BRANCH}...")

        execute_process(
            COMMAND ${GIT_EXECUTABLE} -C ${TBB_SRC_DIR} fetch --depth=${GIT_CLONE_DEPTH} origin ${GIT_TAG_OR_BRANCH}:${GIT_TAG_OR_BRANCH}
            COMMAND ${GIT_EXECUTABLE} -C ${TBB_SRC_DIR} checkout ${GIT_TAG_OR_BRANCH}
            RESULT_VARIABLE result
        )
        if (NOT result EQUAL 0)
            message(STATUS "Failed to switch to your expected ${GIT_TAG_OR_BRANCH}")
        endif()
    endif()
endif()

#===================================================================================================

include(ExternalProject)

ExternalProject_Add(TBB
    PREFIX                  ${TBB_STATE_DIR}
    SOURCE_DIR              ${TBB_SRC_DIR}
    DOWNLOAD_COMMAND        ""
    GIT_CONFIG              "core.worktree=${TBB_SRC_DIR}"
    UPDATE_DISCONNECTED     TRUE
    CMAKE_ARGS
        -DCMAKE_BUILD_TYPE=Release
        -DBUILD_SHARED_LIBS=ON
        -DCMAKE_INSTALL_PREFIX=${TBB_INSTALL_DIR}
        -DTBB_TEST=OFF
        -DTBB_CONTROL_FLOW_GUARD=ON
    BUILD_ALWAYS            TRUE
    STEP_TARGETS            install
)


set(TBB_INCLUDE_DIR     ${TBB_INSTALL_DIR}/include)
set(TBB_LIB_DIR         ${TBB_INSTALL_DIR}/lib)