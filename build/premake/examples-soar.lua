
--------------------------------------------------------
-- Soar apps
--------------------------------------------------------

project "soar-hello-world"
   kind "ConsoleApp"
   targetname "soar-hello-world"
   targetdir "../../soar-hello-world"
   debugdir "../../soar-hello-world"
   files {
      "../../soar-hello-world/**.cpp",
      "../../soar-hello-world/**.h"
   }
   includedirs { Dep3rdPartyIncPath }
   libdirs     { Dep3rdPartyLibPath }
   defines { "_CONSOLE" }
   links {LibSoar}

project "soar-basicIo"
   kind "ConsoleApp"
   targetname "soar-basicIo"
   targetdir "../../soar-basicIo"
   debugdir "../../soar-basicIo"
   files {
      "../../soar-basicIo/**.cpp",
      "../../soar-basicIo/**.hpp",
      "../../soar-basicIo/**.h"
   }
   includedirs { Dep3rdPartyIncPath }
   libdirs     { Dep3rdPartyLibPath }
   defines { "_CONSOLE" }
   links {LibSoar}

project "soar-events"
   kind "ConsoleApp"
   targetname "soar-events"
   targetdir "../../soar-events"
   debugdir "../../soar-events"
   files {
      "../../soar-events/**.cpp",
      "../../soar-events/**.hpp",
      "../../soar-events/**.h"
   }
   includedirs { Dep3rdPartyIncPath }
   libdirs     { Dep3rdPartyLibPath }
   defines { "_CONSOLE" }
   links {LibSoar}

project "soar-client"
   kind "ConsoleApp"
   targetname "soar-client"
   targetdir "../../soar-client"
   debugdir "../../soar-client"
   files {
      "../../soar-client/**.cpp",
      "../../soar-client/**.h"
   }
   includedirs { Dep3rdPartyIncPath }
   libdirs     { Dep3rdPartyLibPath }
   defines { "_CONSOLE" }
   links {LibSoar}

project "soar-server"
   kind "ConsoleApp"
   targetname "soar-server"
   targetdir "../../soar-server"
   debugdir "../../soar-server"
   files {
      "../../soar-server/**.cpp",
      "../../soar-server/**.h"
   }
   includedirs { Dep3rdPartyIncPath }
   libdirs     { Dep3rdPartyLibPath }
   defines { "_CONSOLE" }
   links {LibSoar}
