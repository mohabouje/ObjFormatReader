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
        std::cout << "Required field: --obj" << std::endl;
        print_help();
        return -1;
    }


    ObjFormatReader reader;


    if (print) {

    }

    return 0;
}