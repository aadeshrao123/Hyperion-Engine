workspace "Hyperion"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	startproject "Sandbox"


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Hyperion/vendor/GLFW/include"
IncludeDir["Glad"] = "Hyperion/vendor/Glad/include"
IncludeDir["ImGui"] = "Hyperion/vendor/imgui"

include "Hyperion/vendor/GLFW"
include "Hyperion/vendor/Glad"
include "Hyperion/vendor/imgui"

project "Hyperion"
	location "Hyperion"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

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
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links 
	{ 
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"HY_PLATFORM_WINDOWS",
			"HY_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "HY_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "HY_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "HY_DIST"
		runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

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
		systemversion "latest"

		defines
		{
			"HY_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "HY_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "HY_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "HY_DIST"
		runtime "Release"
		optimize "On"