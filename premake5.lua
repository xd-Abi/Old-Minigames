workspace "Minigames"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "Minigames"
include "Minigames/vendor/glfw"
include "Minigames/vendor/glad"
include "Minigames/vendor/ImGui"
