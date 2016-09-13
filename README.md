
AI-Test
=======

Breeding ground for examples on how to interface C++ to Soar, Lua and Clips.  This include several real-evaluate-print-loop (REPL) examples.

Directories
-----------

* 3rdparty: contains include files and libraries for 3rd party dependencies. Soar library has been manually placed here, the lua and clips library are compiled.

* build: Run make.bat in build/premake directory to create Visual Studio/C++ project and solution files.

* docs: collected documentation

* packages: contains related packages/libraries of interest.

* clips-repl: REPL for clips

* lua-luac: lua compiler (i.e., luac)

* lua-repl: REPL included with stock lua distribution

* lua-repl2: very simple REPL for lua

* lua-repl3: REPL for lua with extensions

* lua-test1: example of extending Lua with Luna

* soar-test1: test program that exercises C++ to interation with soar.  It causes soar to spawn agents and associated debuggers.

Notes
------

* At the moment, this is Windows only code.  Linux oriented Makefile are out of date and meaningless; please ignore.

* Add the 3rdparty/bin directory to your Windows system PATH.  This is needed so that soar example can spawn an interactive debugger.

