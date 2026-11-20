cmake_minimum_required(VERSION 3.16)
project(TheCountingHouse LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Search all subfolders recursively for C++ source files
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/*.cpp"
    "${CMAKE_SOURCE_DIR}/*.cc"
    "${CMAKE_SOURCE_DIR}/*.cxx"
)

# Ignore files CMake generates inside build/ so they do not conflict with your code
list(FILTER SOURCES EXCLUDE REGEX "${CMAKE_SOURCE_DIR}/build/.*")

# Print the exact list of files CMake found in the terminal output
message(STATUS "Discovered source files: ${SOURCES}")

add_executable(the_counting_house ${SOURCES})

# Automatically add every subfolder containing .h or .hpp files to the include path
file(GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/*.h"
    "${CMAKE_SOURCE_DIR}/*.hpp"
)
set(INCLUDE_DIRS "${CMAKE_SOURCE_DIR}")
foreach(HEADER_PATH ${HEADER_FILES})
    get_filename_component(DIR_PATH ${HEADER_PATH} DIRECTORY)
    list(APPEND INCLUDE_DIRS ${DIR_PATH})
endforeach()
list(REMOVE_DUPLICATES INCLUDE_DIRS)
list(FILTER INCLUDE_DIRS EXCLUDE REGEX "${CMAKE_SOURCE_DIR}/build.*")

target_include_directories(the_counting_house PRIVATE ${INCLUDE_DIRS})