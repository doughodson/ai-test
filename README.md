
AI-Test
=======

Breeding ground for examples on how to interface C++ to Soar, Lua, Clips and Duktape.  This include several read-evaluate-print loop (REPL) examples.

Directories
-----------

* 3rdparty: contains include files and libraries for 3rd party dependencies. Soar library has been manually placed here, the lua and clips library are compiled.

* build: run make.bat in build/premake directory to create Visual Studio/C++ project and solution files.

* docs: documentation of interest

* packages: contains related packages/libraries of interest.

* clips-repl: stock REPL included with distribution

* duktape-test1: simple example that calls duktape from C++

* lua-luac: stock lua compiler (i.e., luac) included with distribution

* lua-repl: stock REPL included with distribution

* lua-repl2: simple and dumb REPL

* lua-repl3: lua REPL extensioned with some custom C functions

* lua-test1: example of extending Lua with a C++ class using Luna

* soar-basicIo: test program that exercises C++ to interation I/O with soar.  It causes soar to spawn agents with associated debuggers.

* soar-hello-world: simpliest example of creating an agent and feeding it a soar 'script'

Notes
------

* At the moment, this is Windows only code.  Linux oriented Makefile are out of date and meaningless; please ignore.

* Add the 3rdparty/bin directory to your Windows system PATH.  This is needed so that soar example can spawn an interactive debugger.

