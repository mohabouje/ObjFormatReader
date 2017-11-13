//
// Created by Mohammed Boujemaoui on 13/11/2017.
//
#include "objformat_reader.h"

#include <fstream>
#include <map>
#include <chrono>

using namespace std;

enum ObjCommands {
    Definition = 100,
    UseMtl,
    Position,
    Normal,
    TextureCoordinates,
    ParameterSpace,
    Face
};


// HACK: to iterate over a switch by using strings, not the best solution, but a clean one.
static map<string, ObjCommands> Command = {
        {"g", ObjCommands::Definition},
        {"usemtl", ObjCommands::UseMtl},
        {"v", ObjCommands::Position},
        {"vt", ObjCommands::Normal},
        {"vn", ObjCommands::TextureCoordinates},
        {"vp", ObjCommands::ParameterSpace},
        {"f", ObjCommands::Face}
};



ObjFormatReader::Error ObjFormatReader::load_file(const std::string &file_path) {
    if (!utility::filesystem::file_exist(file_path)) return FileNotExist;
    if (!utility::filesystem::is_format_supported(file_path, ".obj")) return FormatNotSupported;

    std::ifstream file(file_path, std::ios_base::in);
    if (file.peek() == std::ifstream::traits_type::eof()) return FileEmpty;
    if (file.fail()) return FileUnrecheable;

    string current_line;
    while (getline(file, current_line)) {
        auto tokens = utility::parser::split_space<list<string>>(current_line);
        auto elements = tokens.size();
        if (!elements) continue;

        const string& command = tokens.front(); tokens.pop_front();
        switch (Command[command]) {
            case ObjCommands::Definition:
                break;
            case ObjCommands::UseMtl:
                break;
            case ObjCommands::Position:
                assert(elements >= 4 && "Expecting 3 parameters for the v parameter, format: v [x] [y] [z] [w| optional]");
                obj.v.push_back(
                        utility::parser::to_arithmetic_array<list<string>::const_iterator, sample, 4>(tokens.begin(),
                                                                                                 tokens.end()));
                break;
            case ObjCommands::Normal:
                assert(elements >= 4 && "Expecting 3 parameters for the vn parameter, format: vn [x] [y] [z]");
                obj.vn.push_back(
                        utility::parser::to_arithmetic_array<list<string>::const_iterator, sample, 3>(tokens.begin(),
                                                                                                 tokens.end()));
                break;
            case ObjCommands::TextureCoordinates:
                assert(elements >= 3 && "Expecting 2 parameters for the vt paramters, format: vt [x] [y] w| optional]");
                obj.vt.push_back(
                        utility::parser::to_arithmetic_array<list<string>::const_iterator, sample, 3>(tokens.begin(),
                                                                                                 tokens.end()));
                break;
            case ObjCommands::ParameterSpace:
                assert(elements >= 3 && "Expecting 2 parameters for the vp parameters, format: vn [x] [y] [z]");
                obj.vp.push_back(
                        utility::parser::to_arithmetic_array<list<string>::const_iterator, sample, 3>(tokens.begin(),
                                                                                                 tokens.end()));
                break;
            case ObjCommands::Face:
                break;
            default:
                break;

        }
    }

    file.close();
    return NoError;
}

ostream &operator<<(ostream &os, const ObjFormatReader &reader) {
    auto time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    os << "File parsed at " << std::ctime(&time) << endl;
    os << reader.obj << endl;
    return os;
}