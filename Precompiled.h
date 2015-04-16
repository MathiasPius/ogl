#pragma once

#include <memory>
#include <map>
#include <array>
#include <string>
#include <vector>
#include <utility>
#include <fstream>
#include <iostream>
#include <functional>

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <Windows.h>
#include <gl/glew.h>
#include <gl/wglew.h>
#include <gl/glext.h>
#include <gl/wglext.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include "Export.h"
#include "NonAssignable.h"
#include "NonCopyable.h"
#include "Bindable.h"
#include "Assert.h"
#include "Types.h"
#include "Utility.h"