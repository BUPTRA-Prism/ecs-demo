cmake_minimum_required(VERSION 3.16)
project(ecs_demo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


include_directories(${CMAKE_SOURCE_DIR}/include)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.14.0
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(test_core
    tests/core/test_hash.cpp
    tests/core/test_type_id.cpp
)
target_link_libraries(test_core gtest_main)
include(GoogleTest)
gtest_discover_tests(test_core)