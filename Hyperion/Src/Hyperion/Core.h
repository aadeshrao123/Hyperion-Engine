#pragma once

#ifdef HY_PLATFORM_WINDOWS
	#ifdef HY_BUILD_DLL
		#define HYPERION_API __declspec(dllexport)
	#else
		#define HYPERION_API __declspec(dllimport)
	#endif
#else
	#error Hyperion Only Supports Windows!
#endif

