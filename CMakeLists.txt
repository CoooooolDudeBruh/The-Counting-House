cmake_minimum_required(VERSION 3.16)
project(TheCountingHouse LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Adjust paths if your .cpp files live in the repo root instead of src/
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/*.cpp")

add_executable(the_counting_house ${SOURCES})
target_include_directories(the_counting_house PRIVATE "${CMAKE_SOURCE_DIR}/include")
