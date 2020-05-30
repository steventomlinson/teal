workspace "teal"
    architecture "x64"

    configurations {
        "Debug",
        "Release"
    }

startproject "testbed"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "teal"
    location "teal"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("obj/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.location}/src/teal/**.h",
        "%{prj.location}/src/teal/**.cpp",
        "%{prj.location}/include/**"
    }

    includedirs {
        "%{prj.location}/include/",
        "dep/spdlog/include"
    }

    links {
        "opengl32"
    }

    postbuildcommands {
        ("{COPY} ../bin/" .. outputdir .. "/teal/ ../bin/" .. outputdir .. "/testbed/")
    }

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"
        defines {
            "TL_WIN32",
            "TL_DLL"
        }
        characterset ("ASCII")
        files {
            "%{prj.location}/src/platform/win32/**.cpp",
            "%{prj.location}/src/platform/win32/**.h"
		}

    filter "configurations:Debug"
        defines "TL_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "TL_RELEASE"
        optimize "On"

project "testbed"
    location "testbed"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("obj/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.location}/src/**.h",
        "%{prj.location}/src/**.cpp"
    }

    includedirs {
        "teal/include"
    }

    links {
        "teal"
    }

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"
        characterset ("ASCII")
        defines {
            "TL_WIN32"
        }

    filter "configurations:Debug"
        defines "TL_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "TL_RELEASE"
        optimize "On"