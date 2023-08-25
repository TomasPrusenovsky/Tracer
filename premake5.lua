workspace "Tracer"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Tracer"
	location "Tracer"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/"..outputdir.."/%{prj.name}")
	objdir ("bin-int/"..outputdir.."/%{prj.name}")

	pchheader "tcpch.h"
	pchsource "Tracer/src/tcpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src"
	}

	links
	{
	}

    filter "system:windows"
    cppdialect "C++20"
    systemversion "latest"

    defines
    {
        "TC_PLATFORM_WINDOWS",
        "TC_BUILD_DLL"
    }

    postbuildcommands
    {
        ("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
    }

filter "configurations:Debug"
    defines "DW_DEBUG"
    runtime "Debug"
    symbols "On"

filter "configurations:Release"
    defines "DW_RELEASE"
    runtime "Release"
    optimize "On"

filter "configurations:Dist"
    defines "DW_DIST"
    runtime "Release"
    optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    staticruntime "off"

targetdir ("bin/".. outputdir .."/%{prj.name}")
objdir ("bin-int/".. outputdir .."/%{prj.name}")

files
{
    "%{prj.name}/src/**.h",
    "%{prj.name}/src/**.cpp"
}

includedirs
{
    "Tracer/src"
}

links
{
    "Tracer"
}

filter "system:windows"
    cppdialect "C++20"
    systemversion "latest"

    defines
    {
        "TC_PLATFORM_WINDOWS"
    }

filter "configurations:Debug"
    defines "TC_DEBUG"
    runtime "Debug"
    symbols "On"

filter "configurations:Release"
    defines "TC_RELEASE"
    runtime "Release"
    optimize "On"

filter "configurations:Dist"
    defines "TC_DIST"
    runtime "Release"
    optimize "On"