cmake_minimum_required(VERSION 3.11)

project(RDR-Classes LANGUAGES CXX VERSION 0.0.1 DESCRIPTION "Reversed structures for Red Dead Redemption 2 PC")

include(CheckIncludeFileCXX)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_REQUIRED_QUIET ON)

set(OK TRUE)

file(GLOB_RECURSE HEADERS "**.hpp")
file(GLOB_RECURSE SRC_MAIN "**.cpp")
source_group(FILES "${SRC_MAIN}")
add_library(RDR-Classes STATIC "${SRC_MAIN}" "${HEADERS}")
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
add_compile_definitions(_CRT_SECURE_NO_WARNINGS)

message(STATUS "")
 
target_include_directories(RDR-Classes PRIVATE 
    "${SRC_DIR}"
)

if(NOT OK)
    file(READ "${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/CMakeError.log" LOG)
    message(STATUS ${LOG})
endif()
