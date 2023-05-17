group "garrysmod_common"
	project "scanning-advanced"
		kind "StaticLib" 
		location("projects/" .. os.target() .. "/" .. _ACTION)
		targetdir "%{prj.location}/%{cfg.architecture}/%{cfg.buildcfg}"
		debugdir "%{prj.location}/%{cfg.architecture}/%{cfg.buildcfg}"
		objdir "!%{prj.location}/%{cfg.architecture}/%{cfg.buildcfg}/intermediate/%{prj.name}"
		includedirs {"include", _GARRYSMOD_COMMON_DIRECTORY .. "/include"}
		
		files {
			"include/scanning/*.h",
			"source/*.cxx"
		}
		
		vpaths {
			["Header files/*"] = "include/scanning/*.h",
			["Source files/*"] = "source/*.cxx"
		}

		filter "system:linux or macosx"
			links "dl"
		
		IncludeHelpers()
		IncludeHelpersExtended()
		IncludeDetouring()
		IncludeScanning()
		IncludeSDKCommon()