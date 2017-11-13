#include <iostream>
#include "objformat_reader.h"

void print_help() {
    std::cout << "Developed by: Mohammed Boujemaoui Boulaghmoudi" << std::endl;
    std::cout << "\t --help : Print help messages" << std::endl;
    std::cout << "\t --obj : Set the object file path" << std::endl;
    std::cout << "\t --print, p : Print the information of the different elements inside the file" << std::endl;
}

int main(int argc, char** argv) {
    if (argc == 1) {
        std::cerr << "Required field: --obj" << std::endl;
        print_help();
        return -1;
    };

    std::vector<std::string> args(argv + 1, argv + argc);
    std::string file_path{};
    bool print{false};
    for (auto i = args.begin(); i != args.end(); ++i) {
        if ("--print" == *i) {
            print = true;
        } else if ("--obj" == *i) {
            file_path = * (++i);
        } else {
            print_help();
            return 0;
        }
    }

    if (file_path.empty()) {
        std::cerr << "Required field: --obj" << std::endl;
        print_help();
        return -1;
    }


    ObjFormatReader reader;
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now(), t2;
    const ObjFormatReader::Error error = reader.load_file(file_path);
    t2 = std::chrono::high_resolution_clock::now();

    switch (error) {
        case ObjFormatReader::NoError:
            std::cout << "File loaded with success =)" << std::endl;
            break;
        case ObjFormatReader::FileEmpty:
            std::cerr << "Error: empty file" << std::endl;
            break;
        case ObjFormatReader::FileNotExist:
            std::cerr << "Error: file not exist" << std::endl;
            break;
        case ObjFormatReader::FormatNotSupported:
            std::cerr << "Error: format not supported" << std::endl;
            break;
        case ObjFormatReader::FileUnrecheable:
            std::cerr << "Error: could not open the file" << std::endl;
            break;
        case ObjFormatReader::Unknown:
        default:
            std::cerr << "Error: Unknown error =(" << std::endl;
            break;
    }

    if (print) {
        std::cout << reader << std::endl;
    }

    std::cout << "Processing time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()
              << " nsecs." << std::endl;
    return error;
}