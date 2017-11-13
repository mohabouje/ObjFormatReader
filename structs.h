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


#include <array>
#include <numeric>
#include <list>
#include <set>
#include <unordered_set>


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
    Vertex()  = default;
    explicit Vertex(const ObjPosition &v) : v(v) {}
    Vertex(const ObjPosition &v, const ObjVn &vn) : v(v), vn(vn) {}
    Vertex(const ObjPosition &v, const ObjVn &vn, const ObjVt &vt) : v(v), vn(vn), vt(vt) {}

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

#endif //OBJFORMATREADER_STRUCTS_H
