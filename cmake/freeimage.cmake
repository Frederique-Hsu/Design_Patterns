cmake_minimum_required(VERSION 3.20)


set(FreeImage_SRC_DIR           ${CMAKE_SOURCE_DIR}/3rd_party_libraries/freeimage-src)
set(FreeImage_STATE_DIR         ${CMAKE_BINARY_DIR}/freeimage-state)
set(FreeImage_BUILD_DIR         ${FreeImage_STATE_DIR}/src/FreeImage-build)
set(FreeImage_INSTALL_DIR       ${3RD_PARTY_DIR}/freeimage-install)

set(GIT_REPO_NAME           FreeImage)
set(GIT_REPO_URL            https://github.com/danoli3/FreeImage.git)
set(GIT_TAG_OR_BRANCH       3.19.10)
set(GIT_CLONE_DEPTH         10)

#===================================================================================================

find_program(GIT_EXECUTABLE git REQUIRED)
if (NOT EXISTS ${FreeImage_SRC_DIR}/.git)
    message(STATUS "git cloning shallowly the ${GIT_REPO_NAME} repository...")

    execute_process(
        COMMAND ${GIT_EXECUTABLE} clone --recurse-submodules --depth=${GIT_CLONE_DEPTH} --branch=${GIT_TAG_OR_BRANCH} ${GIT_REPO_URL} ${FreeImage_SRC_DIR}
        WORKING_DIRECTORY   ${CMAKE_CURRENT_BINARY_DIR}
        RESULT_VARIABLE     git_clone_result
    )
    if (NOT git_clone_result EQUAL 0)
        message(FATAL_ERROR "Failed to git clone the ${GIT_REPO_NAME} repository!")
    endif()
else()
    execute_process(
        COMMAND ${GIT_EXECUTABLE} -C ${FreeImage_SRC_DIR} describe --tags --exact-match HEAD
        OUTPUT_VARIABLE     current_version_tag
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    if (NOT ${current_version_tag} STREQUAL ${GIT_TAG_OR_BRANCH})
        message(STATUS "Switching ${GIT_REPO_NAME} to ${GIT_TAG_OR_BRANCH}")

        execute_process(
            COMMAND ${GIT_EXECUTABLE} -C ${FreeImage_SRC_DIR} fetch --depth=${GIT_CLONE_DEPTH} origin ${GIT_TAG_OR_BRANCH}:${GIT_TAG_OR_BRANCH}
            COMMAND ${GIT_EXECUTABLE} -C ${FreeImage_SRC_DIR} checkout ${GIT_TAG_OR_BRANCH}
            RESULT_VARIABLE result
        )
        if (NOT result EQUAL 0)
            message(STATUS "Failed to switch to your expected ${GIT_TAG_OR_BRANCH}")
        endif()
    endif()
endif()

#===================================================================================================

include(ExternalProject)

ExternalProject_Add(FreeImage
    PREFIX                      ${FreeImage_STATE_DIR}
    SOURCE_DIR                  ${FreeImage_SRC_DIR}
    DOWNLOAD_COMMAND            ""
    GIT_CONFIG                  "core.worktree=${FreeImage_SRC_DIR}"
    UPDATE_DISCONNECTED         TRUE
    CMAKE_ARGS
        -DCMAKE_BUILD_TYPE=Release
        -DBUILD_SHARED_LIBS=ON
        -DCMAKE_INSTALL_PREFIX=${FreeImage_INSTALL_DIR}
    BUILD_ALWAYS                TRUE
    INSTALL_COMMAND             ${CMAKE_COMMAND} --install ${FreeImage_BUILD_DIR} && 
                                ${CMAKE_COMMAND} -E rename ${FreeImage_INSTALL_DIR}/lib/libFreeImage.so ${FreeImage_INSTALL_DIR}/lib/libfreeimage.so
    STEP_TARGETS                install
)

set(FreeImage_INCLUDE_DIR       ${FreeImage_INSTALL_DIR})
set(FreeImage_LIB_DIR           ${FreeImage_INSTALL_DIR}/lib)