rem
rem set premake location
rem
@SET Premake=premake5-alpha9.exe
rem
rem delete old solution/workspace files
rem
rmdir /S /Q ..\vs2013
rem
rem delete old compiled libraries
rem
rem del ..\..\lib\*.lib
rem
rem create new solution/workspace files
rem
%Premake% --os=windows --file=premake5.lua vs2013
