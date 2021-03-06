function get_root_location()
	return "%{wks.location}/"
end

function get_output_location(prj_name)
	return get_root_location() .. "build/bin/" .. prj_name .. "/%{cfg.longname}/"
end

function include_self()
	includedirs {
		"include/",
	}
	files {
		"include/**",
		"src/**",
	}
end

function set_location()
	location "%{wks.location}/build/proj/%{prj.name}/"
end

workspace "fun-with-sfml"
	location "../"
	language "C++"
	cppdialect "c++17"
	startproject "game-code"

	architecture "x86_64"
	configurations { "Debug", "Release" }

	filter { "configurations:Debug" }
		defines { "DEBUG", "_DEBUG" }
		symbols "On"

	filter { "configurations:Release" }
		defines { "NDEBUG" }
		optimize "On"
	
	filter {"system:windows", "action:vs*"}
		systemversion "latest"

	filter {}

	flags {
		"FatalWarnings"
	}

	targetdir ("%{wks.location}/build/bin/%{prj.name}/%{cfg.longname}")
	objdir ("%{wks.location}/build/obj/%{prj.name}/%{cfg.longname}")

include "../external/"

group "*"

project "game-code"
	kind "WindowedApp"
	set_location()
	debugdir "%{wks.location}/"
	
	defines {
		"SFML_STATIC",
	}

	files {
		get_root_location() .. "game-code/**.h",
		get_root_location() .. "game-code/**.cpp",
		get_root_location() .. "game-code/**.c",
	}

	includedirs {
		get_root_location() .. "external/sfml/include/",
		get_root_location() .. "game-code/",
	}

	dependson {
		'sfml-system',
		'sfml-graphics',
		'sfml-window',
		'sfml-audio',
	}
	
	libdirs { get_root_location() .. "external/sfml/extlibs/libs-msvc-universal/x64" }
	links {
		'sfml-system',
		'sfml-graphics',
		'sfml-window',
		'sfml-audio',

		'flac.lib',
		'freetype.lib',
		'ogg.lib',
		'openal32.lib',
		'vorbis.lib',
		'vorbisenc.lib',
		'vorbisfile.lib',
		'opengl32.lib',
		'freetype.lib',
		'winmm.lib',
		'gdi32.lib',
	}
