cmake_minimum_required(VERSION 3.5.0)
project(ProceduralSandbox VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES "src/**/*.cpp")
file(GLOB_RECURSE HEADER_LIST "include/**/*.h")

add_executable(ProceduralSandbox src/main.cpp ${SOURCES} ${HEADER_LIST})

target_include_directories(ProceduralSandbox PUBLIC include)

source_group(
  TREE "${PROJECT_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST})