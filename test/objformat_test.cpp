//
// Created by Mohammed Boujemaoui on 14/11/2017.
//

#include <fstream>
#include "../Catch2/include/catch.hpp"
#include "../objformat_reader.h"

SCENARIO("Testing object format parser") {
    ObjFormatReader reader;
    GIVEN("A file format archive") {
        const std::string my_file = "test.thing";
        const std::string my_obj = "test.obj";
        WHEN("The file doesnt exist") {
            remove(my_file.c_str());
            AND_WHEN("We try to parse the archive") {
                auto error = reader.load_file(my_file);
                THEN("The error should be: EmptyFile"){
                    REQUIRE(error == ObjFormatReader::FileNotExist);
                }
            }
        }

        WHEN( "The file is empty & not .obj format" ) {
            remove(my_file.c_str());
            std::ofstream outfile (my_file.c_str());
            AND_WHEN("We try to parse the archive that is not an .obj format") {
                auto error = reader.load_file(my_file);
                THEN("The error should be: FormatNotSupported"){
                    REQUIRE(error == ObjFormatReader::FormatNotSupported);
                }
            }
        }

        WHEN( "The file is empty and & .obj format" ) {
            remove(my_obj.c_str());
            std::ofstream outfile (my_obj.c_str());
            AND_WHEN("We try to parse the archive that is an .obj format") {
                auto error = reader.load_file(my_obj);
                THEN("The error should be: File empty"){
                    REQUIRE(error == ObjFormatReader::FileEmpty);
                }
            }
        }
    }

}