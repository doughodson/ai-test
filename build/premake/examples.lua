--------------------------------------------------------
-- Example applications
--------------------------------------------------------

project "test1"
   kind "ConsoleApp"
   targetname "test1"
   targetdir "../../test1"
   debugdir "../../test1"
   files {
      "../../test1/**.cpp",
      "../../test1/**.h"
   }
   includedirs { Dep3rdPartyIncPath }
   libdirs     { Dep3rdPartyLibPath }
   defines { "_CONSOLE" }
   links {LibSoar}


