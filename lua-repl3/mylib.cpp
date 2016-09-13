
#include "mylib.h"

// C headers
extern "C"
{
#include "lua.h"
#include "lauxlib.h"
};

int test_string(lua_State* l)
{
  printf("testme\n");
  return 0;
}

static const luaL_Reg mylib [] =
{
    { "test_string", test_string },
    { NULL, NULL }
};

int luaopen_mylib(lua_State* l)
{
   luaL_newlib(l, mylib);
   return 1;
}
