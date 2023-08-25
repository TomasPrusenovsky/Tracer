#pragma once

#ifdef TC_PLATFORM_WINDOWS
#ifdef	TC_BUILD_DLL
#define TRACER_API _declspec(dllexport)
#else
#define TRACER_API _declspec(dllimport)
#endif // TC_BUILD_DLL
#else 
#error Drawer only supports windows!

#endif // TC_PLATFORM_WINDOWS

#ifdef TC_DEBUG
#define TC_ENABLE_ASSERTS
#endif

#ifdef TC_ENABLE_ASSERTS
#define TC_ASSERT(x, ...) { if(!(x)) { TC_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define TC_CORE_ASSERT(x, ...) { if(!(x)) { TC_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define TC_ASSERT(x, ...)
#define TC_CORE_ASSERT(x, ...)
#endif
