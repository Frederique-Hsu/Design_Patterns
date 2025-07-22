cmake_minimum_required(VERSION 3.20)


set(OpenVR_SRC_DIR          ${CMAKE_SOURCE_DIR}/3rd_party_libraries/openvr-src)
set(OpenVR_STATE_DIR        ${CMAKE_BINARY_DIR}/openvr-state)
set(OpenVR_INSTALL_DIR      ${3RD_PARTY_DIR}/openvr-install)

set(GIT_REPO_NAME       OpenVR)
set(GIT_REPO_URL        https://github.com/ValveSoftware/openvr.git)
set(GIT_TAG_OR_BRANCH   v2.12.1)



#===================================================================================================

find_program(GIT_EXECUTABLE git REQUIRED)
if (NOT EXISTS ${OpenVR_SRC_DIR}/.git)
    message(STATUS "git cloning shallowly the ${GIT_REPO_NAME} repository...")

    execute_process(
        COMMAND ${GIT_EXECUTABLE} clone --recurse-submodules --depth=${GIT_CLONE_DEPTH} --branch=${GIT_TAG_OR_BRANCH} ${GIT_REPO_URL} ${OpenVR_SRC_DIR}
        WORKING_DIRECTORY   ${CMAKE_CURRENT_BINARY_DIR}
        RESULT_VARIABLE     git_clone_result
    )
    if (NOT git_clone_result EQUAL 0)
        message(FATAL_ERROR "Failed to git clone the ${GIT_REPO_NAME} repository!")
    endif()
else()
    execute_process(
        COMMAND ${GIT_EXECUTABLE} -C ${OpenVR_SRC_DIR} describe --tags --exact-match HEAD
        OUTPUT_VARIABLE     current_version_tag
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    if (NOT ${current_version_tag} STREQUAL ${GIT_TAG_OR_BRANCH})
        message(STATUS "Switching ${GIT_REPO_NAME} to ${GIT_TAG_OR_BRANCH}")

        execute_process(
            COMMAND ${GIT_EXECUTABLE} -C ${OpenVR_SRC_DIR} fetch --depth=${GIT_CLONE_DEPTH} origin ${GIT_TAG_OR_BRANCH}:${GIT_TAG_OR_BRANCH}
            COMMAND ${GIT_EXECUTABLE} -C ${OpenVR_SRC_DIR} checkout ${GIT_TAG_OR_BRANCH}
            RESULT_VARIABLE result
        )
        if (NOT result EQUAL 0)
            message(STATUS "Failed to switch to your expected ${GIT_TAG_OR_BRANCH}")
        endif()
    endif()
endif()

#===================================================================================================

include(ExternalProject)

ExternalProject_Add(OpenVR
    PREFIX                  ${OpenVR_STATE_DIR}
    SOURCE_DIR              ${OpenVR_SRC_DIR}
    DOWNLOAD_COMMAND        ""
    GIT_CONFIG              "core.worktree=${OpenVR_SRC_DIR}"
    UPDATE_DISCONNECTED     TRUE
    CMAKE_ARGS
        -DCMAKE_BUILD_TYPE=Release
        -DBUILD_SHARED_LIBS=ON
        -DCMAKE_INSTALL_PREFIX=${OpenVR_INSTALL_DIR}
    BUILD_ALWAYS            TRUE
    STEP_TARGETS            install
)

set(OpenVR_INCLUDE_DIR      ${OpenVR_INSTALL_DIR}/include)
set(OpenVR_LIB_DIR          ${OpenVR_INSTALL_DIR}/lib)