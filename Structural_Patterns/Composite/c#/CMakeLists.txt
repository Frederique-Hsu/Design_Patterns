cmake_minimum_required(VERSION 3.20)

project(CSharpComposite)

set(DOTNET_SDK      "dotnet")
set(CMAKE_CFG       "Debug")

file(GLOB_RECURSE sources "./*.cs")
message(STATUS "${PROJECT_NAME} project's code files list:")
foreach(source ${sources})
    message(STATUS "\t\t ${source}")
endforeach()
message(STATUS "\n")

set(APP_NAME    CSharpComposite)

add_custom_command(
    OUTPUT      ${CMAKE_BINARY_DIR}/${APP_NAME}.dll
    COMMAND     ${DOTNET_SDK} build ${sources} -c ${CMAKE_CFG} -o ${CMAKE_BINARY_DIR}/app
    DEPENDS     ${sources}
    COMMENT     "Building C# application"
)

add_custom_target(${APP_NAME} ALL
    DEPENDS ${CMAKE_BINARY_DIR}/${APP_NAME}.dll
)
