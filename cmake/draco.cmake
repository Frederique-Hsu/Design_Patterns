cmake_minimum_required(VERSION 3.20)

SET(DRACO_SRC_DIR           ${CMAKE_SOURCE_DIR}/3rd_party_libraries/draco-src)
set(DRACO_STATE_DIR         ${CMAKE_BINARY_DIR}/draco-state)
set(DRACO_INSTALL_DIR       ${3RD_PARTY_DIR}/draco-install)

set(GIT_REPO_NAME           DRACO)
set(GIT_REPO_URL            https://github.com/google/draco.git)
set(GIT_TAG_OR_BRANCH       1.5.6)
set(GIT_CLONE_DEPTH         10)


#===================================================================================================

find_program(GIT_EXECUTABLE git REQUIRED)
if (NOT EXISTS ${DRACO_SRC_DIR}/.git)
    message(STATUS "git cloning shallowly the ${GIT_REPO_NAME} repository...")

    execute_process(
        COMMAND ${GIT_EXECUTABLE} clone --recurse-submodules --depth=${GIT_CLONE_DEPTH} --branch=${GIT_TAG_OR_BRANCH} ${GIT_REPO_URL} ${DRACO_SRC_DIR}
        WORKING_DIRECTORY   ${CMAKE_CURRENT_BINARY_DIR}
        RESULT_VARIABLE     git_clone_result
    )
    if (NOT git_clone_result EQUAL 0)
        message(FATAL_ERROR "Failed to git clone the ${GIT_REPO_NAME} repository!")
    endif()
else()
    execute_process(
        COMMAND ${GIT_EXECUTABLE} -C ${DRACO_SRC_DIR} describe --tags --exact-match HEAD
        OUTPUT_VARIABLE     current_version_tag
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    if (NOT ${current_version_tag} STREQUAL ${GIT_TAG_OR_BRANCH})
        message(STATUS "Switching ${GIT_REPO_NAME} to ${GIT_TAG_OR_BRANCH}")

        execute_process(
            COMMAND ${GIT_EXECUTABLE} -C ${DRACO_SRC_DIR} fetch --depth=${GIT_CLONE_DEPTH} origin ${GIT_TAG_OR_BRANCH}:${GIT_TAG_OR_BRANCH}
            COMMAND ${GIT_EXECUTABLE} -C ${DRACO_SRC_DIR} checkout ${GIT_TAG_OR_BRANCH}
            RESULT_VARIABLE result
        )
        if (NOT result EQUAL 0)
            message(STATUS "Failed to switch to your expected ${GIT_TAG_OR_BRANCH}")
        endif()
    endif()
endif()

#===================================================================================================

include(ExternalProject)

ExternalProject_Add(DRACO
    PREFIX                      ${DRACO_STATE_DIR}
    SOURCE_DIR                  ${DRACO_SRC_DIR}
    DOWNLOAD_COMMAND            ""
    GIT_CONFIG                  "core.worktree=${DRACO_SRC_DIR}"
    UPDATE_DISCONNECTED         TRUE
    CMAKE_ARGS
        -DCMAKE_BUILD_TYPE=Release
        -DBUILD_SHARED_LIBS=ON
        -DCMAKE_INSTALL_PREFIX=${DRACO_INSTALL_DIR}
    BUILD_ALWAYS                TRUE
    STEP_TARGETS                install
)


set(DRACO_INCLUDE_DIR       ${DRACO_INSTALL_DIR}/include)
set(DRACO_LIB_DIR           ${DRACO_INSTALL_DIR}/lib)