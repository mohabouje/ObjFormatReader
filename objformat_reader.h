
//
// Created by Mohammed Boujemaoui on 13/11/2017.
//

#ifndef OBJFORMATREADER_OBJFORMATREADER_H
#define OBJFORMATREADER_OBJFORMATREADER_H

#include "structs.h"
class ObjFormatReader {

public:
    enum Error {
        NoError = 0, FileNotExist, FormatNotSupported, FileEmpty, FileUnrecheable, FileCorrupted, Unknown
    };
    ObjFormatReader() = default;
    virtual ~ObjFormatReader() = default;
    friend std::ostream &operator<<(std::ostream &os, const ObjFormatReader &reader);
    Error load_file(const std::string& file_path);
    inline const Obj& object() const { return obj; }
    inline Obj* object() { return &obj; }
private:
    Obj obj;


    template <typename T, template <typename, typename = std::allocator<T>> class Container>
    inline typename std::enable_if<std::is_same<std::basic_string<char>, T>::value, std::vector<Vertex>>::type
    load_vertices_from_face(const Container<T> &face_line);

    template <typename T, template <typename, typename = std::allocator<T>> class Container>
    typename std::enable_if<std::is_same<Vertex, T>::value, void>::type
    vertices_triangle_fan(const Container<T> &vertices);

};


#endif //OBJFORMATREADER_OBJFORMATREADER_H
