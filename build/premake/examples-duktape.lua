
--------------------------------------------------------
-- Duktape (i.e. JavaScript)
--------------------------------------------------------

project "duktape-test1"
   kind "ConsoleApp"
   targetname "test1"
   targetdir "../../duktape-test1"
   debugdir "../../duktape-test1"
   files {
      "../../duktape-test1/**.cpp",
      "../../duktape-test1/**.c",
      "../../duktape-test1/**.h",
      "../../3rdparty/src/duktape-1.5.1/duktape.c"
   }
   includedirs { Dep3RDPartyRoot .. "/src/duktape-1.5.1" }
   defines { "_CONSOLE" }
   filter "Release32"
      links {"Ws2_32", "Winmm", "comctl32", "gdi32"}
   filter "Debug32"
      links {"Ws2_32", "Winmm", "comctl32", "gdi32"}


