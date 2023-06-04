workspace "Hyperion"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Hyperion/vendor/GLFW/include"

include "Hyperion/vendor/GLFW"

project "Hyperion"
	location "Hyperion"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-intermediate/" .. outputdir .. "/%{prj.name}")

	pchheader "Hypch.h"
	pchsource "Hyperion/src/Hypch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links 
	{ 
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"HY_PLATFORM_WINDOWS",
			"HY_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "HY_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "HY_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "HY_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-intermediate/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Hyperion/vendor/spdlog/include",
		"Hyperion/src"
	}

	links
	{
		"Hyperion"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"HY_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "HY_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "HY_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "HY_DIST"
		optimize "On"