#pragma once

#ifdef TC_PLATFORM_WINDOWS
#ifdef	TC_BUILD_DLL
#define TRACER_API _declspec(dllexport)
#else
#define TRACER_API _declspec(dllimport)
#endif // DW_BUILD_DLL
#else 
#error Drawer only supports windows!

#endif // DW_PLATFORM_WINDOWS