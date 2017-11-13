//
// Created by Mohammed Boujemaoui on 13/11/2017.
//

#ifndef OBJFORMATREADER_STRUCTS_H
#define OBJFORMATREADER_STRUCTS_H

#if _WIN32 || _WIN64
#if _WIN64
#define ENVIRONMENT_64
#else
#define ENVIRONMENT_32
#endif
#endif

// Check GCC
#if __GNUC__
#if __x86_64__ || __ppc64__
#define ENVIRONMENT_64
#else
#define ENVIRONMENT_32
#endif
#endif


#ifdef ENVIRONMENT_64
using sample = double;
#else
using sample = float;
#endif

#include "utility.h"

#include <array>
#include <numeric>
#include <list>
#include <set>
#include <unordered_set>
#include <ostream>
#include <vector>


// Basic parameters from a obj format
// v List of vertices - x, y, z, [w]=1.0
// vt	= {}, -- Texture coordinates - u, v, [w]=0
// vn	= {}, -- Normals - x, y, z
// vp	= {}, -- Parameter space vertices - u, [v], [w]
// f	= {}, -- Faces

using ObjPosition = std::array<sample, 4>;
using ObjVt = std::array<sample, 3>;
using ObjVp = std::array<sample, 3>;
using ObjVn = std::array<sample, 3>;
using Index = size_t;


// TODO: we can save the position in the global buffer of any fiels instead of copy everithing.
struct Vertex {
    enum VertexType { JustPos = 1, PosAndTCoord, PosTCoordAndNormal};
    constexpr Vertex()  = default;
    constexpr Vertex(const ObjPosition &v) : v(v) {}
    constexpr Vertex(const ObjPosition &v, const ObjVn &vn) : v(v), vn(vn) {}
    constexpr Vertex(const ObjPosition &v, const ObjVn &vn, const ObjVt &vt) : v(v), vn(vn), vt(vt) {}

    ObjPosition v{};
    ObjVn vn{};
    ObjVt vt{};
};

inline bool operator == (Vertex const& lhs, Vertex const& rhs) {
    return (lhs.v == rhs.v) &&
           (lhs.vn == rhs.vn) &&
           (lhs.vt == rhs.vt);
}


inline bool operator < (Vertex const& lhs, Vertex const& rhs) {
    return (lhs.v < rhs.v) &&
           (lhs.vn < rhs.vn) &&
           (lhs.vt < rhs.vt);
}

struct VertexHash {
    inline size_t operator() (const Vertex &vertex) const {
        return static_cast<size_t>(std::accumulate(std::begin(vertex.v), std::end(vertex.v), static_cast<ObjPosition::value_type>(0))
                                   + std::accumulate(std::begin(vertex.vn), std::end(vertex.vn), static_cast<ObjVn::value_type>(0))
                                   + std::accumulate(std::begin(vertex.vt), std::end(vertex.vt), static_cast<ObjVt::value_type>(0)));
    }
};

using VertexVector = std::vector<Vertex>;
using VertexList = std::list<Vertex>;
using VertexSet = std::set<Vertex>;
using VertexUSet = std::unordered_set<Vertex, VertexHash>;


enum Axis { AxisX = 0, AxisY, AxisZ};
struct Obj {
    enum SupportedFaces  { Triangles = 3, Sguares = 4 };
    friend std::ostream &operator<<(std::ostream &os, const Obj &obj) {
        os << "Number of v: " << obj.v.size() << std::endl;
        os << "Number of vn: " << obj.vn.size() << std::endl;
        os << "Number of vt: " << obj.vt.size() << std::endl;
        os << "Number of vp: " << obj.vp.size() << std::endl;
        os << "Number of vertices in faces: " << obj.vertices.size() << std::endl;
        os << "Number of indexes to plot: " << obj.indexes.size() << std::endl;
        os << "Number of triangles: " << obj.indexes.size() / Triangles << std::endl;
        os << "X Size: " << obj.width() << std::endl;
        os << "Y Size: " << obj.height() << std::endl;
        os << "Z Size: " << obj.weigth() << std::endl;
        os << std::endl;
        return os;
    }

    inline sample width() const {
        return utility::algorithm::distance_minmaxelement_at(v, Axis::AxisX);
    }

    inline sample height() const {
        return utility::algorithm::distance_minmaxelement_at(v, Axis::AxisY);
    }

    inline sample weigth() const {
        return utility::algorithm::distance_minmaxelement_at(v, Axis::AxisZ);
    }


    // TODO: same situation: check the best container for any case, for quick search and push_back list give better behaviout than vector, but we lost the random access.
    std::list<Vertex>           vertices{};
    std::list<Index>            indexes{};
    std::vector<ObjPosition>    v{};
    std::vector<ObjVn>          vn{};
    std::vector<ObjVt>          vt{};
    std::vector<ObjVp>          vp{};
};




#endif //OBJFORMATREADER_STRUCTS_H
