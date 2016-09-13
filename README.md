
AI-Test
=======

Breeding ground for examples on how to interface C++ to Soar, Lua and Clips

Directories
-----------

* 3rdparty: contains include files and libraries for 3rd party dependencies. Soar library has been manually placed here, the lua and clips library are compiled.

* build: Run make.bat in build/premake directory to create Visual Studio/C++ project and solution files.

* docs: collected documentation

* packages: contains related packages/libraries of interest.

* soar-test1: simple test program that exercises C++ to interation to soar to spawn agents and a soar debugger.

Notes
------

* At the moment, this is Windows only code.

* Add the 3rdparty/bin directory to your Windows system PATH.  This is needed so that soar example can spawn an interactive debugger.

