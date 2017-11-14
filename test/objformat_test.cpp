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
            outfile << "g test";
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


#define COMPARE_ARRAYS_WITH_ELEMENT(X, Y)           \
    for(const auto& elem : X)                       \
        for (size_t i = 0; i < elem.size(); ++i)    \
            REQUIRE(elem[i] == Approx(Y[i]));


SCENARIO("Loading a basic .obj file") {
    const string my_obj = "test.obj";
    ofstream outfile(my_obj);
    srand(static_cast<unsigned int>(duration_cast< milliseconds >(system_clock::now().time_since_epoch()).count()));
    default_random_engine generator;
    uniform_real_distribution<ObjPosition::value_type > distribution(0.0, 1.0);


    GIVEN("A v parameter that we will save in the file X times") {
        outfile.clear();
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
                COMPARE_ARRAYS_WITH_ELEMENT(reader.object()->v, v);
            } AND_THEN("The rest of the fields should be empty") {
                Obj* o = reader.object();
                REQUIRE((o->vn.empty()
                         && o->vt.empty()
                         && o->vp.empty()
                         && o->indexes.empty()
                         && o->vertices.empty()));
            }

        }
        remove(my_obj.c_str());
    }

    GIVEN("A vn parameter that we will save in the file X times") {
        outfile.clear();
        const size_t num = 1000;
        const ObjVn vn = { distribution(generator), distribution(generator), distribution(generator) };
        for (size_t i = 0; i < num; ++i) {
            outfile << "vn " << vn[0] <<  " " << vn[1] << " " << vn[2]   << endl;
        }
        WHEN("We read the file from the parser") {
            ObjFormatReader reader;
            auto error = reader.load_file(my_obj);
            THEN("No error is the return statement") {
                REQUIRE(error == ObjFormatReader::NoError);
            } AND_THEN("The number of v loaded should be the same") {
                REQUIRE(reader.object()->vn.size() == num);
            } AND_THEN("The values of every single v should be the same") {
                COMPARE_ARRAYS_WITH_ELEMENT(reader.object()->vn, vn);
            } AND_THEN("The rest of the fields should be empty") {
                Obj* o = reader.object();
                REQUIRE((o->v.empty()
                         && o->vt.empty()
                         && o->vp.empty()
                         && o->indexes.empty()
                         && o->vertices.empty()));
            }

        }
    }



    GIVEN("A vt parameter that we will save in the file X times") {
        outfile.clear();
        const size_t num = 1000;
        const ObjVn vt = { distribution(generator), distribution(generator), distribution(generator) };
        for (size_t i = 0; i < num; ++i) {
            outfile << "vt " << vt[0] <<  " " << vt[1] << " " << vt[2]   << endl;
        }
        WHEN("We read the file from the parser") {
            ObjFormatReader reader;
            auto error = reader.load_file(my_obj);
            THEN("No error is the return statement") {
                REQUIRE(error == ObjFormatReader::NoError);
            } AND_THEN("The number of v loaded should be the same") {
                REQUIRE(reader.object()->vt.size() == num);
            } AND_THEN("The values of every single v should be the same") {
                COMPARE_ARRAYS_WITH_ELEMENT(reader.object()->vt, vt);
            } AND_THEN("The rest of the fields should be empty") {
                Obj* o = reader.object();
                REQUIRE((o->v.empty()
                         && o->vn.empty()
                         && o->vp.empty()
                         && o->indexes.empty()
                         && o->vertices.empty()));
            }

        }
    }


    GIVEN("A vp parameter that we will save in the file X times") {
        outfile.clear();
        const size_t num = 1000;
        const ObjVn vp = { distribution(generator), distribution(generator), distribution(generator) };
        for (size_t i = 0; i < num; ++i) {
            outfile << "vp " << vp[0] <<  " " << vp[1] << " " << vp[2]   << endl;
        }
        WHEN("We read the file from the parser") {
            ObjFormatReader reader;
            auto error = reader.load_file(my_obj);
            THEN("No error is the return statement") {
                REQUIRE(error == ObjFormatReader::NoError);
            } AND_THEN("The number of v loaded should be the same") {
                REQUIRE(reader.object()->vp.size() == num);
            } AND_THEN("The values of every single v should be the same") {
                COMPARE_ARRAYS_WITH_ELEMENT(reader.object()->vp, vp);
            } AND_THEN("The rest of the fields should be empty") {
                Obj* o = reader.object();
                REQUIRE((o->v.empty()
                         && o->vn.empty()
                         && o->vt.empty()
                         && o->indexes.empty()
                         && o->vertices.empty()));
            }

        }
    }

    GIVEN("A generic file .obj") {
        outfile.clear();
        const ObjPosition v = { distribution(generator), distribution(generator), distribution(generator), distribution(generator)};
        const ObjVn vn = { distribution(generator), distribution(generator), distribution(generator) };
        const ObjVn vp = { distribution(generator), distribution(generator), distribution(generator) };
        const ObjVn vt = { distribution(generator), distribution(generator), distribution(generator) };

        const size_t nV = 65, nVn = 56, nVp = 87, nVt = 78;
        for (size_t i = 0; i < nV; ++i) {
            outfile << "v " << v[0] <<  " " << v[1] << " " << v[2]  << " " << v[3] << endl;
        }
        for (size_t i = 0; i < nVt; ++i) {
            outfile << "vt " << vt[0] <<  " " << vt[1] << " " << vt[2]   << endl;
        }
        for (size_t i = 0; i < nVn; ++i) {
            outfile << "vn " << vn[0] <<  " " << vn[1] << " " << vn[2]   << endl;
        }
        for (size_t i = 0; i < nVp; ++i) {
            outfile << "vp " << vp[0] <<  " " << vp[1] << " " << vp[2]   << endl;
        }

        WHEN("We read the file from the parser") {
            ObjFormatReader reader;
            auto error = reader.load_file(my_obj);
            THEN("No error is the return statement") {
                REQUIRE(error == ObjFormatReader::NoError);
            } AND_THEN("The number of elements loaded should be the same") {
                REQUIRE(reader.object()->v.size() == nV);
                REQUIRE(reader.object()->vn.size() == nVn);
                REQUIRE(reader.object()->vt.size() == nVt);
                REQUIRE(reader.object()->vp.size() == nVp);
            }  AND_THEN("The rest of the fields should be empty") {
                Obj* o = reader.object();
                REQUIRE((o->indexes.empty()
                         && o->vertices.empty()));
            }

        }
    }
}

