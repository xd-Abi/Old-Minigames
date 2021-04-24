project "Minigames"
    kind "ConsoleApp"
    language "C++"
    staticruntime "on"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "mgpch.h"
    pchsource "src/mgpch.cpp"

    files
    {
        "src/**.h",
        "src/**.cpp"
    }

    includedirs
    {
        "src",
        "vendor/glfw/include",
        "vendor/glad/include",
        "vendor/glm",
        "vendor/stb_image",
	"vendor/ImGui",
	"vendor/ImGui/src"
    }

    links
    {
        "glfw",
        "glad",
	"ImGui",
        "opengl32.lib"
    }

    defines
    {
        "_CRT_SECURE_NO_WARNINGS",
	"GLFW_INCLUDE_NONE"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

    filter "configurations:Debug"
        symbols "On"
		runtime "Debug"

    filter "configurations:Release"
        optimize "On"       
		runtime "Release"

    filter "configurations:Dist"
        optimize "On"        
		runtime "Release"