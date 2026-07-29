include(FetchContent)
FetchContent_Declare(
    googletest
    URL
    https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(
    ecs_test
    dummy_test.cpp
)
target_link_libraries(
    ecs_test
    PRIVATE
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(ecs_test)