#pragma once

#ifdef OGLPROJECT
#	define OGLEXPORT __declspec(dllexport)
#else
#	define OGLEXPORT __declspec(dllimport)
#endif