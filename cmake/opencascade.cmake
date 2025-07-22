cmake_minimum_required(VERSION 3.20)

message(STATUS "current path is ${CMAKE_CURRENT_LIST_DIR}")


set(3RD_PARTY_DIR       ${CMAKE_BINARY_DIR}/3RD_PARTY_DIR)


include(${CMAKE_CURRENT_LIST_DIR}/tcl.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/tk.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/freetype.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/tbb.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/freeimage.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/vtk.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/rapidjson.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/draco.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/ffmpeg.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/openvr.cmake)


set(OCCT_SRC_DIR            ${CMAKE_SOURCE_DIR}/3rd_party_libraries/occt-src)
set(OCCT_STATE_DIR          ${CMAKE_BINARY_DIR}/occt-state)
set(OCCT_INSTALL_DIR        ${CMAKE_BINARY_DIR}/occt-install)

set(GIT_REPO_NAME           OpenCASCADE)
set(GIT_REPO_URL            https://git.dev.opencascade.org/repos/occt.git)
set(GIT_TAG_OR_BRANCH       V7_9_0)
set(GIT_CLONE_DEPTH         10)

#===================================================================================================

find_program(GIT_EXECUTABLE git REQUIRED)
if (NOT EXISTS ${OCCT_SRC_DIR}/.git)
    message(STATUS "It is now git-cloning (shallow) the OCCT repository...")

    execute_process(
        COMMAND ${GIT_EXECUTABLE} clone --recurse-submodules --depth=${GIT_CLONE_DEPTH} --branch=${GIT_TAG_OR_BRANCH} ${GIT_REPO_URL} ${OCCT_SRC_DIR}
        WORKING_DIRECTORY       ${CMAKE_CURRENT_BINARY_DIR}
        RESULT_VARIABLE         git_clone_result
    )

    if (NOT git_clone_result EQUAL 0)
        message(FATAL_ERROR "Failed to git clone the ${GIT_REPO_NAME} repository!")
    endif()
else()
    execute_process(
        COMMAND ${GIT_EXECUTABLE} -C ${OCCT_SRC_DIR} describe --tags --exact-match HEAD
        OUTPUT_VARIABLE     current_version_tag
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    if (NOT ${current_version_tag} STREQUAL ${GIT_TAG_OR_BRANCH})
        message(STATUS "Switching ${GIT_REPO_NAME} to ${GIT_TAG_OR_BRANCH}...")

        execute_process(
            COMMAND ${GIT_EXECUTABLE} -C ${OCCT_SRC_DIR} fetch --depth=${GIT_CLONE_DEPTH} origin ${GIT_TAG_OR_BRANCH}:${GIT_TAG_OR_BRANCH}
            COMMAND ${GIT_EXECUTABLE} -C ${OCCT_SRC_DIR} checkout ${GIT_TAG_OR_BRANCH}
            RESULT_VARIABLE result
        )
        if (NOT result EQUAL 0)
            message(STATUS "Failed to switch to your expected ${GIT_TAG_OR_BRANCH}")
        endif()
    endif()
endif()

#===================================================================================================

include(ExternalProject)

ExternalProject_Add(OCCT
    PREFIX                  ${OCCT_STATE_DIR}
    SOURCE_DIR              ${OCCT_SRC_DIR}
    DOWNLOAD_COMMAND        ""
    GIT_CONFIG              "core.worktree=${OCCT_STATE_DIR}"
    UPDATE_DISCONNECTED     TRUE
    CMAKE_ARGS
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        -DBUILD_SHARED_LIBS=ON
        -DCMAKE_INSTALL_PREFIX=${OCCT_INSTALL_DIR}

        -D3RDPARTY_DIR=${3RD_PARTY_DIR}

        -DUSE_FREETYPE=ON
        -D3RDPARTY_FREETYPE_DIR=${FreeType_INSTALL_DIR}
        
        -DUSE_TK=ON

        -DUSE_FREEIMAGE=ON

        -DUSE_TBB=ON

        -DUSE_OPENGL=ON
        -DUSE_VTK=ON

        -DUSE_RAPIDJSON=ON
        -DUSE_DRACO=ON
        # -DUSE_FFMPEG=ON

        -DUSE_OPENVR=ON
        -D3RDPARTY_OPENVR_INCLUDE_DIR=${OpenVR_INCLUDE_DIR}/openvr

        -DBUILD_RESOURCES=ON
        -DBUILD_SAMPLES_QT=ON
        -DINSTALL_SAMPLES=ON
    BUILD_ALWAYS            TRUE
    STEP_TARGETS            install
)

add_dependencies(OCCT 
    Tcl 
    Tk
    FreeType
    TBB
    FreeImage
    VTK
    RapidJSON
    DRACO
    FFmpeg
    OpenVR
)

set(OCCT_INCLUDE_DIR    ${OCCT_INSTALL_DIR}/include)
set(OCCT_LIB_DIR        ${OCCT_INSTALL_DIR}/lib)