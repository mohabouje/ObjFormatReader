//
// Created by Mohammed Boujemaoui on 13/11/2017.
//

#include <Catch2/include/catch_with_main.hpp>
#include "utility.h"
#include <fstream>
#include <cstdio>

SCENARIO("Testing filesystem functionalities") {
    GIVEN("A file path: the CMakeLists that should be stored at the same place as the test app") {
        auto file_path = "CMakeLists.txt";
        WHEN("We want to check that the file exist") {
            auto state = utility::filesystem::file_exist(file_path);
            THEN("The function should find the file") {
                REQUIRE(state);
            }
        }

        WHEN("We want to check the format of the file") {
            auto format = utility::filesystem::file_format(file_path);
            THEN("Then we should get .txt") {
                REQUIRE(format == ".txt");
            }
        }
    }

    GIVEN("A file that we will create in runtime") {
        auto my_file = "test.txt.is.an.stranger.thing";
        remove(my_file);
        WHEN("We check if the file exist") {
            auto state = utility::filesystem::file_exist(my_file);
            THEN("The file should not exist") {
                REQUIRE(!state);
            }
            AND_WHEN("We create the file manually") {
                std::ofstream a(my_file);
                a << ('a');
                THEN("The file should exist but should be empty") {
                    REQUIRE(utility::filesystem::file_exist(my_file));
                }
                AND_THEN("The format should be .thing") {
                    REQUIRE(utility::filesystem::file_format(my_file) == ".thing");
                    REQUIRE(utility::filesystem::is_format_supported(my_file, ".thing"));
                }
                a.close();
                remove(my_file);
            }
        }


    }
}


SCENARIO("Split & join of strings") {
    GIVEN("A spaces separated string") {
        const std::string tmp = "Hello!";
        const std::size_t size = 1000;
        const char separator = ' ';
        std::string buffer{};
        for (size_t i = 0; i < size; i++) {
            buffer += tmp;
            buffer += separator;
        }

        WHEN("We want to split the string by commas") {
            auto container = utility::parser::split_space<std::vector<std::string>>(buffer);
            THEN("The container should have the correct size") {
                REQUIRE(!container.empty());
                REQUIRE(container.size() == size);
            }
            THEN("Every single value should be tmp") {
                for (auto& str : container) {
                    REQUIRE(str == tmp);
                }
            }
            AND_THEN("When we join the strings by the same separator") {
                auto str = utility::parser::join(std::begin(container), std::end(container), " ");
                THEN("The string should be the same") {
                    REQUIRE(str == buffer);
                }
            }
        }
    }


    GIVEN("A slash separated string") {
        const std::string tmp = "Hello!";
        const std::size_t size = 1000;
        const char separator = '/';
        std::string buffer{};
        for (size_t i = 0; i < size; i++) {
            buffer += tmp;
            buffer += separator;
        }

        WHEN("We want to split the string by commas") {
            auto container = utility::parser::split<std::vector<std::string>>(buffer, separator);
            THEN("The container should have the correct size") {
                REQUIRE(!container.empty());
                REQUIRE(container.size() == size);
            }
            THEN("Every single value should be tmp") {
                for (auto& str : container) {
                    REQUIRE(str == tmp);
                }
            }
            AND_THEN("When we join the strings by the same separator") {
                auto str = utility::parser::join(std::begin(container), std::end(container), "/");
                THEN("The string should be the same") {
                    REQUIRE(str == buffer);
                }
            }
        }
    }

}