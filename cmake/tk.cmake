cmake_minimum_required(VERSION 3.20)


include(ExternalProject)

set(TK_SRC_DIR          ${CMAKE_SOURCE_DIR}/3rd_party_libraries/tk-src)
set(TK_BUILD_DIR        ${CMAKE_BINARY_DIR}/tk-build)
set(TK_INSTALL_DIR      ${CMAKE_BINARY_DIR}/tk-install)
set(TK_DOWNLOAD_DIR     ${CMAKE_BINARY_DIR}/tk-download)


ExternalProject_Add(Tk
    GIT_REPOSITORY          https://github.com/tcltk/tk.git
    GIT_TAG                 main
    GIT_SHALLOW             TRUE
    GIT_PROGRESS            TRUE
    SOURCE_DIR              ${TK_SRC_DIR}
    BINARY_DIR              ${TK_BUILD_DIR}
    DOWNLOAD_DIR            ${TK_DOWNLOAD_DIR}
    UPDATE_DISCONNECTED     TRUE
    CONFIGURE_COMMAND       ${TK_SRC_DIR}/unix/configure --enable-shared --enable-64bit --with-tcl=${TCL_INSTALL_DIR}/lib --prefix=${TK_INSTALL_DIR}
    BUILD_COMMAND           make -j 8
    INSTALL_COMMAND         make install
    STEP_TARGETS            install
)

add_dependencies(Tk Tcl)