struct ObjFileInfo {
    ObjFileInfo(size_t PositionCount, size_t TriangleCount) : PositionCount(PositionCount),
                                                              TriangleCount(TriangleCount) {}
    size_t PositionCount;
    size_t TriangleCount;
};


SCENARIO("Testing real files") {

    GIVEN("The file test_1.obj that was analyzed with ") {
        const std::string file_path = "./test/test_1.obj";
        ObjFileInfo info(8, 12);
        ObjFormatReader reader;
        WHEN("We parse the file") {
            auto error = reader.load_file(file_path);
            THEN("We should get no error") {
                REQUIRE(error == ObjFormatReader::NoError);
            } AND_THEN("The number of positions should be the same") {
                REQUIRE(reader.object()->v.size() == info.PositionCount);
            } AND_THEN("The number of indexes to plot should be 3 times the number of triangles") {
                REQUIRE(reader.object()->indexes.size()  == (info.TriangleCount * Obj::Triangles));
            }
        }

    }


    GIVEN("The file test_1.obj that was analyzed with ") {
        const std::string file_path = "./test/test_2.obj";
        ObjFileInfo info(7895, 14128);
        ObjFormatReader reader;
        WHEN("We parse the file") {
            auto error = reader.load_file(file_path);
            THEN("We should get no error") {
                REQUIRE(error == ObjFormatReader::NoError);
            } AND_THEN("The number of positions should be the same") {
                REQUIRE(reader.object()->v.size() == info.PositionCount);
            } AND_THEN("The number of indexes to plot should be 3 times the number of triangles") {
                REQUIRE(reader.object()->indexes.size()  == (info.TriangleCount * Obj::Triangles));
            }
        }

    }


    GIVEN("The file test_1.obj that was analyzed with ") {
        const std::string file_path = "./test/test_3.obj";
        ObjFileInfo info(24, 36);
        ObjFormatReader reader;
        WHEN("We parse the file") {
            auto error = reader.load_file(file_path);
            THEN("We should get no error") {
                REQUIRE(error == ObjFormatReader::NoError);
            } AND_THEN("The number of positions should be the same") {
                REQUIRE(reader.object()->v.size() == info.PositionCount);
            } AND_THEN("The number of indexes to plot should be 3 times the number of triangles") {
                REQUIRE(reader.object()->indexes.size()  == (info.TriangleCount * Obj::Triangles));
            }
        }
    }

}