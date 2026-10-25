cmake_minimum_required(VERSION 3.16)

if(NOT EXISTS "$ENV{ZOS_PATH}/cmake/zos_init.cmake")
    message(FATAL_ERROR "Set ZOS_PATH to a Zeal OS checkout with the CMake toolchain, or build with zde cmake.")
endif()

set(ZOS_TOOLCHAIN sdcc)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
include("$ENV{ZOS_PATH}/cmake/zos_init.cmake")

project(zeal_qr LANGUAGES C ASM)

add_executable(qr src/main.c src/qrtiny.c)
zos_add_outputs(qr)
