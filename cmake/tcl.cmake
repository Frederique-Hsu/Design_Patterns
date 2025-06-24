cmake_minimum_required(VERSION 3.20)

include(ExternalProject)

set(TCL_SRC_DIR         ${CMAKE_SOURCE_DIR}/3rd_party_libraries/tcl-src)
set(TCL_BUILD_DIR       ${CMAKE_BINARY_DIR}/tcl-build)
set(TCL_INSTALL_DIR     ${CMAKE_BINARY_DIR}/tcl-install)
set(TCL_DOWNLOAD_DIR    ${CMAKE_BINARY_DIR}/tcl-download)


ExternalProject_Add(Tcl
    GIT_REPOSITORY          https://github.com/tcltk/tcl.git
    GIT_TAG                 main
    GIT_SHALLOW             TRUE
    GIT_PROGRESS            TRUE
    SOURCE_DIR              ${TCL_SRC_DIR}
    BINARY_DIR              ${TCL_BUILD_DIR}
    DOWNLOAD_DIR            ${TCL_DOWNLOAD_DIR}
    UPDATE_DISCONNECTED     TRUE
    # 以下一些命令，不需要用""给引用起来。 引用起来反而会出错。
    CONFIGURE_COMMAND       ${TCL_SRC_DIR}/unix/configure --enable-shared --enable-64bit --prefix=${TCL_INSTALL_DIR}
    BUILD_COMMAND           make -j 8
    INSTALL_COMMAND         make install
    STEP_TARGETS            install
)