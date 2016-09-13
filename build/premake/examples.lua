--------------------------------------------------------
-- Example applications
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


