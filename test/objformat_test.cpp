//
// Created by Mohammed Boujemaoui on 14/11/2017.
//

#include "../Catch2/include/catch_with_main.hpp"
#include "../objformat_reader.h"

SCENARIO("Testing object format parser") {
    ObjFormatReader reader;
    GIVEN("A file format archive") {
        auto my_file = "test.thing";
        WHEN("The file doesnt exist") {
            remove(my_file);
            AND_WHEN("We try to parse the archive") {
                auto error = reader.load_file(my_file);
                THEN("The error should be: EmptyFile"){
                    REQUIRE(error == ObjFormatReader::FileNotExist);
                }
            }
        }


        WHEN( "The file is empty" ) {
            remove(my_file);
            std::ofstream outfile (my_file);
            AND_WHEN("We try to parse the archive") {
                auto error = reader.load_file(my_file);
                THEN("The error should be: EmptyFile"){
                    REQUIRE(error == ObjFormatReader::FileEmpty);
                }
            }

        }
    }

}