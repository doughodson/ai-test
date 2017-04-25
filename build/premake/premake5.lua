--
-- If premake command is not supplied an action (target compiler), exit!
--
-- Target of interest:
--     vs2013     (Visual Studio 2013)
--     vs2015     (Visual Studio 2015)
--     vs2017     (Visual Studio 2017)
--

-- we must have an ide/compiler specified
if (_ACTION == nil) then
  return
end

--
-- directory locations for 3rd party includes and libs
--
Dep3RDPartyRoot       = "../../3rdparty"
Dep3rdPartyIncPath    = Dep3RDPartyRoot .. "/include"
Dep3rdPartyLibPath    = Dep3RDPartyRoot .. "/lib/" .. _ACTION .. "-32"

print ("3rd Party Paths:")
print ("  Include   :" .. Dep3rdPartyIncPath)
print ("  Libraries :" .. Dep3rdPartyLibPath)

--
-- target directory path for compiled libraries (Lua and Clips)
--
targetDirPath = Dep3rdPartyLibPath

print ("Target directory path: " .. targetDirPath)

--
-- 3rd party library names
--
LibSoar  = "Soar"

workspace "ai-test"

   -- destination directory for generated solution/project files
   location ("../" .. _ACTION)

   -- create console application by default
   kind "ConsoleApp"

   -- C++ code in all projects
   language "C++"

   --
   -- Build (solution) configuration options:
   --     Release        (Application linked to Multi-threaded DLL)
   --     Debug          (Application linked to Multi-threaded Debug DLL)
   --
   configurations { "Release32", "Debug32" }

   -- common release configuration flags and symbols
   filter { "Release32" }
      flags { "Optimize" }
      -- enable compiler intrinsics and favour speed over size
--      buildoptions { "/Oi", "/Ot" }
      defines { "WIN32", "NDEBUG" }

   -- common debug configuration flags and symbols
   filter { "Debug32" }
      flags { "Symbols" }
      targetsuffix "_d"
      -- enable compiler intrinsics
--      buildoptions { "/Oi" }
      defines { "WIN32", "_DEBUG" }

   -- libs
   dofile "libs.lua"

   -- examples
   dofile "examples-clips.lua"
   dofile "examples-duktape.lua"
   dofile "examples-lua.lua"
   dofile "examples-soar.lua"
