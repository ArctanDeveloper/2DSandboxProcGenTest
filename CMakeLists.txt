cmake_minimum_required(VERSION 3.5.0)
project(ProceduralSandbox VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Gather all source and header files
file(GLOB_RECURSE SOURCES "src/**/*.cpp")
file(GLOB_RECURSE HEADER_LIST "include/**/*.h")

# Create a library for ProceduralSandbox
add_library(ProceduralSandboxLib ${SOURCES} ${HEADER_LIST})
target_include_directories(ProceduralSandboxLib PUBLIC include)

# Add the main executable
add_executable(ProceduralSandbox src/main.cpp)
target_link_libraries(ProceduralSandbox PRIVATE ProceduralSandboxLib)

# Organize headers in the IDE (e.g., Visual Studio)
source_group(
  TREE "${PROJECT_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST})

# Enable testing
enable_testing()

# Add the tests subdirectory
add_subdirectory(tests)