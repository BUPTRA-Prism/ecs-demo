include(FetchContent)
FetchContent_Declare(
    googlebenchmark
    URL
    https://github.com/google/benchmark/archive/refs/tags/v1.8.3.zip
)
set(BENCHMARK_ENABLE_TESTING OFF)
set(BENCHMARK_ENABLE_WERROR OFF)
FetchContent_MakeAvailable(googlebenchmark)

add_executable(
    ecs_benchmark
    dummy_benchmark.cpp
)
target_link_libraries(
    ecs_benchmark
    PRIVATE
    benchmark::benchmark
)