#pragma once

#ifdef HY_PLATFORM_WINDOWS
#if HY_DYNAMIC_LINK
	#ifdef HY_BUILD_DLL
		#define HYPERION_API __declspec(dllexport)
	#else
		#define HYPERION_API __declspec(dllimport)
	#endif
#else
#define HYPERION_API
#endif
#else
	#error Hyperion Only Supports Windows!
#endif

#ifdef HY_DEBUG
	#define HY_ENABLE_ASSERTS
#endif // HY_DEBUG


#ifdef HY_ENABLE_ASSERTS
#define HY_ASSERT(x, ...) { if(!(x)) { HY_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define HY_CORE_ASSERT(x, ...) { if(!(x)) { HY_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define HY_ASSERT(x, ...)
#define HY_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define HY_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)