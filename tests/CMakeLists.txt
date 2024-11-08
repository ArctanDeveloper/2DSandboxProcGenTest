# Add GoogleTest using FetchContent
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/b514bdc898e2951020cbdca1304b75f5950d1f59.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

file(GLOB_RECURSE TESTS "**/*.cpp")

# Create the test executable
add_executable(tests ${TESTS})

# Link GoogleTest and the ProceduralSandbox library
target_link_libraries(tests PRIVATE ProceduralSandboxLib GTest::gtest GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)