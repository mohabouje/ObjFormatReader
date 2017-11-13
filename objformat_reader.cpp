//
// Created by Mohammed Boujemaoui on 13/11/2017.
//
#include "objformat_reader.h"

#include <fstream>
using namespace std;


ObjFormatReader::Error ObjFormatReader::load_file(const std::string &file_path) {
    if (!utility::filesystem::file_exist(file_path)) return FileNotExist;
    if (!utility::filesystem::is_format_supported(file_path, ".obj")) return FormatNotSupported;

    std::ifstream file(file_path, std::ios_base::in);
    if (file.peek() == std::ifstream::traits_type::eof()) return FileEmpty;
    if (file.fail()) return FileUnrecheable;



    return NoError;
}
