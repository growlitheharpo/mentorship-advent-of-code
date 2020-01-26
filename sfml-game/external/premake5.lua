group "external/SFML"

local export_include_root = "%{wks.location}/../external/"

function sfml_lib (libName, extra)
	project("sfml-" .. libName)
		kind "StaticLib"
		warnings "Off"

		includedirs {
			"sfml/extlibs/headers/",
			"sfml/include",
			"sfml/src/",
		}

		files { 
			"sfml/include/SFML/" .. libName .. "/**",
			"sfml/src/SFML/" .. libName .. "/**",
		}

		defines { "SFML_STATIC" }
		
		removefiles { 
			"sfml/src/SFML/" .. libName .. "/*/**", -- remove the platform folders
		}

		filter { "system:windows" }
			files { "sfml/src/SFML/" .. libName .. "/Win32/**" }

		set_location()
		debugdir "./"

		if extra then
			extra()
		end
end

sfml_lib("system")

sfml_lib("window", function ()
	removefiles {
		"sfml/src/SFML/window/EGL**",
	}
end)

sfml_lib("graphics", function ()
	includedirs {
		"sfml/extlibs/headers/stb_image",
		"sfml/extlibs/headers/freetype2",
	}
	files {
		"sfml/extlibs/headers/stb_image/**.h",
		"sfml/extlibs/headers/freetype2/**.h",
	}
end)

sfml_lib("audio", function ()
	includedirs {
		"sfml/extlibs/headers/AL",
	}
	files {
		"sfml/extlibs/headers/AL/**.h"
	}

	defines {
		"auto_ptr=shared_ptr" -- WOW this is a hack
	}

end)
