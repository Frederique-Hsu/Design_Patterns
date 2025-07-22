cmake_minimum_required(VERSION 3.20)


set(VTK_SRC_DIR             ${CMAKE_SOURCE_DIR}/3rd_party_libraries/vtk-src)
set(VTK_STATE_DIR           ${CMAKE_BINARY_DIR}/vtk-state)
set(VTK_INSTALL_DIR         ${3RD_PARTY_DIR}/vtk-install)

set(GIT_REPO_NAME           VTK)
set(GIT_REPO_URL            https://gitlab.kitware.com/vtk/vtk.git)
set(GIT_TAG_OR_BRANCH       v9.2.2)
set(GIT_CLONE_DEPTH         10)


#===================================================================================================

find_program(GIT_EXECUTABLE git REQUIRED)
if (NOT EXISTS ${VTK_SRC_DIR}/.git)
    message(STATUS "git cloning shallowly the ${GIT_REPO_NAME} repository...")

    execute_process(
        COMMAND ${GIT_EXECUTABLE} clone --recurse-submodules --depth=${GIT_CLONE_DEPTH} --branch=${GIT_TAG_OR_BRANCH} ${GIT_REPO_URL} ${VTK_SRC_DIR}
        WORKING_DIRECTORY   ${CMAKE_CURRENT_BINARY_DIR}
        RESULT_VARIABLE     git_clone_result
    )
    if (NOT git_clone_result EQUAL 0)
        message(FATAL_ERROR "Failed to git clone the ${GIT_REPO_NAME} repository!")
    endif()
else()
    execute_process(
        COMMAND ${GIT_EXECUTABLE} -C ${VTK_SRC_DIR} describe --tags --exact-match HEAD
        OUTPUT_VARIABLE     current_version_tag
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    if (NOT ${current_version_tag} STREQUAL ${GIT_TAG_OR_BRANCH})
        message(STATUS "Switching ${GIT_REPO_NAME} to ${GIT_TAG_OR_BRANCH}")

        execute_process(
            COMMAND ${GIT_EXECUTABLE} -C ${VTK_SRC_DIR} fetch --depth=${GIT_CLONE_DEPTH} origin ${GIT_TAG_OR_BRANCH}:${GIT_TAG_OR_BRANCH}
            COMMAND ${GIT_EXECUTABLE} -C ${VTK_SRC_DIR} checkout ${GIT_TAG_OR_BRANCH}
            RESULT_VARIABLE result
        )
        if (NOT result EQUAL 0)
            message(STATUS "Failed to switch to your expected ${GIT_TAG_OR_BRANCH}")
        endif()
    endif()
endif()

#===================================================================================================

include(ExternalProject)

ExternalProject_Add(VTK
    # GIT_REPOSITORY          https://gitlab.kitware.com/vtk/vtk.git
    # GIT_REPOSITORY          https://github.com/Frederique-Hsu/VTK.git
    # GIT_TAG                 v8.2.0  
    # GIT_TAG                 v9.4.2
    # GIT_TAG                 v9.1.0 
    # GIT_TAG                 v9.0.0
    # GIT_TAG                 v9.2.2
    # GIT_TAG                 fix_compilation_error_for_vtk9.1.0
    PREFIX                  ${VTK_STATE_DIR}
    SOURCE_DIR              ${VTK_SRC_DIR}
    DOWNLOAD_COMMAND        ""
    GIT_CONFIG              "core.worktree=${VTK_SRC_DIR}"
    UPDATE_DISCONNECTED     TRUE
    CMAKE_ARGS
        -DCMAKE_BUILD_TYPE=Release
        -DBUILD_SHARED_LIBS=ON
        -DCMAKE_INSTALL_PREFIX=${VTK_INSTALL_DIR}
        -DCMAKE_CXX_STANDARD=17
        -DCMAKE_CXX_STANDARD_REQUIRED=ON
        -DCMAKE_CXX_EXTENSIONS=ON

        # -DBUILD_TESTING=OFF
        -DVTK_QT_VERSION=5
        -DVTK_GROUP_ENABLE_Qt=YES
        -DVTK_GROUP_ENABLE_Imaging=YES
        -DVTK_GROUP_ENABLE_Views=YES
        -DVTK_GROUP_ENABLE_Rendering=YES

        # -DVTK_MODULE_ENABLE_VTK_GUISupportQtQuick=NO
    BUILD_ALWAYS            TRUE
    STEP_TARGETS            install
)

set(VTK_INCLUDE_DIR         ${VTK_INSTALL_DIR}/include)
set(VTK_LIB_DIR             ${VTK_INSTALL_DIR}/lib)