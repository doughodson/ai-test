
AI-Test
=======

Breeding ground for examples on how to interface C++ to Soar, Lua, Clips and Duktape.  This include several read-evaluate-print loop (REPL) examples.

Directories & Examples
-------------------

* 3rdparty: contains include files and libraries for 3rd party dependencies. Soar library has been manually placed here, the lua and clips library are compiled.

* build: run make.bat in build/premake directory to create Visual Studio/C++ project and solution files.

* docs: documentation of interest

* packages: contains related packages/libraries of interest.

CLIPS
----

* clips-repl: stock REPL included with distribution

Duktape
-------

* duktape-test1: simple example that calls duktape from C++

Lua
---

* lua-luac: stock lua compiler (i.e., luac) included with distribution

* lib-mylib-dll: stock REPL that loads a shared extension library. Note: this requires the use of repl and library to be dynamically linked to lua library dll

* lua-repl: stock REPL included with distribution

* lua-repl-simple: simple and dumb REPL

* lua-repl-extend: stock lua REPL with extended C++ functions. The lua REPL is compiled with C++, not C.

* lua-test1: example of extending Lua with a C++ class using Luna

Soar
----

* soar-basicIo: test program that exercises C++ to interation I/O with soar.  It causes soar to spawn agents with associated debuggers.

* soar-hello-world: simpliest example of creating an agent and feeding it a soar 'script'

* soar-events: example that demostrates soar callback event system

* soar-client: connects to a remote kernel in a different process

* soar-server: spawns a kernel instance in a new thread and does nothing else

Notes
------

* At the moment, this is Windows only code.

* Add the 3rdparty/bin directory to your Windows system PATH.  This is needed so that soar example can spawn an interactive debugger.
