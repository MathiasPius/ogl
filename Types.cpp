#include "Precompiled.h"
#include "Types.h"

using namespace ogl;

static const std::map<primitive, std::function<int(int)>> g_primtable{
	{ points, [](int i) { return i; } },
	{ lines, [](int i) { return i / 2; } },
	{ line_loop, [](int i) { return i; } },
	{ line_strip, [](int i) { return -1; } },
	{ lines_adjacency, [](int i) { return i / 4; } },

	{ triangles, [](int i) { return i / 3; } },
	{ triangle_strip, [](int i) { return i - 2; } },
	{ triangle_fan, [](int i) { return i - 2; } },
	{ triangles_adjacency, [](int i) { return i / 6; } }
};

int ogl::to_primitive_count(primitive aPrimitive, int aVertexCount)
{
	return g_primtable.at(aPrimitive)(aVertexCount);
}