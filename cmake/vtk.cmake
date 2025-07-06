cmake_minimum_required(VERSION 3.20)


include(ExternalProject)

set(VTK_SRC_DIR             ${CMAKE_SOURCE_DIR}/3rd_party_libraries/vtk-src)
set(VTK_BUILD_DIR           ${CMAKE_BINARY_DIR}/vtk-build)
set(VTK_INSTALL_DIR         ${CMAKE_BINARY_DIR}/vtk-install)
set(VTK_DOWNLOAD_DIR        ${CMAKE_BINARY_DIR}/vtk-download)

ExternalProject_Add(VTK
    GIT_REPOSITORY          https://gitlab.kitware.com/vtk/vtk.git
    # GIT_REPOSITORY          https://github.com/Frederique-Hsu/VTK.git
    # GIT_TAG                 v8.2.0  
    # GIT_TAG                 v9.4.2
    # GIT_TAG                 v9.1.0 
    # GIT_TAG                 v9.0.0
    GIT_TAG                 v9.2.2
    # GIT_TAG                 fix_compilation_error_for_vtk9.1.0
    GIT_SHALLOW             TRUE
    GIT_PROGRESS            TRUE
    SOURCE_DIR              ${VTK_SRC_DIR}
    BINARY_DIR              ${VTK_BUILD_DIR}
    DOWNLOAD_DIR            ${VTK_DOWNLOAD_DIR}
    UPDATE_DISCONNECTED     TRUE
    CMAKE_ARGS
        -DCMAKE_BUILD_TYPE=Release
        -DBUILD_SHARED_LIBS=ON
        -DCMAKE_INSTALL_PREFIX=${VTK_INSTALL_DIR}
        -DCMAKE_CXX_STANDARD=17
        -DCMAKE_CXX_STANDARD_REQUIRED=ON
        -DCMAKE_CXX_EXTENSIONS=ON

        -DBUILD_TESTING=OFF
        -DVTK_QT_VERSION=6
        -DVTK_GROUP_ENABLE_Qt=YES
        # -DVTK_GROUP_ENABLE_Imaging=YES
        -DVTK_GROUP_ENABLE_Views=YES
        -DVTK_GROUP_ENABLE_Rendering=YES

        -DVTK_MODULE_ENABLE_VTK_GUISupportQtQuick=NO
    BUILD_ALWAYS            TRUE
    STEP_TARGETS            install
)