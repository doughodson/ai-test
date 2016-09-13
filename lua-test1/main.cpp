
#include "Account.h"
#include "LuaState.h"

int main(int argc, char *argv[])
{
   // check if a Lua Script was specified
   if(argc != 2){
      printf("Error! No Lua script or too many scripts were specified.\n");
      printf("Usage: %s <Script>.lua\n", argv[0]);
      return -1;
   }

   // create a new state
   lua_State *L = luaL_newstate(); 

   // load Lua base library 
   luaopen_base(L);

   // register C++ classes
   Luna<Account>::Register(L);
   Luna<LuaState>::Register(L);

   // execute script
   printf("C++: Executing Lua Script: %s\n",argv[1]);
   if(luaL_dofile(L, argv[1]) != 0){
      printf("Lua Error: %s\n", lua_tostring(L,-1));
   }

   // close state
   lua_close(L);
   return 0;
}
