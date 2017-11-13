//
// Created by Mohammed Boujemaoui on 13/11/2017.
//

#include "../Catch2/include/catch.hpp"
#include "../utility.h"
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
                std::ofstream(my_file).put('a');
                THEN("The file shoyld exist but should be empty") {
                    REQUIRE(utility::filesystem::file_exist(my_file));
                }
                AND_THEN("The format should be .thing") {
                    REQUIRE(utility::filesystem::file_format(my_file) == ".thing");
                    REQUIRE(utility::filesystem::is_format_supported(my_file, ".thing"));
                }
                remove(my_file);
            }
        }


    }
}
