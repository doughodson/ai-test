rem
rem delete old solution/workspace files
rem
rmdir /S /Q ..\vs2013
rmdir /S /Q ..\vs2015
rmdir /S /Q ..\vs2017
rem
rem delete old compiled libraries
rem
rem del ..\..\lib\*.lib
rem
rem create new solution/workspace files
rem
premake5-alpha11.exe --os=windows --file=premake5.lua vs2013
premake5-alpha11.exe --os=windows --file=premake5.lua vs2015
premake5-alpha11.exe --os=windows --file=premake5.lua vs2017

