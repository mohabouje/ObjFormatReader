//
// Created by Mohammed Boujemaoui on 14/11/2017.
//

#include <benchmark/include/benchmark/benchmark.h>
#include "utility.h"
#include "objformat_reader.h"

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
static void BM_Regex_Split_Spaces(benchmark::State &state) {
    const std::string tmp = "Never gonna give you up\n"
            "Never gonna let you down\n"
            "Never gonna run around and desert you\n"
            "Never gonna make you cry\n"
            "Never gonna say goodbye\n"
            "Never gonna tell a lie and hurt you";
    for (auto _ : state)
        parser::regex_split_form_1<Container, std::string>(tmp, "[\\s\\xA0]+");
}

template <typename Container>
static void BM_Regex_Split_Slash(benchmark::State &state) {
    const std::string tmp = "Never/gonna/give/you/up\n"
            "Never/gonna/let/you/down\n"
            "Never/gonna/run/around/and/desert/you\n"
            "Never/gonna/make/you/cry\n"
            "Never/gonna/say/goodbye\n"
            "Never/gonna/tell/a/lie/and/hurt/you";
    for (auto _ : state)
        parser::regex_split_form_1<Container, std::string>(tmp,  "/+");
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


template <typename Q>
void BM_Arithmetic_String_To_Arithmetic_Array(benchmark::State &state) {
    using SList = std::vector<std::string>;
    const SList tmp = {"-24", "2", "90", "24", "50", "76", "-24", "2", "90", "24", "50", "76",
                       "-24", "2", "90", "24", "50", "76", "-24", "2", "90", "24", "50", "76", "-24", "2", "90", "24", "50", "76",
                       "-24", "2", "90", "24", "50", "76", "-24", "2", "90", "24", "50", "76", "-24", "2", "90", "24", "50", "76",
                       "-24", "2", "90", "24", "50", "76", "-24", "2", "90", "24", "50", "76", "-24", "2", "90", "24", "50", "76"};

    for (auto _ : state)
        parser::to_arithmetic_array<SList::const_iterator, Q, 50>(std::begin(tmp), std::end(tmp));
}

static void BM_Load_Obj(benchmark::State &state) {
    const std::string tmp = "/Users/mohabouje/Downloads/test_2.obj";
    ObjFormatReader reader;
    for (auto _ : state)
        reader.load_file(tmp);
}

BENCHMARK(BM_Load_Obj);
BENCHMARK_TEMPLATE(BM_Split_Spaces, std::vector<std::string>);
BENCHMARK_TEMPLATE(BM_Split_Spaces, std::list<std::string>);
BENCHMARK_TEMPLATE(BM_Split_Slash, std::vector<std::string>);
BENCHMARK_TEMPLATE(BM_Split_Slash, std::list<std::string>);
BENCHMARK_TEMPLATE(BM_Regex_Split_Slash, std::vector<std::string>);
BENCHMARK_TEMPLATE(BM_Regex_Split_Slash, std::list<std::string>);
BENCHMARK_TEMPLATE(BM_Regex_Split_Spaces, std::vector<std::string>);
BENCHMARK_TEMPLATE(BM_Regex_Split_Spaces, std::list<std::string>);
BENCHMARK_TEMPLATE(BM_Join_List_String, std::vector<std::string>);
BENCHMARK_TEMPLATE(BM_Join_List_String, std::list<std::string>);
BENCHMARK_TEMPLATE(BM_Arithmetic_String_To_Arithmetic_Array, float);
BENCHMARK_TEMPLATE(BM_Arithmetic_String_To_Arithmetic_Array, double);
BENCHMARK_TEMPLATE(BM_Arithmetic_String_To_Arithmetic_Array, int);
BENCHMARK_TEMPLATE(BM_Arithmetic_String_To_Arithmetic_Array, long);
BENCHMARK_MAIN();
