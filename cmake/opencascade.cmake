cmake_minimum_required(VERSION 3.20)

message(STATUS "current path is ${CMAKE_CURRENT_LIST_DIR}")
include(${CMAKE_CURRENT_LIST_DIR}/tcl.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/tk.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/freetype.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/tbb.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/freeimage.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/vtk.cmake)

set(OCCT_SRC_DIR            ${CMAKE_SOURCE_DIR}/3rd_party_libraries/occt-src)
set(OCCT_BUILD_DIR          ${CMAKE_BINARY_DIR}/occt-build)
set(OCCT_INSTALL_DIR        ${CMAKE_BINARY_DIR}/occt-install)
set(OCCT_DOWNLOAD_DIR       ${CMAKE_BINARY_DIR}/occt-download)

include(ExternalProject)

ExternalProject_Add(OCCT
    GIT_REPOSITORY          https://git.dev.opencascade.org/repos/occt.git
    GIT_TAG                 V7_6_0
    GIT_SHALLOW             TRUE
    GIT_PROGRESS            TRUE
    SOURCE_DIR              ${OCCT_SRC_DIR}
    BINARY_DIR              ${OCCT_BUILD_DIR}
    DOWNLOAD_DIR            ${OCCT_DOWNLOAD_DIR}
    UPDATE_DISCONNECTED     TRUE
    CMAKE_ARGS
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        -DBUILD_SHARED_LIBS=ON
        -DCMAKE_INSTALL_PREFIX=${OCCT_INSTALL_DIR}
        -DUSE_FREETYPE=ON
        # -D3RDPARTY_FREETYPE_DIR=${FreeType_INSTALL_DIR}
        # -D3RDPARTY_FREETYPE_INCLUDE_DIR_freetype2=${FreeType_INSTALL_DIR}/include/freetype2
        # -D3RDPARTY_FREETYPE_INCLUDE_DIR_ft2build=${FreeType_INSTALL_DIR}/include/freetype2
        # -D3RDPARTY_FREETYPE_LIBRARY_DIR=${FreeType_INSTALL_DIR}/lib
        
        # -D3RDPARTY_TCL_DIR=${TCL_INSTALL_DIR}
        # -D3RDPARTY_TCL_INCLUDE_DIR=${TCL_INSTALL_DIR}/include
        # -D3RDPARTY_TCL_LIBRARY_DIR=${TCL_INSTALL_DIR}/lib
        
        -DUSE_TK=ON
        # -D3RDPARTY_TK_DIR=${TK_INSTALL_DIR}
        # -D3RDPARTY_TK_INCLUDE_DIR=${TK_INSTALL_DIR}/include
        # -D3RDPARTY_TK_LIBRARY_DIR=${TK_INSTALL_DIR}/lib

        -DUSE_FREEIMAGE=ON
        # -D3RDPARTY_FREEIMAGE_DIR=${FreeImage_INSTALL_DIR}
        # -D3RDPARTY_FREEIMAGE_INCLUDE_DIR=${FreeImage_INSTALL_DIR}/include
        # -D3RDPARTY_FREEIMAGE_LIBRARY_DIR_freeimage=${FreeImage_INSTALL_DIR}/lib

        -DUSE_TBB=OFF
        # -D3RDPARTY_TBB_DIR=${TBB_INSTALL_DIR}
        # -D3RDPARTY_TBB_INCLUDE_DIR=${TBB_INSTALL_DIR}/install
        # -D3RDPARTY_TBB_LIBRARY_DIR=${TBB_INSTALL_DIR}/lib
        # -D3RDPARTY_TBBMALLOC_LIBRARY_DIR=${TBB_INSTALL_DIR}/lib

        -DUSE_OPENGL=ON
        -DUSE_VTK=OFF
        # -D3RDPARTY_VTK_DIR=${VTK_INSTALL_DIR}
        # -D3RDPARTY_VTK_INCLUDE_DIR=${VTK_INSTALL_DIR}/include
        # -D3RDPARTY_VTK_LIBRARY_DIR=${VTK_INSTALL_DIR}/lib

        -DUSE_RAPIDJSON=ON
        -DUSE_DRACO=ON
    BUILD_ALWAYS            TRUE
    STEP_TARGETS            install
)

add_dependencies(OCCT 
    Tcl 
    Tk
    FreeType
    TBB
    FreeImage
    VTK)