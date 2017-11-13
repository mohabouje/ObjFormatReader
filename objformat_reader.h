
//
// Created by Mohammed Boujemaoui on 13/11/2017.
//

#ifndef OBJFORMATREADER_OBJFORMATREADER_H
#define OBJFORMATREADER_OBJFORMATREADER_H

#include "structs.h"
class ObjFormatReader {

public:
    ObjFormatReader() = default;
    virtual ~ObjFormatReader() = default;


    const Obj& object() const { return obj; }
    Obj* object() { return &obj; }
private:
    Obj obj;

};


#endif //OBJFORMATREADER_OBJFORMATREADER_H
