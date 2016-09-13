--------------------------------------------------------
-- Soar apps
--------------------------------------------------------

project "soar-test1"
   kind "ConsoleApp"
   targetname "soar-test1"
   targetdir "../../soar-test1"
   debugdir "../../soar-test1"
   files {
      "../../soar-test1/**.cpp",
      "../../soar-test1/**.h"
   }
   includedirs { Dep3rdPartyIncPath }
   libdirs     { Dep3rdPartyLibPath }
   defines { "_CONSOLE" }
   links {LibSoar}

--------------------------------------------------------
-- Lua apps
--------------------------------------------------------

-- lua compiler
project "lua-luac"
   kind "ConsoleApp"
   targetname "luac"
   targetdir "../../lua-luac"
   debugdir "../../lua-luac"
   files {
      "../../lua-luac/**.cpp",
      "../../lua-luac/**.c",
      "../../lua-luac/**.h"
   }
   includedirs { Dep3RDPartyRoot .. "/src/lua-5.3.3" }
   libdirs     { Dep3rdPartyLibPath }
   defines { "_CONSOLE" }
   filter "Release32"
      links { "lua" }
      links {"Ws2_32", "Winmm", "comctl32", "gdi32"}
   filter "Debug32"
      links { "lua_d" }
      links {"Ws2_32", "Winmm", "comctl32", "gdi32"}


-- lua read-eval-print-loop
project "lua-repl"
   kind "ConsoleApp"
   targetname "repl"
   targetdir "../../lua-repl"
   debugdir "../../lua-repl"
   files {
      "../../lua-repl/**.c",
      "../../lua-repl/**.h"
   }
   includedirs { Dep3RDPartyRoot .. "/src/lua-5.3.3" }
   libdirs     { Dep3rdPartyLibPath }
   defines { "_CONSOLE", }
   filter "Release32"
      links { "lua" }
      links {"Ws2_32", "Winmm", "comctl32", "gdi32"}
   filter "Debug32"
      links { "lua_d" }
      links {"Ws2_32", "Winmm", "comctl32", "gdi32"}


-- lua read-eval-print-loop
project "lua-repl2"
   kind "ConsoleApp"
   targetname "repl"
   targetdir "../../lua-repl2"
   debugdir "../../lua-repl2"
   files {
      "../../lua-repl2/**.c",
      "../../lua-repl2/**.h"
   }
   includedirs { Dep3RDPartyRoot .. "/src/lua-5.3.3" }
   libdirs     { Dep3rdPartyLibPath }
   defines { "_CONSOLE", }
   filter "Release32"
      links { "lua" }
      links {"Ws2_32", "Winmm", "comctl32", "gdi32"}
   filter "Debug32"
      links { "lua_d" }
      links {"Ws2_32", "Winmm", "comctl32", "gdi32"}

-- lua read-eval-print-loop
project "lua-repl3"
   kind "ConsoleApp"
   targetname "repl"
   targetdir "../../lua-repl3"
   debugdir "../../lua-repl3"
   files {
      "../../lua-repl3/**.cpp",
      "../../lua-repl3/**.c",
      "../../lua-repl3/**.h"
   }
   includedirs { Dep3RDPartyRoot .. "/src/lua-5.3.3" }
   libdirs     { Dep3rdPartyLibPath }
   defines { "_CONSOLE", "LUA_COMPAT_MODULE" }
   filter "Release32"
      links { "lua" }
      links {"Ws2_32", "Winmm", "comctl32", "gdi32"}
   filter "Debug32"
      links { "lua_d" }
      links {"Ws2_32", "Winmm", "comctl32", "gdi32"}

-- lua test to interact with C++ code
project "lua-test1"
   kind "ConsoleApp"
   targetname "repl"
   targetdir "../../lua-test1"
   debugdir "../../lua-test1"
   files {
      "../../lua-test1/**.cpp",
      "../../lua-test1/**.c",
      "../../lua-test1/**.h"
   }
   includedirs { Dep3RDPartyRoot .. "/src/lua-5.3.3" }
   libdirs     { Dep3rdPartyLibPath }
   defines { "_CONSOLE", "LUA_COMPAT_MODULE" }
   filter "Release32"
      links { "lua" }
      links {"Ws2_32", "Winmm", "comctl32", "gdi32"}
   filter "Debug32"
      links { "lua_d" }
      links {"Ws2_32", "Winmm", "comctl32", "gdi32"}

--------------------------------------------------------
-- Clips apps
--------------------------------------------------------

-- interactive clips read-eval-print-loop
project "clips-repl"
   kind "ConsoleApp"
   targetname "repl"
   targetdir "../../clips-repl"
   debugdir "../../clips-repl"
   files {
      "../../clips-repl/**.cpp",
      "../../clips-repl/**.c",
      "../../clips-repl/**.h"
   }
   includedirs { Dep3RDPartyRoot .. "/src/clips-6.30" }
   libdirs     { Dep3rdPartyLibPath }
   defines { "_CONSOLE" }
   filter "Release32"
      links { "clips" }
      links {"Ws2_32", "Winmm", "comctl32", "gdi32"}
   filter "Debug32"
      links { "clips_d" }
      links {"Ws2_32", "Winmm", "comctl32", "gdi32"}


