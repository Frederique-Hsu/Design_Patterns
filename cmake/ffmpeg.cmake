cmake_minimum_required(VERSION 3.20)


set(FFmpeg_SRC_DIR          ${CMAKE_SOURCE_DIR}/3rd_party_libraries/ffmpeg-src)
set(FFmpeg_STATE_DIR        ${CMAKE_BINARY_DIR}/ffmpeg-state)
set(FFmpeg_INSTALL_DIR      ${3RD_PARTY_DIR}/ffmpeg-install)


set(GIT_REPO_NAME       FFmpeg)
set(GIT_REPO_URL        https://git.ffmpeg.org/ffmpeg.git)
set(GIT_TAG_OR_BRANCH   master)


#===================================================================================================

find_program(GIT_EXECUTABLE git REQUIRED)
if (NOT EXISTS ${FFmpeg_SRC_DIR}/.git)
    message(STATUS "git cloning shallowly the ${GIT_REPO_NAME} repository...")

    execute_process(
        COMMAND ${GIT_EXECUTABLE} clone --recurse-submodules --depth=${GIT_CLONE_DEPTH} --branch=${GIT_TAG_OR_BRANCH} ${GIT_REPO_URL} ${FFmpeg_SRC_DIR}
        WORKING_DIRECTORY   ${CMAKE_CURRENT_BINARY_DIR}
        RESULT_VARIABLE     git_clone_result
    )
    if (NOT git_clone_result EQUAL 0)
        message(FATAL_ERROR "Failed to git clone the ${GIT_REPO_NAME} repository!")
    endif()
else()
    execute_process(
        COMMAND ${GIT_EXECUTABLE} -C ${FFmpeg_SRC_DIR} describe --tags --exact-match HEAD
        OUTPUT_VARIABLE     current_version_tag
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    if (NOT ${current_version_tag} STREQUAL ${GIT_TAG_OR_BRANCH})
        message(STATUS "Switching ${GIT_REPO_NAME} to ${GIT_TAG_OR_BRANCH}")

        execute_process(
            COMMAND ${GIT_EXECUTABLE} -C ${FFmpeg_SRC_DIR} fetch --depth=${GIT_CLONE_DEPTH} origin ${GIT_TAG_OR_BRANCH}:${GIT_TAG_OR_BRANCH}
            COMMAND ${GIT_EXECUTABLE} -C ${FFmpeg_SRC_DIR} checkout ${GIT_TAG_OR_BRANCH}
            RESULT_VARIABLE result
        )
        if (NOT result EQUAL 0)
            message(STATUS "Failed to switch to your expected ${GIT_TAG_OR_BRANCH}")
        endif()
    endif()
endif()

#===================================================================================================

include(ExternalProject)

ExternalProject_Add(FFmpeg
    PREFIX                  ${FFmpeg_STATE_DIR}
    SOURCE_DIR              ${FFmpeg_SRC_DIR}
    DOWNLOAD_COMMAND        ""
    GIT_CONFIG              "core.worktree=${FFmpeg_SRC_DIR}"
    UPDATE_DISCONNECTED     TRUE

    CONFIGURE_COMMAND       ${FFmpeg_SRC_DIR}/configure --disable-x86asm --enable-shared --prefix=${FFmpeg_INSTALL_DIR}
    BUILD_COMMAND           make -j 8
    INSTALL_COMMAND         make install
    
    BUILD_ALWAYS            TRUE
    STEP_TARGETS            install
)

set(FFmpeg_INCLUDE_DIR      ${FFmpeg_INSTALL_DIR}/include)
set(FFmpeg_LIB_DIR          ${FFmpeg_INSTALL_DIR}/lib)