//
// Created by Mohammed Boujemaoui on 14/11/2017.
//

#include <benchmark/benchmark.h>
#include "../objformat_reader.h"


static void BM_Load_Obj(benchmark::State &state) {
    const std::string tmp = "/Users/mohabouje/Downloads/test_2.obj";
    ObjFormatReader reader;
    for (auto _ : state)
        reader.load_file(tmp);
}

BENCHMARK(BM_Load_Obj);
BENCHMARK_MAIN();
