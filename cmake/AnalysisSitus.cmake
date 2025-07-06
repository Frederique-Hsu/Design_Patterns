cmake_minimum_required(VERSION 3.20)


include(ExternalProject)

set(AnalysisSitus_SRC_DIR       ${CMAKE_SOURCE_DIR}/3rd_party_libraries/AnalysisSitus-src)
set(AnalysisSitus_BUILD_DIR     ${CMAKE_BINARY_DIR}/AnalysisSitus-build)
set(AnalysisSitus_INSTALL_DIR   ${CMAKE_BINARY_DIR}/AnalysisSitus-install)
set(AnalysisSitus_DOWNLOAD_DIR  ${CMAKE_BINARY_DIR}/AnalysisSitus-download)


ExternalProject_Add(AnalysisSitus
    # GIT_REPOSITORY              https://gitlab.com/ssv/AnalysisSitus.git
    GIT_REPOSITORY              https://github.com/Frederique-Hsu/AnalysisSitus.git
    # GIT_TAG                     v2024.2.1 
    # GIT_TAG                     v2025.1
    GIT_TAG                     user-specify-VTK-version-number
    GIT_SHALLOW                 TRUE
    GIT_PROGRESS                TRUE
    SOURCE_DIR                  ${AnalysisSitus_SRC_DIR}
    BINARY_DIR                  ${AnalysisSitus_BUILD_DIR}
    DOWNLOAD_DIR                ${AnalysisSitus_DOWNLOAD_DIR}
    UPDATE_DISCONNECTED         TRUE
    CMAKE_ARGS
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        -DBUILD_SHARED_LIBS=ON
        -DCMAKE_INSTALL_PREFIX=${AnalysisSitus_INSTALL_DIR}
        -D3RDPARTY_DIR=/usr/lib
        -DINSTALL_DIR=${AnalysisSitus_INSTALL_DIR}
        -DCMAKE_CXX_STANDARD=17
        -DCMAKE_CXX_STANDARD_REQUIRED=ON

        -DVTK_MAJOR_VERSION=9
        -DVTK_MINOR_VERSION=2
        
        -D3RDPARTY_EIGEN_DIR=${Eigen_INSTALL_DIR}/include
        # -DEigen3_DIR=

        -D3RDPARTY_OCCT_DIR=${OCCT_INSTALL_DIR}
        -D3RDPARTY_OCCT_INCLUDE_DIR=${OCCT_INSTALL_DIR}/include/opencascade
        -D3RDPARTY_OCCT_LIBRARY_DIR=${OCCT_INSTALL_DIR}/lib

        # -D3RDPARTY_vtk_INCLUDE_DIR=/usr/include/vtk-9.1
        # -D3RDPARTY_vtk_LIBRARY_DIR=/usr/lib/x86_64-linux-gnu

        -D3RDPARTY_vtk_DIR=${VTK_INSTALL_DIR}
        -D3RDPARTY_vtk_INCLUDE_DIR=${VTK_INSTALL_DIR}/include/vtk-9.2
        -D3RDPARTY_vtk_LIBRARY_DIR=${VTK_INSTALL_DIR}/lib

        -D3RDPARTY_tcl_INCLUDE_DIR=/usr/include/tcl8.6
        -D3RDPARTY_tcl_LIBRARY_DIR=/usr/lib/x86_64-linux-gnu

        -D3RDPARTY_freetype_INCLUDE_DIR=/usr/include/freetype2
        -D3RDPARTY_freetype_LIBRARY_DIR=/usr/lib/x86_64-linux-gnu

    BUILD_ALWAYS                TRUE
    STEP_TARGETS                install
)

add_dependencies(AnalysisSitus OCCT VTK)