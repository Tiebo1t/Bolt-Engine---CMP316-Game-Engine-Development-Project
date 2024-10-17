#pragma once

#ifdef BOLT_PLATFORM_WINDOWS // States we are working on Windows
	#ifdef BOLT_BUILD_DLL
	#define BOLT_ENGINE_API __declspec(dllexport) // Sets up the dll for the Bolt Engine and not the Game layer
#else
	#define BOLT_ENGINE_API __declspec(dllimport)
#endif
#else
#error Bolt Engine only supports Windows
	
#endif