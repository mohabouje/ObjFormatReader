//
// Created by Mohammed Boujemaoui on 14/11/2017.
//

#include <benchmark/benchmark.h>
#include "../utility.h"

#include <vector>
#include <list>
#include <queue>

using namespace utility;


template <typename Container>
static void BM_Split_Spaces(benchmark::State &state) {
    const std::string tmp = "Never gonna give you up\n"
            "Never gonna let you down\n"
            "Never gonna run around and desert you\n"
            "Never gonna make you cry\n"
            "Never gonna say goodbye\n"
            "Never gonna tell a lie and hurt you";
    for (auto _ : state)
        parser::split_space<Container, std::string>(tmp);
}


template <typename Container>
static void BM_Split_Slash(benchmark::State &state) {
    const std::string tmp = "Never/gonna/give/you/up\n"
            "Never/gonna/let/you/down\n"
            "Never/gonna/run/around/and/desert/you\n"
            "Never/gonna/make/you/cry\n"
            "Never/gonna/say/goodbye\n"
            "Never/gonna/tell/a/lie/and/hurt/you";
    for (auto _ : state)
        parser::split_slash<Container, std::string>(tmp);
}

template <typename Container>
void BM_Join_List_String(benchmark::State &state) {
    const Container tmp = {"Never gonna give you up\n",
                                          "Never gonna let you down\n",
                                          "Never gonna run around and desert you\n",
                                          "Never gonna make you cry\n",
                                          "Never gonna say goodbye\n",
                                          "Never gonna tell a lie and hurt you"};
    for (auto _ : state)
        parser::join(std::begin(tmp), std::end(tmp), " ");
}

BENCHMARK_TEMPLATE(BM_Split_Spaces, std::vector<std::string>);
BENCHMARK_TEMPLATE(BM_Split_Spaces, std::list<std::string>);
BENCHMARK_TEMPLATE(BM_Split_Slash, std::vector<std::string>);
BENCHMARK_TEMPLATE(BM_Split_Slash, std::list<std::string>);

BENCHMARK_TEMPLATE(BM_Join_List_String, std::vector<std::string>);
BENCHMARK_TEMPLATE(BM_Join_List_String, std::list<std::string>);

