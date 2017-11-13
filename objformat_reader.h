
//
// Created by Mohammed Boujemaoui on 13/11/2017.
//

#ifndef OBJFORMATREADER_OBJFORMATREADER_H
#define OBJFORMATREADER_OBJFORMATREADER_H

#include "structs.h"
class ObjFormatReader {

public:
    enum Error {
        NoError = 0, FileNotExist, FormatNotSupported, FileEmpty, FileUnrecheable, Unknown
    };
    ObjFormatReader() = default;
    virtual ~ObjFormatReader() = default;
    Error load_file(const std::string& file_path);
    inline const Obj& object() const { return obj; }
    inline Obj* object() { return &obj; }
private:
    Obj obj;

};


#endif //OBJFORMATREADER_OBJFORMATREADER_H
