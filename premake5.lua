local current_dir = _SCRIPT_DIR

function IncludeScanningAdvanced()
	local refcount
	if IncludePackage then
		refcount = IncludePackage "scanning-advanced"
	end

	local _project = project()
	
	local incld = externalincludedirs or sysincludedirs
	incld(current_dir .. "/include")
	
	links {"scanning-advanced", "helpers_extended", "helpers", "scanning"}

	if refcount == 1 then
		dofile(current_dir .. "/premake5_create_project.lua")
		project(_project.name)
	end
end
