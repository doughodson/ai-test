
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

