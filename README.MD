### Algorithm
Polygon triangulation is the decomposition of a polygonal area (simple polygon) P into a set of triangles, finding a set of triangles with pairwise non-intersecting interiors whose union is P.

![The 42 possible triangulations for a convex heptagon (7-sided convex polygon). This number is given by the 5th Catalan number.](https://upload.wikimedia.org/wikipedia/commons/thumb/c/c3/Polygon_Triangulations_%28heptagon%29.svg/561px-Polygon_Triangulations_%28heptagon%29.svg.png)

If we see the attached image, there are handreds of different ways to triangulate the figure.  In this case we take the easiest one, **using monotone polygons**

 **About the algorithm**
 > For each point, check if the neighboring points are both on the same side of the 'sweep line', a horizontal or vertical line on which the point being iterated lies. If they are, check the next  sweep line on the other side. Break the polygon on the line between the original point and one of the points on this one.

> Note that if you are moving downwards, the points where both of the vertices are below the sweep line are 'split points'. They mark a split in the polygon. From there you have to consider both sides separately.

*Using this algorithm to triangulate a simple polygon takes O(n log n) time.*

In this case, as we expect just TRIANGLES & SQUARES as primitives, we use the triangle-fan approach of OpenGL.

 Example for a quad in the 1/1/1 2/2/2 3/3/3 4/4/4 format:

 - Triangle 1: 1/1/1 2/2/2 3/3/3
 -  Triangle 2: 1/1/1 3/3/3 4/4/4.

So for a 6-vertex polygon like this one: 1//1 2//2 3//3 4//4 5//5 6//6

 - Triangle1: 1//1 2//2 3//3
 - Triangle2: 1//1 3//3 4//4
 - Triangle3: 1//1 4//4 5//5
 - Triangle4: 1//1 5//5 6//6

Just count the number of entries for each face, and do a for loop for them, and increase the starting index for the 2nd and 3rd vertex by 1 for each extra triangle.  Generic algorithm, something like that:

    vector<Index> tmp;
    for (size_t i = 0, sz = (NumberOfVertex - 2); i < sz; ++i) {
         tmp.push_back(0);
         tmp.push_back(i + 1);
         tmp.push_back(i + 2);
    }

As we suppose that the inputs are SQUARES or INTEGERS, the index are fixed: 

 1.  { 0 1 2 0 2 3} for SQUARES
 1.  { 0 1 2 } for TRIANGLES

### Compilation

Dont test it in Windows systems, test it in Unix systems. It should compile and run in every compile that supports C++ 11/14.

    cmake .
    make 

To run the benchmark, install the [google-benchmark](https://github.com/google/benchmark) library:

On Mac OS:

    brew install google-benchmark

On generic Unix & Linux systems:

    git clone --recursive https://github.com/google/benchmark.git
    cd benchmark
    cmake .
    make
    sudo make install

**How to run it?**

    objformatreader --obj "test.obj" --print
