#include "Precompiled.h"
#include "Context.h"

using namespace ogl;

context::settings::settings( flags aFlags /* = Default */, unsigned int aColorBits /* = 32 */, unsigned int aDepthBits /* = 32 */, unsigned int aMajorVersion /* = 3 */, unsigned int aMinorVersion /* = 2 */ ) :
my_flags(aFlags),
my_colorbits(aColorBits),
my_depthbits(aDepthBits),
my_majorversion(aMajorVersion),
my_minorversion(aMinorVersion)
{

}

context::settings::~settings()
{

}