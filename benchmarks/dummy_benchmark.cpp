#include <benchmark/benchmark.h>

static void BM_Dummy(benchmark::State& state) {
    for(auto _ : state) {
        bool value = true;
        benchmark::DoNotOptimize(value);
    }
}
BENCHMARK(BM_Dummy);

BENCHMARK_MAIN();