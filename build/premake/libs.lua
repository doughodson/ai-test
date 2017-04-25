     
-- lua
project "lua-5.3.4"
   kind "StaticLib"
   -- destination directory for compiled binary target
   targetdir (targetDirPath)
   files {
      "../../3rdparty/src/lua-5.3.4/**.h",
      "../../3rdparty/src/lua-5.3.4/**.hpp",
      "../../3rdparty/src/lua-5.3.4/**.cpp",
      "../../3rdparty/src/lua-5.3.4/**.c"
   }
   defines { "LUA_COMPAT_MODULE" }
   targetname "lua-5.3.4"

project "lua-5.1.5"
   kind "StaticLib"
   -- destination directory for compiled binary target
   targetdir (targetDirPath)
   files {
      "../../3rdparty/src/lua-5.1.5/**.h",
      "../../3rdparty/src/lua-5.1.5/**.hpp",
      "../../3rdparty/src/lua-5.1.5/**.cpp",
      "../../3rdparty/src/lua-5.1.5/**.c"
   }
   defines { "LUA_COMPAT_MODULE" }
   targetname "lua-5.1.5"

-- clips
project "clips-6.30"
   kind "StaticLib"
   -- destination directory for compiled binary target
   targetdir (targetDirPath)
   files {
      "../../3rdparty/src/clips-6.30/**.h",
      "../../3rdparty/src/clips-6.30/**.cpp",
      "../../3rdparty/src/clips-6.30/**.c"
   }
   targetname "clips-6.30"

