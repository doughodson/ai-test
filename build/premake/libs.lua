     
-- lua
project "lua"
   kind "StaticLib"
   -- destination directory for compiled binary target
   targetdir (targetDirPath)
   files {
      "../../3rdparty/src/lua-5.3.3/**.h",
      "../../3rdparty/src/lua-5.3.3/**.hpp",
      "../../3rdparty/src/lua-5.3.3/**.cpp",
      "../../3rdparty/src/lua-5.3.3/**.c"
   }
   defines { "LUA_COMPAT_MODULE" }
   targetname "lua"

-- clips
project "clips"
   kind "StaticLib"
   -- destination directory for compiled binary target
   targetdir (targetDirPath)
   files {
      "../../3rdparty/src/clips-6.30/**.h",
      "../../3rdparty/src/clips-6.30/**.cpp",
      "../../3rdparty/src/clips-6.30/**.c"
   }
   targetname "clips"

