//
// Created by Mohammed Boujemaoui on 13/11/2017.
//
#include "objformat_reader.h"

#include <fstream>
#include <map>
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
                break;
            case ObjCommands::Normal:
                break;
            case ObjCommands::TextureCoordinates:
                break;
            case ObjCommands::ParameterSpace:
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