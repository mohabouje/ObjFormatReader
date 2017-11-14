//
// Created by Mohammed Boujemaoui on 14/11/2017.
//

#include <fstream>
#include <random>
#include "../Catch2/include/catch.hpp"
#include "../objformat_reader.h"

using namespace std;
using namespace chrono;
SCENARIO("Testing object format parser") {
    const string my_file = "test.thing";
    const string my_obj = "test.obj";
    ObjFormatReader reader;

    GIVEN("A file format archive") {

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
            ofstream outfile (my_file.c_str());
            AND_WHEN("We try to parse the archive that is not an .obj format") {
                auto error = reader.load_file(my_file);
                THEN("The error should be: FormatNotSupported"){
                    REQUIRE(error == ObjFormatReader::FormatNotSupported);
                }
            }
        }

        WHEN( "The file is empty and & .obj format" ) {
            remove(my_obj.c_str());
            ofstream outfile (my_obj.c_str());
            AND_WHEN("We try to parse the archive that is an .obj format") {
                auto error = reader.load_file(my_obj);
                THEN("The error should be: File empty"){
                    REQUIRE(error == ObjFormatReader::FileEmpty);
                }
            }
        }
    }

    remove(my_obj.c_str());
    remove(my_file.c_str());

}

SCENARIO("Loading a basic .obj file") {
    const string my_obj = "test.obj";
    ofstream outfile(my_obj);
    srand(static_cast<unsigned int>(duration_cast< milliseconds >(system_clock::now().time_since_epoch()).count()));
    default_random_engine generator;
    uniform_real_distribution<ObjPosition::value_type > distribution(0.0, 1.0);


    GIVEN("A vertex obj that we will save in the file X times") {
        const size_t num = 1000;
        const ObjPosition v = { distribution(generator), distribution(generator), distribution(generator), distribution(generator)};
        for (size_t i = 0; i < num; ++i) {
            outfile << "v " << v[0] <<  " " << v[1] << " " << v[2]  << " " << v[3] << endl;
        }

        WHEN("We read the file from the parser") {
            ObjFormatReader reader;
            auto error = reader.load_file(my_obj);
            THEN("No error is the return statement") {
                REQUIRE(error == ObjFormatReader::NoError);
            } AND_THEN("The number of v loaded should be the same") {
                REQUIRE(reader.object()->v.size() == num);
            } AND_THEN("The values of every single v should be the same") {
                for (size_t i = 0; i < num; ++i) {
                    REQUIRE(reader.object()->v[i] == v);
                }
            }

        }




    }




}